#ifndef __DATA_CONVERSION_H
#define __DATA_CONVERSION_H

#include <iostream>
#include <string>

using namespace std;

/*
    - Data Conversion:
        - Overflow
        - Underoverflow
        
    - Real World:
        - All variables Should be from the same data type.
            - ex:
                int + int = int
                double + double = double
                float + float = float
    - Notes:
        - Compiler does Conversion without our involvement.
        - Compiler applies implecit Conversions when types are different.
        - Conversions done from the smallest to largest type
            - ex:
                int -> double;
        - Conversions done before the expression is evaluated, Unless we are doing an assignment
    - Conversion Guidline:
        int ---> unsigned int ---> long
        unsigned long ---> long long ---> unsigned long long
        float ---> double ---> long double
    - Narrwing Conversion
        - Happens when as assignment doing data Conversion
            - ex:
                double ---> int;
    - Explicit Conversion 
        - Implicit Cast using static_cast<type>
    - Overflow && Underflow
        - Be a mindful of the valid range of your data types.
        - Check the <limits> header for valid range.
        - Compiler will throw some tips and warnings about Overflow & Underflow
*/

void data_conversion()
{
    double unit_price { 42.60 };
    int unit_quantity { 15 };
    
    // Implecit converstion [int -> double]
    auto total_price { unit_quantity * unit_price };
    
    std::cout << "Total Price: " << total_price << std::endl << std::endl;
    std::cout << "sizeof total_price: " << sizeof total_price << std::endl << std::endl;
    
    
    // Narrwing converstion
    int x_val;
    double y_val { 9756.1254 };
    
    // Implecit Conversion by an assignment
    x_val = y_val;  // double ---> int
    
    std::cout << "x_val: " << x_val << std::endl;
    std::cout << "sizeof x_val: " << sizeof x_val << std::endl << std::endl;
    
    std::cout << "y_val: " << y_val << std::endl;
    std::cout << "sizeof y_val: " << sizeof y_val << std::endl << std::endl;
    
    // Explicit Conversion by static_cast
    double xp01 { 95.56 }, xp02 { 54.67 };
    
    // 01) Cast then sum method
    int sum_to_int { 
        static_cast<int>(xp01) + static_cast<int>(xp02) 
    };
    
    // 02) Sum then Cast method
    int sum;
    sum = static_cast<int>(xp01 + xp02);
    
    // 03 Old-Style C-Cast
    int sum_with_cast = (int)(xp01 + xp02);
    
    // original value
    double sum_to_double { xp01 + xp02 };
    
    std::cout << "xp01: " << xp01 << std::endl;
    std::cout << "sizeof xp01: " << sizeof xp01 << std::endl << std::endl;
    
    std::cout << "xp02: " << xp02 << std::endl;
    std::cout << "sizeof xp02: " << sizeof xp02 << std::endl << std::endl;
    
    // 01) Cast then sum method
    std::cout << "sum_to_int of {xp01 + xp02}: " << sum_to_int << std::endl;
    std::cout << "sizeof sum_to_int: " << sizeof sum_to_int << std::endl << std::endl;
    
    // 02) Sum then Cast method
    std::cout << "sum of {xp01 + xp02}: " << sum << std::endl;
    std::cout << "sizeof sum: " << sizeof sum << std::endl << std::endl;
    
    // 03) Old-Style C-Cast
    std::cout << "sum_with_cast of {xp01 + xp02}: " << sum_with_cast << std::endl;
    std::cout << "sizeof sum_with_cast: " << sizeof sum_with_cast << std::endl << std::endl;
    
    // original value
    std::cout << "sum_to_double of {xp01 + xp02}: " << sum_to_double << std::endl;
    std::cout << "sizeof sum_to_double: " << sizeof sum_to_double << std::endl << std::endl;
    
    // Overflow && Underflow
    unsigned char char_var (65);    // Here the data size is: from 0 to 255
    char_var = 261; // Store in the memory in more than data size -> Overflow
    char_var = -5;  // Store in the memory in less than data size -> Underflow
}





#endif











