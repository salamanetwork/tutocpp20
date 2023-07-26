#ifndef __FUNCTIONS_ADVANCE_002_H
#define __FUNCTIONS_ADVANCE_002_H

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
    - Function Overload:
        - Function overloading is a powerful feature in C++ that allows you to define multiple functions with the same name in the same scope, but with different parameter lists. 
        - This means you can have functions that perform similar tasks but operate on different types or different numbers of parameters. 
        - The compiler resolves which overloaded function to call based on the arguments provided during the function call.
        - Function overloading allows you to write more expressive and readable code, providing different function implementations based on the input types, without having to invent distinct function names for each variation.
        - Here are some key points to consider when using function overloading in C++:
            - Function Signatures: 
                - Function overloading is based on function signatures, which consist of the function name and the types of its parameters. 
                - The return type is not considered in function overloading.

            - Parameter Types and Order: 
                - The parameters of the overloaded functions must differ in either their types or the number of parameters. 
                - The order of parameters can also be used to differentiate overloaded functions.

            - Return Type: 
                - As mentioned earlier, the return type alone does not distinguish overloaded functions. 
                - Two functions with the same name and the same parameter list but different return types are not considered overloaded; it will result in a compilation error.

            - Scope: 
                - Overloading can happen within the same scope, including global scope, class scope, or namespace scope.

            - Default Arguments: 
                - Functions with default arguments can be overloaded, but be careful with the order of overloaded functions with default arguments, as it can lead to ambiguous function calls.

            - Best Match Resolution: 
                - During a function call, the compiler tries to find the best match for the provided arguments. 
                - If an exact match is found, that function is called. 
                - If no exact match is found, the compiler tries to find the closest match that can be converted implicitly.

            - Function Overloading vs Function Templates: 
                - Function templates provide another way to achieve similar behavior as function overloading. 
                - Templates allow you to write generic functions that can operate on multiple types. 
                - Function overloading, on the other hand, is more suitable when you have different implementations based on specific types.
*/

// Function to add integers
int fn_add(int a, int b)
{
    return a + b;
}

// Function to add doubles
double fn_add(double a, double b)
{
    return a + b;
}

void func_add_overloaded()
{
    int result_1 = fn_add(3, 4);        // Calls the int add(int, int)
    double result_2 = fn_add(2.5, 3.7); // Calls the double add(double, double)

    std::cout << "Result 1: " << result_1 << std::endl;
    std::cout << "Result 2: " << result_2 << std::endl;
}

/*
    - Overloading with different parameters:
*/

// Function to perform addition
int fn_calculate(int a, int b)
{
    return a + b;
}

// Function to perform subtraction
int fn_calculate(int a, int b, int c)
{
    return a - b - c;
}

// Function to perform multiplication
int fn_calculate(int a, int b, int c, int d)
{
    return a * b * c * d;
}

// Function to perform division
double fn_calculate(double a, double b)
{
    if (b != 0)
        return a / b;
    else
    {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
}

void func_calculate_overloaded()
{
    int sum = fn_calculate(1, 2);                 // Calls calculate(int a, int b)
    int difference = fn_calculate(10, 2, 3);      // Calls calculate(int a, int b, int c)
    int product = fn_calculate(2, 3, 4, 5);       // Calls calculate(int a, int b, int c, int d)
    double division = fn_calculate(10.0, 2.0);    // Calls calculate(double a, double b)

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Division: " << division << std::endl;

}






#endif
