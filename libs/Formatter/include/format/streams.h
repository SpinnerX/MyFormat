#include <sstream>
#include <cstring>
#include <messageFormatter.h>

namespace MyFormatter{
    template<typename... Args>
    std::string format(const std::string msg, Args&&... args){
        return messageFormatter(msg, args...).get_message();
    }
};