#include <iostream>
#include <vector>
#include <thread>
#include <stdexcept>
#include <cctype>
#include <formatCpp.h>
using namespace std;
using namespace MyFormatter;

void tests(){
    messageFormatter test0("This is {} and he is {} years old!\n", "Bob", 2);
    messageFormatter test1("This is {} and he is {}man!\n", "Old man", "Candy");
    messageFormatter test2("{} + {} = {}\n", 2, 2, 2+2);
    messageFormatter test3("{} + {} = {}\n", 2.5, 2.3, 2.5+2.3);
    messageFormatter test4("{} + {} = {}\n", 2.5f, 2.7f, 2.5f + 2.7f);

    std::string expected0 = "This is Bob and he is 2 years old!\n";
    std::string expected1 = "This is Old man and he is Candyman!\n";
    std::string expected2 = std::to_string(2) + " + " + std::to_string(2) + " = " + std::to_string(2+2) + '\n';
    std::string expected3 = std::to_string(2.5) + " + " + std::to_string(2.3) + " = " + std::to_string(2.5+2.3) + '\n';
    std::string expected4 = std::to_string(2.5f) + " + " + std::to_string(2.7f) + " = " + std::to_string(2.5f+2.7f) + '\n';

    if(test0 == expected0) std::cout << "TEST 0 PASSED\n";
    if(test1 == expected1) std::cout << "TEST 1 PASSED\n";
    if(test2 == expected2) std::cout << "TEST 2 PASSED\n";
    if(test3 == expected3) std::cout << "TEST 3 PASSED\n";
    if(test4 == expected4) std::cout << "TEST 4 PASSED\n";
}

void testPrints(){
    messageFormatter message("This is {} and he is {} years old!", "Bob", 2);
    cout << message << endl;

    messageFormatter message2("This is {} and he is {} years old!", "Bob", 2);
    cout << message2 << endl;

    MyFormatter::print("This is {} and he is {}man!", "Old man", "Candy");
    MyFormatter::print("{} + {} = {}", 2, 2, 2+2);
    MyFormatter::print("{} + {} = {}", 2.5, 2.3, 2.5+2.3);
    MyFormatter::print("{} + {} = {}", 2.5f, 2.7f, 2.5f + 2.7f);
}

// Allows us to check if the two types are the same.
template<typename _Tp, typename _Tp2>
void compareTypes0(){
    // Checks if the parameter type "_Tp" is the same type as std::is_same_v<int>
    if constexpr (std::is_same_v<_Tp, _Tp2>) MyFormatter::print("The same type!\n");
    else MyFormatter::print("Not the same type!\n");
}

