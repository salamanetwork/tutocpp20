#ifndef __TEMPLATES_FUNCTIONS_WITH_MULTIPLE_PARAMS_H
#define __TEMPLATES_FUNCTIONS_WITH_MULTIPLE_PARAMS_H

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
    - Function Templates with Multiple Parameters:
        - This feature allows you to create functions that can accept multiple template parameters. 
        - These parameters can be of different types and can provide additional flexibility and customization to your code.
        - Definition and Syntax:
            - Function templates with multiple parameters are defined using the template keyword followed by a list of template parameters enclosed in angle brackets (<>).
            - Each template parameter can have a unique name and type.
        - Usage and Syntax:
            - When declaring or defining a function template with multiple parameters, you specify the types of the template parameters within angle brackets.
            - These parameters are then used as placeholders in the function's parameter list or return type.
        - Instantiation and Argument Types:
            - When using a function template, you provide specific types for the template parameters, and the compiler generates a concrete function based on those types.
            - The compiler deduces template parameter types based on the provided function arguments.

        - By employing function templates with multiple parameters, you can create versatile functions that handle various types of inputs and perform calculations accordingly. 
        - This enables code reuse and flexibility across different scenarios.

*/

namespace cpp_fun_templates 
{

    // Function template with auto return type deduction
    template <typename Container>
    auto cpp_func_sum(const Container &container)
    {
        auto sum = typename Container::value_type(); // Initialize sum to default value
        for (const auto &value : container)
        {
            sum += value;
        }
        return sum;
    }

    // Function template with auto return type deduction for finding min and max
    template <typename Container>
    auto cpp_func_find_min_max(const Container& container) {
        if (container.empty()) {
            throw std::invalid_argument("Container is empty");
        }

        auto minMaxPair = std::make_pair(*std::min_element(container.begin(), container.end()),
                                         *std::max_element(container.begin(), container.end()));
        return minMaxPair;
    }

} // namespace cpp_fun_templates

void cpp_func_templates_call() 
{
    using namespace cpp_fun_templates;

    std::vector<int> intValues = {1, 2, 3, 4, 5};
    std::vector<double> doubleValues = {2.5, 1.5, 3.5, 2.0};

    // Calculate sum using the function template with auto return type deduction
    auto intSum = cpp_func_sum(intValues);
    auto doubleSum = cpp_func_sum(doubleValues);

    std::cout << "Sum of int values: " << intSum << std::endl;
    std::cout << "Sum of double values: " << doubleSum << std::endl;

    std::vector<int> _intValues = {3, 9, 2, 8, 1};
    std::vector<double> _doubleValues = {2.5, 1.0, 3.7, 2.2};

    try {
        // Find min and max using the function template with auto return type deduction
        auto intMinMax = cpp_func_find_min_max(_intValues);
        auto doubleMinMax = cpp_func_find_min_max(_doubleValues);

        std::cout << "Min and max of int values: " << intMinMax.first << ", " << intMinMax.second << std::endl;
        std::cout << "Min and max of double values: " << doubleMinMax.first << ", " << doubleMinMax.second << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}




#endif


