#ifndef __FUNCTIONS_ADVANCE_004_H
#define __FUNCTIONS_ADVANCE_004_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <exception>
#include <limits>
#include <random>
#include <typeinfo>
#include <tuple>
#include <regex>
#include <memory>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>
#include <filesystem>
#include <chrono>
#include <optional>

#include <cassert>
#include <cstddef>
#include <cwctype>
#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cctype>
#include <cstring>
#include <cmath>


using namespace std;

/*
    - static variable within the function:
        - In C++, a static variable is a variable that retains its value across function calls and exists throughout the entire program's execution. 
        - The static keyword is used to declare a static variable. 
        - When a variable is declared as static inside a function, its lifetime extends beyond the function's scope, and its value persists between calls to that function.
        - Static variables have the following key characteristics:
            - 01) Lifetime: 
                - The lifetime of a static variable begins when the program starts and ends when the program terminates. 
                - Unlike local variables, which are created and destroyed each time the function is called, a static variable's memory is allocated only once when the program starts, and it remains allocated throughout the entire program's execution.
            - 02) Initialization:
                - A static variable is initialized only once, during the first call to the function in which it is declared. 
                - Subsequent calls to the function will not reinitialize the static variable; instead, it will retain its value from the previous call.
            - 03) Scope:
                - A static variable has local scope, meaning it is accessible only within the function where it is declared. 
                - It is not visible outside that function, even though its lifetime extends beyond the function's scope.
            - 04) Storage:
                - The storage class of a static variable is "static," indicating that it is stored in the data segment of the program's memory, rather than the stack (where automatic variables are stored). 
                - This makes static variables suitable for preserving data across function calls.
        - Static variables are commonly used when you need to maintain state information between function calls or track the number of times a function is called. 
        - However, due to their persistent nature, using static variables inappropriately can lead to unintended side effects and hinder program readability and maintainability. 
        - Therefore, it's essential to use static variables judiciously and for their intended purposes.
*/

void fn_static_variable()
{
    // Declare a static variable within the function
    static int count = 0;
    count++;

    std::cout << "Static variable count: " << count << std::endl;
}

void func_static_variable_calls()
{
    // Call the function multiple times
    fn_static_variable();
    fn_static_variable();
    fn_static_variable();
}











#endif
