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


/*
    - Recursive Function:
        - Introduction to Recursive Functions:
            - In computer programming, a recursive function is a function that calls itself to solve a problem. 
            - The process of solving a problem by breaking it down into smaller subproblems and solving each subproblem in a similar way is called recursion. 
            - Recursive functions are a fundamental concept in programming and are widely used in various algorithms and data structures.
        - How Recursive Functions Work:
            - A recursive function consists of two main components:
                - Base case: 
                    - This is the termination condition that defines when the recursion should stop. 
                    - It represents the simplest instance of the problem that can be solved directly without further recursion. 
                    - The base case is crucial to prevent infinite recursion and stack overflow errors.
                - Recursive case: 
                    - This is the part of the function where it calls itself with modified parameters to solve a smaller subproblem. 
                    - The function makes progress towards the base case with each recursive call.
                - The general structure of a recursive function is as follows:
                    return_type recursive_function(parameters)
                    {
                        // Base case(s) - Termination condition(s)
                        if (base_case_condition)
                        {
                            // Return the base case result
                            return base_case_result;
                        }
                        else
                        {
                            // Recursive case - Call the function with modified parameters
                            return recursive_function(modified_parameters);
                        }
                    }

                    - The function keeps calling itself with modified parameters until the base case is reached, at which point the recursion stops, and the function returns a result back through the chain of recursive calls.
        - Example of Recursive Function: Factorial
            - A recursive function that calculates the factorial of a non-negative integer. 
            - The factorial of a number n (denoted as n!) is the product of all positive integers less than or equal to n.
        - Tail Recursion:
            - In some programming languages, tail recursion is a special case of recursion where the recursive call is the last operation performed in a function. 
            - In such cases, the compiler may optimize the recursion by reusing the current function's stack frame for the next recursive call, effectively reducing the risk of stack overflow.
            - However, C++ does not guarantee tail call optimization (TCO), so tail recursion should be used with caution in C++. 
            - Tail recursion is still useful for its simplicity and conceptual clarity.
        - When to Use Recursive Functions:
            - Recursive functions are useful when solving problems that exhibit recursive structures, such as tree traversal, searching, backtracking, and divide-and-conquer algorithms. 
            - However, not all problems are suitable for recursive solutions. 
                - For instance, problems with exponential growth in recursion depth may not be efficiently solved using recursion.
        - Performance Considerations:
            - Recursion involves function calls and maintaining a stack of recursive calls, which can lead to increased memory consumption and slower execution for deeply nested recursions. 
                - In such cases, iterative solutions or memoization techniques may be more efficient.
        - Summary:
            - Recursive functions in C++ are functions that call themselves to solve problems by dividing them into smaller subproblems. 
            - They involve a base case that terminates the recursion and a recursive case where the function calls itself with modified parameters. 
            - Recursive functions are widely used to solve problems with recursive structures, but they should be designed carefully with proper base cases to prevent infinite recursion. 
            - While recursion can lead to concise and elegant solutions, it's essential to consider performance implications for deeply nested recursions.

*/

// Recursive function to calculate factorial
int fn_rec_factorial(int n)
{
    // Base case: 0! and 1! are both 1
    if (n == 0 || n == 1)
        return 1;
    
    // Recursive case: n! = n * (n-1)!
    return n * fn_rec_factorial(n - 1);
}

void func_rec_fact()
{
    int num = 5;
    int result = fn_rec_factorial(num);
    std::cout << "Factorial of " << num << " is: " << result << std::endl;
}

/*
    
    Let's analyze the output of the Fibonacci number calculation for `n = 10` from the previous recursive function example.
    
    - Explanation:
        - The output `Fibonacci(10) = 55` indicates that the 10th Fibonacci number is 55.
    
    - Working of the Recursive Function:
        - The `fibonacci()` function is defined to compute the nth Fibonacci number using recursion. 
    
    - Let's walk through how the function evaluates `Fibonacci(10)`:
        - 1. `fibonacci(10)` is called in the `main()` function.
        - 2. In the `fibonacci()` function:
           - The base cases are checked. Since `n` is not 0 or 1, the recursive case is executed.
           - The function returns `fibonacci(n - 1) + fibonacci(n - 2)`.
        
        - 3. The function now calls `fibonacci(9)` and `fibonacci(8)` to calculate the 9th and 8th Fibonacci numbers, respectively.
        
        - 4. The recursive calls continue until reaching the base cases:
           - `fibonacci(2)` calls `fibonacci(1)` and `fibonacci(0)`.
           - `fibonacci(1)` returns 1, and `fibonacci(0)` returns 0.
        
        - 5. Now, the recursion starts to unwind, and the Fibonacci numbers are computed in reverse:
           - `fibonacci(2)` returns `fibonacci(1) + fibonacci(0)` = 1 + 0 = 1.
           - `fibonacci(3)` returns `fibonacci(2) + fibonacci(1)` = 1 + 1 = 2.
           - `fibonacci(4)` returns `fibonacci(3) + fibonacci(2)` = 2 + 1 = 3.
           - `fibonacci(5)` returns `fibonacci(4) + fibonacci(3)` = 3 + 2 = 5.
           - `fibonacci(6)` returns `fibonacci(5) + fibonacci(4)` = 5 + 3 = 8.
           - `fibonacci(7)` returns `fibonacci(6) + fibonacci(5)` = 8 + 5 = 13.
           - `fibonacci(8)` returns `fibonacci(7) + fibonacci(6)` = 13 + 8 = 21.
           - `fibonacci(9)` returns `fibonacci(8) + fibonacci(7)` = 21 + 13 = 34.
        
        - 6. Finally, the original call `fibonacci(10)` returns `fibonacci(9) + fibonacci(8)` = 34 + 21 = 55.
            - Thus, the function call stack unwinds, and the Fibonacci number for `n = 10` is computed as 55.
    
    Performance Considerations:
        - The recursive implementation of Fibonacci numbers has an exponential time complexity of O(2^n) due to redundant calculations. 
        - This makes it inefficient for large values of `n`. For more efficient solutions, iterative methods or memoization techniques can be used to avoid redundant calculations and achieve linear time complexity. 
        - Nevertheless, the recursive implementation helps illustrate the concept of recursion and how it can be used to solve problems that have recursive structures.
*/

// Recursive function to compute the nth Fibonacci number
int fn_rec_fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case
    return fn_rec_fibonacci(n - 1) + fn_rec_fibonacci(n - 2);
}

void func_rec_fibonacci()
{
    int n = 10;
    int result = fn_rec_fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
}








#endif
