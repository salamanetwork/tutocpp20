# tutocpp20:
                ( My Tutorial's Journey On C++ 20 ) || ( Modern C++ ) = starts at 1 June 2023
    Notes:
    - I Like To Document Every Steps I Have Been Done. Therefore, I Wrote A Heavy Commentaries On Each File.
    - I Kept All The Source Code Files Naked To Your Eyes As '.hpp' Header Files, You Do NOT Need To Compile It.
    - This Code Repository Is Available As A Free To Use For Everyone, Permission Granted.

###### Hints:
    This is not my first attempt to start this journey.
    I think there are 10 or more attempts.
    By the way I completed many courses before, but I keep doing that since 2003. 
    Finally I decided to note down and keep logging my progress. 
    May I hope it will help me and some people too.

###### For Future Me:
    - I Really, Did A Great Job Here 💪.
    - I Should Know When I Must Stop! 🫷.
    - I Love Classic Programming At The Most 😍.
    - I Love C-Style Syntax Programming Forever 🥰.
    - Keep It Up, HALAL Way! 😉.
    - ChatGPT Is Your Friend, Not Your Enemy 😉.
    - AI Keeps Its Eyes On You, But It Will Never Ever Beats You 😜.
    - Python For Smart People. Let's Face The Truth "I Am Not!", But I Am Seeking Professionalism 😂.
    - Love Myself Before Seeking Someone Loves Me 🤪.
    - CTRL+S: Saves Lives After Every One Line Of The Code, But It Keeps Destroying The Keyboards 💸.

## Usage:
    01)    Using Your Favorit Editor, or IDE.
    02)    Open file "main.cpp".
    03)    Include any file has extension ".hpp" -> (e.g: #include "functions.hpp").
    04)    Call any function inside the file you included in step 3.
    05)    Use any Command from utilities section below depends on your OS (Windows, Linux, macOS, ...).

## Utilities:
    
  ##### bash 'UNIX-Like':
    clear && g++ -std=c++2a *.cpp -o main && ./main
    
  ##### pwsh 'Windows':
    cls && g++.exe -std=c++2a *.cpp -o main.exe && main.exe

## Files Index:
  ### These are the files I coded ordered by LIFO (The recent one is the last one on the below list):
    00001)    main.cpp
    00002)    std_ios.hpp
    00003)    data_types.hpp
    00004)    std_math.hpp
    00005)    rock_paper_scissor_game.hpp
    00006)    data_conversion.hpp
    00007)    bitwise_ops.hpp
    00008)    variables_lifetime_scopes.hpp
    00009)    control_flow.hpp
    00010)    loops.hpp 
    00011)    arrays.hpp
    00012)    pointers.hpp
    00013)    dyn_mem_alloc.hpp
    00014)    references.hpp
    00015)    strings.hpp
    00016)    functions.hpp
    00017)    compilation.hpp
    00018)    enums.hpp
    00019)    aliases.hpp
    00020)    functions_advance_001.hpp
    00021)    functions_advance_002.hpp
    00022)    functions_advance_003.hpp
    00023)    functions_advance_004.hpp
    00024)    templates.hpp
    00025)    templates_by_value.hpp
    00026)    templates_by_reference.hpp

## The Contents & The Logs:
    
    ---------------------------------------------------------------------
    00001)    main.cpp
    ---------------------------------------------------------------------
        // Include Any File Here
        // Call Any Function Here
            
    ---------------------------------------------------------------------
    00002)    std_ios.hpp
    ---------------------------------------------------------------------
        #define STR_HELPER(x) #x
        #define STR(x) STR_HELPER(x)
        auto sum(auto x = 0.0, auto y = 0.0)
        void std_ios()
        void std_ioformat()
        void std_numeric_limits()
     
    ---------------------------------------------------------------------
    00003)    data_types.hpp
    ---------------------------------------------------------------------
         // Literals and Constants:
             // const
             // Constant Expressions
                 // constexpr
                 // constinit
        void literals_and_constants()
        Weired Integral Types:
        void weried_integral_types()
        void integers_types()
        void floats_types()
        void booleans_types()
        void chars_types()
        void auto_types()
    
    ---------------------------------------------------------------------
    00004)    std_math.hpp
    ---------------------------------------------------------------------
            void std_math()
        
    ---------------------------------------------------------------------
    00005)    rock_paper_scissor_game.hpp
    ---------------------------------------------------------------------
            // Rock-Paper-Scissor Game
            std::string rps_game_get_input()
            Chois rps_game_check(int uc)
            void rps_game_check_message(Chois ch)
            void rps_game_apply_the_rules_and_get_the_winner
            void rps_game_play()
        
    ---------------------------------------------------------------------
    00006)    data_conversion.hpp
    ---------------------------------------------------------------------
        // Data Conversion:
        // Real World:
        // Conversion Guidline:
        // Narrwing Conversion
        // Explicit Conversion
        // Overflow && Underflow
        void data_conversion()
        
    
    ---------------------------------------------------------------------
    00007)    bitwise_ops.hpp
    ---------------------------------------------------------------------
        // Bitwise operators:
        void bitwise_ops()
        // Bitwise shift operators:
        void shift_ops()
        // Logical Bitwise operators:
        void logical_bitwise_ops()
        // Compound Bitwith operators:
        void compound_bitwise_ops()
        // Bit Masks (Shadow):
        void bitwise_mask()
        // Masks Demo 01
        void fun_opts_v0    // Uses many parameters & waste of memory
        // Masks 8-bit = 1-byte 
        void fun_opts_v1    // Uses 1 parameter & no waste of memory
        void bitwise_mask_demo_1()
        // Masks Demo 02
        void bitwise_mask_demo_02()
        
    ---------------------------------------------------------------------    
    00008)    variables_lifetime_scopes.hpp
    ---------------------------------------------------------------------
        // Storage Duration: 
        
    ---------------------------------------------------------------------
    00009)    control_flow.hpp
    ---------------------------------------------------------------------
        // Short Circuit Evaluation:
        void short_circuit_evaluation()
        // Itegral Logic Conditions
        void itegral_logic_conditions()
        // Ternary Operators:
        void ternary_ops()
        void ternary_init()
        // if constexpr
        void if_constexpr()
        // if with initializer:
        void if_with_initializer()
        // switch with initializer:
        void switch_with_initializer()
                
    ---------------------------------------------------------------------
    00010)    loops.hpp 
    ---------------------------------------------------------------------
        // Traditional For Loop Statement:
        void for_trad_loop()
        // Range Based For Loop Statement:
        void for_range_loop()
        // Traditional While Loop Statement:
        void while_trad_loop()
        // Traditional Do While Loop Statement:
        void do_while_trad_loop()
        // Infinite Loops:
        void infinite_loops()
        // Nesting Loops
        void nesting_loops()
        // Range based for loop with Initializer
        void range_based_for_loop_with_initializer()
        
    ---------------------------------------------------------------------
    00011)    arrays.hpp
    ---------------------------------------------------------------------    
        void arrays()
        // Arrays of Chars
        void arrays_of_chars()
        // Random Numbers:
        void arrays_rands()
        void arrays_rands_ranges_range_0_to_10_starts_from_0_without_seeding()
        void arrays_rands_ranges_range_1_to_10_starts_from_1_without_seeding()
        void arrays_rands_ranges_range_1_to_10_starts_from_1_with_seeding()
        // Multi-Dimessional Array
        void multi_dim_2d_array()
        void multi_dim_3d_array()
        
        
    ---------------------------------------------------------------------
    00012)    pointers.hpp
    ---------------------------------------------------------------------    
        void pointers()
        // Pointer to char
        void pointer_to_array_of_chars()
        // Arrays of pointer to chars (Array of Pointers to Strings):
        void arrays_of_pointer_to_chars()
        // Const Pointer and Pointer to Const:
            // 01) Non 'const' pointer:
            // 02) Pointer to 'const'
            // 03) Const Pointer (Opposite to case (02)):
            // 04) Const Pointer to Pointer to Const (Opposite to Case (01)):
        void const_pointer_and_pointer_to_const()
        // Array of const pointer to const char:
        void array_of_const_pointer_to_const_char()
        // Pointer and Array
        void arrays_and_pointers()
        // Demo [Swapping Arrays' Data]:
        void demo_swapping_arrays_data()
        // Pointer Arithmetic:
        void pointer_arithm()
        // Distance between elements (Subtarcting Pointers):
        void dist_pointers()
        // Comparing Pointers
        void compr_ptrs()
                
    ---------------------------------------------------------------------
    00013)    dyn_mem_alloc.hpp
    ---------------------------------------------------------------------    
        // Difference Between Stack and Heap:
        // Difference Between Static and Dynamic Memory Allocation in C:
        // Allocating the dynamic memory by using 'new' keyword:
        // Releasing And Resetting the dynamic memory by using 'delete' && 'nullptr' keyword:
        // Intializing at the same time declaring the pointer:
        // IMPORTANT Guidelines:
        void dyn_mem()
        // Dangling Pointers (Wild pointers ):
        void dangling_ptrs()
        // Handling a memory allocation failure:
        void dyn_mem_alloc_fails()
        //  Null Pointer Safety:
        void nullptr_safety()
        // Memory Leaks
        void mem_leaks()
        // Dynamic Arrays:
        void dyn_arr_alloc()
        
    ---------------------------------------------------------------------
    00014)    references.hpp
    ---------------------------------------------------------------------    
        // References are Just Aliases:
        // Comparison of references and pointers in C++:
        void references()
        
    ---------------------------------------------------------------------    
    00015)    strings.hpp
    ---------------------------------------------------------------------    
        // Using String & Chars manipulation with C/C++ Standard Library:
        void chr_str_manip()
        // Using 'cstring' standard library:
        void std_cstring()
        //  Using some useful functions of strings
        void std_cstring_02()
        // C++ String (<string>) (std::string):
        // You can initialize an std::string object in C++ using various methods.
        // Here is a list of functions provided by the <string> header in C++:
        void cpp_string_01()
        // Using some useful functions of strings
            // 01) Accessing and Modifying:
            // 02) String Manipulation:
            // 03) String Information and Properties:
            // 04) String Conversion and I/O:
        bool startsWith(const std::string& str, const std::string& prefix)
        bool endsWith(const std::string& str, const std::string& suffix)
        void cpp_string_02()
        // String Literals (#include <string_literals>):
        void cpp_string_literals()
        // std::to_string():
        void cpp_string_to_sting()
        // Accessing & Modification & Looping Through std::string:
        void cpp_string_access_modif_loop()
        // Size & The Capacity of std::string:
        void cpp_string_size_n_capacity()
        // Modifying std::strings:
        void cpp_string_modif_funcs()
        // C++ Compare Strings:
        void cpp_string_comparison()
        // C++ String Resizeing
        void cpp_string_resizing()
        // C++ String Copying
        void cpp_string_copying()
        // C++ String Searching & Finding
        void cpp_string_searching()
        // C++ String To Numbers
        void cpp_string_to_num()
        // C++ String Escape Sequence:
        void cpp_string_esc_seq()
        // C++ String / Raw String Literals:
        void cpp_string_raw_str_literals()
        // C++ String / Copied Strings:
        void cpp_string_copied_strings()
        // C++ String View:
        void processStringView(std::string_view strView)
        void cpp_string_view()
    ---------------------------------------------------------------------
    00016)    functions.hpp
    ---------------------------------------------------------------------
        // Functions In C/C++:
            // Function Declaration/Prototype:
            // Function Definition:
            // Function Call:
            // Function Parameters:
            // Return Type:
            // Void Functions:
            // Function arguments:
            // Differences between parameters and arguments:
            // The scope of an argument :
            // A simple diagram illustrating the input, processing, and output of a function:
            // Passing Methods:
        // The different parameter passing methods in C++:
            // Pass by Value: 
            // Pass by Const Value: 
            // Pass by Pointer: 
            // Pass by Pointer to Const: 
            // Pass by Reference: 
            // Pass by Const Reference: 
        // The Call Stack:
            // Stack Frames (Activation Record): 
            // Stack Operations: 
            // Call Stack Management:
            // Recursion: 
            // Recursion and the Call Stack:
            // Stack Overflow:
            // Exception Handling: 
            // Diagram:
        // Passed By Value:
        void func_passed_by_value(int num) 
        void cpp_func_params_passed_by()
        // Pass by const value:
        void func_passed_by_const_value(const std::string message) 
        void cpp_func_params_passed_by_const_value()
        // Pass by pointer:
        void func_passed_by_pointer(int* numPtr) 
        void cpp_func_params_passed_by_pointer()
        // Passing by pointer to const:
        void func_passed_by_pointer_to_const(const char* message) 
        void cpp_func_params_passed_by_pointer_to_const()
        // Passing by reference:
        void func_passed_by_reference(int& numRef)
        void cpp_func_params_passed_by_reference()
        // Array function parameters:
            // Pass by Pointer:
            // Pass by Reference:
            // Pass by Pointer to const:
            // Pass by Array:
        // Use the ARRAY_SIZE macro to get the size of the array
        #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
        void array_parameters_pass_by_pointer(int* arr, int size) 
        void array_function_parameters_pass_by_pointer() 
        void array_function_parameters_pass_by_reference(int (&arr)[], int size)
        void array_parameters_pass_by_reference()
        void array_function_parameters_pass_by_pointer_to_const(const int* arr, int size)
        void array_parameters_pass_by_pointer_to_const()
        void array_function_parameters_pass_by_array(int arr[], int size)
        void array_parameters_pass_by_array()
        // Sized array function parameters:
        void print_with_sized_array(int arr[5])
        void func_with_sized_array()
        // Passing sized arrays by reference
        void print_with_sized_array_passed_by_ref(int (&arr)[5])
        void func_with_sized_array_passed_by_ref()
        // Multi dimensional array function parameter:
        void print_with_multi_dim_passed_as_params(int matrix[][3], int rows)
        void func_with_multi_dim_passed_as_params()
        // Default function arguments:
        void print_message_with_default_argument(const std::string& message = "Hello, World!")
        void print_numbers_with_default_argument(int start, int end = 10, int step = 1)
        void func_print_message_and_numbers_with_default_argument()
        // String View as a Parameter:
        void process_substring_string_view_passed_as_a_param(std::string_view str)
        void func_string_view_passed_as_a_param() 
        // constexpr function:
        constexpr int fibonacci_by_constexpr_function(int n)
        void func_fibonacci_by_constexpr_function()
        // consteval function:
        consteval int fibonacci_by_consteval_function(int n)
        void func_fibonacci_by_consteval_function()
    
    ---------------------------------------------------------------------
    00017)    compilation.hpp
    ---------------------------------------------------------------------    
        // Compilation In C/C++:
        // ODR stands for "One Definition Rule:
        // Detailed diagram illustrating the compilation process in C++:

    ---------------------------------------------------------------------    
    00018)    enums.hpp
    ---------------------------------------------------------------------    
        // Enumeration in C++:
        void enum_c_style()
        // Enumeration Class In C++:
        void enum_class_cpp_style()
        // Enumeration Features in C++20:
        enum class Permissions : unsigned int
        Permissions operator|(Permissions lhs, Permissions rhs)
        Permissions operator&(Permissions lhs, Permissions rhs)
        void PrintPermissions(Permissions permissions)
        void enum_cpp20()
        void enum_cpp20_using_no_repeat()

    ---------------------------------------------------------------------
    00019)    aliases.hpp
    ---------------------------------------------------------------------
        // Aliases in C++:
        void aliases_c_cpp()

    ---------------------------------------------------------------------    
    00020)    functions_advance_001.hpp
    ---------------------------------------------------------------------    
        // Inputs & Outputs Parameters In C++:
        void compute_sum_and_product(int a, int b, int& sum, int& product)
        void func_compute_sum_and_product()
        // Returning from functions (by value):
        int calculate_sum(int a, int b)
        void func_calculate_sum()
        // Returning by reference:
        int& increment_by_reference(int& num)
        void func_increment_by_reference()
        // Returning by pointer:
        int* create_dynamic_integer()
        void func_create_dynamic_integer()
        //Returning array element pointer:
        const int* get_array_element(const int arr[], size_t size, size_t index)
        void func_get_array_element()
        // Bare auto type deduction:
        void func_bare_auto_type_deduction()
        // typeid Operator:
        void func_typeid_typeinfo()
        // Bare auto reference deduction:
        void func_bare_auto_ref_deduct()
        // Proper Reference Deduction:
        void func_proper_reference_deduct()
        // Const Qualifiers:
        void func_const_qualifiers()
        // Function return type deduction:
        auto calculate_average(const std::vector<int>& numbers)
        void func_calculate_average()
        // Return type deduction with references:
        auto& get_larger(int& value1, int& value2)
        void func_get_larger()
        //  Optional output from functions:
        bool calculate_square_root(double number, double* result)
        void func_calculate_square_root()
        // std::optional
        std::optional<Student> find_student(int studentId, const std::vector<Student>& students) 
        void func_find_student() 
        // std::nulopt
        std::optional<int> get_even_number(int number) 
        void func_get_even_number() 
        // Reading method of  a value from std::optional
        std::optional<int> get_value(bool hasValue) 
        void func_get_value() 
        // Optional output with stdoptional from function
        std::optional<double> calculate_square_root_02(double number)
        void func_calculate_square_root_02()

    ---------------------------------------------------------------------
    00021)    functions_advance_002.hpp
    ---------------------------------------------------------------------
        // Function Overload:
        int fn_add(int a, int b)
        double fn_add(double a, double b)
        void func_add_overloaded()
        // Overloading with different parameters:
        int fn_calculate(int a, int b)
        int fn_calculate(int a, int b, int c)
        int fn_calculate(int a, int b, int c, int d)
        double fn_calculate(double a, double b)
        void func_calculate_overloaded()
        // Overloading with pointer parameters:
        void fn_print_int_value(int* ptr)
        void fn_print_double_value(double* ptr)
        void fn_swap_int_values(int* ptr1, int* ptr2)
        void func_print_overloaded_values()
        // Overloading with reference parameters:
        double fn_calculate_area_with_ref(const double& radius)
        double fn_calculate_area_with_ref(const double& length, const double& width)
        double fn_calculate_area_with_ref(const long double& base, const double& height)
        void func_calculate_overloaded_area()
        int fn_calculate_sum(const int arr[], const int& size)
        double fn_calculate_sum(const double arr[], const int& size)
        void func_calc_overloaded_sum()
        // Overloading with const parameters by value:
        int fn_find_min(const int a, const int b)
        double fn_find_min(const double a, const double b)
        void func_find_min_overloaded()
        // Overloading with const pointer and pointer to const parameters:
        void fn_swap_values(int* const ptr1, int* const ptr2)
        void fn_swap_values(const double* ptr1, const double* ptr2)
        void func_swap_values_with_overloaded_ptr_to_const_const_ptr()
        // Overloading with default parameters:
        double fn_calculate_volume(const long double& radius, const double& pi = PI)
        double fn_calculate_volume(const double& side)
        double fn_calculate_volume(const double& length, const double& width, const double& height)
        void func_calculate_volume_with_default_parameter_overloaded()

    ---------------------------------------------------------------------    
    00022)    functions_advance_003.hpp
    ---------------------------------------------------------------------
        // Declaring and using lambda functions:
        void func_various_lambda_funs()
        void func_lambdas_captures_types() 
        // Capture all in context:
        void func_capture_all_in_context_01()
        void func_capture_all_in_context_02()

    ---------------------------------------------------------------------    
    00023)    functions_advance_004.hpp
    ---------------------------------------------------------------------
        // static variable within the function:
        void fn_static_variable()
        void func_static_variable_calls()
        // Inline functions:
        inline int fun_inline_add(int a, int b)
        void func_inline_add_call()
        // Recursive Function:
        int fn_rec_factorial(int n)
        void func_rec_fact()
        // Analyze the output of the Fibonacci number calculation for n
        int fn_rec_fibonacci(int n)
        void func_rec_fibonacci()

    ---------------------------------------------------------------------
    00024)    templates.hpp
    ---------------------------------------------------------------------
        // Templates:
        // Here's a list of benefits and drawbacks of using C++ function templates:
        // Syntax:
        // void cpp_func_template_print(T value)
        void cpp_func_template_print<std::string>(std::string value)
        T cpp_func_template_power(T base)
        void cpp_func_template_process(T value)
        void cpp_func_template_log(Args... args)
        void cpp_func_template_print_proc_log()
        //  Let's consider a real-world example of a function template that performs element-wise addition for different types of arrays 
        std::vector<T> cpp_func_template_array_add(const std::vector<T>& arr1, const std::vector<T>& arr2)
        void cpp_func_template_array_add_call()
        // Let's consider another real-world example of a function template. In this case, we'll create a function template that finds the maximum element in a container.
        typename Container::value_type cpp_func_template_find_max(const Container& container)
        void cpp_func_template_find_max_call()
        // Let's explore another real-world example of a function template. This time, we'll create a template for a mathematical function that calculates the average of a collection of values.
        T cpp_func_template_calculate_average(const std::vector<T>& values)
        void cpp_func_template_calculate_average_call()
        // Let's explore another real-world example of a function template. In this scenario, we'll create a template for a sorting function that sorts elements of different types in ascending order.
        void cpp_func_template_sort(std::vector<T>& elements)
        void cpp_func_template_sort_call()
        // Let's explore another real-world example of a function template. In this case, we'll create a template for a function that finds the first occurrence of a given value in a collection.
        typename Container::const_iterator cpp_func_template_find(const Container& container, const T& value) {
        size_t calculate_index(const Container& container, Iterator it)
        void cpp_func_template_find_call()
        // Let's explore another example, this time focusing on a function template that finds the minimum and maximum elements in a collection.
        std::pair<T, T> cpp_func_template_find_min_max(const Container& container)
        void cpp_func_template_find_min_max_call()
        // Let's explore another example of a function template. This time, we'll create a template for a function that performs element-wise multiplication of two vectors and returns a new vector containing the result.
        std::vector<T> cpp_func_template_vector_multiply(const std::vector<T>& vec1, const std::vector<T>& vec2)
        void cpp_func_template_vector_multiply_call()
        // In this example, we'll create a function template for a generic calculator that supports basic arithmetic operations.
        T cpp_func_template_calculator(T a, T b, char operation)
        void cpp_func_template_calculator_call()
        // In this example, let's create a function template for a generic converter that converts temperature values between Fahrenheit and Celsius.
        T cpp_func_template_convert_temperature(T temperature, char fromUnit, char toUnit)
        void cpp_func_template_convert_temperature_call()
        //  In this example, let's create a function template for a generic swap function that swaps the values of two variables.
        void cpp_func_template_swap(T& a, T& b)
        void cpp_func_template_swap_call()  
        
# Tools:
1) Fedora 38 GNU/LINUX, KDE
2) Mozilla FireFox 114
4) www.repl.it
3) www.onlinegdb.com
5) KDE Kate Code Editor
6) KDE KDevelop
7) g++ (GCC) 13.1.1 20230511 (Red Hat 13.1.1-2)
8) clang version 16.0.4 (Fedora 16.0.4-1.fc38)
9) Microsoft Visual Studio Code
10) Microsoft Visual Studio 2022  / Windows Only
11) Windows 11
12) Notepad++ / Windows Only
13) Eclipse IDE
14) Code::Blocks
15) www.cppinsights.io
16) cppcheck
17) clazy
18) clang-tidy
19) valgrind

# References:
  
  #### Websites:
  1) www.cppreference.com
  2) www.cplusplus.com
  3) www.stackoverflow.com 
  4) www.geeksforgeeks.org
  5) www.programiz.com
  6) www.tutorialspoint.com
  7) www.cppsecrets.com
  8) www.leetcode.com
  9) www.gcc.gnu.org
  10) www.clang.llvm.org
  11) www.overiq.com
  12) https://www.educative.io
  13) www.cprogramming.com
  14) www.wikipedia.org
  15) www.w3schools.com
  16) https://chat.openai.com
  
  #### Videos, Online Courses:
  1) Udemy - The C++20 Masterclass - From Fundamentals to Advanced / Daniel Gakwaya
  2) Udemy - Complete Modern C++ (C++11/14/17) / Umar Lone
  3) LinkedIn - Master C Language Pointers / Dan Gookin
  3) LinkedIn - C: Data Structures, Pointers, and File Systems / Dan Gookin
  4) Linkedin - Programming Foundations: Memory, Pointers, and Garbage Collection / Maaike van Putten
  5) InfiniteSkills - C++ Programming Bundle Training Video / Brook Monroe
  6) Udemy - Garbage Collection Algorithms 2020 / Dmitry Soshnikov
  
  #### Books, PDF's:
  1) Beginning C++20: From Novice to Professional / Ivor Horton and Peter Van Weert
  2) Programming: Principles and Practice Using C++ / Bjarne Stroustrup
  3) C++ Programming Language / Bjarne Stroustrup
  4) C: A Reference Manual, 5th Edition 5th Edition /  Samuel Harbison, Guy Steele Jr.
  5) C Programming: A Modern Approach 2nd Edition / K. N King
  6) C: The Complete Reference, 4th Edition / Herbert Schildt
  7) C++: A Beginner's Guide, Second Edition / Herbert Schildt
  8) C++: The Complete Reference, Fourth Edition / Herbert Schildt
  9) C++ from the Ground Up (From the Ground Up) 3rd Edition / Herbert Schildt
  10) Professional C++ / Marc Gregoire 
  11) C++ How to Program / Paul Deitel and Harvey Deitel
  12) Understanding the linux kernel 3rd Edition / Daniel P. Bovet and Marco Cesati
  13) Linux Kernel Development 3rd Edition / Robert Love
  14) Deep understanding of Linux kernel / Jim Green
  15) Linux Kernel Programming A Comprehensive Guide To Kernel Internals, Writing Kernel Modules, and Kernel Synchronization / Kaiwan N Billimoria
  16) Linux Internals Simplified: A beginners guide to Linux Internals / Haris Kundan Prasad
  17) Windows Internals Seventh Edition / Pavel Yosifovich, Alex Ionescu, Mark E. Russinovich, and David A. Solomon
  18) 

  ### Blogs, Articles:
  1) https://www.educative.io/blog/cpp-memory-management
  2) https://linux-kernel-labs.github.io/refs/heads/master/labs/memory_mapping.html
  3) https://www.mathworks.com/help/matlab/import_export/overview-of-memory-mapping.html
  4) https://byjus.com/gate/cache-mapping-notes/
  5) https://stackoverflow.com/questions/1401359/understanding-linux-proc-pid-maps-or-proc-self-maps/1401595#1401595
  6) https://learn.microsoft.com/en-us/dotnet/standard/io/memory-mapped-files
  7) https://techcommunity.microsoft.com/t5/ask-the-performance-team/memory-management-x86-virtual-address-space/ba-p/372536
  8) https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/
  9) https://www.guru99.com/stack-vs-heap.html
  10) https://www.geeksforgeeks.org/difference-between-static-and-dynamic-memory-allocation-in-c/
  11) https://www.cprogramming.com/tutorial/function-pointers.html
  12) https://www.scaler.com/topics/c/dangling-pointer-in-c/
  13) https://en.wikipedia.org/wiki/Dangling_pointer
  14) https://interviewsansar.com/what-if-memory-allocation-using-new-fails-in-cpp-how-to-handle/
  15) https://www.geeksforgeeks.org/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
  16) https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
  17) https://www.w3schools.com/cpp/cpp_exceptions.asp
  18) 






