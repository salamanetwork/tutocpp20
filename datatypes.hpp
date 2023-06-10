#ifndef __DATATYPES_H
#define __DATATYPES_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

/*
    Weired Integral Types:
        char;
        short int;
        -------------------------------------------------------------------------------
        * Integral types less than 4 bytes don not support arithmetic operations [+, -, *, /, %]
        * Because, of the CPU Designs.
*/

void weried_integral_types()
{
    short int si01 = 20;
    short int si02 = 30;
    
    char c01 = 40;
    char c02 = 50;
    
    // get the sizeof si01, si02, c01, and c02.
    std::cout << "sizeof si01: "    << sizeof(si01) << " Bytes" << std::endl;
    std::cout << "sizeof si02: "    << sizeof(si02) << " Bytes" << std::endl;
    std::cout << "sizeof c01: "     << sizeof(c01)  << " Bytes" << std::endl;
    std::cout << "sizeof c02: "     << sizeof(c02)  << " Bytes" << std::endl;
    
    // If we use an arithmetic operations it will convert directly to int
    short int result01 { si01 + si02 }; // Warning: << -Wnarrwing
    short int result02 { c01 + c02 };   // Warning: << -Wnarrwing
    
    // warning: narrowing conversion of ‘(((int)si01) + ((int)si02))’ from ‘int’ to ‘short int’ [-Wnarrowing]
    std::cout << "sizeof result01: "    << sizeof(result01) << " Bytes" << std::endl;
    
    // warning: narrowing conversion of ‘(((int)si01) + ((int)si02))’ from ‘int’ to ‘short int’ [-Wnarrowing]
    std::cout << "sizeof result02: "    << sizeof(result02) << " Bytes" << std::endl;

    // Fix & Solution
    auto result03 { si01 + si02 }; // Convert automatically to int [Wide conversion] 
    auto result04 { c01 + c02 };   // Convert automatically to int [Wide conversion]
    
    std::cout << "sizeof result03: "    << sizeof(result03) << " Bytes" << std::endl;
    std::cout << "sizeof result04: "    << sizeof(result04) << " Bytes" << std::endl;
}

void integers_types()
{
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    short s = 1;
    std::cout << "short s: \t\t\t\t\t\t\t\t" << sizeof s << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    int i = 1;
    std::cout << "int i: \t\t\t\t\t\t\t\t\t" << sizeof i << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    long l = 1;
    std::cout << "long l: \t\t\t\t\t\t\t\t" << sizeof l << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    long long ll = 1;
    std::cout << "long long ll: \t\t\t\t\t\t\t\t" << sizeof ll << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed _si = 1;
    std::cout << "signed _si: \t\t\t\t\t\t\t\t" << sizeof _si << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned _ui = 1;
    std::cout << "unsigned _ui: \t\t\t\t\t\t\t\t" << sizeof _ui << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed short ssi = 1;
    std::cout << "signed short: \t\t\t\t\t\t\t\t" << sizeof ssi << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed int sii = 1;
    std::cout << "signed int sii: \t\t\t\t\t\t\t" << sizeof sii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed long sli = 1;
    std::cout << "signed long sli: \t\t\t\t\t\t\t" << sizeof sli << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned short usi = 1;
    std::cout << "unsigned short usi: \t\t\t\t\t\t\t" << sizeof usi << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned int uii = 1;
    std::cout << "unsigned int uii: \t\t\t\t\t\t\t" << sizeof uii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned long uli = 1;
    std::cout << "unsigned long uli: \t\t\t\t\t\t\t" << sizeof uli << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    short int _sii = 1;
    std::cout << "short int _sii: \t\t\t\t\t\t\t" << sizeof _sii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed short int ssii = 1;
    std::cout << "signed short int ssii: \t\t\t\t\t\t\t" << sizeof ssii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned short int usii = 1;
    std::cout << "unsigned short int usii: \t\t\t\t\t\t" << sizeof usii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    long int lii = 1;
    std::cout << "long int lii: \t\t\t\t\t\t\t\t" << sizeof lii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed long int slii = 1;
    std::cout << "signed long int slii: \t\t\t\t\t\t\t" << sizeof slii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned long int ulii = 1;
    std::cout << "unsigned long int ulii: \t\t\t\t\t\t" << sizeof ulii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    long long int llii = 1;
    std::cout << "long long int llii: \t\t\t\t\t\t\t" << sizeof llii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    signed long long int sllii = 1;
    std::cout << "signed long long int sllii: \t\t\t\t\t\t" << sizeof sllii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    unsigned long long int ullii = 1;
    std::cout << "unsigned long long int ullii: \t\t\t\t\t\t" << sizeof ullii << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

void floats_types()
{
    std::cout << std::setprecision(100);

    float f = 1.12345678901234567890f;
    std::cout << "float f: \t\t\t\t\t\t\t\t" << sizeof f << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    double d = 1.12345678901234567890;
    std::cout << "double d: \t\t\t\t\t\t\t\t" << sizeof d << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    long double ld = 1.12345678901234567890L;
    std::cout << "long double ld: \t\t\t\t\t\t\t" << sizeof ld << std::endl;
    std::cout << "ld: " << ld << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

void booleans_types()
{
    bool t = true;
    bool f = false;
    std::cout << "sizeof bool: " << sizeof(bool) << std::endl;
    std::cout << "sizeof bool t: " << sizeof t << std::endl;
    std::cout << "sizeof bool f: " << sizeof f << std::endl;
    std::cout << "valueof bool t: " << t << std::endl;
    std::cout << "valueof bool f: " << f << std::endl;
    std::cout << std::boolalpha << "valueof bool t: " << t << std::endl;
    std::cout << std::boolalpha << "valueof bool f: " << f << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

void chars_types()
{
    char c {'c'};
    std::cout << "sizeof char: " << sizeof(char) << std::endl;
    std::cout << "sizeof char c: " << sizeof c << std::endl;
    std::cout << "char c: " << c << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    char a {65};
    std::cout << "sizeof char a: " << sizeof a << std::endl;
    std::cout << "char a[char]: " << a << std::endl;
    std::cout << "char a[int by old style casting/(int) a]: " << (int) a << std::endl;
    std::cout << "char a[int by new style casting/static_cast<int>(a)]: " << static_cast<int>(a) << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    // char str[13] = "Ahmed Salama";
    // const char *str = "Ahmed Salama";

    // for(int i = 0; i <= std::strlen(str); i++)
    // {
    //     std::cout << (int)str[i] << std::endl;
    // }
}

void auto_types()
{
    auto v01 (1);               // int
    auto v02 {1.3};             // double
    auto v03 = 3.5f;            // float
    auto v04 {'c'};             // char
    auto v05 (44.53L);          // long double
    auto v06 {765u};            // unsigned int
    auto v07 {765ul};           // unsigned long
    auto v08 {765ll};           // long long
    auto v09 = 2ull;            // unsigned long long

    v06 = -99;  // !!!!! Dnager, because it was declared and initialized as an *auto unsigned int* -> auto v06 {765u};            // unsigned int

    std::cout << "sizeof v01: " << sizeof v01 << std::endl;
    std::cout << "valueof v01: " << v01 << std::endl;

    std::cout << "sizeof v02: " << sizeof v02 << std::endl;
    std::cout << "valueof v02: " << v02 << std::endl;

    std::cout << "sizeof v03: " << sizeof v03 << std::endl;
    std::cout << "valueof v03: " << v03 << std::endl;

    std::cout << "sizeof v04: " << sizeof v04 << std::endl;
    std::cout << "valueof v04: " << v04 << std::endl;

    std::cout << "sizeof v05: " << sizeof v05 << std::endl;
    std::cout << "valueof v05: " << v05 << std::endl;

    std::cout << "sizeof v06: " << sizeof v06 << std::endl;     // !!!!! should be print out a garbage value, not (-99), because, it should be an unsigned int
    std::cout << "valueof v06: " << v06 << std::endl;

    std::cout << "sizeof v07: " << sizeof v07 << std::endl;
    std::cout << "valueof v07: " << v07 << std::endl;

    std::cout << "sizeof v08: " << sizeof v08 << std::endl;
    std::cout << "valueof v08: " << v08 << std::endl;

    std::cout << "sizeof v09: " << sizeof v09 << std::endl;
    std::cout << "valueof v09: " << v09 << std::endl;
}



#endif



