#ifndef __TEMPLATES_SPECIALIZATION_H
#define __TEMPLATES_SPECIALIZATION_H

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
    - Template Spcialization:
        - Create specialized versions of the function template for specific data types. 
        - Use the same naming convention and coding style for specialized functions.
        - Advantages of Specialization:
            - Provides optimized implementations for specific data types.
            - Allows handling unique cases that the generic template might not cover.
        - Maintainability:
            - Comment your specialized functions to explain their purpose and any deviations from the generic template's behavior.
            - Clearly document the optimization or customization provided by each specialization.
        - Usage:
            - When using the unction with int or double arguments, the specialized versions will be invoked.
        - Considerations:
            - Use specialization judiciously; only specialize when necessary to avoid code redundancy.
            - Ensure that the generic template caters to most cases and that specialization is reserved for specific scenarios.
        - Syntax:
            template <typename T>
            T cpp_func_max(T a, T b)
            {
                return (a > b) ? a : b;
            }

            // Specialization for int data type
            template <>
            int cpp_func_max<int>(int a, int b)
            {
                return (a > b) ? a : b;
            }
            
            // Specialization for double data type
            template <>
            double cpp_func_max<double>(double a, double b)
            {
                return (a > b) ? a : b;
            }         
*/

#include <bitset>
#include <numeric>
#include <stdexcept>
#include <sstream>
#include <type_traits>

namespace cpp_fun_templates {

    // Function template to convert elements of a container to strings
    template <typename Container>
    std::vector<std::string> cpp_func_convert_to_strings(const Container& container) {
        std::vector<std::string> result;
        for (const auto& value : container) {
            result.push_back(std::to_string(value));
        }
        return result;
    }

    // Specialization for std::vector<bool> container
    template <>
    std::vector<std::string> cpp_func_convert_to_strings<std::vector<bool>>(const std::vector<bool>& container) {
        std::vector<std::string> result;
        for (bool value : container) {
            // Convert bool value to "true" or "false" strings
            result.push_back(value ? "true" : "false");
        }
        return result;
    }

    // Function template to calculate the mean of elements in a container
    template <typename Container>
    double cpp_func_mean(const Container& container) {
        if (container.empty()) {
            throw std::invalid_argument("Container is empty");
        }
        double sum = std::accumulate(container.begin(), container.end(), 0.0);
        return sum / container.size();
    }

    // Specialization for std::vector<std::string> container
    template <>
    double cpp_func_mean<std::vector<std::string>>(const std::vector<std::string>& container) {
        throw std::logic_error("Cannot calculate mean of strings");
    }

    // Helper function to convert a value to JSON string
    template <typename T>
    std::string to_json_string(const T& value) {
        return "\"" + std::to_string(value) + "\"";
    }

    // Function template to convert elements of a container to JSON format
    template <typename Container>
    std::string cpp_func_to_json(const Container& container) {
        std::ostringstream json;
        json << "[";

        bool first = true;
        for (const auto& value : container) {
            if (!first) {
                json << ", ";
            }
            json << to_json_string(value);
            first = false;
        }

        json << "]";
        return json.str();
    }

    // Specialization for std::vector<bool> container
    template <>
    std::string cpp_func_to_json<std::vector<bool>>(const std::vector<bool>& container) {
        std::ostringstream json;
        json << "[";

        bool first = true;
        for (bool value : container) {
            if (!first) {
                json << ", ";
            }
            json << (value ? "true" : "false");
            first = false;
        }

        json << "]";
        return json.str();
    }

    // A simple 3D vector class
    class Vector3D {
    public:
        double x, y, z;

        Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
            : x(x), y(y), z(z) {}

        // Element-wise addition
        Vector3D operator+(const Vector3D& other) const {
            return Vector3D(x + other.x, y + other.y, z + other.z);
        }
    };

    // Function template for element-wise addition of containers
    template <typename Container>
    Container cpp_func_elementwise_add(const Container& a, const Container& b) {
        static_assert(std::is_same<typename Container::value_type, double>::value,
                      "cpp_func_elementwise_add requires containers of doubles");

        Container result;
        for (size_t i = 0; i < a.size(); ++i) {
            result.push_back(a[i] + b[i]);
        }
        return result;
    }

    // Specialization for Vector3D container
    template <>
    Vector3D cpp_func_elementwise_add(const Vector3D& a, const Vector3D& b) {
        return a + b;
    }

    // A simple matrix class
    template <typename T>
    class Matrix {
    private:
        std::vector<std::vector<T>> data;

    public:
        Matrix(const std::vector<std::vector<T>>& values)
            : data(values) {}

        // Find the maximum element in the matrix
        T max_element() const {
            if (data.empty() || data[0].empty()) {
                throw std::runtime_error("Matrix is empty");
            }

            T maxVal = data[0][0];
            for (const auto& row : data) {
                for (const T& val : row) {
                    maxVal = std::max(maxVal, val);
                }
            }
            return maxVal;
        }
    };

    // Function template to find the maximum element in a container
    template <typename Container>
    typename Container::value_type cpp_func_max_element(const Container& container) {
        return *std::max_element(container.begin(), container.end());
    }

    // Specialization for Matrix container
    template <typename T>
    T cpp_func_max_element(const Matrix<T>& matrix) {
        return matrix.max_element();
    }

} // namespace cpp_fun_templates

void cpp_func_templates_call() {

    // cpp_fun_templates::Matrix
    // cpp_fun_templates::cpp_func_max_element
    {
        std::vector<int> intValues = {1, 7, 3, 9, 5};
        cpp_fun_templates::Matrix<double> doubleMatrix({
            {1.1, 2.2, 3.3},
            {4.4, 5.5, 6.6},
            {7.7, 8.8, 9.9}
        });
    
        // Find the maximum element in a vector of integers
        int maxInt = cpp_fun_templates::cpp_func_max_element(intValues);
        std::cout << "Maximum element in int vector: " << maxInt << std::endl;
    
        // Find the maximum element in a Matrix of doubles
        double maxDouble = cpp_fun_templates::cpp_func_max_element(doubleMatrix);
        std::cout << "Maximum element in double matrix: " << maxDouble << std::endl;

    }
    
    // cpp_fun_templates::cpp_func_elementwise_add
    {
        std::vector<double> doubleValuesA = {1.0, 2.0, 3.0};
        std::vector<double> doubleValuesB = {0.5, 1.5, 2.5};
    
        cpp_fun_templates::Vector3D vectorA(1.0, 2.0, 3.0);
        cpp_fun_templates::Vector3D vectorB(0.5, 1.5, 2.5);
    
        // Element-wise addition of double containers
        std::vector<double> doubleResult = cpp_fun_templates::cpp_func_elementwise_add(doubleValuesA, doubleValuesB);
        std::cout << "Element-wise addition of double containers: ";
        for (const auto& value : doubleResult) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    
        // Element-wise addition of Vector3D objects
        cpp_fun_templates::Vector3D vectorResult = cpp_fun_templates::cpp_func_elementwise_add(vectorA, vectorB);
        std::cout << "Element-wise addition of Vector3D objects: "
                  << "x: " << vectorResult.x << ", y: " << vectorResult.y << ", z: " << vectorResult.z << std::endl;
    
    }
    
    // cpp_fun_templates::cpp_func_to_json
    {
        std::vector<int> intValues = {1, 2, 3, 4, 5};
        std::vector<double> doubleValues = {1.5, 2.5, 3.5, 4.5, 5.5};
        std::vector<bool> boolValues = {true, false, true, true, false};
    
        // Convert int values to JSON format
        std::string intJson = cpp_fun_templates::cpp_func_to_json(intValues);
        std::cout << "Int values in JSON: " << intJson << std::endl;
    
        // Convert double values to JSON format
        std::string doubleJson = cpp_fun_templates::cpp_func_to_json(doubleValues);
        std::cout << "Double values in JSON: " << doubleJson << std::endl;
    
        // Convert bool values to JSON format
        std::string boolJson = cpp_fun_templates::cpp_func_to_json(boolValues);
        std::cout << "Bool values in JSON: " << boolJson << std::endl;
    
    }
    
    // cpp_fun_templates::cpp_func_mean
    {
        std::vector<int> intValues = {1, 2, 3, 4, 5};
    std::vector<double> doubleValues = {1.5, 2.5, 3.5, 4.5, 5.5};
    std::vector<std::string> stringValues = {"apple", "banana", "cherry"};

    try {
        // Calculate mean of int values
        double intMean = cpp_fun_templates::cpp_func_mean(intValues);
        std::cout << "Mean of int values: " << intMean << std::endl;

        // Calculate mean of double values
        double doubleMean = cpp_fun_templates::cpp_func_mean(doubleValues);
        std::cout << "Mean of double values: " << doubleMean << std::endl;

        // Attempt to calculate mean of string values
        double stringMean = cpp_fun_templates::cpp_func_mean(stringValues);
        std::cout << "Mean of string values: " << stringMean << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    }
    
    // cpp_fun_templates::cpp_func_convert_to_strings
    {
        std::vector<int> intValues = {1, 2, 3, 4, 5};
        std::vector<double> doubleValues = {1.5, 2.5, 3.5, 4.5, 5.5};
        std::vector<bool> boolValues = {true, false, true, true, false};
    
        // Convert int values to strings
        std::vector<std::string> intStrings = cpp_fun_templates::cpp_func_convert_to_strings(intValues);
        std::cout << "Int values as strings: ";
        for (const auto& str : intStrings) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    
        // Convert double values to strings
        std::vector<std::string> doubleStrings = cpp_fun_templates::cpp_func_convert_to_strings(doubleValues);
        std::cout << "Double values as strings: ";
        for (const auto& str : doubleStrings) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    
        // Convert bool values to strings
        std::vector<std::string> boolStrings = cpp_fun_templates::cpp_func_convert_to_strings(boolValues);
        std::cout << "Bool values as strings: ";
        for (const auto& str : boolStrings) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}







#endif


