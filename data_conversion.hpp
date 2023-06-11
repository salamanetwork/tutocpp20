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
    
    
}





#endif











