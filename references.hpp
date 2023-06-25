#ifndef __REFERENCES_H
#define __REFERENCES_H

#include <iostream>
#include <iomanip>
#include <ios>
#include <array>
#include <new>


#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <climits>

#include <bitset>

using namespace std;


/*
    - References are Just Aliases:
        - Simple Meaning:
            - A reference in C++ is like a nickname or an alias for an existing variable.
            - It's another name that can be used to refer to the same value or object.
            - When you modify the reference, you are actually modifying the original variable. 
            - References are often used to avoid making copies of objects or to allow functions to modify variables directly.
        - Deep Meaning:
            - The deep meaning of references in C++ goes beyond just providing alternative names for variables. Here are some key aspects:
            - Object Identity: References allow you to create multiple names that refer to the same object in memory. They establish a relationship between the reference and the original object, providing a way to access and modify the object through different names.
            - Avoiding Copies: When you pass objects by value in C++, a copy of the object is made, which can be inefficient for large objects. By using references as function parameters, you can avoid this overhead. Changes made to the reference inside the function directly affect the original object.
            - Efficiency: References provide a way to work with large objects or complex data structures without incurring the memory and time costs of copying them. They allow you to pass objects to functions without duplicating the data, which can be especially important when dealing with performance-critical code.
            - Modifying Objects: References allow functions to modify the original object directly. This is particularly useful when you want a function to have the ability to change the state of an object passed to it as a parameter. By using references, you can avoid the need for returning values or using pointers explicitly.
            - Aliasing: References can be used to create aliases for variables, enabling you to work with multiple names for the same value. This can enhance code readability and expressiveness, as well as facilitate the use of complex data structures where different parts of the program need to refer to the same object.
            - Overall, references in C++ provide a powerful mechanism for efficient and flexible manipulation of objects, enabling you to work with complex data structures, avoid unnecessary copies, and directly modify objects. They contribute to the overall performance, clarity, and maintainability of your code.
        - Syntax:
            - type& ref_name { original_var };
        - Ex:
            int original_var { 100 };
            int& ref_to_original_var { original_var };            // Normal Reference
            const int& const_ref_to_original_var { original_var };      // Constant Reference
        - Notes:
            - Any changes made to 'ref_to_original_var' will be reflected in 'original_var' since they refer to the same memory location. 
            - Modifying 'ref_to_original_var' to 20 updates the value of 'original_var' accordingly.
            - References can be declared as const references, where the referenced object cannot be modified through the reference.
                - In this case, 'const_ref_to_original_var' is a constant reference to 'original_var', meaning that you can read the value of 'original_var' through constRef, but you cannot modify 'original_var' through 'const_ref_to_original_var'.
            - Remember that references in C++ are different from pointers. 
                - Once a reference is bound to an object, it behaves like an alias for that object, whereas pointers can be reassigned to point to different objects.

            - Comparison of references and pointers in C++:
            --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                    |            References                                                    |                Pointers
            --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            Declaration                 Must be initialized upon declaration                                        Can be declared without initialization
            Syntax                      type& referenceName = originalVariable;                                     type* pointerName = nullptr;
            Reassignment                Cannot be reassigned to refer to a different object                         Can be reassigned to point to different objects
            Nullability                 Cannot be null                                                              Can be set to null (nullptr) or point to valid objects
            Indirection                 Automatically dereferenced when accessing the referenced object	            Must be explicitly dereferenced using the * operator
            Address-of operator         Not applicable                                                              Uses the & operator to obtain the address of an object
            Arithmetic operations       Not applicable                                                              Supports arithmetic operations (pointer arithmetic)
            Function parameters         Can be used to pass arguments by reference                                  Can be used to pass arguments by value or reference
            Memory management           Automatically handled by the language                                       Requires manual memory allocation and deallocation
            Size                        Generally same size as the referenced object                                Generally same size as a pointer (4 or 8 bytes)
            Safety                      Provides more safety as they cannot be null or uninitialized                May have null or uninitialized values, potential for nullptr dereference or memory errors
            Use cases                   Preferred for aliasing, function parameters, avoiding copies                Used for dynamic memory allocation, passing by reference, or allowing null values
            --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            - Summary:
                -    It's important to note that both references and pointers have their own use cases and situations where they are more appropriate. 
                    References are commonly used for aliasing variables and passing parameters by reference, 
                    while pointers are often used for dynamic memory allocation, creating data structures, or allowing null values. 
                    Choosing between references and pointers depends on the specific requirements and design of your program.
*/





#endif









