#include "formatter.h"

namespace MyFormatter{
    /**
     * @brief 
     * Handle using the Formatter
     * Using Formatter to format message
     * Example: LoggerMessage msg("This is {} and he is {} years old!", "Bob", 2);
     * 
     */
    class messageFormatter {
        using filename_t = std::string;
    public:

    template<typename... Args>
    messageFormatter(const std::string& message, Args&&... args) {
        std::lock_guard<std::mutex> guard(m_mutex);
        // this->message = Formatter().format(message, std::forward<Args>(args)...);
        this->message = Formatter::formats(message, std::forward<Args>(args)...);
    }
    
    // For debugging purpose.
    inline std::string get_message() const {
        std::lock_guard<std::mutex> guard(m_mutex);
        return message;
    }

    // make printing out this class easier.
    friend std::ostream& operator<<(std::ostream& outs, messageFormatter& LogMsg){
        outs << LogMsg.message;
        return outs;
    }

    bool operator==(const messageFormatter& other){ return message == other.message; }
    bool operator==(const std::string& other) { return message == other; }
    
    private:
        std::string message;
        mutable std::mutex m_mutex; // mutable allows this to be assigned as a const variable.
    };

};