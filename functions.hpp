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
    - The Call Stack:
        - The call stack is a crucial data structure used by programs to manage function calls and control flow during program execution. 
        -  It's a fundamental concept in computer science and programming, and it plays a significant role in languages like C++.
        - Here's an overview of what the call stack is and how it works:
            - Definition: 
                - The call stack is a region of memory used to manage function calls and their corresponding activation records (stack frames). 
                - It operates on a Last-In-First-Out (LIFO) basis, meaning the most recent function call made is the first one to be completed and removed from the stack.
            - Function Calls: 
                - Whenever a function is called in a program, a new activation record (stack frame) is created and pushed onto the call stack. 
                - This record contains information about the function's local variables, parameters, return address, and other necessary bookkeeping data.
            - Stack Frames (Activation Record): 
                - A stack frame, also known as an activation record, is a data structure associated with a function call. 
                - It contains various pieces of information needed to manage the execution of that function. 
                - Each time a function is called, a new stack frame is created and pushed onto the call stack. 
                - Each stack frame corresponds to a single function call. 
                - It contains the function's local variables and parameters, as well as any other data associated with the function's execution. 
                - The return address stored in the frame indicates where the program should resume execution after the function call completes.
                - Here's what a typical stack frame might include:
                    - Local Variables: 
                        - Memory space for the function's local variables is allocated within the stack frame. 
                        - Local variables are those declared within the function and are only accessible within that function's scope.
                    - Function Parameters: 
                        - The function's parameters, which are passed when the function is called, are also stored within the stack frame. 
                        - These are the values that the function works with.
                    - Return Address:
                        - The return address is the memory address of the instruction that needs to be executed after the function call completes. 
                        - It's stored in the stack frame so that when the function completes, the program knows where to continue executing.
                    - Previous Frame Pointer: 
                        - This is a reference to the previous stack frame. 
                        - It helps in maintaining the sequence of stack frames and the order of function calls.
                    - Exception Handling Data: 
                        - Some compilers add information for exception handling, allowing the program to correctly unwind the stack in the event of an exception.
            - Stack Operations: 
                - When a function call is made, a new stack frame is pushed onto the stack. When the function call completes, the corresponding frame is popped from the stack, and program execution resumes at the return address stored in the previous frame. 
                - This allows the program to continue where it left off before the function call.
            - Call Stack Management:
                - The call stack operates as a LIFO data structure, which means that the most recently added item (stack frame) is the first to be removed. 
                - Here's how the call stack is managed during function calls:
                    - Function Call: 
                        - When a function is called, a new stack frame is created and its information is pushed onto the call stack. 
                        - This includes the local variables, parameters, return address, and other necessary data.
                    - Function Execution: 
                        - The function's code executes within the context of its stack frame.
                        - t can access its local variables and parameters as if they were ordinary variables.
                    - Nested Function Calls: 
                        - If the function being executed calls another function, a new stack frame is created for the called function.
                        - The new frame is pushed on top of the current one.
                    - Function Return:
                        - When a function completes its execution, it returns control to the calling function. 
                        - The stack frame associated with the completed function call is popped from the stack. 
                        - The return address guides the program to the next instruction after the function call.
            - Recursion: 
                - The call stack is essential for handling recursive function calls. 
                - Each recursive call creates a new stack frame, allowing the function to operate on different sets of data. 
                - As each recursive call completes, its stack frame is popped, and the program continues with the data from the previous frame.
            - Recursion and the Call Stack:
                - Recursion is a process where a function calls itself. 
                - Each recursive call results in a new stack frame being created. 
                - The call stack allows each recursive call to have its own set of local variables and parameters, ensuring that they don't interfere with each other.                
            - Stack Overflow:
                - The call stack has a finite size. 
                - If a program makes too many nested function calls or recursive calls, the stack can become exhausted, leading to a stack overflow error. 
                - This occurs when there's no more space on the stack to accommodate new stack frames.
            - Exception Handling: 
                - The call stack also plays a role in handling exceptions. 
                - When an exception is thrown, the program unwinds the call stack, looking for an appropriate exception handler. 
                - As it unwinds, it cleans up stack frames and resources allocated within those frames.
        - In summary:
            - The call stack is a critical part of managing function calls, local variables, and control flow in C++ programs.
            - It allows for organized and efficient execution of functions while maintaining isolation between different function calls.
            - Understanding how the call stack works is essential for writing correct and efficient code, especially when dealing with recursion, complex control flow, and exception handling.
        - Here's how the call stack would look during the execution of the factorial function in this 
         - Code:
            
                int factorial(int n) {
                    if (n <= 1)
                        return 1;
                    else
                        return n * factorial(n - 1);
                }
                
                int main() {
                    int result = factorial(4);
                    std::cout << "Factorial: " << result << std::endl;
                    return 0;
                }
        - Diagram:
            Main Call Stack:
            ----------------
            | main()         |
            |                |
            ----------------
            
            factorial(4) Call Stack:
            --------------------------
            | factorial(4)           |
            | n = 4                  |
            | return address: ______ |     (1)
            --------------------------
            
            factorial(3) Call Stack:
            --------------------------
            | factorial(3)           |
            | n = 3                  |
            | return address: ______ |     (2)
            --------------------------
            | factorial(4)           |
            | n = 4                  |
            | return address: ______ |     (1)
            --------------------------
            
            factorial(2) Call Stack:
            --------------------------
            | factorial(2)           |
            | n = 2                  |
            | return address: ______ |     (3)
            --------------------------
            | factorial(3)           |
            | n = 3                  |
            | return address: ______ |     (2)
            --------------------------
            | factorial(4)           |
            | n = 4                  |
            | return address: ______ |     (1)
            --------------------------
            
            factorial(1) Call Stack:
            --------------------------
            | factorial(1)           |
            | n = 1                  |
            | return address: ______ |     (4)
            --------------------------
            | factorial(2)           |
            | n = 2                  |
            | return address: ______ |     (3)
            --------------------------
            | factorial(3)           |
            | n = 3                  |
            | return address: ______ |     (2)
            --------------------------
            | factorial(4)           |
            | n = 4                  |
            | return address: ______ |     (1)
            --------------------------
        - Explaination:
            - The "Main Call Stack" represents the initial state with just the main() function.
            - As the factorial function is called with different values of n, new stack frames are created and pushed on top of the stack.
            - The return address in each stack frame points to where the program should continue after the function call completes.
            - The stack frame at the top represents the currently executing function.
            - As each function completes its execution, its stack frame is popped off the stack.
            - This process continues until the base case of the recursion is reached (n <= 1), and then the stack unwinds as the results are calculated.
            - This is a simplified representation, but it illustrates how the call stack manages function calls, parameters, local variables, and control flow.
            
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

/*
    - Passing sized arrays by reference
        - In C++, you can pass a sized array by reference using a reference to an array type. 
        - By passing the array by reference, you provide the function direct access to the original array without making a copy. 
        - The sized array reference parameter ensures that the function works with arrays of the expected size.
        - It's important to note that passing arrays by reference in this way is a C++ feature and not available in the C language.
        - Passing sized arrays by reference in C++ provides several advantages and features.
        - Here are some additional details about passing sized arrays by reference:
            - 01) Direct Access and Modifiability: 
                - By passing the array by reference, the function gains direct access to the original array. 
                - This allows the function to read and modify the array elements directly without making a copy. 
                - Any changes made to the array inside the function will be reflected in the original array.
            - 02) Size Enforcement: 
                - By specifying the size of the array in the reference parameter, you enforce that only arrays of the specified size can be passed to the function. 
                - This can provide compile-time safety by preventing accidental usage of arrays with different sizes.
            - 03) Avoiding Array Decay: 
                - In C++, arrays passed by reference do not decay into pointers. 
                - Unlike passing arrays by pointer, passing by reference retains the array's original type and size information. 
                - This can be useful when you need to work with the actual array type, such as when using array-specific operations or when preserving multidimensional array dimensions.                
            - 04) Flexibility: 
                - When passing arrays by reference, you can easily work with arrays of varying sizes. 
                - By changing the size in the reference parameter, you can adapt the function to handle arrays of different sizes, as long as the sizes are known at compile-time.
            - 05) Simplified Syntax: 
                - Using a reference to an array as a function parameter provides a concise and clear syntax.
                -  It allows you to work with the array in a natural manner without the need for pointer dereferencing or explicit size calculations.
            - 06) Readability and Documentation: 
                - Passing arrays by reference with a specified size in the function parameter enhances code readability and serves as self-documentation.
                - It communicates the expected size of the array to other developers using the function.
*/

void print_with_sized_array_passed_by_ref(int (&arr)[5])
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void func_with_sized_array_passed_by_ref()
{
    int myArray[] = {1, 2, 3, 4, 5};

    // Call the function and pass the sized array by reference
    print_with_sized_array_passed_by_ref(myArray);
}

/*
    - Multi dimensional array function parameter:
        - In C and C++, you can pass multi-dimensional arrays as function parameters. 
        - When passing multi-dimensional arrays, the size of all dimensions except the first one must be specified. 
        - By passing the 2D array as a function parameter, you can perform operations on the array inside the function while preserving its dimensions and element values.
        - Note that when passing multi-dimensional arrays as function parameters, you must specify the sizes of all dimensions except the first one. 
        - The first dimension's size is optional, as it is automatically deduced from the size of the array being passed.
        - Here are some additional details about passing multi-dimensional arrays as function parameters:
            - Array Size Deduction: 
                - When passing a multi-dimensional array to a function, the size of the first dimension is usually deduced automatically. 
                - This means you don't need to specify the size of the first dimension explicitly. 
                - However, you must specify the sizes of all subsequent dimensions.
            
            - Row-Major Order: 
                - Multi-dimensional arrays in C and C++ are typically stored in row-major order. 
                - This means that the elements of each row are stored consecutively in memory. 
                - When passing a multi-dimensional array to a function, you can access its elements using nested loops, iterating over the rows and columns.
            
            - Array Decay: 
                - When passing a multi-dimensional array to a function, it decays into a pointer to its first element. 
                - This pointer can be used to access and manipulate the array elements inside the function. 
                - However, note that the size information of the dimensions other than the first one is lost during array decay.
            
            - Flexibility: 
                - The size of the first dimension of a multi-dimensional array passed to a function can be dynamic or determined at runtime. 
                - However, the sizes of subsequent dimensions must be known at compile-time. 
                - This allows you to work with multi-dimensional arrays of different sizes within the function.
            
            - Memory Efficiency: 
                - When passing multi-dimensional arrays as function parameters, keep in mind that the entire array is typically copied into the function's stack frame. 
                - If the array is large, this can result in increased memory usage. 
                - In such cases, passing the array by pointer or using dynamic memory allocation might be more memory-efficient.
            
            - Type Safety: 
                - When passing multi-dimensional arrays as function parameters, it's important to ensure that the array dimensions match between the function declaration and the function call. 
                - Mismatched dimensions can lead to undefined behavior or runtime errors.
            
            - Alternative Approaches: 
                - In addition to passing multi-dimensional arrays directly, you can also pass arrays of pointers to arrays. 
                - This approach allows for more flexibility in handling multi-dimensional arrays of varying sizes, but it involves additional memory management.
        
        - Remember to consider the requirements of your specific program and choose the appropriate approach for passing multi-dimensional arrays based on factors such as memory usage, flexibility, and type safety.
*/

void print_with_multi_dim_passed_as_params(int matrix[][3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void func_with_multi_dim_passed_as_params()
{
    int myMatrix[][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    // Call the function and pass the 2D array
    print_with_multi_dim_passed_as_params(myMatrix, 3);
}

/*
    - Default function arguments:
        - In C++ allow you to specify default values for function parameters. 
        - These default values are used when the corresponding arguments are not provided during function calls. 
        - Here are some additional details about default function arguments in C++:
            - 01) Placement and Declaration: 
                - Default function arguments are specified in the function declaration or prototype, typically in the corresponding header file. 
                - They are not repeated in the function definition. 
                - Default arguments are placed at the end of the argument list, meaning that all arguments to the right of the default argument must also have default values.
        
            - 02) Default Values: 
                - Default values can be of any valid type in C++, including fundamental types (e.g., int, float), pointers, references, and even user-defined types. 
                - The default value can be a constant, a variable, or an expression.
        
            - 03) Function Overloading: 
                - Default arguments are often used in conjunction with function overloading to provide multiple versions of a function with different sets of default values. 
                - This allows callers to choose which arguments to provide explicitly and which ones to use the defaults for.
        
            - 04) Order of Evaluation: 
                - The default arguments are evaluated at the point of the function call. 
                - This means that if a default argument is an expression involving other arguments, those arguments are evaluated before the default argument is determined.
        
            - 05) Forward Declaration: 
                - If a function with default arguments is forward declared in a header file, the default argument values must be provided in the header file itself. 
                - The values cannot be specified in a separate source file.
        
            - 06) Changing Default Values: 
                - It's possible to change the default values of function arguments by redeclaring the function with different default values. 
                - However, be cautious when changing default values, as it can affect existing code that relies on the original defaults.
        
            - 07) Avoiding Default Arguments in Headers: 
                - It's generally recommended to avoid default arguments in function declarations placed in header files to prevent potential compatibility issues. 
                - Instead, consider using function overloading or separate functions with different names to achieve similar behavior.
        
            - 08) Default Arguments and Function Pointers: 
                - When using function pointers, it's important to note that the default arguments are not part of the function type. 
                - Therefore, if you pass a function pointer to a function with default arguments, you need to ensure that the correct number and types of arguments are provided.

        - Note:
            - Default function arguments in C++ provide a convenient way to define functions with flexible parameter sets. 
            - They allow you to specify default values that are used when the corresponding arguments are omitted during function calls, enhancing code readability and reducing the need for repetitive argument specifications.
*/

void print_message_with_default_argument(const std::string& message = "Hello, World!")
{
    std::cout << message << std::endl;
}

void print_numbers_with_default_argument(int start, int end = 10, int step = 1)
{
    for (int i = start; i <= end; i += step)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void func_print_message_and_numbers_with_default_argument()
{
    // Example 1: Default argument for print_message_with_default_argument
    print_message_with_default_argument();                     // Prints "Hello, World!"
    print_message_with_default_argument("Greetings!");         // Prints "Greetings!"

    // Example 2: Default arguments for print_numbers_with_default_argument
    print_numbers_with_default_argument(1);                    // Prints numbers from 1 to 10 with a step of 1
    print_numbers_with_default_argument(2, 20);                 // Prints numbers from 2 to 20 with a step of 1
    print_numbers_with_default_argument(10, 100, 10);           // Prints numbers from 10 to 100 with a step of 10

}


/*
    - String View as a Parameter:
        - In C++, std::string_view is a lightweight class introduced in C++17 that provides a non-owning, read-only view of a sequence of characters. 
        - It serves as an alternative to passing strings by value or const reference, allowing you to efficiently work with string data without the need for memory allocation or copying.
        - Benefits:
            - Efficient: 
                - std::string_view avoids the overhead of copying or allocating memory since it does not own the underlying data.
            - Lightweight: 
                - It only consists of a pointer to the data and a size, resulting in a small object size.
            - Flexibility: 
                - It can be used to represent a substring or a view into a larger string.
        - Common operations:
            - Accessing data: 
                - Use the data() member function to obtain a pointer to the underlying character data. 
                - The size() member function gives you the length of the string vi
            - Comparisons: 
                - You can compare std::string_view objects using comparison operators (==, !=, <, >, etc.) or use the compare() member function.
            - Substring operations: 
                - std::string_view supports substring extraction using the substr() member function, allowing you to obtain a new string view representing a portion of the original string view.
            - Iteration: 
                - You can iterate over the characters of a std::string_view using standard iterators.
        - Lifetime considerations:
            - It's important to ensure that the lifetime of the underlying string data is valid and longer than the std::string_view itself. 
            - std::string_view does not manage the memory or lifetime of the data it refers to, so it's crucial to avoid accessing invalidated or freed memory.

        -Notes:
            - By using std::string_view as a parameter, you can pass strings or substrings efficiently, minimizing memory overhead and potentially improving the performance of your code. 
            - It's particularly useful when you need read-only access to the string data within a function or when passing string-like data to functions without making unnecessary copies.
*/

void process_substring_string_view_passed_as_a_param(std::string_view str) {
    std::cout << "Processing substring: " << str << std::endl;
    // Perform operations on the string view
    std::cout << "Length of substring: " << str.length() << std::endl;
    std::cout << "First character: " << str.front() << std::endl;
    std::cout << "Last character: " << str.back() << std::endl;
}

void func_string_view_passed_as_a_param() {
    std::string fullString = "Hello, World!";

    // Pass a substring to the function
    std::string_view substring1(fullString.data() + 7, 5);
    process_substring_string_view_passed_as_a_param(substring1);

    // Pass the full string
    std::string_view substring2(fullString);
    process_substring_string_view_passed_as_a_param(substring2);
}


/*
    - constexpr function:
        - Compile-Time Evaluation: 
            - A constexpr function is evaluated at compile-time rather than runtime. 
            - This means that its result is computed during the compilation process, and the computed value is used wherever the function is called with constant expressions as arguments.
        - Compile-Time Constants:
            - constexpr functions enable the generation of compile-time constants, which can be used in various parts of the program.
            - These constants are known and determined during the compilation process, providing efficiency and the ability to use them in other compile-time computations.
        - Requirements for constexpr Functions:
            - The function must have a literal type, which includes fundamental types, arrays, structures, and classes that meet certain criteria (e.g., having a constexpr constructor).
            - The function must be defined in a way that allows the compiler to evaluate it at compile-time. 
            - This includes having a body that consists of a single return statement and performing only computationally deterministic operations.
        - Constant Expressions: 
            - A constexpr function can be used in constant expressions, meaning that it can participate in compile-time computations. 
            - This allows you to perform calculations, initialize variables, and create compile-time constants using the constexpr function.
        - Improving Performance: 
            - Using constexpr functions can lead to improved performance by enabling computations to be done at compile-time instead of runtime. 
            - This reduces the need for the same calculations to be performed repeatedly during program execution.
        - Expanded Functionality: 
            - constexpr functions can perform operations that are not typically allowed in regular runtime functions. 
            - They can use if-statements, loops, and other control flow constructs, as long as they can be evaluated at compile-time.
        - Recursive constexpr Functions: 
            - C++ allows constexpr functions to be recursive, meaning they can call themselves. 
            - However, the recursion must be done in a way that allows the compiler to evaluate the function at compile-time, such as using conditional statements to terminate the recursion.
        - Usage Examples: 
            - Common use cases for constexpr functions include computing mathematical constants, generating lookup tables, performing compile-time validations, and providing compile-time configurations.
        - Non-constexpr Contexts:
            - Although constexpr functions are evaluated at compile-time, they can still be used in non-constexpr contexts where runtime execution is required.
            - In such cases, the constexpr function behaves like a regular function and is evaluated at runtime.
        - Performance Benefits:
            - Using constexpr functions can improve program performance by allowing computations to be done at compile-time.
            - This reduces the need for the same calculations to be performed repeatedly at runtime.
        
        - Notes:
            - It's important to note that the constexpr keyword is a hint to the compiler, indicating that the function can be evaluated at compile-time. 
            - The compiler may choose to evaluate the function at compile-time or fall back to runtime evaluation if necessary.
            - By utilizing constexpr functions effectively, you can leverage compile-time evaluation to improve performance, create compile-time constants, and perform complex computations during the compilation process rather than at runtime.
            - constexpr functions can also be used in non-constexpr contexts, where they are evaluated at runtime like regular functions.
*/
// Fibonacci function using constexpr
constexpr int fibonacci_by_constexpr_function(int n)
{
    // Base cases: Fibonacci sequence starts with 0 and 1
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        // Recursive call to calculate the Fibonacci number
        return fibonacci_by_constexpr_function(n - 1) + fibonacci_by_constexpr_function(n - 2);
}

void func_fibonacci_by_constexpr_function()
{
    // Calculate Fibonacci number at compile-time
    constexpr int fibNum = fibonacci_by_constexpr_function(10);

    std::cout << "The 10th Fibonacci number is: " << fibNum << std::endl;
}


/*
    - consteval function:
        - consteval is a new keyword introduced in C++20 to specify that a function must be evaluated at compile-time. 
        - It is similar to constexpr functions but with more stringent requirements and guarantees. 
        - Evaluation at Compile-Time:
            - A consteval function is explicitly specified to be evaluated at compile-time, ensuring that it is only called in contexts where compile-time evaluation is required.
            - Unlike constexpr functions, which can be evaluated at either compile-time or runtime, consteval functions must be evaluated strictly at compile-time.
        - Limited Use in Constant Expressions:
            - consteval functions can only be used in constant expressions, ensuring that they are evaluated during the compilation phase.
            - They enable the generation of constant values and computations that can be known and determined at compile-time.
        - Stringent Requirements:
            - consteval functions have more stringent requirements than constexpr functions:
                - The function must be defined as consteval in both its declaration and definition.
                - The function body should consist of a single return statement and must not contain any statements or operations that cannot be evaluated at compile-time.
                - The parameters and return types of consteval functions must be literal types.
        - Compile-Time Error Checking:
            - consteval functions provide compile-time error checking for their arguments and expressions.
            - This allows the compiler to catch errors and issue diagnostic messages during the compilation process, preventing potential issues at runtime.
        - Explicit Compile-Time Behavior:
            - By using consteval, you explicitly communicate your intent to have the function evaluated strictly at compile-time.
            - This can improve program efficiency by ensuring that the function is only called in contexts where compile-time evaluation is required.
        - Performance and Optimization:
            - consteval functions offer potential performance benefits by allowing computations to be performed during compilation, reducing the need for runtime calculations.
            - They enable the generation of efficient code by leveraging compile-time evaluation for constant expressions.
        - Limitations and Trade-offs:
            - The stringent requirements of consteval functions impose restrictions on their usage, as they must adhere to compile-time evaluation rules strictly.
            - The trade-off is that some computations or operations that are valid in constexpr functions may not be allowed in consteval functions.

        - Notes:
            - It's important to note that consteval is a C++20 feature and may not be supported in earlier versions of the language. 
            - The introduction of consteval expands the possibilities for compile-time evaluation and empowers developers to explicitly control when and where computations occur during the compilation process.
*/

// consteval function to calculate the factorial of a number
consteval int fibonacci_by_consteval_function(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fibonacci_by_consteval_function(n - 1);
}

void func_fibonacci_by_consteval_function()
{
    constexpr int num = 5;
    constexpr int result = fibonacci_by_consteval_function(num);

    std::cout << "Factorial of " << num << " is: " << result << std::endl;
}





















#endif









