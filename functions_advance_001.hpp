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

/*
    - Returning array element pointer:
        - The function takes the array, its size, and the desired index as parameters and returns a pointer to the element if the index is within bounds; otherwise, it returns nullptr. 
*/
// Function that returns a pointer to an element in the integer array
const int* get_array_element(const int arr[], size_t size, size_t index)
{
    // Check if the index is within the array bounds
    if (index < size)
    {
        return &arr[index]; // Return a pointer to the element at the specified index
    }
    else
    {
        return nullptr; // Return nullptr if the index is out of bounds
    }
}

void func_get_array_element()
{
    int intArray[] = {13250, 232550, 312440, 1234523, 3452346};

    // Get a pointer to the element at index 2 in the integer array
    const int* ptr_to_element = get_array_element(intArray, std::size(intArray), 2);

    if (ptr_to_element != nullptr)
    {
        // Print the value of the element using the pointer
        std::cout << "Element at index 2: " << *ptr_to_element << std::endl;
    }
    else
    {
        std::cout << "Index out of bounds!" << std::endl;
    }

}

/*
    - Bare auto type deduction:
        - 'auto' type deduction allows the compiler to automatically determine the type of a variable based on its initializer expression.
*/
void func_bare_auto_type_deduction()
{
    // Example 1: Integer type
    auto num1 = 42; // Compiler deduces 'num1' as an integer

    // Example 2: Double type
    auto num2 = 3.14; // Compiler deduces 'num2' as a double

    // Example 3: Character type
    auto letter = 'A'; // Compiler deduces 'letter' as a char

    // Example 4: String type
    auto name = "John"; // Compiler deduces 'name' as a const char*

    // Example 5: Boolean type
    auto flag = true; // Compiler deduces 'flag' as a bool

    // Print the deduced types and their values
    std::cout << "num1:\t\t"     << num1     << "\t\t\ttype:\t\t" << typeid(num1).name()     << std::endl;
    std::cout << "num2:\t\t"     << num2     << "\t\ttype:\t\t" << typeid(num2).name()     << std::endl;
    std::cout << "letter:\t\t"   << letter   << "\t\t\ttype:\t\t" << typeid(letter).name()   << std::endl;
    std::cout << "name:\t\t"     << name     << "\t\ttype:\t\t" << typeid(name).name()     << std::endl;
    std::cout << "flag:\t\t"     << flag     << "\t\t\ttype:\t\t" << typeid(flag).name()     << std::endl;
}

/*
    - typeid Operator:
        - The typeid operator in C++ is used to obtain the std::type_info object that represents the type of a given expression or a type.
        - It is part of the <typeinfo> header in the C++ Standard Library. 
        - The std::type_info object provides information about the type at runtime, such as its name, comparison with other types, and checking for type compatibility.
        - Here's a brief explanation of how the typeid function works:
            - For an expression: 
                - If you pass an expression to the typeid function, it returns a const std::type_info& object representing the type of the expression.
            - For a type: 
                - If you pass a type name to the typeid operator using the typeid(type) syntax, it returns a const std::type_info& object representing that type.
            - Type comparison: 
                - You can use typeid to compare the types of two expressions or types using the == operator. 
                - It returns true if the types are the same and false otherwise.
*/

void func_typeid_typeinfo()
{
    int num = 42;
    double pi = 3.14;
    const char* name = "John";
    bool flag = true;

    // Using typeid with expressions
    std::cout << "Type of num: " << typeid(num).name() << std::endl;
    std::cout << "Type of pi: " << typeid(pi).name() << std::endl;
    std::cout << "Type of name: " << typeid(name).name() << std::endl;
    std::cout << "Type of flag: " << typeid(flag).name() << std::endl;

    // Using typeid with type names
    std::cout << "Type of int: " << typeid(int).name() << std::endl;
    std::cout << "Type of double: " << typeid(double).name() << std::endl;
    std::cout << "Type of const char*: " << typeid(const char*).name() << std::endl;
    std::cout << "Type of bool: " << typeid(bool).name() << std::endl;

    // Type comparison
    if (typeid(num) == typeid(int))
    {
        std::cout << "num is an integer." << std::endl;
    }

    if (typeid(pi) == typeid(double))
    {
        std::cout << "pi is a double." << std::endl;
    }

    if (typeid(name) == typeid(const char*))
    {
        std::cout << "name is a const char*." << std::endl;
    }

    if (typeid(flag) == typeid(bool))
    {
        std::cout << "flag is a bool." << std::endl;
    }

}

/*
    - Bare auto reference deduction:
        - auto reference deduction always includes the reference qualifier when deducing the type of the variable.
        - The reference qualifier is part of the type deduction process when using auto with references.
        
*/

void func_bare_auto_ref_deduct()
{
    int num = 42;
    int& ref_num = num; // Standard reference

    auto auto_ref1 = num; // Auto reference, deduces to int&
    auto& auto_ref2 = ref_num; // Auto reference, deduces to int&

    std::cout << "num: " << num << ", ref_num: " << ref_num << std::endl;
    std::cout << "auto_ref1: " << auto_ref1 << ", auto_ref2: " << auto_ref2 << std::endl;

    // Modify the value through the auto references
    auto_ref1 = 100;
    auto_ref2 = 200;
    std::cout << "After modification: num: " << num << ", ref_num: " << ref_num << std::endl;

}




















#endif




