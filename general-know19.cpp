    // Write your solution here
    // C++23 using GCC 14.2
    // Debug with std::cerr or std::clog.
    // All headers are already included for you in the test environment.
    // !!! IMPORTANT !!!
    // 99% of headers are pre-compiled for you server-side.
    // If your submission fails to compile due to a missing header, add it to your submission.

    class ILogger {
        public:
            virtual ~ILogger() = default;
            virtual void log(const std::string& message) = 0;
        };
        
        class ConsoleLogger : public ILogger {
        public:
            virtual void log(const std::string& message) override {
                std::cout << "LOG: " << message << std::endl;
            }
        };
        
        // Implement this.
        class NullLogger: public ILogger{
            virtual void log(const std::string& message){
                if ( message == nullptr){
                    return nullptr;
                }

            }
        
        
        };
        
        enum class LoggerType {
            None,
            Console,
            // Pretend other logger types exist.
        };
        
        // Implement this.
        class LoggerFactory{
            
            unique_ptr<ILogger> logger = make_unique<NullLogger>(); 
            if (type == LoggerType::None){
                return nullptr;
            }
            else if (type == LoggerType::Console){
                logger = make_unique<ConsoleLogger>();
            }
            else{
                logger = make_unique<NullLogger>();
            }
            return GetLogger(logger);
        }
        
        std::shared_ptr<ILogger> GetLogger(std::unique_ptr<ILogger> logger){
            return logger;
        }
