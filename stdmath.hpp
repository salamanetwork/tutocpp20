#ifndef __STDMATH_H
#define __STDMATH_H

#include <cmath>

void std_math()
{
    const unsigned WIDTH = 45;
    
    // exp(x) f(x) = e ^ x;
    double exponential = std::exp(10);
    std::cout << "The exponential of 10 is: " << exponential << std::endl;
    
    // pow(x, y) f(x, y) = x ^ y;
    std::cout << "3 ^ 4 is: " << std::pow(3, 4) << std::endl;
    std::cout << "9 ^ 3 is: " << std::pow(9, 3) << std::endl;
    
    // log(x) -> reverse to pow(x, ?)
    std::cout << "Log of 43 is: " << std::log(43) << std::endl;
    std::cout << "Log of 10000 is: " << std::log10(10000) << std::endl;
    
    // sqrt(x)
    std::cout << "The square root of 81 is: " << std::sqrt(81) << std::endl;
    
    // round(x)
    std::cout << "3.654 rounded to: " << std::round(3.654) << std::endl;
    std::cout << "2.5   rounded to: " << std::round(2.5) << std::endl;
    std::cout << "2.4   rounded to: " << std::round(2.4) << std::endl;
    
    // ceil(x)
    std::cout << "3.654 ceiled to: " << std::ceil(3.654) << std::endl;
    std::cout << "2.5   ceiled to: " << std::ceil(2.5) << std::endl;
    std::cout << "2.4   ceiled to: " << std::ceil(2.4) << std::endl;
    
    // floor(x)
    std::cout << "3.654 floored to: " << std::floor(3.654) << std::endl;
    std::cout << "2.5   floored to: " << std::floor(2.5) << std::endl;
    std::cout << "2.4   floored to: " << std::floor(2.4) << std::endl;
    
    // abs(x)
    const int WEIGHT = 76678;
    const int LEVEL = -76678;
    std::cout << "Abs for WEIGHT: " << std::abs(WEIGHT) << std::endl;
    std::cout << "Abs for LEVELT: " << std::abs(LEVEL)  << std::endl;
    
}


#endif
