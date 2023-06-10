#ifndef __DATATYPES_H
#define __DATATYPES_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

/*
    Literals and Constants:
        * Literals:
            - Data that is directly represented in code without going through some other variable stored in memory.
            - They are literally stored in the program executable file, hence the name literal!.
        * Constants:
            # const:
                - A variable you can initialize, but can’t change afterwards.
                - A read only variable. Can’t assign data to it.
                - const unsigned PI = 3.14;
            # Constant Expressions:
                * constexpr:
                    - Constant expressions have been introduced in C++11.
                    - Constant that may be evaluated at compile time or runtime.
                    - Constant expressions are also constants, so you can’t reassign values to them.
                    - Notes: 
                        - If possible, move the potentially heavy computations at compile time.
                        - The heavy computation is done once by the developer and users running the application can benefit from the results of the computation done at compile time.
                * constinit:
                    - Constant intialization have been introduced in C++20.
                    - A variable that should be initialized with a constant or literal at compile time.
                    - However, constexpr does imply constinit.
                    - constexpr is not equivalent to const constinit, as the former mandates constant destruction, while the latter doesn't.
                    - It can be both const and constinit. It cannot be both constexpr and constinit.
                    - constinit helps developers ensure that is the case without having to guess or check the generated assembly. 
                    - It can only be applied to variables with static or thread storage duration. It does not make sense to apply it to other variables, as constinit is all about static initialization.
                    
*/

// constexpr constinit double MY_PI {3.14159265359};   // Fail: constexpr + constinit 
const constinit double MY_PI {3.14159265359};       // Pass: const + constinit

int XI {1};                             // Run Time Value
// constinit int VAR_XI {XI};           // Fail
// constexpr int VAR_XI {XI};           // Fail
const int VAR_XI {XI};                  // Pass
const int VAR_XII {2};                  // Pass
// constinit int VAR_XIII {VAR_XI};     // Fail: VAR_XI does not have a constant initializer
constinit int VAR_XIV  {VAR_XII};       // Pass


void literals_and_constants()
{   
    // 01) const
    // Compile error - uninitialized ‘const WIDTH’ [-fpermissive]
    // const unsigned int WIDTH;        // Fail
    const unsigned int WIDTH {80};      // Pass
    const unsigned int HEIGHT {10};     // Pass
    
    const auto AREA { WIDTH * HEIGHT }; // Pass
    std::cout << "Area {WIDTH * HEIGHT} is: " << AREA << std::endl;
    
    // 02) constexpr
    constexpr double FIXED_INTEREST {3.6};
    constexpr double PI {3.14159265359};
    std::cout << std::endl;
    
    std::cout << "FIXED_INTEREST is: " << FIXED_INTEREST << std::endl;
    std::cout << "PI is: " << PI << std::endl;
    std::cout << std::endl;
    
    // Error: the value of ‘my_value’ is not usable in a constant expressio
    unsigned short int my_value (2);    // Non constexpr
    // my_value is not kown at the Compile time
    // constexpr int my_life (my_value);   // Error
    
    // Pass:
    constexpr int const_val = 5;
    constexpr int const_val2 = const_val;
    std::cout << "const_val2: " << const_val2  << std::endl;
    std::cout << std::endl;
    
    // Pass:
    const int const_val3 = 9;
    constexpr int const_val4 = const_val3 * 10;
    std::cout << "const_val4: " << const_val4  << std::endl;
    std::cout << std::endl;
    
    // static_assert(expr) : using to check at compile time
    // static_assert(const_val2 == 3, "const_val2 is not equal!");  // Error
    static_assert(const_val2 == 5, "const_val2 is not equal!");     // Pass
    
    // 03) constinit
    // constinit long double STOCK_MARKET_INTEREST_MONTHLY {987656.9887};       // Error
    static constinit long double STOCK_MARKET_INTEREST_MONTHLY {987656.9887};   // Pass
    std::cout << "STOCK_MARKET_INTEREST_MONTHLY: " << STOCK_MARKET_INTEREST_MONTHLY << std::endl;
    std::cout << std::endl;
    
    // constexpr constinit long double STOCK_MARKET_INTEREST_DAILY {8985.98874};   // Error 
    static const constinit long double STOCK_MARKET_INTEREST_DAILY {8985.98874};   // Pass
    std::cout << "STOCK_MARKET_INTEREST_DAILY: " << STOCK_MARKET_INTEREST_DAILY << std::endl;
    std::cout << std::endl;
    
}

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



