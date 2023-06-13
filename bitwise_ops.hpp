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

/*
    - Bitwise shift operators:
        - Bit shifting is only supported for integral types like int, char,...
        - If data is lost as a result of you shifting bits left(<<) or right(>>), you can’t get the data back just by doing the reverse operation. 
        - You’ve just lost the data permanently!
        - The Rules of bit shifting:
            - Shifting To Right Divides by (2^n)
            - Shifting To Left multiplies by (2^n)
            - The Rule breaks if you throw off 1's either to the right or the left
*/
void shift_ops()
{
    unsigned short int value (0x157c);  // 5500
    
    std::cout << "Original Value is: " << value << std::endl;
    std::cout << "Original Value as a bitset is: " << std::bitset<16>(value) << std::endl;
    
    std::cout << std::endl;
    
    // Using shift ops
    
    // using implicit cast for value by auto
    auto val = (value >> 1);
    
    // using explicit cast for value by static_cast
    // 001)
    // = 2750 after shift to the right 1 pos
    // value = static_cast<unsigned short int>(value >> 1);    // Shift 1 pos to the right.
    
    // std::cout << "Original Value After Shift 1 position to the right is: " << value << std::endl;
    // std::cout << "Original Value After Shift 1 position to the right using bitset representation is: " << std::bitset<16>(value) << std::endl;
    
    // 002)
    // = 11000 after shift to the left 1 pos
    // value = static_cast<unsigned short int>(value << 1);    // Shift 1 pos to the left.
    
    // std::cout << "Original Value After Shift 1 position to the left is: " << value << std::endl;
    // std::cout << "Original Value After Shift 1 position to the left using bitset representation is: " << std::bitset<16>(value) << std::endl;
    
    
    // 003)
    // = 44000 after shift to the left 3 pos
    value = static_cast<unsigned short int>(value << 3);    // Shift 3 pos to the left.
    
    std::cout << "Original Value After Shift 3 position to the left is: " << value << std::endl;
    std::cout << "Original Value After Shift 3 position to the left using bitset representation is: " << std::bitset<16>(value) << std::endl;
 
}


/*
    - Logical Bitwise operators:
        - (&) AND, (|) OR, (~) NOT, (^) XOR
        - Table of truth:
            --------------------------------------------------
            (a) |   (b) |   (a&b)   |  (a|b) |  (~a) |   (a^b)
            --------------------------------------------------
            0       0        0          0         1       0
            0       1        0          1         1       1
            1       0        0          1         0       1
            1       1        1          1         0       0
            --------------------------------------------------
*/
void logical_bitwise_ops()
{
    constexpr int WIDTH(20);
    
    unsigned char ch01 {0x6};   // 0000 0110
    unsigned char ch02 {0x9};   // 0000 1001
    
    std::cout << "Original Values:" << std::endl;
    
    std::cout 
        << std::setw(WIDTH)
        << "ch01 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch01)
        << std::endl;
        
    std::cout 
        << std::setw(WIDTH)
        << "ch02 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch02)
        << std::endl;
    
    std::cout << std::endl;
    
    // Using logical bitwise ops:
    
    std::cout << "Bitwise (&) AND:" << std::endl;
    // 001) (&) AND
    std::cout 
        << std::setw(WIDTH)
        << "ch01 & ch02 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch01 & ch02)
        << std::endl;
        
    std::cout << std::endl;
    std::cout << "Bitwise (|) OR:" << std::endl;        
    // 002) (|) OR
    std::cout 
        << std::setw(WIDTH)
        << "ch01 | ch02 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch01 | ch02)
        << std::endl;
    
    std::cout << std::endl;
    std::cout << "Bitwise (~) NOT:" << std::endl;        
    // 003) (~) NOT
    std::cout 
        << std::setw(WIDTH)
        << "~ch01 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(~ch01)
        << std::endl;
    
    std::cout 
        << std::setw(WIDTH)
        << "~ch02 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(~ch02)
        << std::endl;
        
        // Using bin literal
        std::cout 
            << std::setw(WIDTH)
            << "~0b10101101 is: "
            << std::setw(WIDTH)
            << std::bitset<8>(~0b10101101)
            << std::endl;
            
        // Using hex literal
        std::cout 
            << std::setw(WIDTH)
            << "~0xAD is: "
            << std::setw(WIDTH)
            << std::bitset<8>(~0xAD)
            << std::endl;
    
    std::cout << std::endl;
    std::cout << "Bitwise (^) XOR :" << std::endl;
    // 004) (^) XOR
    std::cout 
        << std::setw(WIDTH)
        << "ch01 ^ ch02 is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch01 ^ ch02)
        << std::endl;
}



#endif














