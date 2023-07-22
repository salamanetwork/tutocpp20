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

/*
    - Proper Reference Deduction:
        - In C++, reference deduction can occur in several scenarios, depending on whether the variable is declared with auto, const auto, auto&, const auto&, or auto&&. 
        - Let's go through each case to understand proper reference deduction:
            - 01) auto:
                - When you use auto to declare a variable without any reference or const qualifiers, the compiler performs value deduction. 
                - The type of the variable will be the same as the initializer's type, but any reference and const qualifiers will be ignored.
            - 02) const auto:
                - Using const auto will deduce the type, including const qualifiers, but without any reference.
            - 03) auto&:
                - When you use auto&, reference deduction occurs, and the type of the variable will match the initializer, including reference and const qualifiers.
            - 04) const auto&:
                - Using const auto& deduces the type with both reference and const qualifiers.
            - 05) auto&& (Universal Reference):
                - auto&& is a universal reference, which means it can bind to both lvalues and rvalues. 
                - In this case, reference collapsing occurs, and the type will be either an lvalue reference or an rvalue reference, depending on the initializer.
                
        - Notes:
            - Reference deduction is powerful and allows C++ to handle different scenarios with the correct reference and const qualifiers, making it easier to work with variables while avoiding unnecessary copying and maintaining const correctness.
*/

void func_proper_reference_deduct()
{
    // 01) auto:
    auto var1 = 42; // var1 is deduced as int
    auto var2 = "Hello"; // var2 is deduced as const char*

    // 02) const auto:
    const auto var3 = 3.14; // var3 is deduced as const double

    // 03) auto&:
    int num = 42;
    auto& ref1 = num; // ref1 is deduced as int&
    const auto& ref2 = num; // ref2 is deduced as const int&

    // 04) const auto&:
    double pi = 3.14;
    const auto& ref3 = pi; // ref3 is deduced as const double&

    // 05) auto&&:
    int x = 42;
    const int y = 10;
    
    auto&& ref4 = x; // ref4 is deduced as int&
    auto&& ref5 = y; // ref5 is deduced as const int&
    auto&& ref6 = 100; // ref6 is deduced as int&&

}

/*
    - Const Qualifiers:
        - In C++, const qualifiers are used to specify that an object or variable should not be modified. 
        - When you declare a variable as const, it means the value stored in that variable cannot be changed after initialization. 
        - This is a key feature for ensuring data integrity and const correctness in your code.
        - Here are some examples of how const qualifiers can be used in C++:
            - 01) Constant variables.
            - 02) Constant pointers.
            - 03) Constant references.
            - 04) Constant member functions.
            - 05) Constant function parameters.
            - 06) Constant objects.
        - Using const qualifiers helps ensure that variables, pointers, references, and member functions are not accidentally modified, enhancing the safety and maintainability of your code. 
        - It also allows the compiler to perform certain optimizations and enables better const correctness.
            
*/

void func_const_qualifiers()
{
    // 01) Constant variables.
    const int MAX_VALUE = 100; // Declares a constant variable with value 100
    const double PI = 3.14159; // Declares a constant variable with value 3.14159

    // 02) Constant pointers.
    int num = 42;
    const int* ptr1 = &num; // Pointer to a constant integer, value cannot be modified through ptr1
    int* const ptr2 = &num; // Constant pointer to an integer, pointer address cannot be modified
    const int* const ptr3 = &num; // Constant pointer to a constant integer

    // 03) Constant references.
    int x = 10;
    const int& ref1 = x; // Reference to a constant integer, value cannot be modified through ref1

    // 04) Constant member functions.
    class MyClass {
    public:
        void doSomething() const; // This member function promises not to modify the object's state
    };

    // 05) Constant function parameters.
    void printArray(const int arr[], size_t size); // The function cannot modify the elements of arr
    
    // 06) Constant objects.
    const MyClass obj; // obj is a constant object, calling non-const member functions is not allowed
    // obj.doSomething(); // Only const member functions can be called on a constant object
}

/*
    - Function return type deduction:
        - Function return type deduction is a C++ feature introduced in C++14.
        - It allows the compiler to deduce the return type of a function based on the return statement. 
        - This enables you to use auto as the return type, making your code more concise and flexible, especially when dealing with complex or templated return types.
        - The key benefit of using function return type deduction with auto is that it allows the function to return different types based on the logic within the function.
        - This flexibility can be quite handy when dealing with various scenarios where the return type might vary based on input parameters or conditions.
*/

// Function with return type deduction using auto
auto calculate_average(const std::vector<int>& numbers)
{
    if (numbers.empty()) {
        // Return a message if the vector is empty
        return std::string("Vector is empty");
    }

    // Calculate the sum of numbers
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }

    // Calculate the average and return it as a string
    double average = static_cast<double>(sum) / numbers.size();
    std::ostringstream oss;
    
    oss << std::fixed << std::setprecision(2) << "Average: " << average;
    return oss.str();
}

void func_calculate_average()
{
    std::vector<int> data1 = {10, 20, 30, 40, 50};
    std::vector<int> data2; // An empty vector

    // Calculate the average for data1
    auto avg1 = calculate_average(data1);
    std::cout << avg1 << std::endl;

    // Calculate the average for data2
    auto avg2 = calculate_average(data2);
    std::cout << avg2 << std::endl;

}


/*
    - Return type deduction with references:
        - Function return type deduction with references follows the same principle as regular function return type deduction using auto. 
        - When you use auto as the return type for a function, the compiler deduces the return type based on the return statements in the function body, including references.
        
*/
// Function with return type deduction using auto&
auto& get_larger(int& value1, int& value2)
{
    return (value1 > value2) ? value1 : value2;
}

void func_get_larger()
{
    int a = 10;
    int b = 5;

    // Get the larger integer by reference
    auto& larger_value = get_larger(a, b);

    // Modify the larger integer through the reference
    // This will modify 'a' since 'a' is the larger value
    // returned by the get_larger function.
    larger_value = 15;

    std::cout << "a: " << a << ", b: " << b << std::endl;
}

/*
    - Optional output from functions:
        - Returning optional values from functions is a useful technique in C++ to indicate that a function may not always produce a valid result. 
        - provides a way to represent an optional value that may or may not have a value.
        - Using optional output from functions allows you to handle cases where the function may fail to produce a valid result gracefully. 
        - It provides a cleaner alternative to using error codes or null pointers for handling exceptional cases. 
*/

// Function that calculates the square root of a number and returns it using a pointer
bool calculate_square_root(double number, double* result)
{
    if (number >= 0)
    {
        *result = std::sqrt(number);
        return true;
    }
    else
    {
        return false; // Return false to indicate an error or absence of value
    }
}

void func_calculate_square_root()
{
    double x = 25.0;
    double y = -4.0;

    double result_x;
    if (calculate_square_root(x, &result_x))
    {
        std::cout << "Square root of " << x << " is " << result_x << std::endl;
    }
    else
    {
        std::cout << "Cannot calculate square root of " << x << ", the number is negative." << std::endl;
    }

    double result_y;
    if (calculate_square_root(y, &result_y))
    {
        std::cout << "Square root of " << y << " is " << result_y << std::endl;
    }
    else
    {
        std::cout << "Cannot calculate square root of " << y << ", the number is negative." << std::endl;
    }
}












#endif




