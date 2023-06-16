#ifndef __VARIABLES_LIFETIME_SCOPES
#define __VARIABLES_LIFETIME_SCOPES

/*
    - Storage Duration: (Ref# https://en.cppreference.com/w/cpp/language/storage_duration)
        - Automatic storage duration. 
            - The storage for the object is allocated at the beginning of the enclosing code block and deallocated at the end.
            - All local objects have this storage duration, except those declared static, extern or thread_local. 
        - Static storage duration. 
            - The storage for the object is allocated when the program begins and deallocated when the program ends. 
            - Only one instance of the object exists. 
            - All objects declared at namespace scope (including global namespace) have this storage duration, plus those declared with static or extern. 
            - See Non-local variables and Static local variables for details on initialization of objects with this storage duration. 
        - Thread storage duration. 
            - The storage for the object is allocated when the thread begins and deallocated when the thread ends. 
            - Each thread has its own instance of the object. Only objects declared thread_local have this storage duration. 
            - thread_local can appear together with static or extern to adjust linkage. 
            - See Non-local variables and Static local variables for details on initialization of objects with this storage duration. 
        - Dynamic storage duration. 
            - The storage for the object is allocated and deallocated upon request by using dynamic memory allocation functions. 
            - See new-expression for details on initialization of objects with this storage duration. 


*/







#endif









