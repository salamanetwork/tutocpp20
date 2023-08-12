#ifndef __TEMPLATES_BY_REFERENCE_H
#define __TEMPLATES_BY_REFERENCE_H

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
    - Templates By Reference:
        - Passing template parameters by reference is a powerful technique that offers efficiency and flexibility, but it also requires careful consideration of object lifetimes and potential modifications. 
        - It's commonly used when you want to work with and potentially modify existing objects efficiently within a template algorithm or function.
        - When you pass a template parameter by reference, you are allowing the function or class template to work with the original object, rather than creating a copy. 
        - This can have implications for performance, memory usage, and the ability to modify the original object. 
*/

#include <iostream>
#include <vector>

// Using the provided naming conventions
namespace cpp_func_templates {
    template <typename Container>
    double cpp_func_modifyAndCalculateAverage(Container& container) {
        if (container.empty()) {
            throw std::invalid_argument("Container must not be empty");
        }

        double sum = 0.0;
        for (auto& element : container) {
            // Modify the element in some way (e.g., increment by 1)
            element += 1;

            sum += static_cast<double>(element);
        }

        return sum / container.size();
    }

    template <typename Container>
    void cpp_func_elementWiseAdd(const Container& container1, const Container& container2, Container& result) {
        if (container1.size() != container2.size() || container1.size() != result.size()) {
            throw std::invalid_argument("Containers must have the same size");
        }

        auto it1 = container1.begin();
        auto it2 = container2.begin();
        auto itResult = result.begin();

        while (it1 != container1.end()) {
            *itResult = *it1 + *it2;
            ++it1;
            ++it2;
            ++itResult;
        }
    }

    template <typename Container>
    void cpp_func_findCommonElements(const Container& container1, const Container& container2, Container& result) {
        std::set_intersection(container1.begin(), container1.end(),
                              container2.begin(), container2.end(),
                              std::back_inserter(result));
    }

    template <typename Container, typename Transformation>
    void processData(Container& data, Transformation transform) {
        std::transform(data.begin(), data.end(), data.begin(), transform);
    }

    template <typename Container, typename Comparator>
    void customSort(Container& container, Comparator comp) {
        std::sort(container.begin(), container.end(), comp);
    }

    template <typename Node>
    void traverseLinkedList(Node* head) {
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    template <typename Container>
    void printContainer(const Container& container) {
        for (const auto& element : container) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void matrixAddition(const std::vector<std::vector<T>>& matrix1,
                        const std::vector<std::vector<T>>& matrix2,
                        std::vector<std::vector<T>>& result) {
        // Perform matrix addition
        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }

#include <fstream>
    
    template <typename T>
    void serializeData(const T& data, std::ofstream& outputFile) {
        // Serialize and write data to the file
        outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
    }

    template <typename T>
    void deserializeData(T& data, std::ifstream& inputFile) {
        // Read and deserialize data from the file
        inputFile.read(reinterpret_cast<char*>(&data), sizeof(data));
    }
    
}

struct ListNode {
    int data;
    ListNode* next;
};

void cpp_func_templates_call() {
    // cpp_func_templates::cpp_func_modifyAndCalculateAverage
    {
        std::vector<int> intVector = { 10, 20, 30, 40, 50 };

        try {
            double average = cpp_func_templates::cpp_func_modifyAndCalculateAverage(intVector);
    
            std::cout << "Modified elements in intVector and calculated average: " << average << std::endl;
    
            std::cout << "Modified intVector: ";
            for (const auto& element : intVector) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    // cpp_func_templates::cpp_func_elementWiseAdd
    {
        std::vector<int> intVector1 = { 1, 2, 3, 4, 5 };
        std::vector<int> intVector2 = { 5, 4, 3, 2, 1 };
        std::vector<int> intResult(5);
    
        try {
            cpp_func_templates::cpp_func_elementWiseAdd(intVector1, intVector2, intResult);
    
            std::cout << "Element-wise addition result: ";
            for (const auto& element : intResult) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    // cpp_func_templates::cpp_func_findCommonElements
    {
        std::vector<int> intVector1 = { 1, 2, 3, 4, 5 };
        std::vector<int> intVector2 = { 3, 4, 5, 6, 7 };
        std::vector<int> commonElements;
    
        try {
            cpp_func_templates::cpp_func_findCommonElements(intVector1, intVector2, commonElements);
    
            std::cout << "Common elements between intVector1 and intVector2: ";
            for (const auto& element : commonElements) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    // cpp_func_templates::processData
    {
        std::vector<int> intVector = { 1, 2, 3, 4, 5 };

        cpp_func_templates::processData(intVector, [](int value) {
            return value * value; // Square each element
        });
    
        std::cout << "Processed intVector: ";
        for (const auto& element : intVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // cpp_func_templates::customSort
    {
        std::vector<int> intVector = { 5, 3, 8, 1, 2, 7 };

        cpp_func_templates::customSort(intVector, [](int a, int b) {
            return a > b; // Sort in descending order
        });
    
        std::cout << "Sorted intVector: ";
        for (const auto& element : intVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // cpp_func_templates::traverseLinkedList
    {
        ListNode* node1 = new ListNode{1, nullptr};
        ListNode* node2 = new ListNode{2, nullptr};
        ListNode* node3 = new ListNode{3, nullptr};
        node1->next = node2;
        node2->next = node3;
    
        cpp_func_templates::traverseLinkedList(node1);
    
        delete node1;
        delete node2;
        delete node3;
    }

    // cpp_func_templates::printContainer
    {
        std::vector<int> intVector = { 1, 2, 3, 4, 5 };
        std::vector<double> doubleVector = { 3.14, 2.71, 1.618 };
    
        cpp_func_templates::printContainer(intVector);
        cpp_func_templates::printContainer(doubleVector);
    }

    // cpp_func_templates::matrixAddition
    {
        std::vector<std::vector<int>> matrix1 = { {1, 2}, {3, 4} };
        std::vector<std::vector<int>> matrix2 = { {5, 6}, {7, 8} };
        std::vector<std::vector<int>> result(2, std::vector<int>(2, 0));
    
        cpp_func_templates::matrixAddition(matrix1, matrix2, result);
    
        std::cout << "Matrix addition result:" << std::endl;
        for (const auto& row : result) {
            for (const auto& element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }

    // cpp_func_templates::serializeData
    // cpp_func_templates::deserializeData
    {
        int intValue = 42;
        double doubleValue = 3.14;
    
        std::ofstream output("data.bin", std::ios::binary);
        cpp_func_templates::serializeData(intValue, output);
        cpp_func_templates::serializeData(doubleValue, output);
        output.close();
    
        int readIntValue;
        double readDoubleValue;
    
        std::ifstream input("data.bin", std::ios::binary);
        cpp_func_templates::deserializeData(readIntValue, input);
        cpp_func_templates::deserializeData(readDoubleValue, input);
        input.close();
    
        std::cout << "Read int value: " << readIntValue << std::endl;
        std::cout << "Read double value: " << readDoubleValue << std::endl;

    }
}





#endif


