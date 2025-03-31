#include <stdio.h>
#include <string.h>
#include "library.h"


enum tf {False,True};
/*
TODO:
1. make loaning function
2. User Authentication
3. Admin only functions(add books,add/delete users)
*/

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    int run=True;
    printf("-----------------------------\n");
    printf("Greatings User!!\n");
    int input;
    while(run){
        printf("0. Exit \n");
        printf("1. Print whole library \n");
        printf("What do you want to do??\t->");
        
        // Check if scanf successfully reads an integer
        if (scanf("%d", &input) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please enter a number.\n");
            continue; // Skip the rest of the loop iteration
        }
        
        clear_input_buffer();

        if (input == 1) {
            readWholeLibrary();
        }else if (input==0){
            break;
        }

    }
    printf("Thanks for coming to our library, hope to see you soon!!");
    return 0;
}