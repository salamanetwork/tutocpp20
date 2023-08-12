#ifndef __TEMPLATES_BY_VALUE_H
#define __TEMPLATES_BY_VALUE_H

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
    - Templates By Value:
        - Template parameters can be passed by value, allowing you to define a template that accepts values of various types.
        - When you pass a template parameter by value, you are essentially instructing the compiler to generate a separate instance of the template code for each unique type that you use with the template. 
        - This means that the compiler will create a specialized version of the template for each distinct type, and this specialization will contain the code specific to that type.
        - It's important to note that passing template parameters by value can lead to code duplication and increased executable size, as separate instances of the template code are generated for each type.
        - However, it provides better performance in some cases, especially for small and simple types.
        - Remember that templates are a powerful feature of C++, and passing template parameters by value is just one aspect of their flexibility. 

*/

// Using the provided naming conventions
namespace cpp_func_templates {
    template <typename T>
    T cpp_func_average(const T arr[], size_t size) {
        if (size == 0) {
            throw std::invalid_argument("Array size must be greater than 0");
        }

        T sum = arr[0];
        for (size_t i = 1; i < size; ++i) {
            sum += arr[i];
        }

        return sum / static_cast<T>(size);
    }

    template <typename T>
    T cpp_func_findMax(const T arr[], size_t size) {
        if (size == 0) {
            throw std::invalid_argument("Array size must be greater than 0");
        }

        T maxElement = arr[0];
        for (size_t i = 1; i < size; ++i) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }

        return maxElement;
    }

    template <typename T>
    void cpp_func_elementWiseMultiply(const T arr1[], const T arr2[], T result[], size_t size) {
        for (size_t i = 0; i < size; ++i) {
            result[i] = arr1[i] * arr2[i];
        }
    }

    template <typename T>
    int cpp_func_findIndex(const T arr[], size_t size, const T& value) {
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return static_cast<int>(i);  // Convert size_t to int for index
            }
        }
        return -1;  // Not found
    }

    template <typename T>
    void cpp_func_bubbleSort(T arr[], size_t size) {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <typename T>
    T cpp_func_dotProduct(const T arr1[], const T arr2[], size_t size) {
        T result = static_cast<T>(0);
        for (size_t i = 0; i < size; ++i) {
            result += arr1[i] * arr2[i];
        }
        return result;
    }

    template <typename T>
    T cpp_func_sumAbsoluteDifferences(const T arr1[], const T arr2[], size_t size) {
        T sum = static_cast<T>(0);
        for (size_t i = 0; i < size; ++i) {
            sum += abs(arr1[i] - arr2[i]);
        }
        return sum;
    }
}

void cpp_func_templates_call() {
    // cpp_func_templates::cpp_func_average
    {    
        int intArray[] = { 10, 20, 30, 40, 50 };
        double doubleArray[] = { 3.5, 2.5, 6.0, 8.0, 1.0 };
    
        size_t intArraySize = sizeof(intArray) / sizeof(int);
        size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
    
        try {
            int intAvg = cpp_func_templates::cpp_func_average(intArray, intArraySize);
            double doubleAvg = cpp_func_templates::cpp_func_average(doubleArray, doubleArraySize);
    
            std::cout << "Average of intArray: " << intAvg << std::endl;
            std::cout << "Average of doubleArray: " << doubleAvg << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    
        try {
            int intMax = cpp_func_templates::cpp_func_findMax(intArray, intArraySize);
            double doubleMax = cpp_func_templates::cpp_func_findMax(doubleArray, doubleArraySize);
    
            std::cout << "Max element in intArray: " << intMax << std::endl;
            std::cout << "Max element in doubleArray: " << doubleMax << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    // cpp_func_templates::cpp_func_elementWiseMultiply
    {
        int intArray1[] = { 1, 2, 3, 4, 5 };
        int intArray2[] = { 5, 4, 3, 2, 1 };
        int intResult[5];
    
        size_t arraySize = sizeof(intArray1) / sizeof(int);
    
        try {
            cpp_func_templates::cpp_func_elementWiseMultiply(intArray1, intArray2, intResult, arraySize);
    
            std::cout << "Element-wise multiplication result: ";
            for (size_t i = 0; i < arraySize; ++i) {
                std::cout << intResult[i] << " ";
            }
            std::cout << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    // cpp_func_templates::cpp_func_findIndex
    {
        int intArray[] = { 10, 20, 30, 40, 50 };
        double doubleArray[] = { 3.5, 2.5, 6.0, 8.0, 1.0 };
        const char* strArray[] = { "apple", "banana", "cherry", "date", "elderberry" };
    
        size_t intArraySize = sizeof(intArray) / sizeof(int);
        size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
        size_t strArraySize = sizeof(strArray) / sizeof(const char*);
    
        int intValueToFind = 30;
        double doubleValueToFind = 6.0;
        const char* strValueToFind = "date";
    
        int intIndex = cpp_func_templates::cpp_func_findIndex(intArray, intArraySize, intValueToFind);
        int doubleIndex = cpp_func_templates::cpp_func_findIndex(doubleArray, doubleArraySize, doubleValueToFind);
        int strIndex = cpp_func_templates::cpp_func_findIndex(strArray, strArraySize, strValueToFind);
    
        if (intIndex != -1) {
            std::cout << "Index of " << intValueToFind << " in intArray: " << intIndex << std::endl;
        } else {
            std::cout << intValueToFind << " not found in intArray." << std::endl;
        }
    
        if (doubleIndex != -1) {
            std::cout << "Index of " << doubleValueToFind << " in doubleArray: " << doubleIndex << std::endl;
        } else {
            std::cout << doubleValueToFind << " not found in doubleArray." << std::endl;
        }
    
        if (strIndex != -1) {
            std::cout << "Index of \"" << strValueToFind << "\" in strArray: " << strIndex << std::endl;
        } else {
            std::cout << "\"" << strValueToFind << "\" not found in strArray." << std::endl;
        }
    }

    // cpp_func_templates::cpp_func_bubbleSort
    {
        int intArray[] = { 10, 4, 8, 25, 17 };
        double doubleArray[] = { 3.5, 12.7, 6.0, 8.0, 1.0 };
    
        size_t intArraySize = sizeof(intArray) / sizeof(int);
        size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
    
        std::cout << "Original intArray: ";
        for (size_t i = 0; i < intArraySize; ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    
        std::cout << "Original doubleArray: ";
        for (size_t i = 0; i < doubleArraySize; ++i) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
    
        cpp_func_templates::cpp_func_bubbleSort(intArray, intArraySize);
        cpp_func_templates::cpp_func_bubbleSort(doubleArray, doubleArraySize);
    
        std::cout << "Sorted intArray: ";
        for (size_t i = 0; i < intArraySize; ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    
        std::cout << "Sorted doubleArray: ";
        for (size_t i = 0; i < doubleArraySize; ++i) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
    }

    // cpp_func_templates::cpp_func_dotProduct
    {
        int intVector1[] = { 1, 2, 3 };
        int intVector2[] = { 4, 5, 6 };
        double doubleVector1[] = { 1.5, 2.5, 3.5 };
        double doubleVector2[] = { 0.5, 1.5, 2.5 };
    
        size_t vectorSize = sizeof(intVector1) / sizeof(int);
    
        int intDotProduct = cpp_func_templates::cpp_func_dotProduct(intVector1, intVector2, vectorSize);
        double doubleDotProduct = cpp_func_templates::cpp_func_dotProduct(doubleVector1, doubleVector2, vectorSize);
    
        std::cout << "Dot product of int vectors: " << intDotProduct << std::endl;
        std::cout << "Dot product of double vectors: " << doubleDotProduct << std::endl;
    
    }

    // cpp_func_templates::cpp_func_sumAbsoluteDifferences
    {
        int intArray1[] = { 10, 4, 8, 25, 17 };
        int intArray2[] = { 12, 3, 6, 20, 15 };
        double doubleArray1[] = { 3.5, 12.7, 6.0, 8.0, 1.0 };
        double doubleArray2[] = { 2.0, 10.0, 5.5, 7.5, 0.5 };
    
        size_t arraySize = sizeof(intArray1) / sizeof(int);
    
        int intSum = cpp_func_templates::cpp_func_sumAbsoluteDifferences(intArray1, intArray2, arraySize);
        double doubleSum = cpp_func_templates::cpp_func_sumAbsoluteDifferences(doubleArray1, doubleArray2, arraySize);
    
        std::cout << "Sum of absolute differences for int arrays: " << intSum << std::endl;
        std::cout << "Sum of absolute differences for double arrays: " << doubleSum << std::endl;
    
    }

}










#endif


