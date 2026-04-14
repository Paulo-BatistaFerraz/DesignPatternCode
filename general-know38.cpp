#include <memory>        // shared_ptr, make_shared
#include <optional>      // std::optional
#include <unordered_map> // std::unordered_map
#include <string>        // std::string

class INotifier{
    public:
        virtual ~INotifier() = default;
        virtual void notify(const std::string& message) = 0;
        
}

class EmailNotifier : public INotifier {
    public:
    virtual void notify(const std::string& message) override{
        std::cout << "EMAIL Notify" << message << std::endl;
    }
};

class NullImplementation : public INotifier { 
    public:
    virtual void notify(const std::string& message) override{}
};

enum class NullNotifierType {
    Email,
    None,
};


shared_ptr<INotifier> GetNotifier(std::optional<NullNotifierType> type){
    const static std::unordered_map<NullNotifierType, std::shared_ptr<INotifier>> loggers_
    {
        {NullNotifierType::Email, make_shared<EmailNotifier>()},
        {NullNotifierType::None, make_shared<NullImplementation>()},
    };

    if (!type.has_value()){
        return loggers_.at(NullNotifierType::None);
    }

    return loggers_.at(type.value());
}

int main(){
    auto log = GetNotifier(NullNotifierType::Email);
    log->notify("LOG EMAIL");
    return 0;
}