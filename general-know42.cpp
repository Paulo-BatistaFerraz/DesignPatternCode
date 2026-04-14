#include <vector>
#include <cstddef>
#include <unordered_set>
#include <utility>

struct IMessageListener {
    virtual ~IMessageListener() = default;
    virtual void OnBytesReceived(const std::vector<std::byte>& bytes) = 0;
};

class TcpMessenger {
public:
    TcpMessenger(std::vector<IMessageListener*> listeners) {
        std::unordered_set<IMessageListener*> seen;
        for (auto* listener : listeners) {
            if (listener && seen.insert(listener).second)
                listeners_.push_back(listener);
        }
    }

protected:
    void OnReceive(const std::vector<std::byte>& bytes) {
        for (auto* listener : listeners_) {
            try {
                listener->OnBytesReceived(bytes);
            } catch (...) {
                // swallow — one bad listener must not break the others
            }
        }
    }

private:
    std::vector<IMessageListener*> listeners_;
};
