#ifndef __COMPILATION_H
#define __COMPILATION_H

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
    - Compilation In C/C++:
        - The compilation process in C++ involves several stages, starting from the source code files and ending with the creation of an executable or a library. 
        - Here is an in-depth explanation of the compilation process in C++:
            - 01) Preprocessing:
                - The preprocessor stage is the first step in the compilation process. 
                - It is responsible for handling preprocessor directives, such as including header files (#include), macro expansions (#define), and conditional compilation (#ifdef, #ifndef, etc.). 
                - The preprocessor modifies the source code based on these directives and generates a preprocessed source file.

            - 02) Compilation:
                - In the compilation stage, the preprocessed source file is fed into the compiler. 
                - The compiler translates the C++ source code into machine-readable object code (usually in the form of assembly code). 
                - This involves lexical analysis, syntax analysis, semantic analysis, and code generation. 
                - The output of this stage is one or more object files, which contain machine code specific to a particular architecture.

            - 03) Linking:
                - The linking stage combines multiple object files, along with any necessary libraries, to create an executable or a library. 
                - It involves resolving external references, performing symbol resolution, and generating the final binary code. 
                - The linker ensures that all the required symbols are defined and properly connected. 
                - If any unresolved symbols are encountered, linker errors occur.

            - 04) There are two types of linking:
                - Static Linking: The linker directly combines the object files and libraries into a single executable file. The resulting executable contains all the necessary code and libraries, making it self-contained.
                - Dynamic Linking: The linker creates an executable file that depends on external dynamic libraries. The references to functions and symbols in the executable are resolved at runtime by the operating system's dynamic linker/loader.

            - 05) Optimization (Optional):
                - Optimizations can be applied during compilation to improve the performance and efficiency of the resulting executable. The compiler analyzes the code and applies various optimizations, such as removing redundant operations, inline expansion, loop unrolling, and more. Optimization levels can be specified during the compilation process to control the aggressiveness of optimization.

            - 06) Output:
                - The output of the compilation process depends on the desired goal:
                    - Executable: If the intention is to create an executable, the output is a binary file that can be directly executed by the operating system.
                    - Library: If the intention is to create a library, the output is a binary file containing compiled code that can be linked with other programs.

            - It's worth noting that the compilation process can be controlled through build systems, such as Makefiles or build automation tools like CMake. 
            - These systems provide flexibility and automate the compilation process, managing dependencies, and handling complex project structures.
            - Understanding the compilation process is crucial for effective software development, as it allows you to optimize code, manage dependencies, and resolve errors and issues that may arise during the build process.
            
    - ODR stands for "One Definition Rule:
        - It is a fundamental rule in the C++ programming language that specifies how entities (such as variables, functions, classes, and templates) with external linkage must be defined consistently across different translation units.
        - The One Definition Rule states that:
            - Each entity with external linkage (i.e., global variables, functions, and non-inline classes) must have exactly one definition in the entire program. 
            - Multiple definitions of the same entity in different translation units are not allowed.
            - The definition of an entity must be the same in every translation unit where it is used. 
            - This includes the name, type, and all other relevant aspects of the entity.
            - The ODR is in place to ensure that the program's behavior is well-defined and consistent. 
            - Violating the ODR can lead to undefined behavior or linker errors.
            - Ex 01:    The declaration acts as a reference to the defined x variable.
                // File1.cpp
                int x = 5;
                
                // File2.cpp
                extern int x;  // Declaration (no definition)
            - Ex 02:     The program should have exactly one definition of x.
                // File1.cpp
                int x = 5;
                
                // File2.cpp
                int x = 10;  // Violation of ODR - multiple definitions of 'x'

            - To adhere to the ODR, you can use techniques such as declaring variables with extern in header files and providing a single definition in one of the source files.
            - The ODR is an essential concept to understand when working with larger C++ programs that involve multiple source files and linking. 
            - It helps ensure consistency and compatibility across translation units and facilitates correct and predictable program behavior.

        -  Multiple Files  Revisition the Linker stage:
            - In C++, when you have a program that consists of multiple files (source files or translation units), the process of linking is performed by the linker to combine these files into a single executable or library.
            - During the linking stage, the linker performs the following tasks:
                - Symbol resolution: 
                    - The linker resolves references to symbols (functions, variables, etc.) that are defined in one file and used in another. 
                    - It ensures that all symbols are correctly linked and available for use.
                - Object file merging: 
                    - The linker combines the object files generated from individual source files into a single executable or library. 
                    - It merges the machine code, data sections, and other relevant sections to create a coherent program.
                - Address assignment: 
                    - The linker assigns memory addresses to the various sections of the program, such as code, data, and stack. 
                    - It ensures that there are no conflicts or overlapping addresses.
                - Relocation: 
                    - If there are references to absolute memory addresses within the code or data, the linker performs relocation. 
                    - It adjusts these references to match the final assigned memory addresses, taking into account the address space of the target system.
                - Library linking: 
                    - If your program uses external libraries, the linker links those libraries with your program. 
                    - It resolves the references to functions or symbols defined in the libraries and includes them in the final executable.
                - Error checking: 
                    - The linker performs various checks to ensure the consistency and correctness of the linked program. It detects and reports any unresolved symbols, duplicate symbols, or other linking errors.
                
                - Once the linking stage is complete, the linker produces an executable file or a library file, depending on the desired output.
                - It's important to note that the specific behavior and options of the linker can vary depending on the platform, build system, and compiler being used. 
                - The linker is typically invoked automatically by the build system or compiler, so you don't need to explicitly call it. 
                - However, understanding the linker's role in the overall build process can help you diagnose and resolve linking issues when building multi-file programs.

    - Detailed diagram illustrating the compilation process in C++:
       +--------------------------------------------------------------+
       |                                                              |
       |                    Source Code Files                         |
       |                                                              |
       +--------------------------------------------------------------+
                                |
                                V
       +--------------------------------------------------------------+
       |                                                              |
       |                       Preprocessing                          |
       |                                                              |
       +--------------------------------------------------------------+
                                |
                                V
       +--------------------------------------------------------------+
       |                                                              |
       |                        Compilation                           |
       |                                                              |
       +--------------------------------------------------------------+
                                |
                                V
       +--------------------------------------------------------------+
       |                                                              |
       |                      Object Files                            |
       |                                                              |
       +--------------------------------------------------------------+
                                |
                                V
       +--------------------------------------------------------------+
       |                                                              |
       |                        Linking                               |
       |                                                              |
       +--------------------------------------------------------------+
                                |
                                V
       +--------------------------------------------------------------+
       |                                                              |
       |                       Final Output                           |
       |                                                              |
       +--------------------------------------------------------------+

       - Explanation of each stage:

        - 01) Source Code Files:
            - This is where your C++ source code files reside. 
            - It contains the code you've written in C++.
        
        - 02) Preprocessing:
            - The preprocessor stage handles preprocessor directives, such as #include, #define, and conditional compilation. 
            - It expands macros, processes included header files, and resolves conditional compilation blocks.
            - The preprocessing stage prepares the source code for the subsequent compilation steps by handling macro expansions, file inclusions, conditional compilation, and comment removal.
            - It transforms the original source code into a modified version that is ready for further processing by the compiler.
            - Understanding the preprocessing stage is essential for comprehending the impact of macros, conditional compilation, and included header files on the final compiled code. 
            - It allows developers to utilize preprocessor directives effectively and control the compilation process based on different conditions.
            
            - Here's a more in-depth explanation of the preprocessing stage in C++:
                - 01) Tokenization:
                    - The preprocessor scans the source code character by character and breaks it down into individual tokens. 
                    - It recognizes various types of tokens, including keywords, identifiers, literals, operators, and preprocessor directives. 
                    - Tokens are the fundamental building blocks of the source code.

                - 02) Macro Expansion:
                    - When the preprocessor encounters a macro invocation (a usage of a macro), it expands it by replacing the macro name with its defined value. 
                    - The preprocessor searches for macro definitions using the #define directive and performs textual substitution. 
                    -  If the macro has parameters, arguments passed to the macro invocation are substituted into the macro body.
                
                - 03) File Inclusion:
                    - The preprocessor handles #include directives, which are used to include header files into the source code. 
                    - It locates the included file based on the provided path and reads its contents. 
                    - The contents of the included file are then inserted into the source code at the location of the #include directive. 
                    - This process allows the reuse of code from other files and libraries.

                - 04) Conditional Compilation:
                    - The preprocessor handles conditional compilation directives, such as #ifdef, #ifndef, #if, #else, and #endif. 
                    - These directives allow portions of code to be included or excluded during compilation based on certain conditions. 
                    - The preprocessor evaluates the conditions specified in these directives, which can involve predefined macros or expressions, and selectively includes or excludes code blocks accordingly.

                - 05) Removal of Comments:
                    - The preprocessor removes comments from the source code. 
                    - It eliminates both single-line comments, denoted by '//', and multi-line comments, enclosed within '/*/ /*/'.
                    - Comments are not relevant to the compilation process and are removed to reduce the code's size and improve processing speed.

                - 06) Line Control:
                    - The preprocessor keeps track of line numbers to assist in error reporting and debugging. 
                    -  It updates line numbers whenever it encounters a newline character in the source code. 
                    - This information is used to generate accurate error messages and helps developers identify the location of issues in the original source code.

                - 06) Output Generation:
                    - After performing the above transformations, the preprocessor generates a preprocessed source file. 
                    - This file represents the modified version of the original source code, with macro expansions, included files, conditional blocks resolved, and comments removed. 
                    - The preprocessed file is then passed to the compiler for the actual compilation process.
                
                - The preprocessing stage prepares the source code for the subsequent compilation steps by handling macro expansions, file inclusions, conditional compilation, and comment removal. 
                - It transforms the original source code into a modified version that is ready for further processing by the compiler.
                - Understanding the preprocessing stage is essential for comprehending the impact of macros, conditional compilation, and included header files on the final compiled code. 
                - It allows developers to utilize preprocessor directives effectively and control the compilation process based on different conditions.
            
        - 03) Compilation:
            - The compiler takes the preprocessed source code files and translates them into object code. 
            - It performs lexical analysis, syntax analysis, semantic analysis, and code generation. 
            - The output is one or more object files containing machine code specific to the target architecture.
            - Here's a more in-depth explanation of the compilation stage in C++:
                - 01) Lexical Analysis:
                    - The compilation process begins with lexical analysis, where the source code is analyzed and divided into tokens. 
                    - Tokens represent the smallest meaningful units of the code, such as keywords, identifiers, literals, operators, and punctuation.

                - 02) Syntax Analysis:
                    - The next step is syntax analysis, also known as parsing. 
                    - The compiler analyzes the structure of the code based on the grammar rules of the C++ language. 
                    - It checks if the tokens form valid expressions, statements, and program structures according to the language syntax.

                - 03) Semantic Analysis:
                    - Semantic analysis focuses on the meaning of the code. 
                    - The compiler performs various checks to ensure that the code is semantically correct. 
                    - It verifies variable declarations, enforces type compatibility, detects undeclared identifiers, and checks for other language-specific rules.
                    
                - 04) Intermediate Code Generation:
                    - After the code's syntax and semantics have been analyzed, the compiler generates an intermediate representation of the code. 
                    - This representation is often in the form of an intermediate language, such as LLVM IR (Intermediate Representation), which is a platform-independent representation of the code.

                - 05) Optimization:
                    - The compiler applies various optimization techniques to the intermediate representation. 
                    - Optimization aims to improve the efficiency, performance, and size of the resulting executable code.
                    - Common optimizations include constant folding, dead code elimination, loop unrolling, and function inlining.
                    
                - 06) Code Generation:
                    - Code generation involves translating the optimized intermediate representation into machine code specific to the target architecture. 
                    - The compiler generates assembly instructions or directly produces object code, which is a binary representation of the machine instructions.

                - 07) Symbol Table Management:
                    - Throughout the compilation process, the compiler builds and maintains a symbol table. 
                    - The symbol table keeps track of identifiers (variables, functions, classes, etc.) and their associated information, such as types, memory addresses, and scope.

                - 08) Error Handling and Reporting:
                    - The compiler detects and reports any errors encountered during the compilation process. 
                    - It provides informative error messages that help developers identify and resolve issues in their code. 
                    -  Errors can range from syntax errors to type mismatch errors or unresolved references.

                - 09) Debug Information Generation:
                    - Optionally, the compiler may generate debug information to facilitate debugging. 
                    - Debug information includes mappings between the compiled code and the original source code, variable names, line numbers, and other debugging-related metadata.

                - The compilation stage transforms the source code into low-level machine code or object code, which can be executed directly by the computer's processor. 
                - It involves several complex processes, including lexical analysis, syntax analysis, semantic analysis, intermediate code generation, optimization, code generation, symbol table management, error handling, and debug information generation.
                - Understanding the compilation stage is crucial for optimizing code performance, diagnosing and resolving compilation errors, and gaining insights into the generated machine code.

        - 04) Object Files:
            - Object files are the intermediate compiled files produced by the compiler. 
            - They contain machine code specific to a particular architecture. 
            - Each object file corresponds to a compiled source code file.
            - Object files are typically independent and self-contained. 
            - They do not have complete information about symbols and references from other source files or libraries. 
            - Instead, they contain unresolved references that need to be resolved during the linking stage.
            - The object files generated in this stage serve as intermediate representations of the compiled code. 
            - They encapsulate the compiled machine code, symbol tables, relocation information, and optionally, debug information. 
            - These object files act as building blocks for the final executable or library during the linking stage.
            - Understanding the object file stage is crucial for understanding the modular nature of the compilation process and how object files are combined by the linker to produce the final executable or library. 
            - It also provides insights into the organization and structure of compiled code and the information needed for symbol resolution and relocation.
        
        - 05) Linking:
            - The linker combines the object files, resolves external references, and generates the final executable or library. 
            - It performs symbol resolution, merges object code, and links with necessary libraries. 
            - This stage involves several sub-processes like symbol table generation, relocation, and resolving dependencies.
            - Here's a more in-depth explanation of the linking stage in C++:
                - 01) Object File Input:
                    - The linking stage takes one or more object files (.o or .obj) generated during the compilation stage as input. 
                    - Each object file contains compiled machine code, symbol tables, and relocation information.

                - 02) Symbol Resolution:
                    - The linker resolves symbols by examining the symbol tables of all input object files. 
                    - It looks for unresolved symbols (references to functions or variables) and tries to find their definitions or addresses in other object files or libraries. 
                    - The linker aims to resolve all symbols and ensure that every reference has a corresponding definition.

                - 03) Symbol Table Merging:
                    - As the linker resolves symbols, it merges the symbol tables of different object files. 
                    - This process creates a consolidated symbol table that includes all symbols from the input files. 
                    - The merged symbol table becomes the reference for symbol resolution during the linking stage.

                - 04) Address and Relocation Fixing:
                    - The linker adjusts the memory addresses or offsets of symbols in the object files based on the relocation information. 
                    - It updates the references to symbols, ensuring that they point to the correct memory locations in the final executable or library.

                - 05) Library Resolution:
                    - If the linking process encounters unresolved symbols, it searches for the definitions in external libraries. 
                    - Libraries are collections of precompiled object files that contain reusable code. 
                    - The linker looks for the required symbols in the libraries specified by the user or default system libraries.

                - 06) Library Symbol Extraction:
                    - When a library is used to resolve a symbol, the linker extracts only the necessary object files from the library. 
                    - It avoids including the entire library, which helps reduce the size of the final executable or library.

                - 07) Link-Time Optimization (LTO):
                    - Link-Time Optimization is an optional step where the linker performs additional optimizations across different object files. 
                    - It can analyze and optimize code at a higher level than individual compilation units. 
                    - LTO can improve performance, reduce code size, and enable more aggressive optimizations across module boundaries.

                - 08) Output Generation:
                    - Finally, the linker generates the final executable or library file. 
                    - It combines the resolved object files, resolves all symbols, applies relocation fixes, and creates the appropriate file format based on the target platform. 
                    - The output file is ready for execution or distribution.

                - The linking stage is responsible for combining object files, resolving symbols, fixing addresses and relocations, and generating the final executable or library. 
                - It ensures that all references are properly resolved and the code is ready to be executed in a coherent and functional manner.

                - Understanding the linking stage is crucial for comprehending how separate modules and libraries are connected to create a complete program. 
                - It also provides insights into the symbol resolution process, symbol table merging, library usage, and optimization opportunities at the linking phase.

        - 06) Final Output:
            - The final output of the compilation process. 
            - It can be an executable file (if the goal is to create a standalone program) or a library file (if the goal is to create a reusable library for other programs). 
            - The output is ready to be executed or used by other programs.
            - Here's a more in-depth explanation of the final output stage in C++:
                - 01) Linking Stage:
                    - The final output stage 
                    - builds upon the output generated by the linking stage. 
                    - The linker combines the resolved object files, resolves symbols, applies relocation fixes, and generates the final executable or library file.

                - 02) Executable File Generation:
                    - In the case of an executable, the final output stage generates a standalone executable file (.exe on Windows, or without an extension on Unix-based systems). 
                    - This file contains the compiled machine code, along with any necessary metadata, such as entry point information and program headers.

                - 03) Library File Generation:
                    - If the output is a library, the final output stage produces a library file (.lib on Windows, or .a on Unix-based systems). 
                    - This file contains compiled object code that can be linked with other programs or libraries. 
                    - Libraries can be either static (linked directly into the executable) or dynamic/shared (loaded during runtime).

                - 04) File Format:
                    - The final output stage ensures that the generated executable or library file adheres to the appropriate file format for the target platform. 
                    - This includes proper formatting of headers, sections, segments, and other platform-specific requirements.

                - 05) Metadata:
                    - The output file may contain additional metadata, such as debug information, version information, and resource data. 
                    - Debug information aids in debugging and can include mappings between the compiled code and the original source code, variable names, line numbers, and other debugging-related metadata.

                - 06) Optional Optimization:
                    - Some compilers may perform additional optimizations during the final output stage. 
                    - These optimizations can include further code transformations, dead code elimination, function inlining, and other techniques to improve the performance and size of the final output.

                - 07) Entry Point:
                    - For executables, the final output stage determines the entry point of the program. 
                    - The entry point is the first instruction executed when the program is launched. 
                    - It typically initializes the program's runtime environment and begins the execution of the main function or a designated startup routine.

                - 08) Artifact Archiving:
                    - If multiple source files were compiled separately and produced individual object files, the final output stage may also involve archiving those object files into an archive file (such as a .a or .lib file). 
                    - This archive allows easy distribution and reusability of the compiled object code.

                - 09) Final File Integrity and Verification:
                    - Before the output file is considered complete, the final output stage performs integrity checks and verifies that the file meets the necessary requirements for execution or linking. 
                    - This ensures that the generated output is valid and can be safely used.

                - The final output stage is responsible for generating the fully executable or linkable file, whether it is an executable or a library. 
                - It handles file formatting, metadata inclusion, optional optimizations, entry point determination, and verification of the output's integrity.
                - Understanding the final output stage is crucial for understanding how the compiled code is packaged into a runnable or linkable form, and how different components of the program interact with each other. 
                - It provides insights into the final executable or library file, its structure, and the requirements for proper execution or linking.
                
        - This detailed diagram provides a comprehensive view of the compilation process, depicting the flow from source code files to the final executable or library. 
        - It highlights the major stages involved and their relationships in building a C++ program.

        - Here is a list of topics related to C++ compilation 'Must Search':
            - 01) Preprocessing:
                - Preprocessor directives (e.g., #include, #define)
                - Macros and macro expansion
            - 02) Lexical Analysis:
                - Tokens
                - Identifiers, keywords, literals, operators
            - 03) Syntax Analysis:
                - Grammar rules
                - Expressions, statements, program structure
            - 04) Semantic Analysis:
                - Type checking
                - Variable declarations and scoping
                - Function and method signatures
                - Type compatibility and conversions
            - 05) Intermediate Representation:
                - Intermediate language (e.g., LLVM IR)
                - Optimization techniques
            - 06) Code Generation:
                - Machine code generation
                - Assembly language
                - Object file format
            - 07) Symbol Resolution:
                - Symbols and symbol tables
                - Static and dynamic linking
                - External libraries
            - 08) Relocation and Address Fixing:
                - Relocation information
                - Linker-generated code and data
                - Address resolution and adjustments
            - 09) Link-Time Optimization (LTO):
                - Cross-module optimization
                - Inlining, dead code elimination, loop unrolling
            - 10) Object Files:
                - Object file format
                - Symbol tables and relocation information
                - Debug information
            - 11) Libraries:
                - Static libraries (.lib, .a files)
                - Dynamic/shared libraries (.dll, .so files)
                - Linker search paths and library resolution
            - 12) Final Output:
                - Executable file format
                - Entry point and program headers
                - Debug information generation
            - 13) Compilation Process Overview:
                - Phases of compilation
                - Compilation pipeline
                - Dependencies and build systems
            - 14) Compiler Flags and Options:
                - Optimization flags
                - Debugging flags
                - Language and platform-specific flags
            - 15) Build Systems:
                - Makefiles
                - CMake
                - Build automation tools (e.g., Bazel, Gradle)
            - 16) Cross-Compilation:
                - Target architectures and platforms
                - Cross-compiling toolchains
            - 17) Error Handling and Diagnostics:
                - Compiler errors and warnings
                - Debugging and profiling tools
            - 18) Incremental Compilation:
                - Dependency tracking
                - Compilation units and recompilation
            - 19) Compiler Extensions:
                - Language extensions (e.g., C++ extensions, compiler-specific features)
                - Compiler-specific optimization options
            - 20) Compiler Internals and Implementations:
                - Compiler architecture and design
                - Compiler optimization strategies
                - Compiler development and research
*/






















#endif









