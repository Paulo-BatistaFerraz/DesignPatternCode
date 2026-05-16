#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <unordered_set>
#include <functional>
#include <utility>
 
// ---------- Domain type ----------
struct Instrument
{
    std::string Symbol;
    double Price;
};
 
// Hash specialization (in std, as the original snippet implied)
namespace std
{
    template<>
    struct hash<Instrument>
    {
        std::size_t operator()(const Instrument& item) const noexcept
        {
            return std::hash<std::string>{}(item.Symbol);
        }
    };
}
 
namespace aux
{
    bool AreEqual(const Instrument& a, const Instrument& b)
    {
        return a.Symbol == b.Symbol;
    }
}
 
// ---------- Deduplicating FIFO queue ----------
template <typename T>
class DedupQueue
{
public:
    // Returns true if inserted, false if a duplicate was rejected.
    bool write(const T& item)
    {
        auto hash_value = std::hash<T>{}(item);
        auto [_, inserted] = items_.insert(hash_value);
        if (!inserted)
            return false;
 
        list_.push_back(item);
        ++size_;
        return true;
    }
 
    std::optional<T> read()
    {
        if (size_ == 0)
            return {};
 
        // FIX: take ownership of the value BEFORE pop_front().
        // The original code held `const auto& item = list_.front();`,
        // which dangled the moment pop_front() destroyed that element.
        auto item = std::move(list_.front());
        auto hash_value = std::hash<T>{}(item);
 
        list_.pop_front();
        items_.erase(hash_value);
        --size_;
 
        return item;          // safe: `item` is a local, fully owned value
    }
 
    std::size_t size() const noexcept { return size_; }
 
private:
    std::list<T> list_;
    std::unordered_set<std::size_t> items_;   // stores hashes for O(1) dedup
    std::size_t size_ = 0;
};
 
// ---------- Demo ----------
int main()
{
    DedupQueue<Instrument> queue;
 
    std::cout << std::boolalpha;
    std::cout << "write AAPL: " << queue.write({"AAPL", 150.0}) << '\n';
    std::cout << "write GOOG: " << queue.write({"GOOG", 2800.0}) << '\n';
    std::cout << "write AAPL: " << queue.write({"AAPL", 151.0}) << "  (duplicate)\n";
    std::cout << "write MSFT: " << queue.write({"MSFT", 300.0}) << '\n';
 
    std::cout << "\nsize = " << queue.size() << "\n\n";
 
    while (auto item = queue.read())
        std::cout << item->Symbol << " @ " << item->Price << '\n';
 
    std::cout << "\nfinal size = " << queue.size() << '\n';
    return 0;
}