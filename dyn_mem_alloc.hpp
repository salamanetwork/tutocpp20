#ifndef __DYNAMIC_MEMORY_ALLOCATION_H
#define __DYNAMIC_MEMORY_ALLOCATION_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <ctime>
#include <cstdlib>
#include <cstdint>

#include <bitset>

using namespace std;

/*
    - Difference Between Stack and Heap:
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Parameter	                      |                      STACK	                                      |                          HEAP                                 
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        - Basic	                               Memory is allocated in a contiguous block.                          Memory is allocated in any random order.
        - Allocation and De-allocation         Automatic by compiler instructions.                                 Manual by the programmer.
        - Cost	                               Less                                                                More
        - Implementation                       Easy                                                                Hard
        - Access time	                       Faster                                                              Slower
        - Main Issue	                       Shortage of memory                                                  Memory fragmentation
        - Locality of reference	               Excellent                                                           Adequate
        - Safety                               Thread safe, data stored can only be accessed by the owner          Not Thread safe, data stored visible to all threads
        - Flexibility	                       Fixed-size                                                          Resizing is possible
        - Data type structure	               Linear                                                              Hierarchical
        - Pr- eferred	                       Static memory allocation is preferred in an array.                  Heap memory allocation is preferred in the linked list.
        - Size	                               Small than heap memory.                                             Larger tha stack memory.
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------


    - Difference Between Static and Dynamic Memory Allocation in C:
    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    Static Memory Allocation                                                            	|                                               Dynamic Memory Allocation
    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In the static memory allocation, variables get allocated permanently,                             	|    In the Dynamic memory allocation, variables get allocated only if your program unit gets active.
      till the program executes or function call finishes.  
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                         
    - Static Memory Allocation is done before program execution.                                        	|    Dynamic Memory Allocation is done during program execution.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - It uses stack for managing the static allocation of memory.                                       	|    It uses heap for managing the dynamic allocation of memory
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - It is less efficient	                                                                            	|    It is more efficient
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In Static Memory Allocation, there is no memory re-usability	                                    	|    In Dynamic Memory Allocation, there is memory re-usability and memory can be freed when not required
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In static memory allocation, once the memory is allocated, 	                                    	|    In dynamic memory allocation, when memory is allocated the memory size can be changed.
      the memory size can not change. 
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------               
    - In this memory allocation scheme, we cannot reuse the unused memory.	                            	|    This allows reusing the memory. The user can allocate more memory when required. 
                                                                                                             		Also, the user can release the memory when the user needs it.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this memory allocation scheme, execution is faster than dynamic memory allocation.	            	|    In this memory allocation scheme, execution is slower than static memory allocation.  
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this memory is allocated at compile time.	                                                    	|    In this memory is allocated at run time.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this allocated memory remains from start to end of the program.	                            	|    In this allocated memory can be released at any time during the program.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - This static memory allocation is generally used for array.	                                    	|    This dynamic memory allocation is generally used for linked list.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*
    - Allocating the dynamic memory by using 'new' keyword:
        - Syntax:
            - Allocating:  ptr_name = new data_type; 
        - Ex:  
            int *ptr_name { nullptr };
            ptr_name = new int;    // Valid Memory Location: Allocating Space Dynamically On The Heap

            *ptr_name = 789;       // Valid Dereferencing: Writting to the allocated memory.
        - Notes:
            - Once you allcoated the pointer its belongs to the program.
            - The system can NOT use this block of memory for anything else.
            - Must defined by the same type of the pointer we pointing to.
    
    - Releasing And Resetting the dynamic memory by using 'delete' && 'nullptr' keyword:
        - Syntax:
            - Releasing: delete ptr_name;
            - Resetting: ptr_name = nullptr;
        - Ex:
            delete ptr_name;        // Valid Releasing: Delete Memory Location
            ptr_name = nullptr;     // Valid Resetting: Reset to NULL
        - Notes:
            - On Releasing: Means returning that deleted location to the system.
            - On Resetting: Means delete all data still remaining to secure that location for preventing memory leaks.

    - Intializing at the same time declaring the pointer:
        - Syntax:
            - Junk Memory Location:     int *ptr_name { new int };              // Valid
            - Direct Initialization:    int *ptr_name { new int (100) };        // Valid
            - Uniform Intialization:    int *ptr_name { new int {100} };        // Valid

    - IMPORTANT Guidelines:
        - Once you allocated the memory on the heap you can use anywhere.
        - Remember To Use 'new' for Allocating a new memory location.
        - Remember To Use the same data type you pointing to.
        - Remember To Use 'delete' Release the memory location.
        - Remember To Reset Using 'nullptr' to prevent data/memory Leaks.
        - Remember After You Releasing And Resetting We Can Not Use That Location Again.
        - Do NOT Initialize the pointer with 'nullptr'.
        - Do NOT use 'delete' many times on the same pointer.
    
*/

void dyn_mem()
{
    // Allocating
    int *ptr_00 { nullptr };            // Junk Value
    ptr_00 = new int;
    *ptr_00 = 789;                      // Writting to it.
    
    int *ptr_01 { new int }; 
    *ptr_01 = 123;
    
    int *ptr_02 { new int (100) };
    int *ptr_03 { new int {100} };

    std::cout 
        << "ptr_00 Address: "
        << ptr_00
        << "\tptr_00 Value: "
        << *ptr_00
        << "\t\tptr_00 Size: "
        << sizeof ptr_00 << " bytes."
        << std::endl;

    std::cout 
        << "ptr_01 Address: "
        << ptr_01
        << "\tptr_01 Value: "
        << *ptr_00
        << "\t\tptr_01 Size: "
        << sizeof ptr_01 << " bytes."
        << std::endl;

    std::cout 
        << "ptr_02 Address: "
        << ptr_02
        << "\tptr_02 Value: "
        << *ptr_02
        << "\t\tptr_02 Size: "
        << sizeof ptr_02 << " bytes."
        << std::endl;

    std::cout 
        << "ptr_03 Address: "
        << ptr_03
        << "\tptr_03 Value: "
        << *ptr_03
        << "\t\tptr_03 Size: "
        << sizeof ptr_03 << " bytes."
        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Releasing
    std::cout << "Releasing: " << std::endl;
    delete ptr_00;
    delete ptr_01;
    delete ptr_02;
    delete ptr_03;
    std::cout << "\tReleasing Done! " << std::endl;
    
    // Resetting
    std::cout << "Resetting: " << std::endl;
    ptr_00 = nullptr;
    ptr_01 = nullptr;
    ptr_02 = nullptr;
    ptr_03 = nullptr;
    std::cout << "\tResetting Done! " << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Maybe system will crash [Because we deleted & resetted the memory locations]
    // std::cout << ptr_00 << std::endl;    // Invalid Data
    // std::cout << ptr_01 << std::endl;    // Invalid Data
    // std::cout << ptr_02 << std::endl;    // Invalid Data
    // std::cout << ptr_03 << std::endl;    // Invalid Data

    // Outer scope
    {
        int *ptr_outer { new int {6009} };

        // Inner scope
        {
            int *ptr_inner { new int {7007} };

            std::cout 
                << "ptr_inner Address: "
                << ptr_inner
                << "\tptr_inner Value: "
                << *ptr_inner
                << "\t\tptr_inner Size: "
                << sizeof ptr_inner << " bytes."
                << std::endl;
        }

        std::cout 
            << "ptr_outer Address: "
            << ptr_outer
            << "\tptr_outer Value: "
            << *ptr_outer
            << "\t\tptr_outer Size: "
            << sizeof ptr_outer << " bytes."
            << std::endl;
    
        // std::cout // error: ‘ptr_inner’ was not declared in this scope; did you mean ‘ptr_outer’?
        //     << "ptr_inner Address: "
        //     << ptr_inner
        //     << "\tptr_inner Value: "
        //     << *ptr_inner
        //     << "\t\tptr_inner Size: "
        //     << sizeof ptr_inner << " bytes."
        //     << std::endl;
    }

    // std::cout // error: ‘ptr_outer’ was not declared in this scope
    //     << "ptr_outer Address: "
    //     << ptr_03
    //     << "\tptr_outer Value: "
    //     << *ptr_outer
    //     << "\t\tptr_outer Size: "
    //     << sizeof ptr_outer << " bytes."
    //     << std::endl;
    

    std::cout << std::endl;
    std::cout << std::endl;

    // Testing Valid Declarations & Definitions for Some Types:
    int             *test_ptr_int             { new int { 1000 } };
    float           *test_ptr_float           { new float { 4.5f } };
    double          *test_ptr_double          { new double { 9.7 } };
    char            *test_ptr_char            { new char { 'c' } };
    bool            *test_ptr_bool            { new bool { false } };
    long            *test_ptr_long            { new long { 7863487L }};
    long long       *test_ptr_long_long       { new long long { 7863487L }};
    short           *test_ptr_short           { new short { 128 } };
    unsigned        *test_ptr_unsigned        { new unsigned { 55 } };
    signed          *test_ptr_signed          { new signed { -55 } };
    std::string     *test_ptr_string          { new std::string { "String" } };

    // We Can NOT Using 'void'
    // void            *test_ptr_void            { new void { void } };

    // Releasing
    delete test_ptr_int;       
    delete test_ptr_float;     
    delete test_ptr_double;    
    delete test_ptr_char;      
    delete test_ptr_bool;      
    delete test_ptr_long;      
    delete test_ptr_long_long; 
    delete test_ptr_short;     
    delete test_ptr_unsigned;  
    delete test_ptr_signed;    
    delete test_ptr_string;

    // Resetting
    test_ptr_int           = nullptr;
    test_ptr_float         = nullptr;
    test_ptr_double        = nullptr;
    test_ptr_char          = nullptr;
    test_ptr_bool          = nullptr;
    test_ptr_long          = nullptr;
    test_ptr_long_long     = nullptr;
    test_ptr_short         = nullptr;
    test_ptr_unsigned      = nullptr;
    test_ptr_signed        = nullptr;
    test_ptr_string        = nullptr;
    
    
    
}












#endif









