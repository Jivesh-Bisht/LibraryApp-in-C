#include <stdio.h>
#include <string.h>

enum ft {False,True};
int saveBook(char name[50],char author[50],int lent);

typedef struct{
    int id;
    char name[255];
    char author[255];
    int lent;
    char lentTo[255];

} BOOK;

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
    BOOK savedBook;
    savedBook.id = id;
    strcpy(savedBook.name, name);
    strcpy(savedBook.author, author);
    savedBook.lent = lent;
    strcpy(savedBook.lentTo, lentTo);
    
    file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    fprintf(file, "%d %s %s %d %s\n", savedBook.id, savedBook.name, savedBook.author, savedBook.lent, savedBook.lentTo);
    fclose(file);
    return 0;
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
        printf("%-5d %-5s %-5s %-5d %-5s\n",b.id,b.name,b.author,b.lent,b.lentTo);
    }
    fclose(file);
}

int main(){
    int saved = saveBook("nfae32322s","gay",0);
    printf("%d",saved); 
    return 0;
}