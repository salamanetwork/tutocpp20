#ifndef __LOOPS_H
#define __LOOPS_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <cstdlib>

#include <bitset>

/*
    - Traditional For Loop Statement:
        - for(initiate_value; condition_stmt; increment_stmt)
        - for(initiate_values; condition_stmt; increment_stmts)

*/
void for_trad_loop()
{
    const items { 10 };
    
    for(size_t i {0}; i < items; i++)
        std::cout << "Item " << i << ":" << std::endl;
}


/*
    - Range Based For Loop Statement:
        - for(value : collection)
            - value: hold a copy of the current iteration in the entire collection
            - collection: is a container like 'Array', 'List', etc...
            - auto: deducing the type automatically.
            - you can inject the collection directly.

*/
void for_range_loop()
{
    int collection [] { 1, 2, 3, 4, 5 };
    
    for(int value : collection)
        std::cout << "Item Value: " << value << std::endl;

    for(auto ch : { 'a', 'b', 'c', 'd', 'e', 'f' })
        std::cout << "Char Value: " << ch << std::endl;
}

/*
    - Traditional While Loop Statement:
        - while(condition)
*/
void while_trad_loop()
{
    // Items
    int items { 10 };
    
    // Iterator
    size_t i { 0 };
    
    while( i < items )
    {
        std::cout << "Item    := " << i << std::endl;
        ++i;
    }
        
}

/*
    - Traditional Do While Loop Statement:
        - do { } while(condition)
        - Note: Run The Body Of Do First, Then Run The Test Of While.
*/
void do_while_trad_loop()
{
    const unsigned int items { 25 };

    // iterator
    int i = 0;

    do
    {
        if(i != 10 && i < 10)
        {
            std::cout << "Item    := 0" << i << std::endl;
        }
        else if(i >= 10)
        {
            std::cout << "Item    := " << i << std::endl;
        }
        
        ++i;
    } 
    while( i < items );
}

/*
    - Infinite Loops:
        - for(;;) {}
        - while(true) {}
        - do {} while(true);
*/

void infinite_loops()
{
    // for
    for(;;)
        std::cout << "This is infinite loop by traditional for loop" << std::endl;

    // while
    while(true)
        std::cout << "This is infinite loop by traditional while loop" << std::endl;

    // do-while
    do
        std::cout << "This is infinite loop by traditional do/while loop" << std::endl;
    while(true);
}

/*
    - Nesting Loops
*/
void nesting_loops()
{
    const int rows { 3 };
    const int cols { 5 };

    // iterators
    int row, col, c, r = 0;

    // Table by: nesting for loop
    std::cout << "Table by: nesting for loop: " << std::endl;

    for(size_t row { 0 }; row < rows; ++row)
    {
        for(size_t col { 0 }; col < cols; ++col)
        {
            std::cout 
                << "( Row: " 
                    << row 
                        << ", Column: " 
                            << col 
                                << " ) ";
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    std::cout << "Table by: nesting while loop: " << std::endl;

    while(row < rows)
    {
        while(col < cols)
        {
            std::cout 
                << "( Row: " 
                    << row 
                        << ", Column: " 
                            << col 
                                << " ) ";
            ++col;
        }
        
        std::cout << std::endl;

        // Reset the col to 0: 
            // must be reset to 0 because of printing out with synchronizing with row number from the beginning like (1, 0), (2, 0), ... 
        col = 0;

        ++row;
    }

    std::cout << std::endl;
    
    std::cout << "Table by: nesting do while loop: " << std::endl;

    do
    {
        do
        {
            std::cout 
                << "( Row: " 
                    << r 
                        << ", Column: " 
                            << c 
                                << " ) ";

            ++c;
        }
        while(c < cols);

        // Reset col to 0
        c = 0;    // col must start at 0 that is why we reset it back to 0

        ++r;

        std::cout << std::endl;
    }
    while(r < rows);

    std::cout << std::endl;
}


/*
    - Range based for loop with Initializer
        - for(auto initializer; value : collection)
*/

void range_based_for_loop_with_initializer()
{
    for(auto multi { 2 }; auto v : { 1, 2, 3, 4, 5, 6, 7, 8, 9 })
    {
        if(v % 2 == 0)
            std::cout 
                << "Even Number " 
                    << v 
                        << " is now: " 
                            << ( v * multi )
                                << "\n";
        else
            std::cout 
                << "Odd Number " 
                    << v  
                        << " is the same." 
                            << "\n";

        std::cout << std::endl;
    }
}


















#endif






