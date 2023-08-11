#ifndef __TEMPLATES_H
#define __TEMPLATES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <exception>
#include <limits>
#include <random>
#include <typeinfo>
#include <tuple>
#include <regex>
#include <memory>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>
#include <filesystem>
#include <chrono>
#include <optional>

#include <cassert>
#include <cstddef>
#include <cwctype>
#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cctype>
#include <cstring>
#include <cmath>


using namespace std;

/*
    - Templates:
        - Templates serve as a blueprint for generating actual code based on the specified template arguments.
        - Templates are a fundamental feature of modern C++ and play a crucial role in enabling code reusability and generic programming. 
        - They are used extensively in the C++ Standard Library and are a powerful tool for creating flexible and efficient software.
        - A template in C++ is a mechanism that allows you to write generic code that works with different data types or values.
        - It enables you to create functions, classes, or data structures that can be parameterized by one or more types or values. 
        - Templates provide several benefits, including code reusability, type safety, performance optimization, and the ability to work with user-defined types seamlessly. 
        - However, they can also introduce complexities in terms of code readability, debugging, and potential code bloat.
        - In summary:
            - templates in C++ are a powerful mechanism that allows you to write generic code and create versatile, type-safe, and efficient software components that adapt to different data types or values.
        - There are two main types of templates in C++:
            - Function Templates: 
                - These allow you to define functions that can operate on different types without duplicating code. 
                - For example, a function template can be used to implement addition for both integers and floating-point numbers.
            - Class Templates: 
                - These enable you to define classes that can work with various types while providing common functionality. 
                - For instance, you can create a template for a dynamic array that can store elements of any type.
        - Templates are instantiated, or "filled in," with specific types or values at compile-time, generating specialized code for each combination of template arguments. 
            - This process is called template instantiation:
                - Template instantiation is the process by which the compiler generates concrete code from a template by substituting the template parameters (types or values) with actual values. 
                - This process occurs at compile-time and results in the creation of specialized functions, classes, or data structures based on the template definition and the provided template arguments.
                - Template instantiation is a powerful feature that allows you to write generic code while maintaining type safety and performance optimizations. 
                - It's a key aspect of modern C++ and is extensively used to create flexible and efficient software components.
                - Let's break down the process of template instantiation:
                    - Template Definition: 
                        - You define a template for a function or class with one or more template parameters. 
                        - These parameters serve as placeholders for types or values that will be provided later.
                    - Template Argument(s): 
                        - When you use the template, you provide specific types or values as template arguments. 
                        - These arguments are used to fill in the template parameters.
                    - Compile-Time Generation: 
                        - During compilation, the compiler processes the template and the provided template arguments.
                        - It substitutes the template parameters with the provided arguments and generates specialized code for each combination of template arguments.
                    - Specialized Code:
                        - The compiler generates actual function or class definitions based on the template with the substituted arguments. 
                        - This specialized code is used for the specific types or values you've used as template arguments.
                    - Linking:
                        - The generated specialized code is linked into the final executable or library during the linking phase of compilation.

                    - Let's explore template instantiation in more detail:
                        - Template Definition:
                            - Templates are defined using the template keyword, followed by template parameters enclosed in angle brackets (<>).
                            - Template parameters can represent types (e.g., typename T) or non-type values (e.g., int N).
                        - Template Structure:
                            - A template serves as a blueprint or recipe for generating code.
                            - The template contains placeholders (template parameters) where types or values will be substituted later.
                        - Template Argument(s):
                            - When using a template, you provide specific types or values as template arguments.
                            - Template arguments replace the template parameters, effectively filling in the placeholders.
                        - Compile-Time Processing:
                            - During compilation, the compiler encounters the template and the provided arguments.
                            - The compiler starts the template instantiation process, where it substitutes template parameters with the provided arguments.
                        - Generation of Specializations:
                            - The compiler generates specialized versions of functions, classes, or data structures based on the template and the provided arguments.
                            - Each combination of template arguments results in a distinct specialization.
                        - Code Generation:
                            - The compiler generates actual code for each specialization.
                            - The generated code includes all the template logic and operations, customized for the specific types or values.
                        - Type-Safe Specializations:
                            - Template specialization ensures type safety. 
                            - Specializations are only generated for valid combinations of template arguments.
                            - If you attempt to use incompatible types or values, the compiler will generate errors.
                        - Function Overloading:
                            - For function templates, the compiler may use template argument deduction to determine the appropriate specialization to use.
                            - If an exact match isn't found, the compiler might perform implicit type conversions or apply function overloading rules.
                            - Here are the key rules and concepts regarding function overloading in C++:
                                - Parameter List:
                                    - Functions are considered overloaded if they have the same name but different parameter lists (number or types of parameters).
                                    - Return type alone is not sufficient for overloading; it's the parameter list that distinguishes overloaded functions.
                                - Function Resolution:
                                    - During a function call, the compiler determines the best-matching function by considering the argument types and implicit conversions.
                                - Exact Match:
                                    - If there's an exact match between the arguments and a function's parameter list, that function is chosen.
                                    - Exact match means the number, types, and order of arguments match the function's parameters.
                                - Implicit Conversions:
                                    - If no exact match is found, the compiler looks for functions where the arguments can be implicitly converted to match the parameter types.
                                - Best Match:
                                    - The compiler selects the best-matching function based on the conversion sequence.
                                    - It prefers the least number of conversions and conversions that don't involve loss of data.
                                - Default Arguments:
                                    - Default arguments can be used to provide a fallback when no exact match or suitable conversion is found.
                                - Function Overloading and Templates:
                                    - Function templates can also participate in overloading.
                                    - When resolving overloaded functions, the compiler considers both regular functions and function templates.
                                - Ambiguity:
                                    - Ambiguity occurs when the compiler cannot decide which overloaded function to call due to multiple equally valid matches.
                                    - In such cases, the compiler generates an error, and you need to resolve the ambiguity by explicitly specifying the function or using type casting.
                            - Interaction Between Function Overloading and Templates:
                                - Function overloading and templates can work together to provide versatile and expressive code:
                                    - Overloading with Templates:
                                        - You can overload functions where some versions are templates and others are not.
                                        - The compiler chooses the best-matching overload based on the arguments, considering both regular functions and function templates.
                                    - Template Specialization in Overloads:
                                        - You can specialize a template version of an overloaded function for specific types or values.
                                        - This allows you to fine-tune the behavior of the template function in certain cases.
                        - Multiple Instantiations:
                            - The same template can be instantiated multiple times with different arguments, leading to multiple specialized versions of the template in the final binary.
                        - Linking and Code Size:
                            - The generated specialized code is linked into the final executable or library.
                            - Template instantiation can lead to increased code size, as each specialization results in separate compiled code.
                        - Performance and Optimization:
                            - Template specialization allows the compiler to optimize the generated code for specific types or values, potentially leading to better performance.
                        - Compile-Time Errors and Debugging:
                            - Template-related errors, such as invalid type combinations, are caught at compile-time.
                            - Debugging template-related issues may involve examining error messages and understanding the interaction between template instantiation and the compiler's optimization process.
        
        - Here's a list of benefits and drawbacks of using C++ function templates:
            - Benefits:
                1. Code Reusability: 
                    Function templates allow you to write generic code that can be reused with different data types, reducing code duplication.
                2. Type Safety: 
                    Templates enforce type safety by generating type-specific code at compile-time. This reduces runtime errors due to type mismatches.
                3. Performance: 
                    Templates generate specialized code for each data type, potentially leading to better performance compared to runtime polymorphism.
                4. Compile-Time Polymorphism: 
                    Templates achieve polymorphism at compile-time, avoiding the runtime overhead associated with virtual function calls.
                5. Standard Library Support: 
                    Many components of the C++ Standard Library, such as containers (e.g., `std::vector`, `std::map`) and algorithms (e.g., `std::sort`, `std::find`), rely on function templates.
                6. Customization: 
                    Templates allow fine-tuning and customization for specific use cases through specialization and constraints.
                7. Flexibility: 
                    Templates can work with user-defined types, allowing for seamless integration with custom classes and structures.
                8. Performance Optimization: 
                    Template specialization enables writing optimized code paths for specific data types.
                9. Compile-Time Errors: 
                    Errors are caught at compile-time, making it easier to debug template-related issues before runtime.
            - Drawbacks:
                1. Code Bloat: 
                    Using templates extensively can lead to code bloat, as each specialization generates separate compiled code.
                2. Compilation Time: 
                    Complex templates can increase compilation times, especially when they're instantiated with various data types.
                3. Readability: 
                    Templates can make code harder to read and understand, especially when dealing with complex type manipulations.
                4. Error Messages: 
                    Template-related errors can sometimes result in long and cryptic error messages that might be challenging to decipher.
                5. Limited Support for Certain Types: 
                    Some advanced template features may not work well with certain types or scenarios, leading to design constraints.
                6. Template Metaprogramming Complexity: 
                    Advanced template metaprogramming techniques can introduce complexity that's difficult to grasp and maintain.
                7. Debugging Difficulty: 
                    Debugging template-related issues can be more challenging, as errors might involve intricate interactions between template instantiation and compiler optimizations.
                8. Lack of Dynamic Polymorphism: 
                    While templates excel at compile-time polymorphism, they cannot be used for dynamic polymorphism like runtime polymorphism achieved with inheritance and virtual functions.
                9. Syntax Complexity: 
                    Writing and understanding templates with complex type manipulations, constraints, and SFINAE can be syntactically complex.
                10. Portability: 
                    Some template features might not be supported by all compilers, leading to potential portability issues.

            - It's important to carefully weigh the benefits and drawbacks of using function templates in your C++ code, considering the specific requirements and trade-offs of your project.
        
        - Syntax:
            - Here's the detailed syntax for defining and using function templates in C++:
                - Defining a Function Template:
                    - A function template is defined using the `template` keyword, followed by template parameters enclosed in angle brackets (`<>`), and then the function signature.

                        template <typename T>
                        void functionName(T parameter) {
                            // Function body
                        }


                - Here's an example of a simple function template:
                
                    template <typename T>
                    void print(T value) {
                        std::cout << value << std::endl;
                    }


                - Using a Function Template:
                    - When you use a function template, you provide the template arguments in angle brackets. 
                    - The compiler generates specialized code based on these arguments.

                        functionName<DataType>(argument);

                    - Here's how you use the `print` function template:

                        print<int>(5);       // Calls print<int>(5)
                        print<double>(3.14); // Calls print<double>(3.14)
                        print("Hello");      // Calls print<const char*>("Hello")

                - Template Specialization:
                    -You can specialize a template for specific types or values to provide custom behavior.

                        template <>
                        void functionName<SpecificType>(SpecificType parameter) {
                            // Specialized function body
                        }

                    - Here's an example of template specialization for the `print` function template:

                        template <>
                        void print<std::string>(std::string value) {
                            std::cout << "String version: " << value << std::endl;
                        }


                - Non-Type Template Parameters:
                    - You can also use non-type template parameters, which are constant values, to further customize your template:

                    template <typename T, int N>
                    T power(T base) {
                        T result = 1;
                        for (int i = 0; i < N; ++i) {
                            result *= base;
                        }
                        return result;
                    }


                - Constraints (C++20):
                    - You can apply constraints to restrict template instantiations to certain conditions using the `requires` keyword.

                        template <typename T>
                        requires std::is_integral_v<T>
                        void process(T value) {
                            // Function body
                        }


                - Variadic Templates:
                    - Variadic templates allow functions to accept a variable number of arguments.

                        template <typename... Args>
                        ReturnType functionName(Args... args) {
                            // Function body
                        }

                        - Here's an example of a variadic function template:

                            template <typename... Args>
                            void log(Args... args) {
                                ((std::cout << args << " "), ...);
                                std::cout << std::endl;
                            }


*/


#endif
