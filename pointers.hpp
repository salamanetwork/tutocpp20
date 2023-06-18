#ifndef __POINTERS_H
#define __POINTERS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <ctime>
#include <cstdlib>

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


























#endif









