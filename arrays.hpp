#ifndef __ARRAYS_H
#define __ARRAYS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <ctime>
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

/*
    - Arrays of Chars
        - c-string: using '\0' null terminated
        - string literal: using "" instead
*/
void arrays_of_chars()
{
     // char array: valid C-string
    // Should add '\0': Null Terminated at the end of the array
    char fname [] { 'A', 'H', 'M', 'E', 'D', '\0' };
    
    std::cout << "(Using c-string '\\0' Null Terminate) The First Name Is: " << fname << std::endl;
    std::cout << "Size of The First Name Is: " << std::size(fname) << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;

    // char array: valid C-string
    // Use "": to avoid '\0' Null Terminated
    char lname [] { "SALAMA" };
    
    std::cout << "(Using string literal \"\" Without Null Terminate) The Last Name Is: " << lname << std::endl;
    std::cout << "Size of The Last Name Is: " << std::size(lname) << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
}


/*
    - Random Numbers:
        - std::rand(): generates an integer number between 0 and RAND_MAX.
        - RAND_MAX: dependes on the compiler.
        - Ranges: std::rand() % integer_num.
            - integer_num: to define the upper bound for the range
                - ex:
                    std:rand() % 11; // define a range [0-10]
            - ((std::rand() % integer_num) + 1): 
                - If we want to start the range from 1 not 0 as [1-10]
                    - 1: is lower bound
                    - 10: is upper bound
                - ex:
                    ((std::rand() % 10) + 1); // Range [1-10]
            - Notes:
                - The Main Issue of std::rand:
                    - Each time the program runs, will give you the same sequance.
                        - std::time(0): Using UNIX time [01 January 1970][00:00:00 AM]
                            - Seeding: depends on the time
                                - std::srand(std::time(0));
*/
void arrays_rands()
{
    std::cout << std::endl;

    cout << "RAND_MAX is: " << RAND_MAX << endl;
    std::cout << std::endl;
    
    for(size_t i = 0; i < 10; ++i)
    {    
        int rand_num = std::rand();
        std::cout 
            << "Random Number of(" 
            << i 
            << ") is: " 
            << rand_num
            << std::endl;
    }
    

    std::cout << std::endl;
    std::cout << std::endl;
}

// Without Seeding
// Using std::rand for range [0-10] starts from 0 *without seeding
void arrays_rands_ranges_range_0_to_10_starts_from_0_without_seeding()
{
    // Define a range betwwen 0 to 10
    int rand_num = std::rand() % 11;

    for(size_t i = 0; i < 10; ++i)
    {    
        rand_num = std::rand() % 11;
        std::cout 
            << "Random Number of(" 
            << i 
            << ") is: " 
            << rand_num
            << std::endl;
    }
}

// Without Seeding
// Using std::rand for range [1-10] starts from 1 *without seeding
void arrays_rands_ranges_range_1_to_10_starts_from_1_without_seeding()
{
    // Define a range betwwen 1 to 10
    int rand_num = (std::rand() % 10) + 1;

    for(size_t i = 0; i < 10; ++i)
    {    
        rand_num = (std::rand() % 10) + 1;
        std::cout 
            << "Random Number of(" 
            << i 
            << ") is: " 
            << rand_num
            << std::endl;
    }
}

// With Seeding
// Using std::rand for range [1-10] starts from 1 *with seeding using std::srand
void arrays_rands_ranges_range_1_to_10_starts_from_1_with_seeding()
{
    // Seeding
    std::srand(std::time(0));    // Using true randomizer by utilize the time
    
    // Define a range betwwen 1 to 10
    int rand_num = (std::rand() % 10) + 1;

    for(size_t i = 0; i < 10; ++i)
    {    
        rand_num = (std::rand() % 10) + 1;
        std::cout 
            << "Random Number of(" 
            << i 
            << ") is: " 
            << rand_num
            << std::endl;
    }
}

/*
    - Multi-Dimessional Array:
        - syntax: type name [row_count][col_count] {};
        - syntax: type name [][col_count] {};    // ommiting row_count
*/

// 2D Array
void multi_dim_2d_array()
{
    // declaring and initializing 2D array
    int data_packet [3] [4]
    {    
        // col: 0    col: 1    col: 2    col: 3
        {    10,     20,       30,         40   },           // row: 0
        {    50,     60,       70,         80   },           // row: 1
        {    90,     10,       20,         30   },           // row: 2
    };

    // printing out the mult-dim array
    for(size_t i {0}; i < std::size(data_packet); ++i)
    {
        std::cout << "Row: " << i << std::endl;

        for(size_t j {0}; j < std::size(data_packet[i]); ++j)
        {
            std::cout 
                << " ( Col: "
                << j
                << " val: "
                << data_packet[i][j]
                << " )\t";
        }
        std::cout  << std::endl;
    }
    std::cout << std::endl << std::endl;
}

// 3D Array
void multi_dim_3d_array()
{
    int cube_3d [8] /* points: */ [2] /* area: w, h */ [3] /* location-axes: x, y, z*/ 
    {
        {
            { 10, 11, 12 } /* area: 0 */, { 13, 14, 15 } /* area: 0 */
        },    // point: 0
        {
            { 16, 17, 18 } /* area: 0 */, { 19, 20, 21 } /* area: 0 */
        },    // point: 1
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 2
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 3
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 4
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 5
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 6
        {
            { 22, 23, 24 } /* area: 0 */, { 25, 26, 27 } /* area: 1 */
        },    // point: 7
    };

    std::cout << std::endl;

    // printing out the mult-dim array
    for(size_t j {0}; j < std::size(cube_3d); ++j)                    // j loop for points
    {
        for(size_t k {0}; k < std::size(cube_3d[j]); ++k)             // k loop for area
        {
            for(size_t l {0}; l < std::size(cube_3d[j][k]); ++l)      // l loop for axes
            {
                std::cout
                    << " ( point: "
                    << j
                    << "\n\t area: "
                    << k
                    << "\n\t\t axes: "
                    << l
                    << "\n\t\t\t val: "
                    << cube_3d[j][k][l]
                    << " ) \n\n";
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}



/*
    - Arrays of pointer to chars (Array of Pointers to Strings):
        - An array of pointers to strings is an array of character pointers where each pointer points to the first character of the string or the base address of the string
        - Advantages:
            - Unlink the two dimensional array of characters, in array of strings and in array of pointers to strings, there is no fixed memory size for storage.
            - The strings occupy only as many bytes as required hence, there is no wastage of space.
        - Explaination : 
            - https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/
        - Syntax:
            const char * todo_list []
            {
                "Study C++ Programming",                // todo_list[0]
                "Read The C++ Programming Book",        // todo_list[1]
                "Initiate C++ Project",                 // todo_list[2]
                "Read About Memory Management",         // todo_list[3]
                "Understand The Pointer In C++",        // todo_list[4]
                "Understand The Reference In C++",      // todo_list[5]
            };

            // todo_list[0] point to the first char of array of chars: 'S' ...
            // todo_list[1] point to the first char of array of chars: 'R' ...
            // todo_list[2] point to the first char of array of chars: 'I' ...
            // todo_list[3] point to the first char of array of chars: 'R' ...
            // todo_list[4] point to the first char of array of chars: 'U' ...
            // todo_list[5] point to the first char of array of chars: 'U' ...
        
*/

void arrays_of_pointer_to_chars()
{
    const char * todo_list []
    {
        "Study C++ Programming",
        "Read The C++ Programming Book",
        "Initiate C++ Project",
        "Read About Memory Management",
        "Understand The Pointer In C++",
        "Understand The Reference In C++",
    };

    for(uint32_t index {1}; auto item : todo_list)
    {
        std::cout << index << ") " << item << std::endl;
        ++index;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
































#endif



