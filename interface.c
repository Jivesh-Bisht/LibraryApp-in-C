#include <stdio.h>
#include <string.h>
#include "library.h"
#include "authentication.h"


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

void afterLogin(char username[50]){
    int run = True;
    int input;
    while (run){
        printf("0. Loan a book\n");
        printf("1. Return a book\n");
        printf("2. Logout\n");
        printf("3. Delete this account\n");
        printf("What do you want to do??   ->");
        // Check if scanf successfully reads an integer
        if (scanf("%d", &input) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please enter a number.\n");
            continue; // Skip the rest of the loop iteration
        }
        
        clear_input_buffer();

        switch (input){
            case 0:{
                break;
            }

            case 1:{
                break;
            }

            case 2:{
                break;
            }

            case 3:{
                break;
            }
        }
        
    }
}   

int main(){
    int run=True;
    printf("-----------------------------\n");
    printf("Greatings User!!\n");
    int input;
    while(run){
        printf("0. Exit \n");
        printf("1. Print whole library \n");
        printf("2. Login \n");
        printf("3. Signup\n");
        printf("What do you want to do??   ->");
        
        // Check if scanf successfully reads an integer
        if (scanf("%d", &input) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please enter a number.\n");
            continue; // Skip the rest of the loop iteration
        }
        
        clear_input_buffer();

        switch (input){
            case 0:
            run = False;
            break;

            case 1:
            readWholeLibrary();
            break;

            case 2: {
            printf("Enter your username: ");
            char username[50];
            scanf("%s",username);
            int isUser = checkUser(username);

            if (isUser){
                printf("Enter your password: ");
                char password[50];
                scanf("%s",password);
                int isPassword = checkPassword(password);

                if (isPassword){
                    printf("Welcome %s!\n",username);
                    afterLogin(username);

                }else{
                    printf("Password was incorrect!\n");
                }

            } else{
                printf("User with the name \"%s\" not found! \n",username);
            }
            break;
        }

            case 3:{
            printf("Enter your username: ");
            char username[50];
            scanf("%s",username);
            int isUser = checkUser(username);
            if (isUser){
                printf("Username already in use! Please use another username\n");
            }else{
                char password[50];
                printf("Enter a secure password: ");
                scanf("%s",password);
                int done = addUser(username,password);
                if (done){
                    printf("Welcome %s\n",username);
                    afterLogin(username);
                }else{
                    printf("An Unexpected error occured!\n");
                }
            }
            break;
        }
        }

    }
    printf("Thanks for coming to our library, hope to see you soon!!");
    scanf("%s");
    return 0;
}