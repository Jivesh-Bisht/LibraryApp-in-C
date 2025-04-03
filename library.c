#include <stdio.h>
#include <string.h>
#include "library.h"


enum ft {False,True};
// Prototyping ----------------------------------------------------
void readWholeLibrary();
int isBookAlreadyPresent(char name[50],char author[50]);
int saveBook(char name[50],char author[50],int lent);
// End Prototyping -----------------------------------------------
typedef struct{
    int id;
    char name[255];
    char author[255];
    int lent;
    char lentTo[255];

} BOOK;

// self-explainatory
int isBookAlreadyPresent(char name[50],char author[50]){
    const char filename[] = "books.txt";
    FILE *file = fopen(filename, "r");
    BOOK b;
    while (fscanf(file,"%d %s %s %d %s",&b.id,b.name,b.author,&b.lent,b.lentTo) == 5){
        if(strcmp(name, b.name) == 0 && strcmp(author, b.author) == 0){
            return 1;
        }
    }
    return 0;
}
// Used to add a new entry for a new book
int saveBook(char name[50],char author[50],int lent) {
    printf("%s,%s,%d\n",name,author,lent);
    char lentTo[50];
    if(lent == False ) {
        strcpy(lentTo,"None");
    }
    const char filename[] = "books.txt";
    FILE *file = fopen(filename, "r");
    BOOK b;
    int id;
    while (fscanf(file,"%d %s %s %d %s",&b.id,b.name,b.author,&b.lent,b.lentTo) == 5){
        if(strcmp(name, b.name) == 0 && strcmp(author, b.author) == 0){
            return 1;
        }
        id = b.id;
    }
    id++;
    fclose(file);
    file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    
    fprintf(file, "%d %s %s %d %s\n", id, name, author, lent, lentTo);
    fclose(file);
    return 0;
}

int loanBook(char username[50],int bookId){
    const char filename[] = "books.txt";
    FILE *file = fopen(filename, "r");
    BOOK b;
    while (fscanf(file,"%d %s %s %d %s",&b.id,b.name,b.author,&b.lent,b.lentTo) == 5){
        if(b.id == bookId){
            
            return True;
        }
    }
    return False;
}
int returnBook(){

}
// Prints out the whole Library
void readWholeLibrary() {
    const char filename[] = "books.txt";
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
    }
    BOOK b;
    printf("ID NAME AUTHOR LENT LENTO\n");
    while (fscanf(file,"%d %s %s %d %s",&b.id,b.name,b.author,&b.lent,b.lentTo) == 5){
        printf("%-5d %-15s %-15s %-5d %-5s\n",b.id,b.name,b.author,b.lent,b.lentTo);
    }
    fclose(file);
}