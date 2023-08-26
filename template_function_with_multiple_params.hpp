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

    // Function template with multiple parameters
    template <typename T, typename U>
    void cpp_func_swap(T& a, U& b) {
        T temp = a;
        a = static_cast<T>(b);
        b = static_cast<U>(temp);
    }

    // Function template to calculate total cost
    template <typename PriceType, typename QuantityType>
    PriceType cpp_func_total_cost(const PriceType& price, const QuantityType& quantity) {
        return price * quantity;
    }

    // Function template for element-wise addition of two containers
    template <typename Container1, typename Container2>
    std::vector<typename Container1::value_type> cpp_func_elementwise_add(const Container1& a, const Container2& b) {
        // Ensure both containers have the same size
        if (a.size() != b.size()) {
            throw std::invalid_argument("Containers must have the same size for element-wise addition");
        }

        // Create a new container to store the result
        std::vector<typename Container1::value_type> result;

        // Perform element-wise addition and store in the result container
        for (size_t i = 0; i < a.size(); ++i) {
            result.push_back(a[i] + b[i]);
        }

        return result;
    }

} // namespace cpp_fun_templates

void cpp_func_templates_call() 
{
    using namespace cpp_fun_templates;

    int intVal = 5;
    double doubleVal = 3.14;

    std::cout << "Before swap: intVal = " << intVal << ", doubleVal = " << doubleVal << std::endl;

    // Swap int and double values using the function template
    cpp_func_swap(intVal, doubleVal);

    std::cout << "After swap: intVal = " << intVal << ", doubleVal = " << doubleVal << std::endl;

    double unitPrice = 2.5;
    int unitsSold = 10;
    float itemPrice = 1.75;
    unsigned int itemsSold = 15;

    // Calculate total cost using the function template
    double totalCost1 = cpp_func_total_cost(unitPrice, unitsSold);
    float totalCost2 = cpp_func_total_cost(itemPrice, itemsSold);

    std::cout << "Total cost for units: $" << totalCost1 << std::endl;
    std::cout << "Total cost for items: $" << totalCost2 << std::endl;

    std::vector<int> intValuesA = {1, 2, 3, 4, 5};
    std::vector<double> doubleValuesB = {0.5, 1.5, 2.5, 3.5, 4.5};

    try {
        // Perform element-wise addition of int and double containers
        std::vector<int> intResult = cpp_func_elementwise_add(intValuesA, doubleValuesB);

        std::cout << "Element-wise addition result: ";
        for (const auto& value : intResult) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


}




#endif


