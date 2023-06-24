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
    Parameter	                      |                      STACK	                                      |                          HEAP                                    |
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - Basic	                          |     Memory is allocated in a contiguous block.	                  |     Memory is allocated in any random order.
    - Allocation and De-allocation    |     Automatic by compiler instructions.	                          |     Manual by the programmer.
    - Cost	                          |     Less	                                                      |     More
    - Implementation	              |     Easy	                                                      |     Hard
    - Access time	                  |     Faster	                                                      |     Slower
    - Main Issue	                  |     Shortage of memory	                                          |     Memory fragmentation
    - Locality of reference	          |     Excellent	                                                  |     Adequate
    - Safety	                      |     Thread safe, data stored can only be accessed by the owner	  |     Not Thread safe, data stored visible to all threads
    - Flexibility	                  |     Fixed-size	                                                  |     Resizing is possible
    - Data type structure	          |     Linear	                                                      |     Hierarchical
    - Pr- eferred	                  |     Static memory allocation is preferred in an array.	          |     Heap memory allocation is preferred in the linked list.
    - Size	                          |     Small than heap memory.	                                      |     Larger than stack memory.
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    - Difference Between Static and Dynamic Memory Allocation in C:
    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    Static Memory Allocation                                                            |                                               Dynamic Memory Allocation
    -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In the static memory allocation, variables get allocated permanently,                             |    In the Dynamic memory allocation, variables get allocated only if your program unit gets active.
      till the program executes or function call finishes.  
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                          
    - Static Memory Allocation is done before program execution.                                        |    Dynamic Memory Allocation is done during program execution.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - It uses stack for managing the static allocation of memory.                                       |    It uses heap for managing the dynamic allocation of memory
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - It is less efficient	                                                                            |    It is more efficient
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In Static Memory Allocation, there is no memory re-usability	                                    |    In Dynamic Memory Allocation, there is memory re-usability and memory can be freed when not required
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	- In static memory allocation, once the memory is allocated, 	                                    |    In dynamic memory allocation, when memory is allocated the memory size can be changed.
      the memory size can not change. 
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                 
    - In this memory allocation scheme, we cannot reuse the unused memory.	                            |    This allows reusing the memory. The user can allocate more memory when required. 
                                                                                                        |    Also, the user can release the memory when the user needs it.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this memory allocation scheme, execution is faster than dynamic memory allocation.	            |    In this memory allocation scheme, execution is slower than static memory allocation.  
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this memory is allocated at compile time.	                                                    |    In this memory is allocated at run time.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - In this allocated memory remains from start to end of the program.	                            |    In this allocated memory can be released at any time during the program.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    - This static memory allocation is generally used for array.	                                    |    This dynamic memory allocation is generally used for linked list.
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/













#endif









