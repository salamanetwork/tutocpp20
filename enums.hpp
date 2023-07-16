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

/*
    - Enumeration Class In C++:
        - In C++, the enum class (also known as a scoped enumeration or strongly-typed enum) is an improved version of the traditional enum construct. 
        - It provides better type safety, scoping, and control over underlying types.
        - Here are some key characteristics and features of enum class:
            - Strongly Typed: 
                - Enumerators within an enum class are strongly typed, meaning they have their own distinct type. 
                - This prevents unintended type conversions and helps catch potential bugs at compile time.

            - Scoped: 
                - Enumerators in an enum class are scoped within the enum class name. 
                - This allows multiple enum class declarations to have enumerators with the same names without conflicts. 
                - You need to qualify the enumerator with the enum class name or use the using directive to bring specific enumerators into the local scope.

            - No Implicit Conversions: 
                - Enumerators in an enum class are not implicitly convertible to integers or other enumerators. 
                - This helps avoid accidental misuse and promotes explicit conversions when necessary.

            - Specifying Underlying Type: 
                - With enum class, you can explicitly specify the underlying integral type that represents the enumerators. 
                - This provides control over the range, size, and signedness of the underlying values. 
                - If not explicitly specified, the underlying type defaults to int.

            - Forward Declaration: 
                - enum class can be forward-declared without defining the underlying enumerators. 
                - This is useful in scenarios where you want to declare a type but define its enumerators later.

            - Improved Compiler Diagnostics: 
                - enum class generates better error messages and compiler diagnostics compared to the traditional enum. 
                - It helps catch potential errors like comparing different enumeration types or performing invalid operations on enumerators. 
        - Synatx:
            enum class EnumName : underlying_type {
                Enumerator1,
                Enumerator2,
                Enumerator3,
                // ...
            };
        
*/

void enum_class_cpp_style()
{
    enum class Month : int {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    Month currentMonth = Month::July;
    int monthValue = static_cast<int>(currentMonth);

    std::cout << "Current month: " << monthValue << std::endl;

    if (currentMonth == Month::December) {
        std::cout << "It's the holiday season!" << std::endl;
    }
}

/*
    - Enumeration Features in C++20:
        - Scoped Enumarations with enum class:
            - C++20 continues to support the enum class syntax introduced earlier. 
            - Using enum class, enumerators are strongly typed and scoped within the enum's name. 
            - This helps prevent name clashes and provides better type safety.
        - Improved Explicit Conversion:
            - In C++20, you can use enum types in a more flexible and expressive way when it comes to explicit conversions. 
            - You can now use enum types in static_cast and reinterpret_cast, making it easier to convert between enum types and other compatible types.
        - Bitmask Enums:
            - C++20 introduces a new syntax for defining bitmask enumerations, also known as flag enums. 
            - This allows you to represent combinations of enum values as bitwise flags. 
            - You can use the bitwise OR operator to combine multiple enum values.
            - In C++20, the enum class bitwise operations require explicit overloading of the operators. 
                - The error you encountered indicates that the bitwise OR (|), AND (&) operator is not defined for the enum class type in the way we attempted to use it.
        - Enum Reflection:
            - C++20 introduces a reflection mechanism called "reflection traits" that enables querying information about enum types at compile-time. 
            - This allows you to obtain information such as the number of enumerators, the names of the enumerators, and more.           
*/

// Using for bitmask
enum class Permissions : unsigned int {
    None = 0,
    Read = 1 << 0,
    Write = 1 << 1,
    Execute = 1 << 2
};

// In C++20, the enum class bitwise operations require explicit overloading of the operators:
Permissions operator|(Permissions lhs, Permissions rhs) {
    return static_cast<Permissions>(
        static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs)
    );
}

// In C++20, the enum class bitwise operations require explicit overloading of the operators:
Permissions operator&(Permissions lhs, Permissions rhs) {
    return static_cast<Permissions>(
        static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs)
    );
}

void PrintPermissions(Permissions permissions) {
    std::bitset<3> bits(static_cast<unsigned int>(permissions));
    std::cout << "Permissions: " << bits << std::endl;
}


void enum_cpp20()
{
    // Scoped Enumarations with enum class:
    enum class Colors {
        Red,
        Green,
        Blue
    };

    // Improved Explicit Conversion:
    enum class Animal {
        Cat,
        Dog,
        Elephant
    };
    
    enum class Sound {
        Meow,
        Bark,
        Trumpet
    };
    
    Animal animal = Animal::Cat;
    Sound sound = static_cast<Sound>(animal);

    // Bitmask Enums:
    Permissions userPermissions = Permissions::Read | Permissions::Write;

    if ((userPermissions & Permissions::Read) == Permissions::Read) {
        std::cout << "User has read permission." << std::endl;
    }

    if ((userPermissions & Permissions::Write) == Permissions::Write) {
        std::cout << "User has write permission." << std::endl;
    }

    if ((userPermissions & Permissions::Execute) == Permissions::Execute) {
        std::cout << "User has execute permission." << std::endl;
    }

    PrintPermissions(userPermissions);
    
    // Enum Reflection:
    constexpr std::size_t enumSize = std::extent_v<std::remove_reference_t<decltype(Colors::Blue)>> + 1;
    
    std::cout << "Number of enumerators: " << enumSize << std::endl;

    if constexpr (std::is_enum_v<Colors>) 
    {
        std::cout << "Colors is an enum type." << std::endl;
    }
}















#endif




