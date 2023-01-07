#include <formatCpp.h>
#include <StopWatch.h>
#include <vector>
#include <cstdlib>
#include <mutex>
#include <atomic>
#include <thread>
using namespace std;
using namespace MyFormatter;

void thread_fun(int n){
    messageFormatter message("Thread # {}\n", n);
    std::cout << message << std::endl;
}

void thread1_is_safe(messageFormatter& msg){
  std::cout << "Thread #1, " << msg << std::endl;
}

void thread2_is_safe(messageFormatter& msg){
  std::cout << "Thread #2, " << msg << std::endl;
}


void testThreadMain(){
    cout << "\n\n-----------[THREADS-SAFETY TESTING]------------------" << endl;
    vector<thread> threads;
    vector<thread> threads2;
    StopWatch sw = StopWatch();

    for(int i = 0; i <= 10; i++){
      // Shows how to check threads by using Mess
        messageFormatter messageThread("number #{}\n", i);
        messageFormatter messageThread2("number #{}\n", i);
        threads.emplace_back(thread1_is_safe, std::ref(messageThread));
        threads2.emplace_back(thread2_is_safe, std::ref(messageThread2));
        this_thread::sleep_for(chrono::milliseconds(10)); // this_thread grabs the current thread. then adds a delay for 10 millisecs.
    }

    // If we do not join, then the thread will have C++ terminate the thread rather then this iteration.
    for (thread& thread : threads) thread.join();
    for(thread& thread : threads2) thread.join();

    MyFormatter::print("Elapsed time: {}\n", sw.elapsed().count());
}