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

/*
    - Compound Bitwith operators:
        - They work on the variable and put the result back in the same variable again.
        - (>>=) Shift To The Right With Assignment
        - (<<=) Shift To The Left With Assignment
        - (&=) AND To The Right With Assignment
        - (|=) OR With Assignment
        - (^=) XOR To The Right With Assignment
*/
void compound_bitwise_ops()
{
    constexpr int WIDTH(40);
    
    unsigned char ch = 0b10110010;  // 178
    
    std::cout << "Original Values:" << std::endl;
    
    std::cout 
        << std::setw(WIDTH)
        << "ch is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
     
    std::cout << std::endl; 
    
    // Using Compound Bitwith operators:
    
    // 001) (<<=) Compound Left Shift
    std::cout << "Bitwise Compound (<<=) Compound Left Shift:" << std::endl;
    ch <<= 2;
    std::cout 
        << std::setw(WIDTH)
        << "ch <<= 2 [Compound Left Shift] is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
        
    // 002) (>>=) Compound Right Shift 
    std::cout << std::endl;
    std::cout << "Bitwise Compound (>>=) Compound Right Shift:" << std::endl;
    ch >>= 2;
    std::cout 
        << std::setw(WIDTH)
        << "ch >>= 2 [Compound Right Shift] is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
        
    // 003) (&=) Compound & AND 
    std::cout << std::endl;
    std::cout << "Bitwise Compound (&=) Compound & AND:" << std::endl;
    ch &= 0b10101101;   // 173
    std::cout 
        << std::setw(WIDTH)
        << "ch &= 2 [Compound (&=) AND] is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
    
    // 004) (|=) Compound & OR 
    std::cout << std::endl;
    std::cout << "Bitwise Compound (|=) Compound | OR:" << std::endl;
    ch |= 0b10101101;   // 173
    std::cout 
        << std::setw(WIDTH)
        << "ch |= 2 [Compound (|=) OR] is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
        
    // 005) (^=) Compound & XOR 
    std::cout << std::endl;
    std::cout << "Bitwise Compound (^=) Compound | XOR:" << std::endl;
    ch ^= 0b10101101;   // 173
    std::cout 
        << std::setw(WIDTH)
        << "ch ^= 2 [Compound (^=) XOR] is: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl;
    
}

/*
    - Bit Masks (Shadow):
        - Operations:
            - Set bit position      (var |= mask)
            - Reset bit position    (var &= mask) OR (var &= ~(Reverse_mask))
            - Check bit position    ((var & mask) >> pos)
            - Toggle bit position   (var ^(mask))
*/
void bitwise_mask()
{
    const int WIDTH { 20 };
    
    // 8-bit = 1-byte 
    const unsigned char mask_bit_0 {0b00000001};    // Bit 0
    const unsigned char mask_bit_1 {0b00000010};    // Bit 1
    const unsigned char mask_bit_2 {0b00000100};    // Bit 2
    const unsigned char mask_bit_3 {0b00001000};    // Bit 3
    const unsigned char mask_bit_4 {0b00010000};    // Bit 4
    const unsigned char mask_bit_5 {0b00100000};    // Bit 5
    const unsigned char mask_bit_6 {0b01000000};    // Bit 6
    const unsigned char mask_bit_7 {0b10000000};    // Bit 7
    
    unsigned char ch { 0b00000000 }; // All bits starts as off
    
    std::cout << "Original Value of ch:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Set bits by: |= with mask of the bits
    // Targeting position 1 = bit 1 => mask_bit_1
    ch |= mask_bit_1;
    std::cout << "Value of ch after setting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Targeting position 5 = bit 5 => mask_bit_5
    ch |= mask_bit_5;
    std::cout << "Value of ch after setting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Targeting all positions 0-7 to set all
    ch |= 
    ( 
        mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
        mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7
    );
    std::cout << "Value of ch after setting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Reset bits by: &= with mask of the bits
    // Targeting position 1 = bit 1 => mask_bit_1
    ch &= ~mask_bit_1;
    std::cout << "Value of ch after resetting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Targeting position 5 = bit 5 => mask_bit_5
    ch &= ~mask_bit_5;
    std::cout << "Value of ch after resetting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
    
     // Targeting positions 0, 2, 4, 6 to reset them
    ch &= 
    ~( 
        mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6
    );
    std::cout << "Value of ch after resetting:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
    
    // Check bits by: (& mask) >> pos
    // Check the state of the bits
    std::cout << "Check the state of a bit is on/off" << std::endl;
    std::cout << "bit_0 is: " << ( ( ch & mask_bit_0 ) >> 0 ) << std::endl;
    std::cout << "bit_0 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_0 ) ) << std::endl;
    
    std::cout << "bit_1 is: " << ( ( ch & mask_bit_1 ) >> 1 ) << std::endl;
    std::cout << "bit_1 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_1 ) ) << std::endl;
    
    std::cout << "bit_2 is: " << ( ( ch & mask_bit_2 ) >> 2 ) << std::endl;
    std::cout << "bit_2 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_2 ) ) << std::endl;
    
    std::cout << "bit_3 is: " << ( ( ch & mask_bit_3 ) >> 3 ) << std::endl;
    std::cout << "bit_3 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_3 ) ) << std::endl;
    
    std::cout << "bit_4 is: " << ( ( ch & mask_bit_4 ) >> 4 ) << std::endl;
    std::cout << "bit_4 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_4 ) ) << std::endl;
    
    std::cout << "bit_5 is: " << ( ( ch & mask_bit_5 ) >> 5 ) << std::endl;
    std::cout << "bit_5 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_5 ) ) << std::endl;
    
    std::cout << "bit_6 is: " << ( ( ch & mask_bit_6 ) >> 6 ) << std::endl;
    std::cout << "bit_6 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_6 ) ) << std::endl;
    
    std::cout << "bit_7 is: " << ( ( ch & mask_bit_7 ) >> 7 ) << std::endl;
    std::cout << "bit_7 with static_cast is: " << ( static_cast<bool>( ch & mask_bit_7 ) ) << std::endl;
    
    // Toggling bits by: ^(mask)
    // Targeting position 0
    std::cout << std::endl;
    ch ^= mask_bit_0;
    std::cout << "Value of ch after Toggling: " << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Targeting position 7
    std::cout << std::endl;
    ch ^= mask_bit_7;
    std::cout << "Value of ch after Toggling: " << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
        
    // Targeting positions  4, 5, 6, 7 to Toggle them
    ch ^=
    ( 
        mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7
    );
    std::cout << "Value of ch after Toggling:" << std::endl;
    std::cout 
        << std::setw(WIDTH) 
        << "ch: "
        << std::setw(WIDTH)
        << std::bitset<8>(ch)
        << std::endl
        << std::endl;
    
}


/*
    - Masks Demo
        - fun_opts_v0 : No Performance / Waste Of Memory
        - fun_opts_v1 : Performance / No Waste Of Memory
*/

void fun_opts_v0    // Uses many parameters & waste of memory
(   
    // using 1 byte for each parameter = 8 bit * 8 = 64 bit; 
    bool f00,   // bool = 1 Byte = 8 bit. 
    bool f01,   // bool = 1 Byte = 8 bit. 
    bool f02,   // bool = 1 Byte = 8 bit.  
    bool f03,   // bool = 1 Byte = 8 bit.
    bool f04,   // bool = 1 Byte = 8 bit. 
    bool f05,   // bool = 1 Byte = 8 bit. 
    bool f06,   // bool = 1 Byte = 8 bit. 
    bool f07    // bool = 1 Byte = 8 bit.
)
{
    std::cout << std::boolalpha;
    std::cout << "f00 is: " << f00 << std::endl;
    std::cout << "f01 is: " << f01 << std::endl;
    std::cout << "f02 is: " << f02 << std::endl;
    std::cout << "f03 is: " << f03 << std::endl;
    std::cout << "f04 is: " << f04 << std::endl;
    std::cout << "f05 is: " << f05 << std::endl;
    std::cout << "f06 is: " << f06 << std::endl;
    std::cout << "f07 is: " << f07 << std::endl;
}

// Masks 8-bit = 1-byte 
const unsigned char mask_bit_0 {0b00000001};    // Bit 0
const unsigned char mask_bit_1 {0b00000010};    // Bit 1
const unsigned char mask_bit_2 {0b00000100};    // Bit 2
const unsigned char mask_bit_3 {0b00001000};    // Bit 3
const unsigned char mask_bit_4 {0b00010000};    // Bit 4
const unsigned char mask_bit_5 {0b00100000};    // Bit 5
const unsigned char mask_bit_6 {0b01000000};    // Bit 6
const unsigned char mask_bit_7 {0b10000000};    // Bit 7

void fun_opts_v1    // Uses 1 parameter & no waste of memory
(   
    // using 1 byte parameter = 8 bit * 1 = 8 bit; 
    unsigned char flags    // char = 1 byte
)
{
    std::cout << std::boolalpha;
    std::cout << "f00 is: " << ( ( flags & mask_bit_0 ) >> 0 ) << std::endl;
    std::cout << "f01 is: " << ( ( flags & mask_bit_1 ) >> 1 ) << std::endl;
    std::cout << "f02 is: " << ( ( flags & mask_bit_2 ) >> 2 ) << std::endl;
    std::cout << "f03 is: " << ( ( flags & mask_bit_3 ) >> 3 ) << std::endl;
    std::cout << "f04 is: " << ( ( flags & mask_bit_4 ) >> 4 ) << std::endl;
    std::cout << "f05 is: " << ( ( flags & mask_bit_5 ) >> 5 ) << std::endl;
    std::cout << "f06 is: " << ( ( flags & mask_bit_6 ) >> 6 ) << std::endl;
    std::cout << "f07 is: " << ( ( flags & mask_bit_7 ) >> 7 ) << std::endl;
}

void bitwise_mask_demo()
{
    std::cout << "fun_opts_v0: " << std::endl;
    fun_opts_v0(0, 0, 1, 1, 1, 0, 1, 0);
    
    std::cout << std::endl;
    
    std::cout << "fun_opts_v1: " << std::endl;
    fun_opts_v1(0b00111010);
    
    std::cout << std::endl;
    
    std::cout << "fun_opts_v1: " << std::endl;
    fun_opts_v1(mask_bit_6 | mask_bit_4 | mask_bit_2 | mask_bit_0);
}
#endif














