#ifndef __POINTERS_H
#define __POINTERS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <ctime>
#include <cstdlib>
#include <cstdint>

#include <bitset>

using namespace std;


/*
    - Pointer:
        - Just a varaiable has another variables' address within its value.
        - Store only the address of another variable from the same data type.
        - The pointer size it is relevant to its type.
        - nullptr: 
            - using to assign NULL to an empty pointer.
            - if any value not assigned to it will return to the default value of the type we used.
        - Symbols:
            - *: to declare a pointer.
            - *: (Dereferening) to get the actual value of the variable that pointer refere to.
            - &: (Referening)   to get the address of the variable.
        - Declaration: 
            type * var_name;
            type * var_name {};
            type * var_name = NULL;            // Old C-Style
            type * var_name = nullptr;         // C++ Style
            type * var_name { nullptr };       // C++ Style
            
        - ex:
            int variable;                                                   // Some garbage value
            int another_variable = 10;                                      // Actual value is 10
            int *pointer_to_variable = &variable;                           // The value is: the address of the variable
            int *pointer_to_another_variable = &another_variable;           // The value is: the address of the another_variable
            
        - explaination:
            ------------------------------------------------------MEMORY---------------------------------------------------------------------
            |    Address        |    Variable Name                   |    Variable Value    |                    Remarks                    |
            ---------------------------------------------------------------------------------------------------------------------------------
            |    0xabcd001      |    variable                        |                      | *Some Garbage Value Assigned By The Compiler* |
            ---------------------------------------------------------------------------------------------------------------------------------
            |    0xabcd002      |    another_variable                |    10                | *The actual value of the another_variable     |
            ---------------------------------------------------------------------------------------------------------------------------------
            |    0xabcd003      |    pointer_to_variable             |    0xabcd001         | *Address of: variable                         |
            ---------------------------------------------------------------------------------------------------------------------------------
            |    0xabcd004      |    pointer_to_another_variable     |    0xabcd002         | *Address of: another_variable                 |
            ---------------------------------------------------------------------------------------------------------------------------------
            |    0xabcd005      |            ...                     |        ...           | ....so on                                     |
            ---------------------------------------------------------------------------------------------------------------------------------
*/

void pointers()
{
    const int WIDTH { 4 };
    
    // Variables
    int variable;                                        
    int another_variable = 10;

    // Pointer Declaration with null values
    int *pointer_to_empty {};               // Initialize with nullptr
    int *pointer_to_null_01 = nullptr;      // Explicity use nullptr
    int *pointer_to_null_02 {nullptr};      // Explicity use nullptr
    int *pointer_to_null_03 (nullptr);      // Explicity use nullptr
    int *pointer_to_null_04 = {nullptr};    // Explicity use nullptr
    int *pointer_to_null_05 = (nullptr);    // Explicity use nullptr
    
    // Pointers with directly assignments
    int *pointer_to_variable = &variable;                
    int *pointer_to_another_variable = &another_variable;

    std::cout << std::endl;

    std::cout << std::setfill('-');
    
    std::cout
        << "The Size of (variable) is: " 
            << sizeof variable
        << std::endl
            << std::setw(WIDTH) 
                << "\t(variable) value is: "
                    << dec
                        << variable
                            << std::endl
            << std::setw(WIDTH)
                << "\t(variable) address is: \t\t\t\t\t\t\t\t\t\t"
                    << hex
                        << &variable
        << std::endl
        << std::endl
        
        << "The Size of (pointer_to_variable) is: " 
            << sizeof pointer_to_variable
        << std::endl
            << std::setw(WIDTH)
                << "\t(pointer_to_variable) value is: \t\t\t\t\t\t\t"
                    <<  std::hex
                        << static_cast<int *>(pointer_to_variable)
        
        << std::endl
        << std::endl
        << "The Size of (another_variable) is: " 
            << sizeof another_variable
        << std::endl
            << std::setw(WIDTH)
                << "\t(another_variable) value is: "
                    << dec 
                        << another_variable
                        <<std::endl
            << std::setw(WIDTH)
                << "\t(another_variable) address is: \t\t\t\t\t\t\t\t"
                    << std::hex
                        << &another_variable
        << std::endl
        << std::endl
        << "The Size of (pointer_to_another_variable) is: " 
            << sizeof pointer_to_another_variable
        << std::endl
            << "\t(pointer_to_another_variable) value is: \t\t\t\t\t"
                <<  std::hex
                    << static_cast<int *>(pointer_to_another_variable)
        << std::endl
        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout 
        << "Value of pointer_to_empty:   " 
        << pointer_to_empty 
        << " its address is: "
        << &pointer_to_empty 
        << std::endl;

    std::cout 
        << "Value of pointer_to_null_01: " 
        << pointer_to_null_01 
        << " its address is: "
        << &pointer_to_null_01 
        << std::endl;

    std::cout 
        << "Value of pointer_to_null_02: " 
        << pointer_to_null_02 
        << " its address is: "
        << &pointer_to_null_02 
        << std::endl;

    std::cout 
        << "Value of pointer_to_null_03: " 
        << pointer_to_null_03 
        << " its address is: "
        << &pointer_to_null_03 
        << std::endl;

    std::cout 
        << "Value of pointer_to_null_04: " 
        << pointer_to_null_04 
        << " its address is: "
        << &pointer_to_null_04 
        << std::endl;

    std::cout 
        << "Value of pointer_to_null_05: " 
        << pointer_to_null_05 
        << " its address is: "
        << &pointer_to_null_05 
        << std::endl;
    


    std::cout << std::endl;
    std::cout << std::endl;
}


/*
    - Pointer to char:
        - syntax: 
            char c {'a'};            // Normal Variable initialized with a single char 'a'
            char *ch { nullptr };    // Intialize with nullptr
            ch = &c;                 // Now 'ch' pointer point to 'c' variable by its address
        - C-String Literals:
            - C-String Literals Means: 'const char *'.
            - We can point to a c-string literal by a pointer.
            - Notes:
                - C-String literals is just an Array of chars.
                    - ex:
                        char f_name[6] {'A', 'H', 'M', 'E', 'D', '\0'};    // '\0' is null terminated character
                        char l_name[] {"SALAMA"};    // using C-String Literals, automatically add null terminated by default
                - We can use pointer to refer to an Array of chars as C-String Literals
                    - ex:
                        char * full_name { "AHMED SALAMA" };
                    - Notes:
                        - This point it will refere to the first item, or the index 0 at this array of chars
                        - explaination:
                            char * full_name { "AHMED SALAMA" };
                            // full_name will refer to 'A'
*/

void pointer_to_array_of_chars()
{
    // Declare & Define with 'const' to avoid compiler warnings
    const char f_name[6] {'A', 'H', 'M', 'E', 'D', '\0'};
    const char l_name[] {"SALAMA"};
    
    // ISO C++: Forbids convertion from 'const char*' to 'char*'
    const char * full_name { "AHMED SALAMA" };

    std::cout << "Print First Name: "     << f_name << std::endl;
    std::cout << "Print Last Name: "      << l_name << std::endl;
    std::cout << "Print Full Name: "      << full_name << std::endl;
    
    std::cout  << std::endl;

    // Using (Deferencing): Will give you the first character only from the array
    /*
        const char * full_name {"AHMED SALAMA"}; // An Array OF Characters
        ------------------------------------------------------------
        |    Index    |    Value        |        Remarks           |
        ------------------------------------------------------------
        |    0        |    'A'          |        Char 'A'          |
        ------------------------------------------------------------
        |    1        |    'H'          |        Char 'H'          |
        ------------------------------------------------------------
        |    2        |    'M'          |        Char 'M'          |
        ------------------------------------------------------------
        |    3        |    'E'          |        Char 'E'          |
        ------------------------------------------------------------
        |    4        |    'D'          |        Char 'D'          |
        ------------------------------------------------------------
        |    5        |    ' '          |        Char ' '          |
        ------------------------------------------------------------
        |    6        |    'S'          |        Char 'S'          |
        ------------------------------------------------------------
        |    7        |    'A'          |        Char 'A'          |
        ------------------------------------------------------------
        |    8        |    'L'          |        Char 'L'          |
        ------------------------------------------------------------
        |    9        |    'A'          |        Char 'A'          |
        ------------------------------------------------------------
        |    10       |    'M'          |        Char 'M'          |
        ------------------------------------------------------------
        |    11       |    'A'          |        Char 'A'          |
        ------------------------------------------------------------
        |    12       |    '\0'         |        Null Terminated   |
        ------------------------------------------------------------

        *full_name = full_name[0];    // Index(0)
        
    */
    std::cout << "Print *full_name[0]:   "      << *full_name      << std::endl;
    std::cout << "Print  full_name[1]:   "      << full_name[1]    << std::endl;
    std::cout << "Print  full_name[2]:   "      << full_name[2]    << std::endl;
    std::cout << "Print  full_name[3]:   "      << full_name[3]    << std::endl;
    std::cout << "Print  full_name[4]:   "      << full_name[4]    << std::endl;
    std::cout << "Print  full_name[5]:   "      << full_name[5]    << std::endl;
    std::cout << "Print  full_name[6]:   "      << full_name[6]    << std::endl;
    std::cout << "Print  full_name[7]:   "      << full_name[7]    << std::endl;
    std::cout << "Print  full_name[8]:   "      << full_name[8]    << std::endl;
    std::cout << "Print  full_name[9]:   "      << full_name[9]    << std::endl;
    std::cout << "Print  full_name[10]:  "      << full_name[10]   << std::endl;
    std::cout << "Print  full_name[11]:  "      << full_name[11]   << std::endl;
    std::cout << "Print  full_name[12]:  "      << full_name[12]   << std::endl;
}

/*
    - Arrays of pointer to chars (Array of Pointers to Strings):
        - An array of pointers to strings is an array of character pointers where each pointer points to the first character of the string or the base address of the string
        - Advantages:
            - Unlink the two dimensional array of characters, in array of strings and in array of pointers to strings, there is no fixed memory size for storage.
            - The strings occupy only as many bytes as required hence, there is no wastage of space.
        - Explaination : 
            - https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/
        - Syntax:
            const char * todo_list []
            {
                "Study C++ Programming",                // todo_list[0]
                "Read The C++ Programming Book",        // todo_list[1]
                "Initiate C++ Project",                 // todo_list[2]
                "Read About Memory Management",         // todo_list[3]
                "Understand The Pointer In C++",        // todo_list[4]
                "Understand The Reference In C++",      // todo_list[5]
            };

            // todo_list[0] point to the first char of array of chars: 'S' ...
            // todo_list[1] point to the first char of array of chars: 'R' ...
            // todo_list[2] point to the first char of array of chars: 'I' ...
            // todo_list[3] point to the first char of array of chars: 'R' ...
            // todo_list[4] point to the first char of array of chars: 'U' ...
            // todo_list[5] point to the first char of array of chars: 'U' ...
        
*/

void arrays_of_pointer_to_chars()
{
    const char * todo_list []
    {
        "Study C++ Programming",
        "Read The C++ Programming Book",
        "Initiate C++ Project",
        "Read About Memory Management",
        "Understand The Pointer In C++",
        "Understand The Reference In C++",
    };

    for(uint32_t index {1}; auto item : todo_list)
    {
        std::cout << index << ") " << item << std::endl;
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
















































#endif









