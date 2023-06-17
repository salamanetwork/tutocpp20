#ifndef __ARRAYS_H
#define __ARRAYS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <cstdlib>

#include <bitset>

using namespace std;


/*
    - Arrays:
        - Elements(Values of the array) should be the same data type as declaration.
        - Index starts at: 0
        - syntax: data_type var_name[array_size];
            - array_size: is the array boundaries ->[start][elements][end]<-
            - empty_values: are garbage data defined by the compiler.
        - Define the array as Constant, *Can Not Be Modified Later*:
            - ex:
                const std::string grades [] { "VERY BAD", "BAD", "GOOD", "VERY GOOD", "EXCELLENT" }; 
        - ex:
            int collection[12];                           // An Empty Array Values
            double _3d[3] { 8.5, 4.6, 3.7 };              // An Array With 3 Elements As Double
            char chs[5] = { 'A', 'H', 'M', 'E', 'D' };    // An Array With 5 Elements As Char
*/

void arrays()
{
    // Decalaring an Array
    int grades[8];    // An Array storing 8 integers
    
    // Accessing the array elements
    // Remeber grades[7] is equal to element 8 in the array, because the array starts at index 0
    std::cout << "Grade 8 is: " << grades[7] << std::endl;

    // Error: Out of boundary of the array: last element should be 7
    // Maybe cause compile-time/run-time error, dependes on the compiler
    std::cout << "Grade 9 is: " << grades[8] << std::endl; // throws a garbage value

    // Writing/Modifying an array element
    grades[3] = 4;    // Writing manually

    std::cout << std::endl;
    
    // Writing/Modifying an array elements through for loop
    for(auto index { 0 }, inc { 1 }; auto value : grades)
    {
        grades[index] = inc;
        ++inc;
        ++index;
    }
    
    std::cout << std::endl;
    
    // Accessing the data through for loop
    for(auto element : grades)
        std::cout << "Current Element Value Is: " << element << std::endl;

    std::cout << std::endl;
    
    // An Initialize Array 
    // An Array With 5 Elements As Char
    char chs[5] = { 'A', 'H', 'M', 'E', 'D' };
    
    std::cout << "My Name Is: ";
    for(auto element : chs)
        std::cout << element;

    std::cout << std::endl;
    std::cout << std::endl;

    // Define An Array As Constant
    // Note: This Array Can Not Be Modified Later!!!!!!
    const std::string str_grades [] 
    { 
        "VERY BAD", 
        "BAD", 
        "GOOD", 
        "VERY GOOD", 
        "EXCELLENT" 
    };

    for(auto element : str_grades)
        std::cout << "Current Element Value Is: " << element << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Sum an array elements
    int sum { 0 };

    for(auto value : { 1, 2, 3, 4, 5 })
        sum += value;    // sum = 1 + 2 + 3 + 4 + 5

    std::cout << "The Sum Of Values Is: " << sum << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
}














#endif



