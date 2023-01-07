#include <thread>
#include <mutex>
#include <atomic>
#include <formatCpp.h>

std::atomic shared_data(0);

void incremend_data(int n){
    for(int i = 0; i < n; i++) shared_data++; 
}

int testThread(){
    std::thread t1(incremend_data, 100);
    std::thread t2(incremend_data, 100);

    if(shared_data != 200) MyFormatter::print("Race condition detected!");

    return 0;
}