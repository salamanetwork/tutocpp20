#ifndef __FUNCTIONS_ADVANCE_003_H
#define __FUNCTIONS_ADVANCE_003_H

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
    - Declaring and using lambda functions:
        - A lambda function in C++ is a form of an anonymous function or closure that allows you to create small, inline functions on-the-fly without giving them a separate name. 
        -  Lambdas are a powerful feature introduced in C++11, and they provide a concise and expressive way to define functions, especially when they are used only within a limited scope.
        - Syntax:
            [ captures ] ( parameters ) -> return_type {
                // function body
            }
            - Let's break down each component of a lambda function:
                - Captures: 
                    - This is an optional part that allows a lambda to capture variables from the surrounding scope. 
                    - Captures are placed inside square brackets []. 
                    - You can capture variables by reference (&) or by value (=) or capture specific variables individually. 
                    - Capturing allows you to use variables from the enclosing context within the lambda function.
                    - In C++, you can capture variables in a lambda function using three different capture modes:
                        - 01) Capture by value (=): 
                            - When you capture a variable by value, a copy of the variable is made and stored inside the lambda function. 
                            - Any modifications to the captured variable inside the lambda will not affect the original variable in the outer scope.
                        - 02) Capture by reference (&): 
                            - When you capture a variable by reference, the lambda function will have access to the original variable in the outer scope. 
                            - Any modifications made to the captured variable inside the lambda will directly affect the original variable.
                        - 03) Capture by reference with read-only (&) or capture by value with read-only (=): 
                            -You can capture variables by reference or by value with read-only access. 
                            -This allows you to access the variable but prohibits any modifications to it inside the lambda function.
                - Parameters:
                    - These are the input parameters that the lambda function takes. 
                    - It follows the same syntax as a regular function, but the parameter types can be omitted and deduced by the compiler using auto.
                - Return Type: 
                    - This is an optional part that indicates the return type of the lambda function.
                    - If omitted, the return type is deduced by the compiler. 
                    - For simple lambdas with a single return statement, return type deduction usually works fine.
                - Function Body:
                    - This is the actual code of the lambda function, enclosed within curly braces {}.
                    - It behaves similarly to a regular function's body, allowing you to execute any code you need.
                - Call Lambda Function:
                    - Using the name of the variable or handler
                    - IIF(Immediate-Invoked Function):
                        - It is also known as a self-executing anonymous function or a self-invoking function.
                        - In C++, lambda functions can serve a similar purpose as IIF in JavaScript. 
                        - They allow you to create and invoke a function without explicitly naming it.
                        - We define a lambda function within the parentheses and immediately invoke it by adding () at the end. 
                        - Syntax:
                            [capture-list](parameters-list){function-body}();
        - Lambdas are often used as arguments to higher-order functions like std::for_each, std::sort, and other algorithms in the Standard Template Library (STL). 
        - They provide a concise way to define custom operations inline without the need for defining a separate function.
        - Lambdas are a powerful feature that makes C++ code more expressive and concise, especially in modern C++ development. 
        - They are widely used in scenarios where small, short-lived functions are needed, such as in functional programming paradigms, event handling, and more.
*/

void func_various_lambda_funs()
{
    using namespace std;

    // Example 1: Basic lambda function
    // Declare a lambda function that takes two integer arguments and returns their sum.
    auto sum = [](int a, int b)
    {
        return a + b;
    };

    int result = sum(3, 5);
    cout << "Example 1 - Sum: " << result << endl;

    // Example 2: Capturing variables
    int x = 10;
    int y = 20;

    // Declare a lambda function that captures x and y by value, and returns their product.
    auto product = [x, y](auto a, auto b)
    {
        return x * y;
    };

    x = 5; // Modifying the original variable x does not affect the captured value.

    result = product(nullptr, nullptr); // Calls the lambda function to get the captured value's product.
    cout << "Example 2 - Product: " << result << endl;

    // Example 3: Capturing by value
    int z = 3;

    // Declare a lambda function that captures z by value, and returns the square of z.
    auto square = [z]()
    {
        return z * z;
    };

    z = 4; // Modifying the original variable z does not affect the captured value.

    result = square(); // Calls the lambda function to get the captured value's square.
    cout << "Example 3 - Square: " << result << endl;

    // Example 4: Using lambda function as a parameter
    auto performOperation = [](auto operation, int a, int b)
    {
        return operation(a, b);
    };

    int sumResult = performOperation(sum, 3, 5); // Uses the sum lambda as an argument
    cout << "Example 4 - Sum Result: " << sumResult << endl;

    int productResult = performOperation(product, 3, 5); // Uses the product lambda as an argument
    cout << "Example 4 - Product Result: " << productResult << endl;

    // IIF using lambda function
    []() {
        std::cout << "IIF in C++ using lambda" << std::endl;
    }();

    // IIF using lambda function that takes parameters
    [](auto a, auto b) {
        std::cout << "IIF in C++ using lambda that takes parameters (" << a << ", " << b << ")" << std::endl;
    }(10, 20);

    // IIF that give us the result directly
    std::cout 
        << "The Result of (a: 70 + b: 30) is: " 
        << [](auto a, auto b) { return (a + b); } (70, 30)
        << std::endl;

    // IIF that give us the result directly with returned type
    std::cout 
        << "The Result of (a: 60 + b: 30) is: " 
        << std::showpoint 
        << [](auto a, auto b) -> double { return (a + b); } (60, 30)
        << std::endl;
}


void func_lambdas_captures_types() 
{
    // Example 1: Capture by value
    int x = 5;
    auto lambdaByValue = [x]() {
        // The lambda has a copy of the variable x
        std::cout << "Capture by value: " << x << std::endl;
    };

    // Example 2: Capture by reference
    int y = 10;
    auto lambdaByReference = [&y]() {
        // The lambda has direct access to the variable y
        std::cout << "Capture by reference: " << y << std::endl;
    };

    // Example 3: Capture by reference with read-only
    int z = 15;
    auto lambdaByReferenceReadOnly = [&z]() {
        // Read-only access to the variable z
        std::cout << "Capture by reference (read-only): " << z << std::endl;
    };

    // Example 4: Capture by value with read-only
    int w = 20;
    auto lambdaByValueReadOnly = [w]() {
        // Read-only access to the variable w
        std::cout << "Capture by value (read-only): " << w << std::endl;
    };

    // Modifying the original variables after the lambdas are defined
    x = 7;
    y = 12;
    z = 18;
    w = 25;

    // Call the lambda functions
    lambdaByValue();
    lambdaByReference();
    lambdaByReferenceReadOnly();
    lambdaByValueReadOnly();
}

/*
    - Capture all in context:
*/


void func_capture_all_in_context_01()
{
    int x = 10;
    int y = 20;
    int z = 30;

    // Capture all variables by reference and capture x by value
    std::vector<int> numbers = {3, 7, 2, 9, 5, 1, 8, 4, 6};
    std::for_each(numbers.begin(), numbers.end(), [&, x](int num)
    {
        std::cout << "x = " << x << ", y = " << y << ", z = " << z << ", num = " << num << std::endl;
    });

    // Capture all variables by value and capture z by reference
    std::sort(numbers.begin(), numbers.end(), [=, &z](int a, int b)
    {
        return a < b + z;
    });

    // Print the sorted numbers
    std::cout << "Sorted Numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}


void func_capture_all_in_context_02()
{
    // Sample list of integers
    std::vector<int> numbers = {3, 7, 2, 9, 5, 1, 8, 4, 6};

    // Example 1: Find the sum of all numbers using a lambda function
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int num)
    {
        sum += num;
    });
    std::cout << "Sum: " << sum << std::endl;

    // Example 2: Find the maximum element using a lambda function
    int maxElement = *std::max_element(numbers.begin(), numbers.end(), [](int a, int b)
    {
        return a < b;
    });
    std::cout << "Max Element: " << maxElement << std::endl;

    // Example 3: Count even numbers using a lambda function
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int num)
    {
        return num % 2 == 0;
    });
    std::cout << "Even Count: " << evenCount << std::endl;

}











#endif
