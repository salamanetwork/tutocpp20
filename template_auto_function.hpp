#ifndef __TEMPLATES_AUTO_FUNCTION_H
#define __TEMPLATES_AUTO_FUNCTION_H

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
    - Template Auto Function:
        - Also known as "function template type deduction", allow you to declare and define template functions without explicitly specifying the template parameters. 
        - Instead, the compiler infers the template parameters based on the arguments passed to the function. 
        - This feature was introduced in C++14 and simplifies the syntax for using function templates.
        - Syntax:
            template <typename T, typename U>
            auto function_name(T arg1, U arg2) -> return_type {
                // Function body
                // ...
            }

            - auto: Instead of explicitly defining the return type, you use auto as the return type specifier.
            - The -> return_type trailing return type syntax specifies the return type of the function.
            - Template parameters, if needed, are still declared within the angle brackets <...>.
        
        - Key Points:
            - Type Deduction: 
                - The compiler deduces the template parameter types and the return type based on the function arguments and the expression within the function.
            - Return Type Inference: 
                - The -> return_type part specifies the return type, which can be automatically inferred based on the expression in the function body.
            - Implicit Conversion:
                - The return type is determined by the return expression's type.
                - If the return expression has multiple types, implicit conversion rules apply to determine the common type.
            - No Need for Explicit Template Arguments: 
                - When calling an auto function template, you don't need to provide explicit template arguments; the compiler deduces them from the provided arguments.

        - Example:
            #include <iostream>

            template <typename T, typename U>
            auto add(T a, U b) -> decltype(a + b) {
                return a + b;
            }
            
            int main() {
                int x = 5;
                double y = 3.5;
            
                auto sum = add(x, y);  // Deduces add<int, double>(x, y)
                std::cout << "Sum: " << sum << std::endl;
            
                return 0;
            }

            - In this example:
                - The add function template uses auto for both the return type and the template parameters. 
                - When the add function is called with an int and a double, the compiler deduces the types as int and double, respectively, and determines the return type to be the result of a + b.
        
        - Benefits:
            - Simplified Syntax: No need to explicitly specify template arguments or return types.
            - Improved Readability: Cleaner code due to reduced template-related syntax clutter.
            - Flexibility: Allows using complex expressions for type deduction and return type determination.
            - Type Safety: The compiler ensures type compatibility of the return expression.

        - Considerations:
            - Type Deduction Limitations: 
                - Complex expressions may result in unexpected or less accurate type deductions.
            - Compiler Errors: 
                - Errors might be less informative if type deduction or return type determination fails.
                - Auto function templates offer a more concise and readable way to define and use function templates, making code easier to write and maintain while retaining the benefits of template-based generic programming.
        

*/ 


namespace cpp_auto_func_template 
{

    // Example 1: Adding Elements of Different Types
    template <typename T, typename U>
    auto add(T a, U b) -> decltype(a + b) {
        return a + b;
    }

    // Example 2: Calculating Average
    template <typename T>
    T calculate_average(const T* values, size_t size) {
        T sum = T();
        for (size_t i = 0; i < size; ++i) {
            sum += values[i];
        }
        return sum / size;
    }

    // Example 3: Concatenating Strings
    template <typename Container>
    auto concatenate_strings(const Container& strings) -> decltype(strings[0]) {
        typename Container::value_type result;
        for (const auto& str : strings) {
            result += str;
        }
        return result;
    }

    // Example 4: Finding Maximum Element
    template <typename ForwardIt>
    auto find_max_element(ForwardIt first, ForwardIt last) -> decltype(*first) {
        auto max = *first;
        for (auto it = first; it != last; ++it) {
            if (*it > max) {
                max = *it;
            }
        }
        return max;
    }

    // Example 5: Generic Swap Function
    template <typename T>
    void swap_values(T& a, T& b) {
        auto temp = a;
        a = b;
        b = temp;
    }

} // namespace cpp_auto_func_template

void cpp_func_templates_call() {
    using namespace cpp_auto_func_template;

    // Combine examples
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {2.0, 3.0, 4.0, 5.0, 6.0};

    auto sum = add(10, 20.5);
    std::cout << "Sum: " << sum << std::endl;

    double average = calculate_average(intArray, 5);
    std::cout << "Average: " << average << std::endl;

    int a = 5, b = 10;
    swap_values(a, b);
    std::cout << "Swapped values: a=" << a << ", b=" << b << std::endl;

}



#endif


