#include <iostream>
#include <cstring>
#include <cstdlib>

namespace Logger_Interface{
    /*
    Trace - minor debug details
    Debug - debugging information
    Info - record major events
    Warn - exceptions, bugs
    Error - failed to perform tasks
    Fatal - error causing crash
    */

    namespace level{
        enum Severity{
            TRACE = 0,
            DEBUG = 1,
            INFO = 2,
            WARNING = 3,
            ERROR = 4,
            FATAL = 5,
            LEVEL_OFF = 6,
        };
    };

    enum levels_enum : int {
        trace = level::TRACE,
        debug = level::DEBUG,
        info = level::INFO,
        warn = level::WARNING,
        err = level::ERROR,
        fatal = level::FATAL,
        off = level::LEVEL_OFF
    };

    namespace LoggerColors{
        const std::string RESET   = "\033[0m";
        const std::string BLACK   = "\033[30m";      /* Black */
        const std::string RED     = "\033[31m";      /* Red */
        const std::string GREEN   = "\033[32m";      /* Green */
        const std::string YELLOW  = "\033[33m";      /* Yellow */
        const std::string BLUE    = "\033[34m";      /* Blue */
        const std::string MAGENTA = "\033[35m";      /* Magenta */
        const std::string CYAN    = "\033[36m";      /* Cyan */
        const std::string WHITE   = "\033[37m";      /* White */
        const std::string BOLDBLACK   = "\033[1m\033[30m";      /* Bold Black */
        const std::string BOLDRED     = "\033[1m\033[31m";      /* Bold Red */
        const std::string BOLDGREEN   = "\033[1m\033[32m";      /* Bold Green */
        const std::string BOLDYELLOW  = "\033[1m\033[33m";      /* Bold Yellow */
        const std::string BOLDBLUE    = "\033[1m\033[34m";      /* Bold Blue */
        const std::string BOLDMAGENTA = "\033[1m\033[35m";      /* Bold Magenta */
        const std::string BOLDCYAN    = "\033[1m\033[36m";      /* Bold Cyan */
        const std::string BOLDWHITE   = "\033[1m\033[37m";      /* Bold White */
        const std::string GRAY       = "\x1b[38;20m";  /* Light Gray (Highlighted)*/
    };
};