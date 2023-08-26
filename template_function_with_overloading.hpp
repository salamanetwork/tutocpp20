#ifndef __TEMPLATES_FUNCTIONS_WITH_OVERLOADING_H
#define __TEMPLATES_FUNCTIONS_WITH_OVERLOADING_H

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
    - Function Template Overloading:
        - Definition and Syntax:
            - Function templates are defined using the template keyword followed by template parameters.
            - Overloaded template functions are declared with the same name and different parameter lists.
            - The compiler selects the most appropriate template function based on the provided arguments.
        - Overloaded Template Functions:
            - Overloaded template functions can have varying parameter types, numbers of parameters, or both.
            - Each overloaded function can have its own implementation based on the specific argument types.
        - Function Resolution:
            - During function call, the compiler selects the best-matching function template based on the provided arguments.
            - It considers the conversion required to match argument types with template parameter types.

        - By using function template overloading, you can provide optimized and consistent implementations for functions that need to handle different numbers of arguments or argument types. 
        - This improves code reuse and maintainability while adhering to your coding style preferences.

*/

namespace cpp_fun_templates 
{

    // Generic function template for maximum of two values
    template <typename T>
    T cpp_func_max(T a, T b) {
        return (a > b) ? a : b;
    }

    // Overloaded function template for maximum of three values
    template <typename T>
    T cpp_func_max(T a, T b, T c) {
        return cpp_func_max(cpp_func_max(a, b), c);
    }

    // Overloaded function template for maximum of four values
    template <typename T>
    T cpp_func_max(T a, T b, T c, T d) {
        return cpp_func_max(cpp_func_max(a, b), cpp_func_max(c, d));
    }

    // Function template to calculate the median of a container
    template <typename Container>
    typename Container::value_type cpp_func_median(const Container& container) {
        // Ensure the container is not empty
        if (container.empty()) {
            throw std::invalid_argument("Cannot calculate median of an empty container");
        }

        // Make a copy of the container to avoid modifying the original
        Container sortedContainer = container;
        std::sort(sortedContainer.begin(), sortedContainer.end());

        // Calculate the median based on container size
        size_t size = sortedContainer.size();
        if (size % 2 == 1) {
            return sortedContainer[size / 2];
        } else {
            size_t midIndex = size / 2;
            return (sortedContainer[midIndex - 1] + sortedContainer[midIndex]) / 2;
        }
    }

    // Specialization for handling vectors of bool
    template <>
    bool cpp_func_median(const std::vector<bool>& container) {
        // Count the number of true values
        size_t trueCount = std::count(container.begin(), container.end(), true);
        size_t size = container.size();

        // Return true if more than half values are true, else false
        return (trueCount > size / 2);
    }

} // namespace cpp_fun_templates

void cpp_func_templates_call() 
{
    using namespace cpp_fun_templates;

    int intMax2 = cpp_func_max(5, 8);                  // Uses two-argument template
    int intMax3 = cpp_func_max(5, 8, 3);               // Uses three-argument template
    int intMax4 = cpp_func_max(5, 8, 3, 11);           // Uses four-argument template

    double doubleMax2 = cpp_func_max(3.14, 2.71);     // Uses two-argument template
    double doubleMax3 = cpp_func_max(3.14, 2.71, 1.0); // Uses three-argument template

    std::cout << "Maximum of 5 and 8: " << intMax2 << std::endl;
    std::cout << "Maximum of 5, 8, and 3: " << intMax3 << std::endl;
    std::cout << "Maximum of 5, 8, 3, and 11: " << intMax4 << std::endl;

    std::cout << "Maximum of 3.14 and 2.71: " << doubleMax2 << std::endl;
    std::cout << "Maximum of 3.14, 2.71, and 1.0: " << doubleMax3 << std::endl;

    std::vector<int> intValues = {5, 2, 8, 3, 1};
    std::vector<double> doubleValues = {2.5, 1.5, 3.5, 2.0};
    std::vector<bool> boolValues = {true, false, true, false, true};

    try {
        // Calculate median of int values
        int intMedian = cpp_func_median(intValues);
        std::cout << "Median of int values: " << intMedian << std::endl;

        // Calculate median of double values
        double doubleMedian = cpp_func_median(doubleValues);
        std::cout << "Median of double values: " << doubleMedian << std::endl;

        // Calculate median of bool values
        double boolMedian = cpp_func_median(boolValues);
        std::cout << "Median of bool values: " << boolMedian << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}





#endif


