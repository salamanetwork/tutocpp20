#ifndef __FUNCTIONS_ADVANCE_001_H
#define __FUNCTIONS_ADVANCE_001_H

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
    - Inputs & Outputs Parameters In C++:
        - In C++, functions can have input parameters, output parameters, or both. 
        - These parameters allow you to pass values to a function and receive values from a function. 
        - Let's look at input and output parameters in detail:
            - Input Parameters:
                - Input parameters, also known as arguments, are used to pass values from the calling function to the called function. 
                - They provide the necessary data for the function to perform its task. 
                - In C++, input parameters are typically passed by value or by reference.
                    - Pass by Value:
                        - When a function parameter is passed by value, a copy of the argument's value is made and stored in a separate memory location. 
                        - Any changes made to the parameter within the function do not affect the original argument.
                    - Pass by Reference:
                        - When a function parameter is passed by reference, the function receives a reference to the original argument. 
                        - This allows the function to modify the argument, and any changes made to the parameter within the function affect the original argument.
            - Output Parameters:
                - Output parameters are used when a function needs to return multiple values or modify existing variables defined outside the function.
                -  In C++, output parameters are typically passed by reference.
        - Notes:
            - It's worth noting that C++ supports additional techniques for returning values, such as returning a structure or using pointers. 
            - However, input and output parameters, particularly pass by value and pass by reference, are commonly used and straightforward to understand.
        - Syntax:
            void functionName(parameterType parameter1, parameterType parameter2, ..., parameterType& outputParameter1, parameterType& outputParameter2, ...);

            - In the prototype syntax:
                - functionName is the name of the function.
                - parameterType is the data type of the parameters.
                - parameter1, parameter2, etc., are the input parameters.
                - outputParameter1, outputParameter2, etc., are the output parameters passed by reference.
        - Example:
            void computeSumAndProduct(int a, int b, int& sum, int& product);
*/

// Function that calculates the sum and product of two integers
void compute_sum_and_product(int a, int b, int& sum, int& product)
{
    sum = a + b;         // Calculate the sum of 'a' and 'b' and store the result in 'sum'
    product = a * b;     // Calculate the product of 'a' and 'b' and store the result in 'product'
}

void func_compute_sum_and_product()
{
    int x = 5;            // Declare and initialize variable 'x' with the value 5
    int y = 3;            // Declare and initialize variable 'y' with the value 3
    int result_sum;       // Declare a variable 'result_sum' to store the sum
    int result_product;   // Declare a variable 'result_product' to store the product

    compute_sum_and_product(x, y, result_sum, result_product);
    // Call the function 'compute_sum_and_product' passing 'x' and 'y' as input parameters
    // and 'result_sum' and 'result_product' as output parameters

    // Print the calculated sum and product
    std::cout << "Sum: " << result_sum << std::endl;
    std::cout << "Product: " << result_product << std::endl;

}

/*
    - Returning from functions (by value):
        - In general, the memory addresses of variables within different functions are separate and distinct. 
        - Each function has its own stack frame, which contains its local variables and function parameters. 
        - When a function is called, a new stack frame is created, and the variables within that function are allocated memory within its stack frame.
        - Therefore, the variable sum in the calculate_sum function and the variable result in the main function are stored in different memory addresses because they belong to different stack frames. 
        - They are separate instances of the variable with their own memory locations.
*/

int calculate_sum(int a, int b)
{
    int sum = a + b;
    std::cout << "Address of 'sum' in calculate_sum: " << &sum << std::endl;
    return sum;
}

void func_calculate_sum()
{
    int x = 5;
    int y = 3;

    int result = calculate_sum(x, y);
    std::cout << "Address of 'result' in main: " << &result << std::endl;

}

/*
    - Returning by reference:
        - Running this code will show that both x and result are located at the same memory address, indicating that they refer to the same variable.
    - Reminder:
        - Do return a reference to a local variable.
*/

// Function that increments a value by 1 and returns it by reference
int& increment_by_reference(int& num)
{
    num++; // Increment the value of 'num' by 1
    return num; // Return 'num' by reference
}

void func_increment_by_reference()
{
    int x = 5; // Declare and initialize variable 'x' with the value 5

    int& result = increment_by_reference(x);
    // Call the function 'increment_by_reference' passing 'x' by reference
    // and store the returned reference in 'result'

    // Print the value of 'x' and the value stored at the reference 'result'
    std::cout << "x: " << x << std::endl;
    std::cout << "result: " << result << std::endl;

    // Print the memory addresses of 'x' and the reference 'result'
    std::cout << "Address of 'x': " << &x << std::endl;
    std::cout << "Address of 'result': " << &result << std::endl;
}

/*
    - Returning by pointer:
        - Returning by pointer involves returning the memory address of a variable from a function. 
        - This allows the calling function to access the variable indirectly by dereferencing the returned pointer. 
        - Note that it is essential to deallocate the dynamically allocated memory using delete to prevent memory leaks.
        
*/

// Function that creates and returns a dynamically allocated integer
int* create_dynamic_integer()
{
    int* dynamic_integer = new int(42);  // Dynamically allocate an integer with value 42
    return dynamic_integer;              // Return the memory address of the dynamically allocated integer
}

void func_create_dynamic_integer()
{
    int* result = create_dynamic_integer();
    // Call the function 'create_dynamic_integer' and store the returned pointer in 'result'

    // Print the value stored at the memory address pointed by 'result'
    std::cout << "Value: " << *result << std::endl;

    // Print the memory address of the original variable and the returned pointer
    std::cout << "Address of original variable: " << &result << std::endl;
    std::cout << "Address returned by the function: " << result << std::endl;

    delete result;  // Deallocate the dynamically allocated integer
}
























#endif




