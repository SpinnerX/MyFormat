#include <ctime>
#include <cstdlib>
#include <chrono>

namespace MyFormatter{
    /**
     * @brief 
     * This class handles by showing us our elapsed time.
     * Such as giving us a starting time
     * then printing out our ending time.
     * This is just used to can just be used to check how long something was to start to end.
     */
    class StopWatch{
        using clock = std::chrono::steady_clock;
    public:
        StopWatch() : start_tp(clock::now()){} // This is our starting time

        std::chrono::duration<double> elapsed() const { // This is our ending time.
            return std::chrono::duration<double>(clock::now() - start_tp);
        }
        
    private:
        std::chrono::time_point<clock> start_tp;
    };
};