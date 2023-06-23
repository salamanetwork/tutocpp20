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


/*
    - Const Pointer and Pointer to Const:
        - 01) Non 'const' pointer:
            - We can change the value of the variable we point to at any time.
            - We can refer to another variable at any time.
            - Notes:
                - Non const pointer should refer to another non const variable.
            - Syntax:
                type * var_name { &another_var_name_to_point_to };
            - ex:
                int var {300};
                int *ptr_var { &var };    // We Can Modify At Any Time.
                
        - 02) Pointer to 'const'
            - We can not modify the variable that we point to through this pointer
            - We can refer to another variables' address
            - Apply 'const' keyword to a variable name
            - Notes:
                - We can refer to non 'const' variable
            - Syntax:
                const type * var_name { &another_var_name_to_point_to };
            - ex:
                int var {300};
                const int *ptr_var { &var };    // We Can Not Modify At Any Time.
        
        - 03) Const Pointer (Opposite to case (02)):
            - We can not refer to another variables' address
            - Apply 'const' keyword to a variable data
            - Notes:
                - We can refer to non 'const' variable
            - Syntax:
                type * const var_name { &another_var_name_to_point_to };
            - ex:
                int var1 {300};
                int var1 {700};
                int * const ptr_var { &var1 };    // We Can Not Point To Somewhere Else At Any Time.
       
        - 04) Const Pointer to Pointer to Const (Opposite to Case (01)):
            - We can not refer to another variables' address
            - We can not modify a variables' value
            - Apply 'const' keyword to a variable name & variable data
            - Notes:
                - We can refer to non 'const' variable
            - Syntax:
                const type * const var_name { &another_var_name_to_point_to };
            - ex:
                int var1 {300};
                int var1 {700};
                const int * const ptr_var { &var1 };    // We Can Not Point To Somewhere Else, And Change The Value At Any Time.
            
        - #### SUMMARY ####
            --------------------------------------------------------------------------------------------------------------------------------------------------------------
            |                Case                        |    Can Modifying Address    |    Can Modifying Value  |                          Syntax                       |
            --------------------------------------------------------------------------------------------------------------------------------------------------------------
            |    01) Non const pointer                   |            Yes              |            No           |  type * ptr_name { &the_address_of_var };             |
            --------------------------------------------------------------------------------------------------------------------------------------------------------------
            |    02) Pointer to Const                    |            Yes              |            No           |  type * const ptr_name { &the_address_of_var };       |
            --------------------------------------------------------------------------------------------------------------------------------------------------------------
            |    3) Const Pointer                        |            No               |            Ye           |  const type * ptr_name { &the_address_of_var };       |
            --------------------------------------------------------------------------------------------------------------------------------------------------------------
            |    4) Const Pointer to Pointer to Const    |            No               |            No           |  const type * const ptr_name { &the_address_of_var }; | 
            --------------------------------------------------------------------------------------------------------------------------------------------------------------

            - Samples:
                int var_01 { 79 };                           // Normal Variable    
                int var_02 { 80 };                           // Normal Variable
                
                int * ptr_var_01 { &var_01 };                // Non Const Poiner [Refer to Another: Yes    Modify the Value: Yes]
                const int * ptr_var_02 { &var_01 };          // Const Pointer [Refer to Another: Yes    Modify the Value: No]
                int * const ptr_var_03 { &var_02 };          // Pointer To Const  [Refer to Another: No    Modify the Value: Yes]
                const int * const ptr_var_04 { &var_02 };    // Const Pointer to Pointer to Const  [Refer to Another: No    Modify the Value: No]               
                
            - Notes:
                - If 'const' keyword shows up on the left of  * : The Data Is Const. 
                - If 'const' keyword shows up on the right of * : The Pointer Is Const. 
*/

void const_pointer_and_pointer_to_const()
{
    // 01) Non 'const' pointer
        // Allow Modifyng The Address That Pointer Referring To.
        // Allow Modifyng The Value Of That Variable That Pointer Referring To.
    
    int var_01 { 300 };    // initialized with 300
    int var_02;            // initialized with 0
    
    int *ptr_var { &var_01 };    // We Can Modify At Any Time.

    std::cout << std::endl;
       
    std::cout << "01) Non 'const' pointer: "     << std::endl;
    
    std::cout << "Before MOdifing: "     << std::endl;
    
    std::cout << "\tvar_01 value: "      << var_01      << std::endl;
    std::cout << "\tvar_01 address: "    << &var_01     << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "\tvar_02 value: "     << var_02       << std::endl;
    std::cout << "\tvar_02 address: "   << &var_02       << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var value: "     << ptr_var       << std::endl;
    std::cout << "\tptr_var address: "   << &ptr_var       << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "After MOdifing: "     << std::endl;

    *ptr_var = 500;        // Changing the value of var_01
    
    std::cout << "\tvar_01 value: "      << var_01      << std::endl;
    std::cout << "\tvar_01 address: "    << &var_01     << std::endl;
    
    std::cout << std::endl;

    ptr_var = &var_02;     // Changing the address that ptr_var refer to

    *ptr_var = 8978914;    // Changing the value of var_02
    
    std::cout << "\tvar_02 value: "     << var_02       << std::endl;
    std::cout << "\tvar_02 address: "   << &var_02       << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var value: "     << ptr_var       << std::endl;
    std::cout << "\tptr_var address: "   << &ptr_var       << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;

    // 02) Pointer to const:
        // We can refer to another variable address
        // Disallow Modifyng The Value Of That Variable That Pointer Referring To.

    int var_03 { 8000 };

    // Declare & Define Pointer to const
    const int * ptr_var_01 { &var_03 };    // We can not modify later

    std::cout << std::endl;

    std::cout << "02) Pointer to const: "     << std::endl;
    
    std::cout << "Before MOdifing: "     << std::endl;
    
    std::cout << "\tvar_03 value: "      << var_03      << std::endl;
    std::cout << "\tvar_03 address: "    << &var_03     << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var_01 value: "     << ptr_var_01       << std::endl;
    std::cout << "\tptr_var_01 address: "   << &ptr_var_01      << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "After MOdifing: "     << std::endl;
    
    // Error: assignment of read-only location ‘* ptr_var_01’
    // *ptr_var_01 = 99999999;    
    
    std::cout << "\tvar_03 value: "      << var_03      << std::endl;
    std::cout << "\tvar_03 address: "    << &var_03     << std::endl;

    std::cout << std::endl;

    // We can refer to another variable address
    ptr_var_01 = &var_01;
    
    std::cout << "\tptr_var_01 value: "     << ptr_var_01       << std::endl;
    std::cout << "\tptr_var_01 address: "   << &ptr_var_01      << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // 03) Const pointer: 
        // Disallow Modifyng The Address That Pointer Referring To.
        // Allow Modifyng The Value Of That Variable That Pointer Referring To.
        // We can NOT refer to another variable address
    
    int var_04 { 120000 };
    int var_05 { 900000 };

    // Declare & Define Pointer to const
    int * const  ptr_var_04 { &var_04 };    // We can not refere to another address later

    std::cout << std::endl;

    std::cout << "03) Const pointer: "     << std::endl;
    
    std::cout << "Before MOdifing: "     << std::endl;
    
    std::cout << "\tvar_04 value: "      << var_04      << std::endl;
    std::cout << "\tvar_04 address: "    << &var_04     << std::endl;
    
    std::cout << std::endl;

    std::cout << "\tvar_05 value: "      << var_05      << std::endl;
    std::cout << "\tvar_05 address: "    << &var_05     << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var_04 value: "     << ptr_var_04       << std::endl;
    std::cout << "\tptr_var_04 address: "   << &ptr_var_04      << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "After MOdifing: "     << std::endl;
    
    // Modifying the value of var_04    -> pass
    *ptr_var_04 = 99999999;
    
     // Modifying the value of var_04 to equal to the value of var_05   -> pass
    *ptr_var_04 = var_05;
    
    std::cout << "\tvar_04 value: "      << var_04      << std::endl;
    std::cout << "\tvar_04 address: "    << &var_04     << std::endl;

    std::cout << std::endl;

    // Error: assignment of read-only variable ‘ptr_var_04’
    // ptr_var_04 = &var_05;


    std::cout << "\tvar_05 value: "      << var_05      << std::endl;
    std::cout << "\tvar_05 address: "    << &var_05     << std::endl;

    std::cout << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var_04 value: "     << ptr_var_04       << std::endl;
    std::cout << "\tptr_var_04 address: "   << &ptr_var_04      << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // 04) Const Pointer to Pointer to Const
        // Disallow Modifyng The Address That Pointer Referring To.
        // Disallow Modifyng The Value Of That Variable That Pointer Referring To.
    
    int var_06 { 300 };            // initialized with 300
    int var_07 { 700 };            // initialized with 0
    
    const int * const ptr_var_06 { &var_06 };    // We Can NOT Modify At Any Time.

    std::cout << std::endl;
       
    std::cout << "04) Pointer To Const To Const Pointer: "     << std::endl;
    
    std::cout << "Before MOdifing: "     << std::endl;
    
    std::cout << "\tvar_06 value: "      << var_06      << std::endl;
    std::cout << "\tvar_06 address: "    << &var_06     << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "\tvar_07 value: "     << var_07       << std::endl;
    std::cout << "\tvar_07 address: "   << &var_07       << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var_06 value: "     << ptr_var_06       << std::endl;
    std::cout << "\tptr_var_06 address: "   << &ptr_var_06       << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "After MOdifing: "     << std::endl;

    // error: assignment of read-only location ‘*(const int*)ptr_var_06’
    // *ptr_var_06 = 500;        // Changing the value of var_06
    
    std::cout << "\tvar_06 value: "      << var_06      << std::endl;
    std::cout << "\tvar_06 address: "    << &var_06     << std::endl;
    
    std::cout << std::endl;

    //  error: assignment of read-only variable ‘ptr_var_06’
    // ptr_var_06 = &var_07;     // Changing the address that ptr_var_06 refer to  --> Fail

    // error: assignment of read-only location ‘*(const int*)ptr_var_06’
    // *ptr_var_06 = 8978914;    // Changing the value of var_07 --> Fail
    
    std::cout << "\tvar_07 value: "     << var_07       << std::endl;
    std::cout << "\tvar_07 address: "   << &var_07       << std::endl;

    std::cout << std::endl;
    
    std::cout << "\tptr_var_06 value: "     << ptr_var_06      << std::endl;
    std::cout << "\tptr_var_06 address: "   << &ptr_var_06       << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
}


/*
    - Array of const pointer to const char:
        - We can not change the value of the array.
        - We can change to point to another const char.        
*/

void array_of_const_pointer_to_const_char()
{
    // To Prevent Modifyin The Data
    // const char * const todo_list_can_edited []    // Disable Modifying the data
    const char * todo_list_can_edited []             // Enable Modifying the data
    {
        "Study C++ Programming",
        "Read The C++ Programming Book",
        "Initiate C++ Project",
        "Read About Memory Management",
        "Understand The Pointer In C++",
        "Understand The Reference In C++",
    };

    // Before Moifying
    std::cout << "After Modifying: " << std::endl;
    for(uint32_t index {1}; auto item : todo_list_can_edited)
    {
        std::cout << index << ") " << item << std::endl;
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Not Allowed To Change To The First Character
    // error: assignment of read-only location ‘* todo_list_can_edited[1]’
    // *todo_list_can_edited[1] = 'S';    // compiler-error

    // Allow to point to another const char array
    const char * replaced_item {"Study The Pointers Well In C/C++."};
    todo_list_can_edited[1] = replaced_item;

    // After Modifying
    std::cout << "After Modifying: " << std::endl;
    for(uint32_t index {1}; auto item : todo_list_can_edited)
    {
        std::cout << index << ") " << item << std::endl;
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
}


/*
    - Pointer and Array
        - Array: is a special pointer has all info about the array and its value.
        - Pointer: is a placeholder for an address that points to another container.
        - Notes:
            - We can not use An Array to refer to another container.
            - We use on A Pointer to refer to any kind of container, vars, arrays ...
            
*/

void arrays_and_pointers()
{
    int levels [15] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int * ptr_levels { nullptr };

    int * ptr_some_level { nullptr };

    // Assign An Array to A Pointer
    ptr_levels = levels;

    // Printing out
    std::cout  << &ptr_levels    << " The Address of ptr_levels. " << std::endl;
    std::cout  << ptr_levels     << " The Value of ptr_levels. "   << std::endl;

    std::cout << std::endl;
    
    std::cout  << &levels        << " The Address of levels. "     << std::endl;
    std::cout  << levels         << " The Value of levels. "       << std::endl;

    std::cout << std::endl;
    
    std::cout  << levels[0]   << " The Actual Value of levels. "      << std::endl;
    std::cout  << *ptr_levels << " The Actual Value of ptr_levels. "  << std::endl;

    // error: incompatible types in assignment of ‘int*’ to ‘int [15]’
    // levels = ptr_some_level;    // Can NOT assign ptr to an array
    
    std::cout << std::endl;
    std::cout << std::endl;
}

/*
    - Demo [Swapping Arrays' Data]:
*/

void demo_swapping_arrays_data()
{
    int arr_01 [5] {1, 2, 3, 4, 5}, arr_02 [5] {6, 7, 8, 9, 10};

    // std::cout << "Array Size (arr_01): " << std::size(arr_01) << std::endl;
    // std::cout << "Array Size (arr_02): " << std::size(arr_02) << std::endl;

    std::cout << "Before Swapping:-----------------------" << std::endl;
    
    std::cout << "(arr_01): " << std::endl;
    for(auto index {0}; auto item : arr_01)
    {
        std::cout << item << " ";
        ++index;
    }

    std::cout << std::endl;
                    
    std::cout << "(arr_02): " << std::endl;
    for(auto index {0}; auto item : arr_02)
    {
        std::cout << item << " ";
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    // The Hard Way:
    std::cout << "After Swapping:--------[The Hard Way]--------" << std::endl;
    int temp_arr[std::size(arr_01)];

    // 01) First Step: Move data from arr_01 to temp_arr
    for(size_t i {0}; i < std::size(arr_01); ++i)
        temp_arr[i] = arr_01[i];

    // 02) Second Step: Move data from arr_01 to arr_02
    for(size_t i {0}; i < std::size(arr_01); ++i)
        arr_01[i] = arr_02[i];

    // 03) Third Step: Move data from temp_arr to arr_02
    for(size_t i {0}; i < std::size(arr_01); ++i)
        arr_02[i] = temp_arr[i];

    std::cout << "(arr_01): " << std::endl;
    for(auto index {0}; auto item : arr_01)
    {
        std::cout << item << " ";
        ++index;
    }

    std::cout << std::endl;
                    
    std::cout << "(arr_02): " << std::endl;
    for(auto index {0}; auto item : arr_02)
    {
        std::cout << item << " ";
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    // The Easy Way:
    std::cout << "After Swapping:--------[The Easy Way]--------" << std::endl;

    // Using pointers
    int * ptr_arr_01 { arr_01 };    // Pointer to arr_01
    int * ptr_arr_02 { arr_02 };    // Pointer to arr_02
    int * ptr_temp_arr;             // Pointer to temp_arr

    // 01) First Step: Move data from arr_01 to temp_arr
    ptr_temp_arr = ptr_arr_01;
    
    // 02) Second Step: Move data from arr_01 to arr_02
    ptr_arr_01 = ptr_arr_02;
    
    // 03) Third Step: Move data from temp_arr to arr_02
    ptr_arr_02 = ptr_temp_arr;

    std::cout << "(arr_01): " << std::endl;
    for(auto index {0}; auto item : arr_01)
    {
        std::cout << item << " ";
        ++index;
    }

    std::cout << std::endl;
                    
    std::cout << "(arr_02): " << std::endl;
    for(auto index {0}; auto item : arr_02)
    {
        std::cout << item << " ";
        ++index;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
}

/*
    - Pointer Arithmetic:
        - A series of operation applying to pointer.
        - Operations:
            - Navigation:
                - Incrementing / Decrementing:
                    - Moving the pointer address by the size of the data type pointed to by the pointer.
                - Modifying the elements by the pointer
                    - *(ptr + index_number) = new_value;
                        - Equivalent to: array[index_number] = new_value;
                    - ex:
                        *(nums_ptr + 1) = 202;    // nums[1] = 202;
                        *(nums_ptr + 2) = 303;    // nums[2] = 303;
*/

void pointer_arithm()
{
    // intialize the array with value
    int nums [] {10, 20, 30 , 40, 50, 60, 70, 80, 90, 100};

    // assign to the pointer
    int *nums_ptr { nullptr };

    std::cout << "Printing Out The Address && Value Of Each Nums: " << std::endl;
    
    for(int *nums_ptr { nums }; auto num : nums)
    {
        std::cout
            << "\t\tAddress: " << nums_ptr
            << "\t\tValue:  " << *nums_ptr
            << std::endl;
        ++nums_ptr;            // Incrementing by the size of the data type: int = 4 => [next = current_index + 4]

        // OR Using Explicit Addition: Move forward by = 4 * sizeof(int)
        // *(nums_ptr + 4);
        
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Printing the array in reverse order
    std::cout << "Printing Out The Address && Value Of Each Nums In Reverse Order: " << std::endl;

    // nums_ptr = current_index(as nums) + (sizeof(data_type) - reduced_by_one)
    // nums_ptr = 0  + (5 - 1) => 4        [At Index: 0]
    // nums_ptr = 4  + (5 - 1) => 8        [At Index: 1]
    // nums_ptr = 8  + (5 - 1) => 12       [At Index: 2]
    // nums_ptr = 12 + (5 - 1) => 16       [At Index: 3]
    // nums_ptr = 16 + (5 - 1) => 20       [At Index: 4]
    // Why Reduced By One: Because already current index referring to the first item in the array means [nums] = first item.
    nums_ptr = nums + (std::size(nums) - 1);

    // We Can Using foor loop with initializer 
    // OR: for(auto nums_ptr { nums + (std::size(nums) - 1) }; auto num : nums)
    for(size_t i { std::size(nums) }; i > 0; --i)
    {
        std::cout
            << "\t\tAddress: " << nums_ptr
            << "\t\tValue:  " << *nums_ptr--
            << std::endl;
        
    }


    std::cout << std::endl;
    std::cout << std::endl;
    
}

/*
    - Distance between elements (Subtarcting Pointers):
        - Another way to represent the arrays' index 
        - Using std::ptrdiff_t -> A type for storing a pointer differences
            - Better to avoid platform issues 
            - Ex:
                std::ptrdiff_t pos_diff_ptrs = ptr2 - ptr1;    // Positive
                std::ptrdiff_t neg_diff_ptrs = ptr1 - ptr2;    // Negative
*/

void dist_pointers()
{
    int teams[] { 3784, 7468, 6789, 2763, 4785 };

    // 001) Array Index Notation
    // int * teams_ptr_00 { &teams[0] };
    // int * teams_ptr_01 { &teams[1] };
    // int * teams_ptr_02 { &teams[2] };
    // int * teams_ptr_03 { &teams[3] };
    // int * teams_ptr_04 { &teams[4] };

    // 002) Pointer Arithmetic Notation - Same As (001) Above
    int * teams_ptr_00 { teams + 0 };
    int * teams_ptr_01 { teams + 1 };
    int * teams_ptr_02 { teams + 2 };
    int * teams_ptr_03 { teams + 3 };
    int * teams_ptr_04 { teams + 4 };

    std::cout 
        << "teams_ptr_00 Address:\t" <<  teams_ptr_00
        << "\t\t\tteams_ptr_00 Value:\t" <<  *teams_ptr_00
        << std::endl;
    std::cout 
        << "teams_ptr_01 Address:\t" <<  teams_ptr_01
        << "\t\t\tteams_ptr_01 Value:\t" <<  *teams_ptr_01
        << std::endl;
    std::cout 
        << "teams_ptr_02 Address:\t" <<  teams_ptr_02
        << "\t\t\tteams_ptr_02 Value:\t" <<  *teams_ptr_02
        << std::endl;
    std::cout 
        << "teams_ptr_03 Address:\t" <<  teams_ptr_03
        << "\t\t\tteams_ptr_03 Value:\t" <<  *teams_ptr_03
        << std::endl;
    std::cout 
        << "teams_ptr_04 Address:\t" <<  teams_ptr_04
        << "\t\t\tteams_ptr_04 Value:\t" <<  *teams_ptr_04
        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Distance between pointers: " << std::endl;

    std::cout 
        << "teams_ptr_04 - teams_ptr_03 =\t"
        << teams_ptr_04 - teams_ptr_03 << " Byte"
        << std::endl;
    std::cout 
        << "teams_ptr_03 - teams_ptr_02 =\t"
        << teams_ptr_03 - teams_ptr_02 << " Byte"
        << std::endl;
    std::cout 
        << "teams_ptr_02 - teams_ptr_01 =\t"
        << teams_ptr_02 - teams_ptr_01 << " Byte"
        << std::endl;
    std::cout 
        << "teams_ptr_01 - teams_ptr_00 =\t"
        << teams_ptr_01 - teams_ptr_00 << " Byte"
        << std::endl;

    // Using long distance (Positive, Negative)
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Long Distance between pointers: " << std::endl;
    std::cout 
        << "teams_ptr_03 - teams_ptr_00 =\t"
        << teams_ptr_03 - teams_ptr_00 << " Byte"
        << std::endl;
    std::cout 
        << "teams_ptr_01 - teams_ptr_04 =\t"
        << teams_ptr_03 - teams_ptr_00 << " Byte"
        << std::endl;
    std::cout 
        << "teams_ptr_02 - teams_ptr_04 =\t"
        << teams_ptr_02 - teams_ptr_04 << " Byte" << "  Giving Negative!Reverse Way"
        << std::endl;

    // Using std::ptrdiff_t
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Using Pointer difference type std::ptrdiff_t: " << std::endl;

    std::ptrdiff_t pos_teams_ptr = teams_ptr_02 - teams_ptr_01;    // Positive
    std::ptrdiff_t neg_teams_ptr = teams_ptr_01 - teams_ptr_04;    // Negative

    std::cout 
        << "std::ptrdiff_t pos_teams_ptr:\t"
        << pos_teams_ptr << " Byte"
        << std::endl;
    std::cout 
        << "std::ptrdiff_t neg_teams_ptr:\t"
        << neg_teams_ptr << " Byte"
        << std::endl;
    std::cout 
        << "std::ptrdiff_t size:\t"
        << sizeof(std::ptrdiff_t) << " Byte"
        << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    
}


/*
    - Comparing Pointers
        - We can use normal symbols for comparing:
        - Symbols: >, <, >=, <=, ==, !=,
        - Rule:
            - The Farther we go in with in the array, the bigger the address.
*/

void compr_ptrs()
{
    int teams[] { 3784, 7468, 6789, 2763, 4785 };

    // Pointer Arithmetic Notation
    int * teams_ptr_00 { teams + 0 };
    int * teams_ptr_01 { teams + 1 };
    int * teams_ptr_02 { teams + 2 };
    int * teams_ptr_03 { teams + 3 };
    int * teams_ptr_04 { teams + 4 };

    std::cout << "Comparing Pointers: " << std::endl;

    std::cout << std::uppercase << std::boolalpha;
    
    std::cout
        << "teams_ptr_00 > teams_ptr_02:\t" 
        <<  (teams_ptr_00 > teams_ptr_02)
        << std::endl;
    std::cout 
        << "teams_ptr_01 < teams_ptr_03:\t" 
        <<  (teams_ptr_01 < teams_ptr_03)
        << std::endl;
    
    std::cout 
        << "teams_ptr_00 == teams_ptr_04:\t" 
        <<  (teams_ptr_00 > teams_ptr_04)
        << std::endl;
    std::cout 
        << "teams_ptr_02 >= teams_ptr_02:\t" 
        <<  (teams_ptr_02 >= teams_ptr_02)
        << std::endl;
    std::cout 
        << "teams_ptr_04 <= teams_ptr_03:\t" 
        <<  (teams_ptr_04 <= teams_ptr_03)
        << std::endl;
    std::cout 
        << "teams_ptr_03 != teams_ptr_03:\t" 
        <<  (teams_ptr_03 != teams_ptr_03)
        << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
}    



















































#endif









