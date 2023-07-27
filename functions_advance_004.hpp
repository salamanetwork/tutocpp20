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

/*
    - Inline functions:
        - What are Inline Functions?
            - In C++, an inline function is a special type of function that is marked with the inline keyword. 
            - When a function is declared as inline, the compiler attempts to replace each function call with the actual code of the function at the call site. 
            - In essence, it's like copy-pasting the function's code directly where it is called, rather than making a regular function call.
        - How do Inline Functions Work?
            - When you call a regular function, the program needs to perform several steps:
                - Push the function parameters onto the stack.
                - Jump to the function's code (function call).
                - Execute the function code.
                - Return to the original location after the function finishes (function return).
            - When you call an inline function:
                - In contrast, when you call an inline function, the function's code is inserted directly at the call site.
                - There is no overhead of function call and return. 
                - The actual function code becomes part of the calling code, and it's as if you had written the function code directly at the call site.
        - Advantages of Using Inline Functions:
            - Performance Improvement: 
                - By eliminating the function call overhead, inline functions can improve performance, especially for small, frequently called functions. 
                - This is because the function code is directly integrated into the calling code, reducing the time taken for function call and return.
            - Optimization Opportunities:
                - Inlining enables the compiler to perform further optimizations, such as constant folding and dead code elimination, as it has more context about the function's usage.
        - When to Use Inline Functions:
            - Small Functions: 
                - Inline functions work best for small functions with a few lines of code.
                - Functions with larger bodies may not benefit from inlining, and the increased code size may outweigh the performance benefits.
            - Frequent Calls: 
                - Inline functions are most effective when they are called frequently. 
                -  Functions that are rarely called may not see significant performance gains from inlining.
            - Header-Only Libraries: 
                - Inline functions are commonly used in header-only libraries, where the function definitions are provided in the header itself. 
                - This approach allows the compiler to see the function's definition during the compilation of all source files that include the header, increasing the likelihood of inlining.
        - Limitations and Considerations:
            - Compiler Decision: 
                - The decision to inline a function is ultimately made by the compiler. 
                - The inline keyword is just a request to the compiler to consider inlining. 
                - The compiler may choose not to inline the function if it believes inlining is not beneficial or if the function is too complex to inline.
            - Code Bloat: 
                - Excessive use of inline functions can lead to code bloat, where the compiled binary becomes larger due to duplicated function code at multiple call sites. 
                - This can impact memory usage and cache performance.
        - When Not to Use Inline Functions:
            - Large Functions: 
                - Avoid marking large or complex functions as inline, as it can result in code bloat and may not provide significant performance improvements.
            - Recursive Functions: 
                - Recursive functions are generally not suitable for inlining due to the potential for excessive code duplication.
        - Inline Functions vs. Function Templates:
            - Function templates also provide a form of code inlining, as they are expanded at compile time for specific argument types. 
            -  In contrast, inline functions are expanded at the call site for a specific function call, regardless of the argument types.
        - Summary:
            - Inline functions in C++ provide a way to request the compiler to replace function calls with the actual function code, leading to potential performance improvements for small, frequently called functions. 
            - However, the decision of inlining is made by the compiler, and it is essential to use inline functions judiciously and in appropriate scenarios to avoid code bloat and maintain readability.
*/

// Inline function definition
inline int fun_inline_add(int a, int b)
{
    return a + b;
}

void func_inline_add_call()
{
    int num1 = 3;
    int num2 = 5;

    // Call the inline function
    int result = fun_inline_add(num1, num2);

    std::cout << "Result: " << result << std::endl;

}











#endif
