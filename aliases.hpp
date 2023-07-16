#ifndef __ALIASES_H
#define __ALIASES_H

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
    - Aliases in C++:
        - Type aliases are especially useful in large codebases, where they can make the code more readable, reduce duplication, and provide a consistent naming convention for types.
        - By using type aliases effectively, you can enhance code readability, abstract away implementation details, and create more expressive and maintainable code in real-world scenarios.
        - Simplifying Long and Complex Type Names:
            - Type aliases can be used to create shorter and more readable names for long and complex type names. 
            - This can make the code more concise and easier to understand.
        - Creating Platform-Independent Types:
            - Type aliases can be used to create platform-independent type names, providing a level of abstraction from underlying platform-specific types.
            - This allows us to write code that is portable across different platforms.
        -  Enhancing Code Readability and Maintainability:
            - Type aliases can be used to give more descriptive and meaningful names to types, improving code readability and maintainability.
            - This makes the code self-explanatory and easier to understand. 

        - Syntax:
            - 01) C-Style:
                typedef existing_type new_name;
            - 02) C++ Style:
                using new_name = existing_type;
            - 03) C++11 Style For Templates:
                template<typename T>
                using new_name = existing_type<T>;   
*/            

// C++11 Style For Templates:
template<typename T>
using Matrix = std::vector<std::vector<T>>;

template<typename T>
using Point = std::pair<T, T>;

void aliases_c_cpp()
{
    // 01) C-Style:
    typedef std::unordered_map<std::string, std::vector<int>> DataMap;
    DataMap data;

    // 02) C++ Style:
    #ifdef _WIN32
        using PlatformString = std::wstring;
    #else
        using PlatformString = std::string;
    #endif
    
    PlatformString message = "Hello, World!";

    using EmployeeID = int;
    using EmployeeName = std::string;
    
    struct Employee {
        EmployeeID id;
        EmployeeName name;
    };
    
    Employee employee;
    employee.id = 123;
    employee.name = "John Doe";
    
    // 03) C++11 Style For Templates:
    Matrix<int> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    Point<double> point = {3.5, 2.8};
    std::cout << "Point coordinates: (" << point.first << ", " << point.second << ")" << std::endl;

    
}







#endif




