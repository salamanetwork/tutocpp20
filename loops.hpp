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





















#endif






