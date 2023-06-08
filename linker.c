#include <stdio.h>
#include <stdlib.h>

// Function declarations to be linked to external files
extern void func1();
extern void func2();

// External variable declaration from external file
extern int sharedVariable;

// Main function
int main() {
    //printf("Linking Example\n");
    
    //Create a variable that stores the address of the functions and variable
    //Save them as void to display the address in hexa decimal format
    
    void (*func1_addr)() = &func1;
    void (*func2_addr)() = &func2;
    int *var_addr = &sharedVariable;
    
    // Call functions from different object files
    
    func1();
    func2();

    // Access shared variable from another object file
    
    printf("\nShared Variable: %d\n", sharedVariable);
    printf("\nThe memory location where shared variable is: %p\n",(void*)var_addr);
    printf("\nThe memory location where function 1 is defined is: %p\n",(void*)func1_addr);
    printf("\nThe memory location where function 2 is defines is: %p\n",(void*)func2_addr);
   
    return 0;
}
