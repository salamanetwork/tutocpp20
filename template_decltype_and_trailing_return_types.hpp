#ifndef __TEMPLATES_DECLTYPE_H
#define __TEMPLATES_DECLTYPE_H

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
    - Decltype and trailing return types:
        - Both decltype and trailing return types are advanced C++ features that are used to specify the return type of a function in more complex scenarios. 
        - They offer more flexibility and precision when determining the return type, especially in cases involving template functions, lambdas, and expressions. 
        - Let's dive into both decltype and trailing return types in detail:
            - decltype:
                - Purpose and Usage:
                    - The decltype specifier allows you to deduce the type of an expression at compile time.
                    - It is commonly used when you want to extract the type of an expression, variable, or function and use it in type declarations, such as return types.
                - Use Cases:
                    - Determining the type of an expression or variable without actually creating an instance of it.
                    - Handling complex return types involving template functions or expressions.
                - Syntax:
                    int x = 5;
                    decltype(x) y = x; // y is of type int
                    
            - Trailing Return Types:
                - Purpose and Usage:
                    - Trailing return types allow you to declare the return type of a function after its parameter list, using the auto keyword and a trailing -> syntax.
                    - They are particularly useful when the return type is dependent on template parameters or involves complex expressions.
                - Use Cases:
                    - Specifying the return type of a function that depends on template parameters.
                    - Clarifying complex return types, such as those involving conditional expressions or complex calculations.
                - Syntax:
                    auto lambda_multiply = [](double x, double y) -> double {
                        return x * y;
                    };

        - Combining decltype and Trailing Return Types:
            - You can combine decltype and trailing return types to create even more precise function return type specifications
            - Syntax:
                template <typename Container>
                auto get_first_element(const Container& container) -> decltype(container.front()) {
                    return container.front();
                }
        
        - Benefits:
            - Both decltype and trailing return types improve code readability and maintainability by providing accurate return type declarations.
            - They are particularly useful in situations where the return type is complex or dependent on template parameters, making your code more concise and expressive.
        - Considerations:
            - Use these features when they offer clear benefits, such as handling complex return types, template functions, or expressions.
            - Strike a balance between using explicit return types for clarity and letting the compiler deduce return types for simpler cases.

        - Summary:
            - decltype and trailing return types are advanced C++ features that provide flexibility and precision in specifying function return types. 
            - They are particularly valuable when dealing with complex expressions, template functions, and scenarios where the return type cannot be easily determined using traditional methods.
        
*/             

namespace cpp_fun_templates 
{
    // Function to calculate sum and product of elements in a container
    template <typename Container>
    std::pair<typename Container::value_type, typename Container::value_type> cpp_func_sum_and_product(const Container& container) {
        if (container.empty()) {
            throw std::invalid_argument("Container is empty");
        }

        using ValueType = typename Container::value_type;
        ValueType sum = ValueType();
        ValueType product = ValueType(1);

        for (const auto& value : container) {
            sum += value;
            product *= value;
        }

        return std::make_pair(sum, product);
    }

    // Function template to calculate the average of elements in a container
    template <typename Container>
    auto cpp_func_average(const Container& container) -> std::decay_t<decltype(container.front())> {
        static_assert(std::is_arithmetic_v<typename Container::value_type>, "Container must contain arithmetic types");

        if (container.empty()) {
            throw std::invalid_argument("Container is empty");
        }

        using ValueType = std::decay_t<decltype(container.front())>;
        ValueType sum = std::accumulate(container.begin(), container.end(), ValueType(0));
        return sum / container.size();
    }

    // Function template to calculate the dot product of two vectors
    template <typename T>
    auto cpp_func_dot_product(const std::vector<T>& vec1, const std::vector<T>& vec2) -> std::decay_t<decltype(vec1[0] * vec2[0])> {
        static_assert(std::is_arithmetic_v<T>, "Vectors must contain arithmetic types");
        
        if (vec1.size() != vec2.size()) {
            throw std::invalid_argument("Vectors must have the same size");
        }

        using ResultType = std::decay_t<decltype(vec1[0] * vec2[0])>;
        ResultType dotProduct = ResultType(0);
        
        for (size_t i = 0; i < vec1.size(); ++i) {
            dotProduct += vec1[i] * vec2[i];
        }
        
        return dotProduct;
    }

    // Function template to find the index of the first occurrence of a value in a container
    template <typename Container, typename Value>
    auto cpp_func_find_index(const Container& container, const Value& value) -> decltype(std::distance(container.begin(), std::find(container.begin(), container.end(), value))) {
        auto it = std::find(container.begin(), container.end(), value);
        if (it != container.end()) {
            return std::distance(container.begin(), it);
        }
        return -1; // Return -1 if value is not found
    }
    

} // namespace cpp_fun_templates

void cpp_func_templates_call() 
{
    using namespace cpp_fun_templates;

    std::vector<int> intValues = {1, 2, 3, 4, 5};
    std::vector<double> doubleValues = {2.0, 1.5, 3.0, 2.5};

    try {
        // Calculate average using the function template
        auto intAverage = cpp_func_average(intValues);
        auto doubleAverage = cpp_func_average(doubleValues);

        std::cout << "Average of int values: " << intAverage << std::endl;
        std::cout << "Average of double values: " << doubleAverage << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::vector<int> _intValues = {1, 2, 3, 4, 5};
    std::vector<double> _doubleValues = {2.0, 1.5, 3.0, 2.5};

    try {
        // Calculate sum and product using the function template
        auto intResult = cpp_func_sum_and_product(_intValues);
        auto doubleResult = cpp_func_sum_and_product(_doubleValues);

        std::cout << "Sum and product of int values: " << intResult.first << ", " << intResult.second << std::endl;
        std::cout << "Sum and product of double values: " << doubleResult.first << ", " << doubleResult.second << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::vector<int> intVec1 = {1, 2, 3};
    std::vector<int> intVec2 = {4, 5, 6};
    
    std::vector<double> doubleVec1 = {0.5, 1.5, 2.5};
    std::vector<double> doubleVec2 = {2.0, 1.0, 0.5};

    try {
        // Calculate dot product using the function template
        auto intDotProduct = cpp_func_dot_product(intVec1, intVec2);
        auto doubleDotProduct = cpp_func_dot_product(doubleVec1, doubleVec2);

        std::cout << "Dot product of int vectors: " << intDotProduct << std::endl;
        std::cout << "Dot product of double vectors: " << doubleDotProduct << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::vector<int> __intValues = {3, 7, 2, 8, 5};
    std::vector<double> __doubleValues = {2.5, 1.5, 3.5, 2.0};

    int targetInt = 8;
    double targetDouble = 3.5;

    try {
        // Find index using the function template
        auto intIndex = cpp_func_find_index(__intValues, targetInt);
        auto doubleIndex = cpp_func_find_index(__doubleValues, targetDouble);

        if (intIndex != -1) {
            std::cout << "Index of " << targetInt << " in intValues: " << intIndex << std::endl;
        } else {
            std::cout << targetInt << " not found in intValues." << std::endl;
        }

        if (doubleIndex != -1) {
            std::cout << "Index of " << targetDouble << " in doubleValues: " << doubleIndex << std::endl;
        } else {
            std::cout << targetDouble << " not found in doubleValues." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}

#endif


