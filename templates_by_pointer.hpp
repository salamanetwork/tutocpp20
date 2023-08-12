#ifndef __TEMPLATES_BY_POINTER_H
#define __TEMPLATES_BY_POINTER_H

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
    - Templates By Pointer:
        - When you pass a template parameter by pointer, you are essentially passing a memory address that points to the object. 
        - This allows the function or class template to work with the original object indirectly. 
        - Passing template parameters by pointer can have implications for memory management, object lifetime, and the ability to modify the original object. 
        - Passing by pointer provides a level of indirection, allowing functions to access and potentially modify the original object without copying its contents. 
        - When passing by pointer, you need to be cautious about the object's ownership and lifetime. 
        - f you pass a raw pointer, you should ensure that the pointed-to object's lifetime exceeds the scope of the function or template using it. 
        - Smart pointers, such as std::shared_ptr or std::unique_ptr, can help manage ownership and automatically handle deallocation.
        - Syntax:
            template <typename T>
            void foo(T* ptr) {
                // Access object using pointer semantics
            }       
*/

template <typename T>
struct CustomData {
    T value;
    CustomData* next;
    CustomData(T val) : value(val), next(nullptr) {}
};

template <typename T>
struct ListNode {
    using ValueType = T;
    T data;
    ListNode* next;
    ListNode(T val, ListNode* nxt) : data(val), next(nxt) {}
};

namespace cpp_func_templates {
    template <typename T>
    void processCustomDataByPointer(CustomData<T>* data) {
        CustomData<T>* current = data;
        while (current) {
            current->value *= 2; // Modify data
            current = current->next;
        }
    }

    template <typename T>
    void matrixMultiplication(const T* matrix1, size_t rows1, size_t cols1,
                              const T* matrix2, size_t rows2, size_t cols2,
                              T* result) {
        if (cols1 != rows2) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }

        for (size_t i = 0; i < rows1; ++i) {
            for (size_t j = 0; j < cols2; ++j) {
                result[i * cols2 + j] = 0;
                for (size_t k = 0; k < cols1; ++k) {
                    result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
                }
            }
        }
    }
    
#include <fstream>
#include <memory>
    
    template <typename T>
    std::unique_ptr<T[]> readFileData(const std::string& filename, size_t& dataSize) {
        std::ifstream file(filename, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }

        file.seekg(0, std::ios::end);
        dataSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::unique_ptr<T[]> buffer(new T[dataSize]);
        file.read(reinterpret_cast<char*>(buffer.get()), dataSize);
        file.close();

        return buffer;
    }

    template <typename Node>
    void appendToLinkedList(Node*& head, typename Node::ValueType value) {
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    template <typename T, typename Transformation>
    void processDataByPointer(T* data, size_t size, Transformation transform) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = transform(data[i]);
        }
    }

    template <typename Container>
    void sortContainer(Container* container) {
        std::sort(container->begin(), container->end());
    }

    template <typename T>
    T* allocateArray(size_t size) {
        return new T[size];
    }

    template <typename T>
    void deallocateArray(T* ptr) {
        delete[] ptr;
    }

    
}

void cpp_func_templates_call()
{
    // cpp_func_templates::allocateArray
    // cpp_func_templates::deallocateArray
    {
        int* intArray = cpp_func_templates::allocateArray<int>(5);
        double* doubleArray = cpp_func_templates::allocateArray<double>(3);
    
        for (size_t i = 0; i < 5; ++i) {
            intArray[i] = static_cast<int>(i);
        }
        for (size_t i = 0; i < 3; ++i) {
            doubleArray[i] = 0.1 * static_cast<double>(i);
        }
    
        for (size_t i = 0; i < 5; ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    
        for (size_t i = 0; i < 3; ++i) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
    
        cpp_func_templates::deallocateArray(intArray);
        cpp_func_templates::deallocateArray(doubleArray);
    }
    
    // cpp_func_templates::sortContainer
    {
        std::vector<int> intVector = { 5, 3, 8, 1, 2, 7 };
        cpp_func_templates::sortContainer(&intVector);
    
        std::cout << "Sorted intVector: ";
        for (const auto& element : intVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    
    // cpp_func_templates::processDataByPointer
    {
        int intArray[] = { 1, 2, 3, 4, 5 };
        size_t arraySize = sizeof(intArray) / sizeof(int);
    
        cpp_func_templates::processDataByPointer(intArray, arraySize, [](int value) {
            return value * value;
        });
    
        std::cout << "Processed intArray: ";
        for (size_t i = 0; i < arraySize; ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;    
    }
    
    // cpp_func_templates::appendToLinkedList
    {
        ListNode<int>* head = nullptr;
        cpp_func_templates::appendToLinkedList(head, 1);
        cpp_func_templates::appendToLinkedList(head, 2);
        cpp_func_templates::appendToLinkedList(head, 3);
    
        ListNode<int>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    
        // Clean up
        while (head) {
            ListNode<int>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // cpp_func_templates::readFileData
    {
       size_t dataSize;
        auto data = cpp_func_templates::readFileData<char>("data.bin", dataSize);
    
        std::cout << "Read " << dataSize << " bytes from file." << std::endl;
 
    }
    
    // cpp_func_templates::matrixMultiplication
    {
        const size_t rows1 = 2, cols1 = 3;
        const size_t rows2 = 3, cols2 = 2;
        int matrix1[rows1 * cols1] = { 1, 2, 3, 4, 5, 6 };
        int matrix2[rows2 * cols2] = { 7, 8, 9, 10, 11, 12 };
        int result[rows1 * cols2];
    
        cpp_func_templates::matrixMultiplication(matrix1, rows1, cols1, matrix2, rows2, cols2, result);
    
        std::cout << "Matrix multiplication result:" << std::endl;
        for (size_t i = 0; i < rows1; ++i) {
            for (size_t j = 0; j < cols2; ++j) {
                std::cout << result[i * cols2 + j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    // cpp_func_templates::processCustomDataByPointer
    {
        CustomData<int>* data1 = new CustomData<int>(1);
        CustomData<int>* data2 = new CustomData<int>(2);
        CustomData<int>* data3 = new CustomData<int>(3);
    
        data1->next = data2;
        data2->next = data3;
    
        cpp_func_templates::processCustomDataByPointer(data1);
    
        CustomData<int>* current = data1;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    
        // Clean up
        while (data1) {
            CustomData<int>* temp = data1;
            data1 = data1->next;
            delete temp;
        }
    }
}




#endif


