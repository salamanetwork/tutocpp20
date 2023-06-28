#ifndef __STRINGS_H
#define __STRINGS_H

#include <iostream>
#include <bitset>
#include <iomanip>
#include <ios>
#include <array>
#include <new>
#include <algorithm>
#include <string>
#include <string_view>


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

        - Here is a list of functions provided by the <string> header in C++:
            std::string (class): Represents a sequence of characters.
            operator+ (overload): Concatenates two strings.
            operator+= (overload): Appends a string to another string.
            operator== (overload): Compares two strings for equality.
            operator!= (overload): Compares two strings for inequality.
            operator< (overload): Performs lexicographical comparison of two strings.
            operator> (overload): Performs lexicographical comparison of two strings.
            operator<= (overload): Performs lexicographical comparison of two strings.
            operator>= (overload): Performs lexicographical comparison of two strings.
            operator[] (overload): Accesses an individual character of the string.
            at(): Accesses an individual character of the string with bounds checking.
            size(): Returns the number of characters in the string.
            length(): Returns the number of characters in the string.
            empty(): Checks if the string is empty.
            clear(): Clears the contents of the string.
            substr(): Extracts a substring from the string.
            compare(): Compares two strings.
            find(): Searches for a substring within the string.
            rfind(): Searches for a substring within the string in reverse.
            find_first_of(): Finds the first occurrence of any character from a set of characters within the string.
            find_last_of(): Finds the last occurrence of any character from a set of characters within the string.
            find_first_not_of(): Finds the first occurrence of a character not present in a given set of characters within the string.
            find_last_not_of(): Finds the last occurrence of a character not present in a given set of characters within the string.
            replace(): Replaces a portion of the string with another string.
            erase(): Erases a portion of the string.
            insert(): Inserts characters into the string.
            push_back(): Appends a character to the end of the string.
            pop_back(): Removes the last character from the string.
            resize(): Changes the size of the string.
            c_str(): Returns a pointer to a null-terminated character array representing the string.
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

/*
    - String Literals (#include <string_literals>):
        - namespace provides user-defined literals for creating std::string objects directly from string literals. 
        - It allows you to create std::string objects using a concise syntax without explicitly calling the std::string constructor. 
        - To use std::string_literals, you need to include the <string> and <string_literals> headers.    
    
    - https://learn.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=msvc-170
*/

void cpp_string_literals()
{
    using namespace std::string_literals;

    std::string str1 = "Hello, World!";  // Regular string literal
    std::string str2 = "Hello, "s + "World!";  // User-defined literal

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // Character literals
    auto c0 =   'A'; // char
    auto c1 = u8'A'; // char
    auto c2 =  L'A'; // wchar_t
    auto c3 =  u'A'; // char16_t
    auto c4 =  U'A'; // char32_t

    // Multicharacter literals
    // warning: multi-character character constant [-Wmultichar]
    // auto m0 = 'abcd'; // int, value 0x61626364


    // String literals
    auto s0 =   "hello"; // const char*
    auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                         // const char8_t* in C++20
    auto s2 =  L"hello"; // const wchar_t*
    auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
    auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32

    // Raw string literals containing unescaped \ and "
    auto R0 =   R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                      // const char8_t* in C++20
    auto R2 =  LR"("Hello \ world")"; // const wchar_t*
    auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
    auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

    // Combining string literals with standard s-suffix
    auto S0 =   "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
    auto S2 =  L"hello"s; // std::wstring
    auto S3 =  u"hello"s; // std::u16string
    auto S4 =  U"hello"s; // std::u32string

    // Combining raw string literals with standard s-suffix
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                       // std::u8string in C++20
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32

    
}

/*
    - std::to_string():
        - Function is used to convert numeric values to their corresponding string representations.
*/

void cpp_string_to_sting() {
    int num = 42;
    double pi = 3.14159;

    std::string numStr = std::to_string(num);
    std::string piStr = std::to_string(pi);

    std::cout << "Number: " << numStr << std::endl;
    std::cout << "Pi: " << piStr << std::endl;

}

/*
    - Accessing & Modification & Looping Through std::string:
        - [], at(), front(), back(), data()
        - Range Based For Loop, and Traditional For Loop
*/

void cpp_string_access_modif_loop()
{
    // Accessing std:string by traditional for loop
    std::string str1 = "Hello, World!";

    for (size_t i = 0; i < str1.size(); ++i) {
        std::cout << str1[i] << " ";
    }

    // accessing std:string by range based for loop
    std::string str2 = "Hello, World!";

    for (char ch : str2) {
        std::cout << ch << " ";
    }

    // Accesing std::string by at() function
    std::string str3 = "Hello, World!";

    for (size_t i = 0; i < str3.size(); ++i) {
        char ch = str3.at(i);
        std::cout << ch << " ";
    }

    // Accesing std::string by data() function
    std::string str4 = "Hello, World!";
    
    const char* charPtr4 = str4.data();
    for (size_t i = 0; i < str4.size(); ++i) {
        std::cout << charPtr4[i] << " ";
    }

    // Accessing std::str with front() and back() functions:
    std::string str5 = "Hello, World!";

    char firstChar = str5.front();
    char lastChar = str5.back();

    std::cout << "First character: " << firstChar << std::endl;
    std::cout << "Last character: " << lastChar << std::endl;

    // Modifying std::string by at() function:
    std::string str6 = "Hello, World!";

    str6.at(0) = 'J';
    str6.at(7) = '-';
    str6.at(str6.size() - 1) = '?';

    std::cout << str6 << std::endl;

    // Modifying std::string by data() function
    std::string str7 = "Hello, World!";

    char* charPtr7 = str7.data();
    charPtr7[0] = 'J';  // Modifying through data() pointer

    std::cout << str7 << std::endl;

    // Modifying std::string by Array Access Operator []:
    std::string str8 = "Hello, World!";

    str8[0] = 'J';
    str8[7] = '-';
    str8[str8.size() - 1] = '?';

    std::cout << str8 << std::endl;

    // Modifying std::string by push_back() & pop_back()  functions:
    std::string str9 = "Hello";

    str9.push_back('!');
    std::cout << str9 << std::endl;

    str9.pop_back();
    std::cout << str9 << std::endl;
}


/*
    - Size & The Capacity of std::string:
        - the size and capacity are two important properties that describe the string's length and memory allocation.
        - Size:
            - The size of a std::string refers to the number of characters currently stored in the string. 
            - You can obtain the size using the member functions size() or length(). 
            - Both functions return the same value, representing the size of the string.
            - The size represents the number of characters stored in the std::string. 
            - It reflects the actual length of the string and provides a measure of its content.
            - By accessing the size, you can determine the length of the string and perform operations based on its character count.
        - Capacity:
            - The capacity of a std::string refers to the amount of memory allocated to store the string. 
            - It represents the maximum number of characters that can be held without requiring reallocation. 
            - You can retrieve the capacity using the capacity() member function.
            - It indicates the maximum number of characters that can be stored without requiring reallocation. 
            - The capacity is often larger than the size to allow for future growth and avoid frequent memory reallocations when appending characters.
            - It helps optimize the performance of string operations by reducing the need for memory management operations.
        - Notes:
            - The size and capacity of a std::string are dynamic properties that can change during its lifetime. 
            - For example, when characters are added to the string using concatenation or append operations, the size increases. If the size exceeds the capacity, the string may need to reallocate memory to accommodate the additional characters.
            - Understanding the size and capacity of a std::string allows you to manage memory efficiently, estimate memory usage, and optimize operations based on the string's length and potential growth.

        ------------------------------------------------------------------------------------------------------------------------------------
        |               Size                                       |                           Capacity                                   |
        ------------------------------------------------------------------------------------------------------------------------------------
        - Represents the number of characters in the string.       |      Represents the amount of memory allocated for the string.
        - Obtained using the size() or length() member function.   |      Obtained using the capacity() member function.
        - Indicates the actual length of the strin.                |      Indicates the maximum number of characters without reallocation.
        - Can change as characters are added or remove.            |      Can change as the string grows or shrinks.
        - Can be equal to or smaller than the capacit.             |      Equal to or greater than the size.
        - Influences the behavior of string operations.            |      Influences memory management and reallocation.
        - Used to access individual characters in the string.      |      Used to optimize memory usage and reduce reallocations.
        ------------------------------------------------------------------------------------------------------------------------------------
*/

void cpp_string_size_n_capacity()
{
    // std::size() & std::length()
    std::string str1 = "Hello, World!";
    
    std::cout << "Size of the string: " << str1.size() << std::endl;
    std::cout << "Length of the string: " << str1.length() << std::endl;

    // capacity()
    std::string str2 = "Hello, World!";
    
    std::cout << "Capacity of the string: " << str2.capacity() << std::endl;

    // empty()
    std::string str3; // Uninitialized string

    if (str3.empty()) {
        std::cout << "The string is empty." << std::endl;
    } else {
        std::cout << "The string is not empty." << std::endl;
    }

    // max_size(), std::string::max_size()
    /* 
        - The actual value of <max_size> will vary depending on the implementation, platform, and available memory.
            - Ex: 9223372036854775807
        - It's important to note that the maximum size represents an upper limit and does not necessarily mean that the std::string can always reach that size due to practical constraints. 
        - The maximum size provides information about the maximum capacity that can be allocated for the string, but it may be limited by factors such as available memory, system resources, or other implementation-specific considerations.
    */
    std::string str4;

    std::cout << "Maximum size of the string: " << str4.max_size() << std::endl;

    // std::string::reserve()
    /*
        - Is used to allocate memory in advance for a std::string object, allowing you to potentially avoid frequent memory reallocations during string operations.
        - By reserving the memory in advance, you can ensure that the string has enough capacity to hold a certain number of characters without requiring reallocation.
        - After reserving the memory, you can assign a string to str or perform other string operations. The std::string object will have the specified capacity, which can be accessed using the std::string::capacity() member function.
        - It's important to note that reserve() only increases the capacity of the std::string and does not affect the size or content of the string. The actual size of the string can still be smaller than the reserved capacity.
    */
    std::string str5;

    str5.reserve(100); // Reserve memory for 100 characters

    // Check the capacity before and after reserving
    std::cout << "Capacity before reserve: " << str5.capacity() << std::endl;

    str5 = "Hello, World!";

    std::cout << "Capacity after reserve: " << str5.capacity() << std::endl;

    // std::string::shrink_to_fit()
    /*
        - Is used to reduce the capacity of a std::string object to fit its actual size. It requests the string to reduce its capacity to the minimum necessary to hold its current contents. 
        - It requests the string to reduce its capacity to the minimum necessary to hold its current contents.
        - This can be useful when you want to minimize memory usage and free up any excess memory that was allocated but is no longer needed.
        - The actual values of <some_value> and <smaller_value> will vary depending on the implementation and the specific situation.
        - After calling shrink_to_fit(), the std::string attempts to reduce its capacity to fit its actual size. 
        - The capacity may be decreased, but it's not guaranteed to reach the exact size of the string. The resulting capacity depends on various factors, such as the underlying implementation and any memory fragmentation.
        - It's important to note that shrink_to_fit() is a non-binding request, meaning that the implementation may choose to ignore the request and keep the capacity unchanged. 
        - Additionally, calling shrink_to_fit() does not affect the size or content of the string itself; it only adjusts the capacity.
    */
    std::string str7 = "Hello, World!";
    
    // Check the capacity before and after shrinking
    std::cout << "Capacity before shrink: " << str7.capacity() << std::endl;
    
    str7.shrink_to_fit();
    
    std::cout << "Capacity after shrink: " << str7.capacity() << std::endl;
    
    
}

/*
    - Modifying std::strings:
        - Assigning a new value:
            - operator=: Assigns a new value to the string.
            - assign(): Assigns a new value to the string, replacing the current contents.
        
        - Appending to the string:
            - operator+=: Appends a string or character to the end of the string.
            - append(): Appends a string or character to the end of the string.

        - Inserting into the string:
            - insert(): Inserts a substring or character into the string at a specified position.

        - Erasing from the string:
            - erase(): Erases a portion of the string, specified by position or range.

        - Replacing part of the string:
            - replace(): Replaces a portion of the string with a new value.

        - Swapping string contents:
            - swap(): Swaps the contents of two strings.

        - Resizing the string:
            -resize(): Resizes the string, either truncating or padding with a specified character.

        - Removing whitespace:
            - erase(): Erases whitespace characters from the beginning and end of the string.
            - std::remove_if() with std::isspace(): Removes whitespace characters based on a predicate.
*/

void cpp_string_modif_funcs()
{
    //  Assigning a new value:
    std::string str11 = "Hello";
    std::string str21;

    str21 = str11;
    // or
    str21.assign(str11);

    std::cout << str21 << std::endl;

    //  Appending to the string:
    std::string str22 = "Hello";

    str22 += " World";
    // or
    str22.append(" World");

    std::cout << str22 << std::endl;
    
    //  Inserting into the string:
    std::string str33 = "Hello";

    str33.insert(5, " World");

    std::cout << str33 << std::endl;
    
    //  Erasing from the string:
    std::string str44 = "Hello World";

    str44.erase(6, 5);

    std::cout << str44 << std::endl;
    
    //  Replacing part of the string:
    std::string str55 = "Hello World";

    str55.replace(6, 5, "Universe");

    std::cout << str55 << std::endl;

    //  Swapping string contents:
    std::string str16 = "Hello";
    std::string str26 = "World";

    str16.swap(str26);

    std::cout << str16 << std::endl;

    //  Resizing the string:
    std::string str77 = "Hello";

    str77.resize(10, '!');

    std::cout << str77 << std::endl;

    //  Removing whitespace:
    std::string str99 = "  Hello World   ";

    std::cout << str99 << std::endl;

    //  Erasing whitespace at the beginning and end
    str99.erase(0, str99.find_first_not_of(" "));
    str99.erase(str99.find_last_not_of(" ") + 1);

    std::cout << str99 << std::endl;

    //  Removing whitespace using remove_if and isspace
    str99.erase(std::remove_if(str99.begin(), str99.end(), ::isspace), str99.end());

    std::cout << str99 << std::endl;

    // Inserting Variants:
    std::string str10 = "Hello";

    //  str.insert(pos, substr);
    str10.insert(3, "lo");

    //  Inserting a portion of a C-style string:
    std::string str111 = "Hello";

    //  str.insert(pos, cstr, count);
    const char* cstr = "lo";
    str111.insert(3, cstr, 2);

    //  Inserting a character multiple times:
    std::string str12 = "Hello";

    //  str.insert(pos, count, ch);
    char ch12 = '!';
    str12.insert(5, 3, ch12);

    //  Inserting a character:
    // std::string str13 = "Hello";

    // //  str.insert(pos, ch);
    // char ch13 = '!';
    // str13.insert(5, ch13);

    //  Inserting a range of characters from another string:
    std::string str114 = "Hello";
    std::string str214 = "World";

    //  str1.insert(pos, str2, subpos, sublen);
    str114.insert(5, str214, 2, 3);
}

/*
    - C++ Compare Strings:
        - Using the comparison operators (==, !=, <, <=, >, >=).
        - Using the compare() function.
*/

void cpp_string_comparison()
{
    std::string str1 = "apple";
    std::string str2 = "banana";
    
    // Equality comparison
    if (str1 == str2) {
        std::cout << "Strings are equal" << std::endl;
    } else {
        std::cout << "Strings are not equal" << std::endl;
    }
    
    // Inequality comparison
    if (str1 != str2) {
        std::cout << "Strings are not equal" << std::endl;
    } else {
        std::cout << "Strings are equal" << std::endl;
    }
    
    // Less-than comparison
    if (str1 < str2) {
        std::cout << "str1 is less than str2" << std::endl;
    } else {
        std::cout << "str1 is not less than str2" << std::endl;
    }
    
    // Less-than or equal-to comparison
    if (str1 <= str2) {
        std::cout << "str1 is less than or equal to str2" << std::endl;
    } else {
        std::cout << "str1 is not less than or equal to str2" << std::endl;
    }
    
    // Greater-than comparison
    if (str1 > str2) {
        std::cout << "str1 is greater than str2" << std::endl;
    } else {
        std::cout << "str1 is not greater than str2" << std::endl;
    }
    
    // Greater-than or equal-to comparison
    if (str1 >= str2) {
        std::cout << "str1 is greater than or equal to str2" << std::endl;
    } else {
        std::cout << "str1 is not greater than or equal to str2" << std::endl;
    }
    
    // compare() function
    int result = str1.compare(str2);
    if (result == 0) {
        std::cout << "Strings are equal" << std::endl;
    } else if (result < 0) {
        std::cout << "str1 is less than str2" << std::endl;
    } else {
        std::cout << "str1 is greater than str2" << std::endl;
    }
}

/*
    - C++ String Resizeing
        - Using std::string::resize() function.
*/

void cpp_string_resizing()
{
    std::string str = "Hello";

    std::cout << "Before resize: " << str << std::endl;
    std::cout << "Size before resize: " << str.size() << std::endl;
    std::cout << "Capacity before resize: " << str.capacity() << std::endl;

    // Increase the size of the string to 10 characters
    str.resize(10);

    std::cout << "After resize: " << str << std::endl;
    std::cout << "Size after resize: " << str.size() << std::endl;
    std::cout << "Capacity after resize: " << str.capacity() << std::endl;

    // Decrease the size of the string to 5 characters
    str.resize(5);

    std::cout << "After resize again: " << str << std::endl;
    std::cout << "Size after resize again: " << str.size() << std::endl;
    std::cout << "Capacity after resize again: " << str.capacity() << std::endl;

}

/*
    - C++ String Copying
        - Using std::string::copy() function.
*/

void cpp_string_copying()
{
    std::string source = "Hello, World!";
    std::string destination(10, ' ');

    std::cout << "Before copy: " << std::endl;
    std::cout << "Source: " << source << std::endl;
    std::cout << "Destination: " << destination << std::endl;

    // Variant 1: Copy the entire source string to the destination
    source.copy(&destination[0], source.length(), 0);
    std::cout << "After variant 1 copy: " << destination << std::endl;

    // Variant 2: Copy a substring from the source to the destination
    source.copy(&destination[0], 5, 7);
    std::cout << "After variant 2 copy: " << destination << std::endl;

    // Variant 3: Copy a substring from the middle of the source to the destination
    source.copy(&destination[5], 5, 2);
    std::cout << "After variant 3 copy: " << destination << std::endl;

    // Variant 4: Copy a substring and handle truncation
    source.copy(&destination[0], 20, 0);
    std::cout << "After variant 4 copy: " << destination << std::endl;

}


/*
    - C++ String Searching & Finding
        - Using std::string::find() function.
        - Using std::string::find_first_of() function.
        - Using std::string::npos() function.
            - Is a static member constant of the std::string class that represents the maximum value for the size type std::string::size_type. It is typically used to indicate the absence of a valid position or index.
            - The usage of std::string::npos allows us to handle cases where a substring is not found, providing a convenient way to check for absence or invalid positions.
*/

void cpp_string_searching()
{
    std::string str = "Hello, World!";

    std::cout << "Source string: " << str << std::endl;

    // Variant 1: Find the position of the substring "World" starting from index 0
    size_t pos1 = str.find("World", 0);
    if (pos1 != std::string::npos) {
        std::cout << "Variant 1: Found 'World' at position " << pos1 << std::endl;
    } else {
        std::cout << "Variant 1: 'World' not found" << std::endl;
    }

    // Variant 2: Find the position of the substring "l" starting from index 3
    size_t pos2 = str.find('l', 3);
    if (pos2 != std::string::npos) {
        std::cout << "Variant 2: Found 'l' at position " << pos2 << std::endl;
    } else {
        std::cout << "Variant 2: 'l' not found" << std::endl;
    }

    // Variant 3: Find the position of the first occurrence of any character in "oe" starting from index 0
    size_t pos3 = str.find_first_of("oe", 0);
    if (pos3 != std::string::npos) {
        std::cout << "Variant 3: Found 'o' or 'e' at position " << pos3 << std::endl;
    } else {
        std::cout << "Variant 3: 'o' or 'e' not found" << std::endl;
    }

    // Variant 4: Find the position of the first occurrence of a character not in "Helo" starting from index 0
    size_t pos4 = str.find_first_not_of("Helo", 0);
    if (pos4 != std::string::npos) {
        std::cout << "Variant 4: Found a character not in 'Helo' at position " << pos4 << std::endl;
    } else {
        std::cout << "Variant 4: No character not in 'Helo' found" << std::endl;
    }
}

/*
    - C++ String To Numbers
        - Converting a string to an integer using std::stoi().
        - Converting a string to a floating-point number using std::stof().
        - Converting an integer to a string using std::to_string().
        - Converting a floating-point number to a string using std::to_string().
        - Converting a string to an integer using std::stringstream.
        - Converting an integer to a string using std::stringstream.
*/

void cpp_string_to_num()
{
    // Example 1: Converting string to integer
    std::string str1 = "12345";
    int num1 = std::stoi(str1);
    std::cout << "String to Integer Conversion: " << num1 << std::endl;

    // Example 2: Converting string to floating-point number
    std::string str2 = "3.14";
    float num2 = std::stof(str2);
    std::cout << "String to Float Conversion: " << num2 << std::endl;

    // Example 3: Converting integer to string
    int num3 = 42;
    std::string str3 = std::to_string(num3);
    std::cout << "Integer to String Conversion: " << str3 << std::endl;

    // Example 4: Converting floating-point number to string
    float num4 = 2.71828;
    std::string str4 = std::to_string(num4);
    std::cout << "Float to String Conversion: " << str4 << std::endl;

    // Example 5: Converting string to integer using stringstream
    std::string str5 = "98765";
    int num5;
    std::stringstream ss1(str5);
    ss1 >> num5;
    std::cout << "String to Integer Conversion using stringstream: " << num5 << std::endl;

    // Example 6: Converting integer to string using stringstream
    int num6 = 99999;
    std::stringstream ss2;
    ss2 << num6;
    std::string str6 = ss2.str();
    std::cout << "Integer to String Conversion using stringstream: " << str6 << std::endl;

}

/*
    - C++ String Escape Sequence:
*/

void cpp_string_esc_seq()
{
    // Example 1: Newline (\n)
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is a new line.\n";

    // Example 2: Tab (\t)
    std::cout << "Name:\tJohn Doe\n";
    std::cout << "Age:\t25\n";

    // Example 3: Backslash (\\)
    std::cout << "This is a backslash: \\\\" << std::endl;

    // Example 4: Single Quote (\')
    std::cout << "I'm happy.\n";

    // Example 5: Double Quote (\")
    std::cout << "She said, \"Hello!\"\n";

    // Example 6: Carriage Return (\r) and Vertical Tab (\v)
    std::cout << "Hello, World!\r";
    std::cout << "Vertical Tab\vTest\n";

    // Example 7: Alert/Bell (\a)
    std::cout << "This will produce a sound \a" << std::endl;
}

/*
    - C++ String / Raw String Literals:
*/

void cpp_string_raw_str_literals()
{
    // Example 1: Basic raw string literal
    std::string str1 = R"(This is a raw string literal)";
    std::cout << "Example 1: " << str1 << std::endl;

    // Example 2: Raw string literal with escaped characters
    std::string str2 = R"(C:\Windows\System32\\)";
    std::cout << "Example 2: " << str2 << std::endl;

    // Example 3: Multiline raw string literal
    std::string str3 = R"(
        Line 1
        Line 2
        Line 3
    )";
    std::cout << "Example 3: " << str3 << std::endl;

    // Example 4: Raw string literal with parentheses
    std::string str4 = R"###((This is a raw string literal with parentheses))###";
    std::cout << "Example 4: " << str4 << std::endl;

    // Example 5: Raw string literal with embedded newline
    std::string str5 = R"(Line 1
Line 2
Line 3)";
    std::cout << "Example 5: " << str5 << std::endl;

    // Example 6: Raw string literal with trailing backslash
    std::string str6 = R"(This is a raw string literal with a trailing backslash\\)";
    std::cout << "Example 6: " << str6 << std::endl;
}




#endif









