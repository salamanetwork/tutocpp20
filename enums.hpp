#ifndef __ENUMS_H
#define __ENUMS_H

#include <iostream>
#include <bitset>
#include <iomanip>
#include <ios>
#include <array>
#include <new>
#include <algorithm>
#include <string>
#include <string_view>


#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cctype>
#include <cstring>


using namespace std;

/*
    - Enumeration in C++:
        - In C++, an enum (short for enumeration) is a user-defined data type that consists of a set of named values.
        - It provides a way to represent a group of related constants or options as a single type
        - When you define an enum, you're essentially creating a new data type. 
        - Each value within the enum is called an enumerator, and they are automatically assigned integral constant values starting from zero by default. 
        - However, you can explicitly assign specific values to the enumerators if desired.
        - To use the enum, you declare variables of the enum type and assign one of its enumerators to the variable. 
        - One advantage of using enum is that it makes the code more readable and self-explanatory. 
        - Instead of using arbitrary integer values, you can use meaningful names to represent different options or states in your program.
        - Enums in C++ can also be used in switch statements, comparisons, and arithmetic operations. 
        - It's a powerful feature that helps improve code clarity and maintainability by providing named values for related constants.
        - Syntax:
            enum EnumName {
                Enumerator1,
                Enumerator2,
                Enumerator3,
                // ...
            };
        - Example:
            enum Colors {
                Red = 5,
                Green = 10,
                Blue = 15
            };
*/

void enum_c_style()
{
    enum DaysOfWeek {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    enum Colors {
        Red = 5,
        Green = 10,
        Blue = 15
    };

    DaysOfWeek today = Wednesday;

    if (today == Wednesday) {
        std::cout << "Today is Wednesday!" << std::endl;
    }

}

















#endif




