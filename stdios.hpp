#ifndef __STDIOS_H
#define __STDIOS_H

#include <iomanip>
#include <ios>

using namespace std;

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

auto sum(auto x = 0.0, auto y = 0.0)
{
  return x + y;
}


void std_ios()
{
    auto x = 0.0;
    auto y = 0.0;
    auto res = 0.0;

    string full_name;
    int age;

    std::cout << "Please, type num1, num2 to calculate:" << std::endl;
    cout << "Num1:  ";
    std::cin >> x;
    cout << "Num2: ";
    cin >> y;

    // res = x + y;
    res = sum(x, y);

    std::cout << "The result is: " << res << std::endl;

    std::cout << "Please, Type your Full Name, and your age" << std::endl;

    std::getline(cin, full_name);
    std::cin >> age;

    std::cout << "Welcome, " << full_name << "you are " << age << " years old." << std::endl;

    int bin_to_int = 0b00001111;
    int oct_to_int = 017;
    int hex_to_int = 0x0f;
    int dic_to_int = 15;
    std::cout << bin_to_int << std::endl;
    std::cout << oct_to_int << std::endl;
    std::cout << hex_to_int << std::endl;
    std::cout << dic_to_int << std::endl;

    int x1(10);
    int y1(10);
    int z(x + y);

    std::cout << z << std::endl;
    std::cout << sizeof z << std::endl;
    std::cout << sizeof(z) << std::endl;

    char c = u8'f';

    const char16_t *str {u"Ahmed Salama"};

    std::cout << STR("HI, THERE") << std::endl;
}



void std_ioformat()
{
    const unsigned WIDTH {50};

    std::cout << std::boolalpha;

    std::cout << true << std::endl;
    std::cout << false << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    //std::cout << std::internal;
    // std::cout  << std::right;

    std::cout << std::setfill('-');
    std::cout << "Ahmed"   << std::setw(WIDTH) << std::showpos << 37 << std::endl;
    std::cout << std::right;
    std::cout << "Mahmoud"  << std::setw(WIDTH) << -79 << std::endl;
    std::cout << "Elsayed"  << std::setw(WIDTH) << std::noshowpos  << 49 << std::endl;
    std::cout << "Salama"   << std::setw(WIDTH) << -150 << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Message that will be flush...!" << std::endl << std::flush;
    std::cout << "---------------" << std::endl << std::flush;
    std::cout << std::endl << std::flush;

    std::cout << std::uppercase;
    std::cout << std::showbase;
    std::cout << std::dec << "DECIMAL 10844: " << 10844 << std::endl;
    std::cout << std::oct << "OCTAL 10844: " << 10844 << std::endl;
    std::cout << std::hex << "HEX 10844: " << 10844 << std::endl; // using std::uppercase
    std::cout << std::nouppercase << std::hex << "HEX 10844: " << 10844 << std::endl; // using std::nouppercase

    std::cout << std::uppercase;
    std::cout << std::noshowbase;
    std::cout << std::dec << "DECIMAL 10844: " << 10844 << std::endl;
    std::cout << std::oct << "OCTAL 10844: " << 10844 << std::endl;
    std::cout << std::hex << "HEX 10844: " << 10844 << std::endl; // using std::uppercase
    std::cout << std::nouppercase << std::hex << "HEX 10844: " << 10844 << std::endl; // using std::nouppercase
}




#endif




