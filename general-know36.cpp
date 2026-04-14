#include <iostream>
#include <memory>
#include <optional>
#include <unordered_map>


class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string&) = 0;
};

class ConsoleLogger : public ILogger {
public:
    virtual void log(const std::string& message) override {
        std::cout << "LOG: " << message << std::endl;
    }
};

class NullLogger : public ILogger {
public:
    virtual void log(const std::string&) override { }
};

enum class LoggerType {
    None,
    Console,
};

std::shared_ptr<ILogger> GetLogger(std::optional<LoggerType> type) {
    // Baby factory method :)
    const static std::unordered_map<LoggerType, std::shared_ptr<ILogger>> loggers_
    {
        { LoggerType::Console, std::make_shared<ConsoleLogger>() },
        { LoggerType::None, std::make_shared<NullLogger>() },
    };

    if (!type.has_value()) {
        return loggers_.at(LoggerType::None);
    }

    return loggers_.at(type.value());
}


int main() {
    auto logger = GetLogger(LoggerType::Console);
    logger->log("Order filled");
    return 0;
}
