#ifndef __STRINGS_H
#define __STRINGS_H

#include <iostream>
#include <bitset>
#include <iomanip>
#include <ios>
#include <array>
#include <new>
#include <string>


#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cctype>
#include <cstring>


using namespace std;

/*
    - Using String & Chars manipulation with C/C++ Standard Library:
        - 'cctype':
            - isalnum, isalpha, isblank, iscntrl, isdigit, isgraph, 
              islower, isprint, ispunct, isspace, isupper, isxdigit, 
              tolower, toupper
*/

void chr_str_manip()
{
    std::string manip_text = "Using, and Manipulating String & Chars manipulation with C/C++20 Standard Library.";

    int c_graphs { 0 }, c_blanks { 0 }, c_uppers { 0 }, c_lowers { 0 }, 
        c_digits { 0 }, c_alnums { 0 }, c_alphas { 0 }, c_spaces { 0 },
        c_puncts { 0 };
    
    std::cout << "Text: " << manip_text << std::endl;
    
    for(auto c : manip_text)
    {
        if(std::isdigit(c)) ++c_digits;
        if(std::isblank(c)) ++c_blanks;
        if(std::isalpha(c)) ++c_alphas;
        if(std::isalnum(c)) ++c_alnums;
        if(std::isupper(c)) ++c_uppers;
        if(std::islower(c)) ++c_lowers;
        if(std::isspace(c)) ++c_spaces;
        if(std::isgraph(c)) ++c_graphs;
        if(std::ispunct(c)) ++c_puncts;
    }

    std::cout << std::endl;
    
    std::cout << "Spaces: "       << c_spaces        << std::endl;
    std::cout << "Digits: "       << c_digits        << std::endl;
    std::cout << "Blanks: "       << c_blanks        << std::endl;
    std::cout << "Alphas: "       << c_alphas        << std::endl;
    std::cout << "Uppers: "       << c_uppers        << std::endl;
    std::cout << "Lowers: "       << c_lowers        << std::endl;
    std::cout << "Alphanums: "    << c_alnums        << std::endl;
    std::cout << "Graphs: "       << c_graphs        << std::endl;
    std::cout << "Puncts: "       << c_puncts        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Convert all chars to upper
    std::cout << "TO UPPER: " << std::endl;
    for(auto c : manip_text)
        std::cout << static_cast<char>(std::toupper(c));

    std::cout << std::endl;
    std::cout << std::endl;

    // Convert all chars to upper
    std::cout << "TO LOWER: " << std::endl;
    for(auto c : manip_text)
        std::cout << static_cast<char>(std::tolower(c));

    std::cout << std::endl;
    std::cout << std::endl;
}





















#endif









