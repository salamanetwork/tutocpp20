#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

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
    - Functions In C/C++:
        - Are a fundamental building block of a program.
        - They allow you to encapsulate a block of code that can be reused and executed whenever needed. 
        - Provide modularity, code organization, and allow you to break down complex tasks into smaller, more manageable pieces. 
        - Here's an overview of functions in C++:
            - Function Declaration/Prototype:
                - At the beginning of your program or in a separate header file, you need to declare or prototype the function. 
                - It specifies the function's name, return type, and parameter list (if any). 
                - Syntax:
                    - returned_type function_name(Parameters_list_if_any_with_its_data_type);
                - Ex:
                    int add(int a, int b);
            - Function Definition:
                - The function definition contains the actual implementation of the function. 
                - It includes the return type, function name, parameter list, and the code to be executed when the function is called.
                - Syntax:
                     - returned_type function_name(Parameters_list_if_any_with_its_data_type)
                       {
                            // The Body Of The Function That Conatins The Code & Implementation.
                       }
                - Ex:
                    int add(int a, int b)
                    {
                        int sum = a + b;
                        return sum;
                    }
            - Function Call:
                - To execute a function, you need to call it by using its name followed by parentheses.
                - If the function has parameters, you pass the required values inside the parentheses. 
                - The return value, if any, can be stored in a variable or used directly. 
                - Syntax:
                    - function_name(Parameters_list_that_represents_parameters_list_data_type)
                - Ex:
                    add(1, 4);                    // Direct Output: 5
                    int result = add(1, 4));      // Indirect Output: 5
            - Function Parameters:
                - Functions can accept zero or more parameters.
                - Parameters act as placeholders for values that are passed to the function when it is called. 
                - They allow you to provide input to the function or specify the data on which the function will operate. 
                - Ex:
                    // Function declaration with parameters
                    void greet(std::string name);
                    
                    // Function definition with parameters
                    void greet(std::string name) {
                        std::cout << "Hello, " << name << "!" << std::endl;
                    }
                    
                    // Function call with argument
                    greet("Alice");  // Output: Hello, Alice!
            - Return Type:
                - Functions can have a return type, which specifies the type of the value the function will return after execution.
                - It can be any valid C++ data type, including fundamental types, user-defined types, or even void (indicating no return value). 
                - Ex:
                    // Function declaration with return type
                    int multiply(int a, int b);
                    
                    // Function definition with return type
                    int multiply(int a, int b) {
                        return a * b;
                    }
                    
                    // Function call with return value
                    int result = multiply(4, 5);  // result = 20
            - Void Functions:
                - Void functions do not return a value. 
                - They are typically used for performing actions or tasks without producing any output. 
                - Ex:
                    // Void function declaration
                    void printMessage();
                    
                    // Void function definition
                    void printMessage() {
                        std::cout << "This is a void function." << std::endl;
                    }
                    
                    // Void function call
                    printMessage();  // Output: This is a void function.
            - Function arguments:
                - Function arguments allow you to customize the behavior of a function by providing different values each time you call it. 
                - They enable functions to work with different inputs and perform various operations based on the provided data.

            - Differences between parameters and arguments:
            |--------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|
            |                                     Parameter                                        |                                     Argument                                          |
            |--------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|
            | Parameters are declared in the function declaration or definition.                   | Arguments are the values or variables passed to a function during its call.           |
            | Parameters act as placeholders within the function.                                  | Arguments are the actual data that is supplied to the function.                       |
            | Parameters define the type and name of the data that a function expects to receive.  | Arguments provide the values that correspond to the parameters of the function.       |
            | Parameters are used to specify the input requirements of a function.                 | Arguments fulfill the input requirements of a function.                               |
            | Parameters are part of the function's declaration or definition.                     | Arguments are part of the function call.                                              |
            | Parameters are local variables within the function.                                  | Arguments are values or variables from the calling code.                              |
            | Parameters receive the values passed as arguments during the function call.          | Arguments are assigned to the parameters of the function when it is called.           |
            |--------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|             

        - The scope of an argument :
            - Refers to the region of the code where the argument is accessible and can be used. 
            - Is typically limited to the body of the function where it is declared as a parameter.
            - Is confined to the function where it is declared as a parameter. 
            - Once the function completes its execution, the argument goes out of scope, and its visibility and accessibility are limited to the function's body.
            
        - A simple diagram illustrating the input, processing, and output of a function:

            ```
                    +-----------------+
            Input:  |    Function     |
            --------|   Processing    |
                    |                 |
                    +-----------------+
                            |
                            V
                    +-----------------+
            Output: |                 |
                    |   Result        |
                    +-----------------+
            ```
            
            In this diagram:
            
            - The input represents the data or values that are provided to the function as arguments.
            - The function performs the processing or computations on the input data.
            - The output represents the result or return value produced by the function.

        - Passing Methods: 
            - By choosing the appropriate parameter passing method, you can control how data is accessed and modified within a function, allowing for flexibility and efficient programming.
            - Passing Values/Data Through Parameters To The Function:
                - 01) Passing By Value:
                    - The default behavior is known as "passing by value." This means that the function receives a copy of the argument's value, and any modifications made to the parameter within the function do not affect the original argument. 
                    - Providing data safety and isolation. 
                    -  If you want to modify the original argument within the function, you can pass it by reference or by pointer.
                    - Ex:
                        void printNumber(int num) {
                            std::cout << "Inside the function: " << num << std::endl;
                        }
                        
                        int main() {
                            int number = 10;
                            printNumber(number);  // Value of 'number' is passed by value
                            return 0;
                        }
                    
                - 02) Passing By Reference:
                    - When you pass a value by reference, you provide the function with direct access to the original argument. 
                    - Any modifications made to the parameter inside the function will affect the original argument. 
                    - This method is useful when you want to modify the original argument within the function or when dealing with larger data structures.
                    - Ex:
                        void addFive(int& num) {
                            num += 5;
                        }
                        
                        int main() {
                            int number = 10;
                            addFive(number);  // Value of 'number' is passed by reference
                            std::cout << "After the function: " << number << std::endl;
                            return 0;
                        }
                    
                - 02) Passing By Reference:
                    - When you pass a value by pointer, you pass the memory address of the argument to the function. 
                    - The function can then access and modify the argument using pointer dereferencing. 
                    - This method is similar to passing by reference but allows for more flexibility, as you can pass null pointers or dynamically allocate memory.
                     Ex:
                        void squareValue(int* numPtr) {
                            if (numPtr != nullptr) {
                                *numPtr = (*numPtr) * (*numPtr);
                            }
                        }
                        
                        int main() {
                            int number = 5;
                            int* numberPtr = &number;
                            squareValue(numberPtr);  // Address of 'number' is passed by pointer
                            std::cout << "After the function: " << number << std::endl;
                            return 0;
                        }
                
                - The different methods of passing arguments to a function in C++:
                |--------------------|--------------------------------------------------------------------------------|-----------------------------------------------------------------------------|----------------------------------------------------------|
                | Passing Method     |                     Description                                                |                     Access to Original Argument                             |             Modifications Affect Original Argument       |
                |--------------------|--------------------------------------------------------------------------------|-----------------------------------------------------------------------------|----------------------------------------------------------|
                | Pass by Value      | A copy of the argument's value is passed to the function.                      | No access to the original argument.                                         | Modifications do not affect the original argument.       |
                | Pass by Reference  | The function receives a reference to the original argument.                    | Direct access to the original argument.                                     | Modifications affect the original argument.              |
                | Pass by Pointer    | The function receives a pointer to the original argument (memory address).     | Indirect access to the original argument through pointer dereferencing.     | Modifications affect the original argument.              |
                |--------------------|--------------------------------------------------------------------------------|-----------------------------------------------------------------------------|----------------------------------------------------------|

*/


/*
    - The different parameter passing methods in C++:
        - Pass by Value: 
            - In pass by value, a copy of the argument is made and passed to the function. 
            - Modifications made to the parameter within the function do not affect the original argument.

        - Pass by Const Value: 
            - Pass by const value is similar to pass by value, but the parameter is declared as const. 
            - This means that the function cannot modify the value of the parameter.

        - Pass by Pointer: 
            - Pass by pointer involves passing the memory address of the argument to the function. 
            - This allows the function to directly access and modify the value pointed to by the pointer. 
            - It also allows passing a null pointer to indicate the absence of a valid value.

        - Pass by Pointer to Const: 
            - Pass by pointer to const is similar to pass by pointer, but the parameter is declared as a const pointer. 
            - This means that the function cannot modify the value pointed to by the pointer.

        - Pass by Reference: 
            - Pass by reference involves passing a reference to the argument. 
            - This allows the function to directly access and modify the original value of the argument. 
            - Any changes made to the parameter within the function are reflected outside the function.

        - Pass by Const Reference: 
            - Pass by const reference is similar to pass by reference, but the parameter is declared as a const reference. 
            - This means that the function cannot modify the original value of the argument.
    
    - Each passing method has its use cases depending on the specific requirements of the function and the desired behavior. 
        - Pass by value is used when you want to work with a local copy of the argument. 
        - Pass by const value and pass by const reference are used when you want to prevent modifications to the argument. 
        - Pass by pointer and pass by pointer to const are used when you need to work with memory addresses or when you want to allow the argument to be optional (null pointer). 
        - Pass by reference is used when you want to directly modify the original argument and have the changes reflected outside the function.

    - It's important to choose the appropriate passing method based on factors such as efficiency, data size, desired behavior, and the need for modification.
*/

/*
    - Passed By Value:
        - Value Copying:
            - When the function is called, the value of the argument is copied into the function's parameter. 
            - This creates a separate memory space for the parameter within the function.
        - Local Parameter Usage:
            - Inside the function, the parameter acts as a local variable. 
            - Any modifications made to the parameter are performed on this local copy, not on the original value.
        - Scope Limitation:
            - Since the parameter is a local variable within the function, it is only accessible within the function's scope. 
            - Changes made to the parameter do not affect the original value in the calling code.
    
    - Passing by value allows you to work with local copies of the arguments within the function, providing a level of isolation and ensuring that the original values are not modified.
*/

// Function that accepts an integer parameter by value
void func_passed_by_value(int num) 
{
    num++;  // Modify the local copy of 'num'
    std::cout << "Inside the function: " << num << std::endl;
}

void cpp_func_params_passed_by()
{
    int num = 10;
    std::cout << "Before function call: " << num << std::endl;
    
    func_passed_by_value(num);  // Pass 'num' by value to the function
    
    std::cout << "After function call: " << num << std::endl;
}

/*
    - Pass by const value:
        - Is a variation of pass by value, where the parameter is declared as a constant value within the function. 
        - It allows you to pass arguments by value, ensuring that the function cannot modify the parameter. 
        - Is useful when you want to pass arguments by value but also ensure that the function does not modify the parameter.
        - It provides a level of safety and guarantees that the original value remains unchanged.
        - Notes:
            - Passing large objects or complex data structures by const value can still involve the overhead of copying the entire object.
            - In such cases, passing by const reference or const pointer may be more efficient.
*/

// Function that accepts a string parameter by const value
void func_passed_by_const_value(const std::string message) 
{
    // Attempting to modify 'message' will result in a compilation error
    // message = "Updated message";  // Error: assignment of read-only parameter 'message'
    std::cout << "Inside the function: " << message << std::endl;
}


void cpp_func_params_passed_by_const_value()
{
    std::string message = "Hello, world!";
    std::cout << "Before function call: " << message << std::endl;

    func_passed_by_const_value(message);  // Pass 'message' by const value to the function

    std::cout << "After function call: " << message << std::endl;

    
}


/*
    -  Pass by pointer:
        - Is a method of passing arguments to a function in C++ by providing the memory address of the argument. 
        - By passing arguments by pointer, you can directly modify the original data within the function. 
        - The pointer is dereferenced using the * operator to modify the value pointed to.
        - By modifying the value at the memory address passed to the function, the original value will be changing too.
        - To pass an argument by pointer, the address of the argument is obtained using the & operator in the function call. 
        - This allows the function to work directly with the memory location of the original data.
        - Passing by pointer is useful when you want to modify the original value of the argument within the function and have those changes reflected outside the function. 
        -  It allows for more direct manipulation of data and can be particularly useful when working with large objects or dynamically allocated memory.
        - However, it requires careful handling of memory addresses and pointer operations to avoid potential issues such as null pointers or invalid memory access.
*/

// Function that accepts an integer parameter by pointer
void func_passed_by_pointer(int* numPtr) 
{
    (*numPtr) *= (*numPtr);  // Dereference the pointer to square the value
}

void cpp_func_params_passed_by_pointer()
{
    int num = 5;
    std::cout << "Before function call: " << num << std::endl;

    func_passed_by_pointer(&num);  // Pass the address of 'num' to the function

    std::cout << "After function call: " << num << std::endl;
}

/*
    - Passing by pointer to const:
        - Is a method of passing arguments to a function in C++ where the parameter is a pointer to a constant value. 
        - It allows you to pass a pointer to data that cannot be modified within the function. 
        - The const qualifier ensures that the value pointed to cannot be modified within the function. 
        - If we attempt to modify the value pointed to by, it will result in a compilation error.
        - Passing by pointer to const allows you to provide a pointer to data that should not be modified within the function, ensuring that the original value is not changed. 
        - It's useful when you want to pass data by pointer for performance reasons but want to enforce immutability of the data within the function.
        - Notes: 
            - When passing by pointer to const, it's important to ensure that the pointer is valid and points to a valid memory location. 
            - Additionally, the function can still access and read the value pointed by the pointer, but it cannot modify it.
*/

// Function that accepts a pointer to a constant string
void func_passed_by_pointer_to_const(const char* message) 
{
    std::cout << "Inside the function: " << message << std::endl;
    // Attempting to modify the value pointed by 'message' will result in a compilation error
    // message[0] = 'H';  // Error: assignment of read-only location '* message'
}

void cpp_func_params_passed_by_pointer_to_const()
{
    const char* message = "Hello, world!";
    std::cout << "Before function call: " << message << std::endl;

    func_passed_by_pointer_to_const(message);  // Pass the pointer to the constant string to the function

    std::cout << "After function call: " << message << std::endl;

}

/*
    - Passing by reference:
        - Is a method of passing arguments to a function in C++ by providing a reference to the original data rather than making a copy of it. 
        - By passing arguments by reference, any modifications made to the parameter within the function directly affect the original data. 
        - To pass an argument by reference, you simply specify the reference type in the function parameter declaration by using the & symbol. 
        - This allows you to work directly with the original data rather than creating a copy.
        - Passing by reference is useful when you want to modify the original value of the argument within the function and have those changes reflected outside the function.
        - It provides a more efficient way of working with data compared to passing by value because it avoids the overhead of copying large objects or data structures.
        - Notes: 
            - When passing by reference, the original data must be valid and accessible within the scope of the function call. 
            - Additionally, passing by reference allows for more efficient and natural-looking code, but it requires careful consideration to ensure that unintended modifications or lifetime issues do not arise.
*/

// Function that accepts an integer parameter by reference
void func_passed_by_reference(int& numRef)
{
    numRef++;  // Modify the original value directly
}

void cpp_func_params_passed_by_reference()
{
    int num = 10;
    std::cout << "Before function call: " << num << std::endl;

    func_passed_by_reference(num);  // Pass 'num' by reference to the function

    std::cout << "After function call: " << num << std::endl;
}

/*
    - Array function parameters:
        - In C++, arrays can be passed as function parameters using different methods. 
        - Here are the commonly used ways to pass arrays as function parameters:
            - 01) Pass by Pointer:
                - Syntax: 
                    void functionName(type* arrayName, size);
                - In this method, you pass a pointer to the first element of the array as the function parameter.
                - The function can access and modify the elements of the array using pointer arithmetic. 
            
            - 02) Pass by Reference:
                - Syntax: 
                    void functionName(type (&arrayName)[size]);
                - In this method, you pass the array by reference to the function. 
                - The function can directly access and modify the elements of the array. 
            
            - 03) Pass by Pointer to const:
                - Syntax: 
                    void functionName(const type* arrayName, size);
                - If you want to pass the array to a function without allowing the function to modify the elements, you can pass a pointer to const. 
                - he function can access the elements but cannot modify them. 
            
            - 04) Pass by Array:
                - Syntax: 
                    void functionName(type arrayName[size]);
                - In this method, you can pass the array by specifying its size in the function parameter. 
                - This method is mostly used when dealing with fixed-size arrays. 

        - Notes:
            - Note that specifying the size of the array in the function parameter is optional, and it can be omitted. 
            - However, it can provide additional information to the function about the array's size.
            - It's important to remember that arrays in C++ decay to pointers when passed as function arguments. 
            - Therefore, the size information is typically required to properly iterate over the elements of the array inside the function.
*/

// Use the ARRAY_SIZE macro to get the size of the array
// !!!!! IMPORTANT NOTE !!!!!
//    I Used The Macro C-Style "The Hard Way". Because I want to explain
//    What is going on the behind of the scene in details.
//    BTW, I Can use std::size(arrayName) from <array> header.
//    But, It will prevent me to have more knowledge How its done.
//    Also, Because, I Like C-Style Programming.
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
    /*
        - The ARRAY_SIZE macro is a commonly used macro in C and C++ to determine the size of an array. 
        - The ARRAY_SIZE macro is used to avoid hard-coding the size of the array manually and allows for automatic calculation based on the number of elements present.
        - It is a convenient way to determine the size of an array, especially when dealing with arrays of varying lengths or dynamic arrays.
        - The macro provides a concise and efficient way to determine the size of an array without explicitly specifying it.
        - It calculates the number of elements in an array by dividing the total size of the array by the size of a single element.
        - sizeof(arr): 
            - The sizeof operator is used to determine the total size of the array arr in bytes.
            -  It calculates the size based on the number of elements multiplied by the size of each element.
        - sizeof(arr[0]):
            - The sizeof operator is also used to determine the size of a single element in the array arr. 
            - By accessing arr[0], which represents the first element of the array, we can get the size of that element in bytes.
        - (sizeof(arr) / sizeof(arr[0])): 
            - This division operation calculates the number of elements in the array by dividing the total size of the array by the size of a single element. 
            - It yields the result as an integer value, representing the number of elements in the array.

        - Example:
            #include <iostream>

            #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
            
            int main()
            {
                int myArray[] = {1, 2, 3, 4, 5};
                int size = ARRAY_SIZE(myArray);
            
                std::cout << "Array size: " << size << std::endl;
            
                return 0;
            }
    */

// - 01) Pass by Pointer:
// Function that takes an array as a parameter using pass by pointer
void array_parameters_pass_by_pointer(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void array_function_parameters_pass_by_pointer() 
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Call the function and pass the array by pointer
    array_parameters_pass_by_pointer(myArray, ARRAY_SIZE(myArray));
}

// - 02) Pass by Reference:
// Function that takes an array as a parameter using pass by reference
void array_function_parameters_pass_by_reference(int (&arr)[], int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void array_parameters_pass_by_reference()
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Call the function and pass the array by reference
    array_function_parameters_pass_by_reference(myArray, ARRAY_SIZE(myArray));
}

// - 03) Pass by Pointer to const:
// Function that takes an array as a parameter using pass by pointer to const
// The const qualifier ensures that the elements of the array are read-only and cannot be modified inside the function. 
void array_function_parameters_pass_by_pointer_to_const(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void array_parameters_pass_by_pointer_to_const()
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Call the function and pass the array by pointer to const
    array_function_parameters_pass_by_pointer_to_const(myArray, ARRAY_SIZE(myArray));
}


// - 04) Pass by Array:
// Function takes an array arr[] as a parameter, along with the size of the array size. 
// By passing the array as a pointer to the first element, you effectively pass the array to the function. 
// The function can access the elements using pointer arithmetic. 
// Note that the size of the array is required to properly iterate over its elements inside the function.
void array_function_parameters_pass_by_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void array_parameters_pass_by_array()
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Call the function and pass the array by array pointer
    array_function_parameters_pass_by_array(myArray, ARRAY_SIZE(myArray));
}

/*
    - Sized array function parameters:
        - In C and C++, you can pass sized arrays as function parameters using a feature known as array function parameters. 
        -  This feature allows you to specify the size of the array directly in the function parameter declaration.
        - Syntax:
            - void functionName(type parameterName[size]);
        - Usage:
            - Sized array function parameters provide a way to indicate the expected size of the array directly in the function signature. 
            - This can serve as documentation to other developers using the function.
        - Array Decay:
            - When an array is passed to a function, it typically decays into a pointer to its first element. 
            - However, with sized array function parameters, the size information is retained, allowing the function to know the expected size of the array.
        - Compile-Time Checking:
            - Using a sized array function parameter allows the compiler to perform some compile-time checks.
            - It can issue warnings or errors if you try to pass an array of incompatible size or if the array size does not match the expected size specified in the function parameter.
        - Limitations:
            - While sized array function parameters provide a way to indicate the size of an array, they have limitations. 
            - For example, the size information is not enforced by the language, and the function can still be called with arrays of different sizes. 
            - Additionally, using sized array function parameters can make the code less flexible and harder to maintain if the array size needs to change.
        - Alternative Approaches:
            - Instead of relying solely on sized array function parameters, 
              alternative approaches include passing arrays along with their sizes as separate parameters or using pointer-based approaches, 
              such as passing a pointer to the array and the size of the array as separate parameters.
        - Notes:
            - It's important to note that sized array function parameters are less commonly used in practice compared to other methods of passing arrays and their sizes. 
            - The choice of passing arrays depends on the specific requirements of the code and the desired flexibility.
*/
// Function takes an array parameter arr with a specified size of [5]. Inside the function, a loop is used to iterate over the elements of the array and print them.
void print_with_sized_array(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void func_with_sized_array()
{
    int myArray[] = {5, 6, 7, 8, 9};

    // Call the function and pass the sized array
    print_with_sized_array(myArray);
}

























#endif









