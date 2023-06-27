#ifndef __STRINGS_H
#define __STRINGS_H

#include <iostream>
#include <bitset>
#include <iomanip>
#include <ios>
#include <array>
#include <new>
#include <string>
#include <string_view>
#include <string_literals>


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
    std::cout << "Alnums: "       << c_alnums        << std::endl;
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

/*
    - Using 'cstring' standard library:
        - https://en.cppreference.com/w/cpp/header/cstring
            - strlen, strcmp, strncmp, strchr, strrchr, 
*/

void std_cstring()
{
    // cstings applied only on 'const char*'
    const char* manip_text { "https://en.cppreference.com/w/cpp/header/cstring" };

    // Printing out the length of the manip_text
    std::cout 
        << "length of the manip_text: " 
        << std::strlen(manip_text) 
        << std::endl;

    // Comparing 2 strings
    const char* 
        str_city_01 { "Alexandria" };
    
    const char* 
        str_city_02 { "Dubai" };
    /*
        - Result One Of:
            - Negative value if 'lhs' appears before 'rhs' in lexicographical order.
            - Zero if 'lhs' and 'rhs' compare equal.
            - Positive value if 'lhs' appears after 'rhs' in lexicographical order. 
    */

    std::cout << "Comparing between str_city_01 & str_city_02: ";
    switch(std::strcmp(str_city_01, str_city_02))
    {
        case 0:
            std::cout 
                << str_city_01 
                << " & " << str_city_02 
                << " are Equals."
                << std::endl;
            break;
        case -1:
            std::cout 
                << str_city_01 
                << " Appears Before "
                << str_city_02 
                << std::endl;
            break;
        case 1:
            std::cout 
                << str_city_02 
                << " Appears Before "
                << str_city_01 
                << std::endl;
            break;
        default:
            std::cout 
                << " Invalid Comaprison!" 
                << std::endl;
            break;
    }

    // Finds the first occurrence of the character: Search for '/' in manip_text
    // Sorry!, I'm Lazy: https://en.cppreference.com/w/cpp/string/byte/strchr
    const char *str = "Try not. Do, or do not. There is no try.";
    char target = 'T';
    const char *result = str;
 
    while ((result = std::strchr(result, target)) != nullptr)
    {
        std::cout << "Found '" << target
                  << "' starting at '" << result << "'\n";
 
        // Increment result, otherwise we'll find target at the same location
        ++result;
    }
        


    std::cout << std::endl;
    std::cout << std::endl;
}

/*
    - Using some useful functions of strings
    - strcat, strcpy, strncat, strncpy
*/

void std_cstring_02()
{
    constexpr int bound { 30 };
    
    char* str_01 { new char[bound] { "Hello, " } };
    char* str_02 { new char[bound] { "World!" } };
    
    // Remember: 'str_01' the length will change afte using 'strcat'
    // Because: 'str_01' will be the distenation for new 'strcat' output.
    char* str_03 { std::strcat(str_01, str_02) };

    std::cout << str_03 << std::endl;
    std::cout << "-------------------------(sizeof)" << std::endl;
    std::cout << "sizeof str_01: " << sizeof str_01 << std::endl;
    std::cout << "sizeof str_02: " << sizeof str_02 << std::endl;
    std::cout << "sizeof str_03: " << sizeof str_03 << std::endl;
    std::cout << "-------------------------(length)" << std::endl;
    std::cout << "length of str_01: " << std::strlen(str_01) << std::endl;
    std::cout << "length of str_02: " << std::strlen(str_02) << std::endl;
    std::cout << "length of str_03: " << std::strlen(str_03) << std::endl;

    // Releasing && Resetting
    delete[] str_01;    str_01 = nullptr;
    delete[] str_02;    str_02 = nullptr;

    // Notes: In C++, the strcat function modifies the destination string in-place by appending the characters from the source string. 
    
    // Check Null Safety, Then Delete, Then Reset 
    if(!str_03)    // Because, We Deleted The Distenation 'str_01' Before.
    {
        delete[] str_03;    
        str_03 = nullptr;
    }
        

    std::cout << std::endl;
    std::cout << std::endl;
}

/*
    - C++ String (<string>) (std::string):
        - Is a class provided by the C++ Standard Library (part of the C++ language) that represents a sequence of characters or a string.
        - It is a versatile and powerful string container that offers a wide range of operations for string manipulation.
        - Key features and characteristics of std::string:
            - Dynamic Size:
                - std::string objects have a dynamic size, meaning they can grow or shrink as needed to accommodate the characters they hold. 
                - This allows flexibility in handling strings of varying lengths.
            - Character Storage: 
                - std::string internally stores its characters as a contiguous sequence of characters, typically using dynamically allocated memory. 
                - It manages the memory allocation and deallocation automatically, making it convenient to work with.
            - Compatibility: 
                - std::string is compatible with C-style strings (const char*). 
                - It can be constructed from C-style strings and can be converted to C-style strings using the c_str() member function.
            - Wide Range of Operations: 
                - std::string provides a rich set of member functions for string manipulation. 
                - These include functions for concatenation, substring extraction, character access and modification, searching and replacing, comparing, and many more.
            - Operator Overloading: 
                - std::string overloads several operators to allow easy manipulation and comparison of strings. 
                - For example, you can concatenate strings using the + operator, compare strings using relational operators (<, >, ==, etc.), and more.
            - Standard Library Integration: 
                - std::string is part of the C++ Standard Library, which means it seamlessly integrates with other standard library components. 
                - It can be used with input/output streams, algorithms, containers, and various other library facilities.
        
        - You can initialize an std::string object in C++ using various methods. 
        - Here are the different ways to initialize an std::string:
            - 01) Default Initialization:
                
                std::string str;
                
                // This initializes an empty std::string object with no initial content.
    
            - 02) Initialization with a C-style string (null-terminated character array):
                
                const char* cstr = "Hello, World!";
                std::string str(cstr);
                
                // This initializes an std::string object str with the content of the null-terminated C-style string cstr. 
                // It creates a copy of the characters from cstr and stores them in str.
    
            - 03) Initialization with a character array and length:
                
                const char chars[] = {'H', 'e', 'l', 'l', 'o'};
                std::string str(chars, 5);
                
                // This initializes an std::string object str with the first n characters from the character array chars. 
                // In this example, str will contain "Hello" since it is initialized with the first 5 characters.
    
            - 04) Initialization with a repeated character:
                
                std::string str(5, 'X');
                
                // This initializes an std::string object str with a sequence of n repeated characters specified by the second argument. 
                // In this example, str will contain "XXXXX" as it is initialized with 5 repetitions of the character 'X'.
    
            - 05) Initialization with another std::string object or substring:
    
                std::string original = "Hello, World!";
                std::string str(original);
                
                //This initializes an std::string object str with the content of another std::string object original. 
                // It creates a copy of the characters from original and stores them in str.
    
            - 06) Direct Initialization with a string literal:
    
                std::string str = "Hello, World!";
                
                // This initializes an std::string object str directly with the content of the string literal. 
                // The compiler automatically converts the string literal to an std::string object.
    
        - These are some common ways to initialize an std::string object in C++. 
        - Choose the method that suits your requirements and coding style.
*/

void cpp_string_01()
{
    // 01) Default Initializer:
    std::string str_01;
    
    // 02) Initialization with a C-style string:
    const char* cstr = "Hello, World!";
    std::string str_02(cstr);

    std::cout << "02) Initialized std::string: " << str_02 << std::endl;

    // 03) Initialization with a character array and length:
    const char chars[] = {'H', 'e', 'l', 'l', 'o'};
    std::string str_03(chars, 5);

    std::cout << "03) Initialized std::string: " << str_03 << std::endl;

    // 04) Initialization with a repeated character:
    std::string str_04(5, 'X');

    std::cout << "04) Initialized std::string: " << str_04 << std::endl;

    
    // 05) Initialization with another std::string object or substring:
    std::string original = "Hello, World!";
    std::string str_05(original);

    std::cout << "05) Initialized std::string: " << str_05 << std::endl;

    std::string substring = original.substr(0, 5);
    std::cout << "\tSubstring: " << substring << std::endl;
    
    // 06) Direct Initialization with a string literal:
    std::string str_06 = "Hello, World!";

    std::cout << "06) Initialized std::string: " << str_06 << std::endl;
    

}

/*
    - Using some useful functions of strings
        -You can perform various operations and apply numerous functions on std::string objects in C++. 
            -Here are some common operations and functions you can apply:

                - 01) Accessing and Modifying:
                    - Access individual characters: str[index]
                    - Modifying characters: str[index] = new_char
                    - Appending characters: str.push_back(new_char)
                    - Concatenating strings: str1 + str2 or str1.append(str2)
                    - Clearing the string: str.clear()
                    - Resizing the string: str.resize(new_size)
                
                - 02) String Manipulation:
                    - Extracting substrings: str.substr(start_pos, length)
                    - Finding a substring or character: str.find(substring) or str.find(character)
                    - Replacing a substring: str.replace(start_pos, length, new_str)
                    - Erasing a portion of the string: str.erase(start_pos, length)
                    - Swapping the contents of two strings: str1.swap(str2)

                - 03) String Information and Properties:
                    - Getting the length: str.length() or str.size()
                    - Checking if the string is empty: str.empty()
                    - Checking if the string starts or ends with a specific substring: str.startswith(substring) or str.endswith(substring)
                    - Comparing strings: str1 == str2, str1 != str2, str1 < str2, etc.
                
                - 04) String Conversion and I/O:
                    - Converting to a C-style string: str.c_str()
                    - Converting to other numeric or data types: std::stoi(str), std::stof(str), etc.
                    - Input/output operations using std::cin and std::cout
*/

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.substr(0, prefix.length()) == prefix;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.substr(str.length() - suffix.length(), suffix.length()) == suffix;
}

void cpp_string_02()
{
    // 01) Accessing and Modifying: ----------------------------------
    
    // Access individual characters: str[index]
    std::string str11 = "Hello, World!";
    
    char firstChar11 = str11[0];
    char fifthChar11 = str11[4];

    std::cout << "First character: " << firstChar11 << std::endl;
    std::cout << "Fifth character: " << fifthChar11 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Modifying characters: str[index] = new_char
    std::string str12 = "Hello, World!";

    std::cout << "Original string: " << str12 << std::endl;

    str12[0] = 'J';
    str12[7] = 'F';
    
    std::cout << "Modified string: " << str12 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Appending characters: str.push_back(new_char)
    std::string str13 = "Hello";

    std::cout << "Original string: " << str13 << std::endl;

    str13.push_back('!');
    str13.push_back(' ');

    std::cout << "Appended string: " << str13 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Concatenating strings: str1 + str2 or str1.append(str2)
    std::string str114 = "Hello";
    std::string str214 = " World!";

    std::string concatenated114 = str114 + str214;
    std::string concatenated214 = str114;
    concatenated214.append(str214);

    std::cout << "Concatenated string 1: " << concatenated114 << std::endl;
    std::cout << "Concatenated string 2: " << concatenated214 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Clearing the string: str.clear()
    std::string str15 = "Hello, World!";

    std::cout << "Original string: " << str15 << std::endl;

    str15.clear();

    std::cout << "Cleared string: " << str15 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Resizing the string: str.resize(new_size)
    std::string str16 = "Hello";

    std::cout << "Original string: " << str16 << std::endl;

    str16.resize(10);

    std::cout << "Resized string (to length 10): " << str16 << std::endl;

    str16.resize(3);

    std::cout << "Resized string (to length 3): " << str16 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    
    // 02) String Manipulation: ----------------------------------
    
    // Extracting substrings: str.substr(start_pos, length)
    std::string str21 = "Hello, World!";

    std::string substring121 = str21.substr(0, 5);     // Extracts "Hello"
    std::string substring221 = str21.substr(7, 5);     // Extracts "World"
    std::string substring321 = str21.substr(7);        // Extracts "World!"

    std::cout << "Substring 1: " << substring121 << std::endl;
    std::cout << "Substring 2: " << substring221 << std::endl;
    std::cout << "Substring 3: " << substring321 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Finding a substring or character: str.find(substring) or str.find(character)
    std::string str22 = "Hello, World!";

    std::size_t position122 = str22.find("World");     // Finds the position of "World"
    std::size_t position222 = str22.find('o');         // Finds the position of the first 'o'
    std::size_t position322 = str22.find("Universe");  // Finds the position of "Universe" (not found)

    std::cout << "Position of \"World\": " << position122 << std::endl;
    std::cout << "Position of 'o': " << position222 << std::endl;

    if (position322 == std::string::npos) {
        std::cout << "\"Universe\" not found in the string." << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Replacing a substring: str.replace(start_pos, length, new_str)
    std::string str23 = "Hello, World!";

    std::cout << "Original string: " << str23 << std::endl;

    str23.replace(7, 5, "Universe");

    std::cout << "Modified string: " << str23 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Erasing a portion of the string: str.erase(start_pos, length)
    std::string str24 = "Hello, World!";

    std::cout << "Original string: " << str24 << std::endl;

    str24.erase(7, 6);

    std::cout << "Modified string: " << str24 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Swapping the contents of two strings: str1.swap(str2)
    std::string str125 = "Hello";
    std::string str225 = "World";

    std::cout << "Before swap:" << std::endl;
    std::cout << "\tstr125: " << str125 << std::endl;
    std::cout << "\tstr225: " << str225 << std::endl;

    str125.swap(str225);

    std::cout << "After swap:" << std::endl;
    std::cout << "\tstr125: " << str125 << std::endl;
    std::cout << "\tstr225: " << str225 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // 03) String Information and Properties: ----------------------------------
    
    // Getting the length: str.length() or str.size()
    std::string str31 = "Hello, World!";

    std::cout << "String length using length(): " << str31.length() << std::endl;
    std::cout << "String length using size(): " << str31.size() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    // Checking if the string is empty: str.empty()
    std::string str132 = "Hello";
    std::string str232 = "";

    if (str132.empty()) {
        std::cout << "str1 is empty." << std::endl;
    } else {
        std::cout << "str1 is not empty. It contains: " << str132 << std::endl;
    }

    if (str232.empty()) {
        std::cout << "str2 is empty." << std::endl;
    } else {
        std::cout << "str2 is not empty. It contains: " << str232 << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Checking if the string starts or ends with a specific substring: str.startswith(substring) or str.endswith(substring)

    std::string str33 = "Hello, World!";

    if (startsWith(str33, "Hello")) {
        std::cout << "String starts with \"Hello\"" << std::endl;
    } else {
        std::cout << "String does not start with \"Hello\"" << std::endl;
    }

    if (endsWith(str33, "World!")) {
        std::cout << "String ends with \"World!\"" << std::endl;
    } else {
        std::cout << "String does not end with \"World!\"" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    // Comparing strings: str1 == str2, str1 != str2, str1 < str2, etc.
    std::string str134 = "Hello";
    std::string str234 = "World";
    std::string str334 = "Hello";
    std::string str434 = "hello";

    if (str134 == str234) {
        std::cout << "str134 is equal to str234" << std::endl;
    } else {
        std::cout << "str134 is not equal to str234" << std::endl;
    }

    if (str134 != str334) {
        std::cout << "str134 is not equal to str334" << std::endl;
    } else {
        std::cout << "str134 is equal to str334" << std::endl;
    }

    if (str134 < str434) {
        std::cout << "str134 is less than str434" << std::endl;
    } else {
        std::cout << "str134 is not less than str434" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    // 04) String Conversion and I/O: ----------------------------------
    
    // Converting to a C-style string: str.c_str()
    std::string str41 = "Hello, World!";

    const char* cStr41 = str41.c_str();

    std::cout << "Original string: " << str41 << std::endl;
    std::cout << "C-style string: " << cStr41 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    // Converting to other numeric or data types: std::stoi(str), std::stof(str), etc.
    /*
        std::stoi(str)    converts a string to an int value.
        std::stol(str)    converts a string to a long value.
        std::stoll(str)   converts a string to a long long value.
        std::stoul(str)   converts a string to an unsigned long value.
        std::stoull(str)  converts a string to an unsigned long long value.
        std::stof(str)    converts a string to a float value.
        std::stod(str)    converts a string to a double value.
        std::stold(str)   converts a string to a long double value.
    */
    
    std::string str4141 = "123";
    std::string str4241 = "3.14";

    int intValue441 = std::stoi(str4141);
    float floatValue441 = std::stof(str4241);

    std::cout << "String: " << str4141 << ", Converted Integer: " << intValue441 << std::endl;
    std::cout << "String: " << str4241 << ", Converted Float: " << floatValue441 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    // Input/output operations using std::cin and std::cout
    /*
    int num;
    std::string name;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Enter your name: ";
    std::cin.ignore(); // Ignore the newline character left in the input buffer
    std::getline(std::cin, name);

    std::cout << "You entered: " << num << std::endl;
    std::cout << "Your name is: " << name << std::endl;
    */
    
    std::cout << std::endl;
    std::cout << std::endl;
}



















#endif









