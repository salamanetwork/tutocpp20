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


















#endif






