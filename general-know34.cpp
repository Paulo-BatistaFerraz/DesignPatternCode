// Write your solution here
// C++23 using GCC 14.2
// Debug with std::cerr or std::clog.
// All headers are already included for you in the test environment.
// !!! IMPORTANT !!!
// 99% of headers are pre-compiled for you server-side.
// If your submission fails to compile due to a missing header, add it to your submission.

struct Instrument { 
    std::string Symbol; 
    double Price; 
};


template <typename T>
class getcrackedQueue
{
public:

    void write(const T& item)
    {
        // Implement
        queue.push_back(item); // 
    }

    std::optional<T> read()
    {
        // Implement
        if (queue.empty())
    }

    bool try_read(T& item)
    {
        // Implement
    }

    [[nodiscard]] bool empty() const
    {
        // Implement
    }

    [[nodiscard]] std::size_t size() const
    {
        // Implement
    }


private:

};

int main() {
    getcrackedQueue<Instrument> instruments;
    instrument.write({ "GOOG", 94.5 });
    instrument.write({ "APPL", 200 });
    instrument.write({ "GOOG", 95 });
    const auto size = instruments.size(); // 2
    const auto initialRead = instruments.read(); // GOOG 95
    const auto nextRead = instruments.read(); // APPL 200
    const auto isEmpty = instruments.empty(); // true
}