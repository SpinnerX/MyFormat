#include <iostream>
#include <cstring>
#include <vector>
#include <thread>
#include <chrono>
#include <any>

namespace MyFormatter{
    class Formatter{
    public:
        // This allows us to format our strings.
        template<typename... Args>
        inline std::string format(const std::string& message, Args&&... args) {
            // std::vector<std::variant<std::string, int>> arg_list{args...};
            std::vector<std::any> arg_list{args...};
            std::string result;
            std::size_t pos = 0;

            for (std::size_t i = 0; i < arg_list.size(); ++i) {
            std::size_t open_bracket = message.find("{}", pos);
            if (open_bracket == std::string::npos) break;
            result += message.substr(pos, open_bracket - pos);
            // DEBUGGING purpose.
            // if(arg_list[i].type() == typeid(std::string)) std::cout << "Debug: " << get_string_from_any(arg_list[i]) << std::endl;
            result += get_string_from_any(arg_list[i]);
            pos = open_bracket + 2;
            }
            result += message.substr(pos);
            return result;
        }

        // This is just a static version for the formats(Args...) function.
        template<typename... Args>
        inline static std::string formats(const std::string& message, Args&&... args){
            std::vector<std::any> arg_list{args...}; // vector containing all of the args.
            std::string result = "";
            std::size_t pos = 0;
            
            for (std::size_t i = 0; i < arg_list.size(); ++i) {
            std::size_t open_bracket = message.find("{}", pos); // search in the strings for any open brackets like: "{}"

            if (open_bracket == std::string::npos) break;
            result += message.substr(pos, open_bracket - pos);
            // DEBUGGING purpose.
            // if(arg_list[i].type() == typeid(std::string)) std::cout << "Debug: " << get_string_from_any(arg_list[i]) << std::endl;
            result += Formatter().get_string_from_any(arg_list[i]);
            pos = open_bracket + 2;
            }

            result += message.substr(pos);
            return result;
        }

        private:
        // this specific function allows to get strings and integers in our print-statements only.
        // Just a mock function, to show how std::holds_alternative is used.
        inline std::string get_string_from_variant(const std::variant<std::string, int>& v) {
            if (std::holds_alternative<std::string>(v)) {
            return std::get<std::string>(v);
            }

            return std::to_string(std::get<int>(v));
        }

        // This checks that any type we pass into the function it will be returned to as a string.
        // This is the function that is the one to be called.
        // As this can be adjusted to take the majority of C++'s primitive types.
        inline std::string get_string_from_any(const std::any& a) {
            
            if (a.type() == typeid(std::string)) return std::any_cast<std::string>(a);
            else if (a.type() == typeid(int)) return std::to_string(std::any_cast<int>(a));
            else if (a.type() == typeid(double)) return std::to_string(std::any_cast<double>(a));
            else if(a.type() == typeid(float)) return std::to_string(std::any_cast<float>(a));
            else if(a.type() == typeid(unsigned)) return std::to_string(std::any_cast<unsigned>(a));
            else if (a.type() == typeid(bool)) return std::any_cast<bool>(a) ? "true" : "false";
            else if(a.type() == typeid(const char*)) return std::any_cast<const char*>(a);
            else if (a.type() == typeid(char)) return std::string(1, std::any_cast<char>(a));

            return "null_type";
        }
    };
};