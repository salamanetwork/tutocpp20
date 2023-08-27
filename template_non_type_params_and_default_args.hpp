#ifndef __TEMPLATES_NON_TYPE_PARMS_DEFAULT_ARGS_H
#define __TEMPLATES_NON_TYPE_PARMS_DEFAULT_ARGS_H

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
#include <utility>
#include <type_traits>

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
    - Non type template parameters:
        - Non-type template parameters are a powerful feature in C++ that allow you to use constant values, including integers, enumerations, pointers, and more, as template parameters. 
        - Non-type template parameters provide a way to leverage compile-time knowledge and optimization, making your code more efficient and expressive.
        - This feature lets you parameterize templates with values that are known at compile time. 
        - Syntax:
            template <typename T, int N>
            class Example {
                // ...
            };
            
            - The N parameter is a non-type template parameter with an integer value. 
            - It's used as a constant value in the template.
        - Characteristics
            - Compile-Time Constant: 
                - Non-type template parameters must be known at compile time. 
                - They cannot depend on runtime values.
            - Value Categories: 
                - Non-type template parameters can have value, reference, or pointer types. 
                - They can be integral types (like int, char, enum), pointers, or references.
            - implicitly Deduced: 
                - When you use a template with non-type parameters, the value doesn't need to be explicitly specified. 
                - The compiler deduces the value from the context of the template instantiation.
        - Use Cases:
            - Creating containers or arrays with fixed sizes at compile time.
            - Compile-time control of template behavior based on constant values.
            - Implementing compile-time constants and algorithms.
    
    - Template with default arguments:
        - Default template arguments provide a way to define default values for one or more template parameters, making the template more flexible and convenient to use.
        - They allow you to omit specific template arguments when calling the function, as the default values will be used instead. 
        - Syntax:
            template <typename T, int N = 2>
            ReturnType FunctionName(T arg);  

            - In the template parameter list, you can assign default values to certain template parameters. Here, N is assigned a default value of 2.
            - When calling the function, if you provide the template arguments for T, the default value of N will be used if you omit the N argument.
        - Use Cases:
            - This feature is useful when you have a commonly used value for a template parameter that you want to avoid specifying every time you call the function.
            - Default template arguments simplify function calls and provide a more ergonomic way to use template functions.
            
*/

namespace math_utils
{
    // Example 1: Matrix Multiplication
    template <typename T, size_t RowsA, size_t ColsA, size_t ColsB>
    void matrix_multiply(const T (&A)[RowsA][ColsA], const T (&B)[ColsA][ColsB], T (&result)[RowsA][ColsB]) {
        for (size_t i = 0; i < RowsA; ++i) {
            for (size_t j = 0; j < ColsB; ++j) {
                result[i][j] = 0;
                for (size_t k = 0; k < ColsA; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    // Example 2: Compile-Time Fibonacci Series
    template <size_t N>
    struct Fibonacci {
        static const size_t value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
    };

    template <>
    struct Fibonacci<0> {
        static const size_t value = 0;
    };

    template <>
    struct Fibonacci<1> {
        static const size_t value = 1;
    };

    template <size_t N>
    void print_fibonacci() {
        std::cout << Fibonacci<N>::value << " ";
        print_fibonacci<N - 1>();
    }

    template <>
    void print_fibonacci<0>() {
        std::cout << Fibonacci<0>::value << std::endl;
    }

    // Example 3: Compile-Time Factorial
    template <size_t N>
    struct Factorial {
        static const size_t value = N * Factorial<N - 1>::value;
    };

    template <>
    struct Factorial<0> {
        static const size_t value = 1;
    };

    // Example 4: Type Traits for Const Checking
    template <typename T>
    void check_const() {
        if (std::is_const_v<T>) {
            std::cout << "Type is const." << std::endl;
        } else {
            std::cout << "Type is not const." << std::endl;
        }
    }

    // Example 5: Compile-Time Sum
    template <int N>
    struct Sum {
        static const int value = N + Sum<N - 1>::value;
    };

    template <>
    struct Sum<1> {
        static const int value = 1;
    };

} // namespace math_utils

void cpp_func_templates_call()
{
    using namespace math_utils;

    int matrixA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrixB[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int result[2][2] = {};

    matrix_multiply(matrixA, matrixB, result);

    std::cout << "Matrix multiplication result:" << std::endl;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Fibonacci series up to N = 10:" << std::endl;
    print_fibonacci<10>();

    constexpr size_t n = 5;
    std::cout << "Factorial of " << n << " is: " << Factorial<n>::value << std::endl;

    int x = 10;
    const int y = 20;

    check_const<decltype(x)>();
    check_const<decltype(y)>();

    constexpr int n2 = 10;
    std::cout << "Sum of integers from 1 to " << n2 << " is: " << Sum<n>::value << std::endl;

    
}

#endif


