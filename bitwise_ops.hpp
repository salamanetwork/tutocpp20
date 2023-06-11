#ifndef __BITWISE_OPS_H
#define __BITWISE_OPS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <bitset>

using namespace std;

/*
    - Bitwise operators:
        - Operators used in programming languages to perform operations at the bit level of binary numbers. 
        - They manipulate individual bits within a binary representation of data.
        - Manipulating individual bits in a bit vector or bit flags.
        - Performing efficient bitwise operations for specific algorithms or data structures.
        - Extracting or manipulating specific bit patterns within binary data.
        - Packing and unpacking data in memory-constrained environments.
        - Optimizing code for performance or memory usage.
        - These bitwise operators are often used in low-level programming languages like C, C++, and assembly language to work with individual bits, manipulate binary data, and perform optimizations in certain algorithms. 
        - They can be useful in tasks like bitwise masking, bit-level operations on flags and permissions, and efficient storage of data.
    
    
*/

void bitwise_ops()
{
    // Size of (unsigned short int) is: 2 bytes <==> 16 bits
    unsigned short int data { 0b10110010 }; 
    
    std::cout << "data in dec:  " << std::dec << data << std::endl;
    std::cout << "data in hex:  " << std::hex << std::showbase << std::uppercase << data << std::endl;
    
    /* 
    - Using std::bitset<base>(data) to represent the binary on the screen
    - (base): should be the Number of bits that (data) represents:
        - 2 bytes <==> 16 bits
        - 4 bytes <==> 32 bits
        - 8 bytes <==> 64 bits
    */
    std::cout << "data in bin:  " << std::bitset<16>(data) << std::endl;
    
    
    
}




#endif














