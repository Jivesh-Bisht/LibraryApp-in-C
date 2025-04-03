#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tf{False,True};

typedef struct {
    int id;
    char name[50];
    char password[50];
    int isAdmin;
} USER;

// Prototyping -------------------------------------------------------------
void printUsers();
int addUser(char name[50], char password[50]);
int removeUser(char name[50]);
int checkUser(char name[50]);
int checkPassword(char password[50]);
// End Prototyping ---------------------------------------------------------

int addUser(char name[50], char password[50]) {
    USER u;
    int id = 0;
    const char filename[] = "users.txt";
    FILE *file = fopen(filename, "r");

    // Read existing users to find the next available ID
    if (file) {
        while (fscanf(file, "%d %s %s %d", &u.id, u.name, u.password, &u.isAdmin) == 4) {
            if (strcmp(name, u.name) == 0) {
                fclose(file);
                return False; // User already exists
            }
            id = u.id;
        }
        fclose(file);
    } else {
        // File doesn't exist, start with ID 1
        id = 0;
    }

    // Increment the ID for the new user
    id++;

    // Open the file in append mode to add the new user
    file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file for writing");
        return False;
    }

    int isAdmin = 0; // Users are not admins, admins may get another function??
    fprintf(file, "%d %s %s %d\n", id, name, password, isAdmin);
    fclose(file);
    return True;
}

int removeUser(char nameToRemove[50]) {
    const char filename[] = "users.txt";
    const char tempFilename[] = "temp_users.txt";
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen(tempFilename, "w");

    if (!file) {
        perror("Error opening users.txt for reading");
        return False;
    }

    if (!tempFile) {
        perror("Error opening temp_users.txt for writing");
        fclose(file);
        return False;
    }

    USER u;
    int userFound = 0;

    while (fscanf(file, "%d %s %s %d", &u.id, u.name, u.password, &u.isAdmin) == 4) {
        if (strcmp(u.name, nameToRemove) != 0) {
            fprintf(tempFile, "%d %s %s %d\n", u.id, u.name, u.password, u.isAdmin);
        } else {
            userFound = 1; // User found, but not written to temp file
        }
    }

    fclose(file);
    fclose(tempFile);

    if (userFound) {
        remove(filename);
        rename(tempFilename, filename);
        printf("User '%s' removed successfully.\n", nameToRemove);
        return True;
    } else {
        remove(tempFilename); // Delete the temporary file
        printf("User '%s' not found.\n", nameToRemove);
        return False;
    }
}

int checkUser(char name[50]) {
    USER u;
    const char filename[] = "users.txt";
    FILE *file = fopen(filename, "r");
    while (fscanf(file, "%d %s %s %d", &u.id, u.name, u.password, &u.isAdmin) == 4) {
        if (strcmp(name, u.name) == 0) {
            fclose(file);
            return True;
        }}
    fclose(file);
    return False;
}

int checkPassword(char password[50]) {
    USER u;
    const char filename[] = "users.txt";
    FILE *file = fopen(filename, "r");
    while (fscanf(file, "%d %s %s %d", &u.id, u.name, u.password, &u.isAdmin) == 4) {
        if (strcmp(password, u.password) == 0) {
            fclose(file);
            return True;
        }}
    fclose(file);
    return False;
}

void printUsers() {
    const char filename[] = "users.txt";
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
    }
    USER u;
    printf("ID NAME PASSWORD \n");
    while (fscanf(file,"%d %s %s %d",&u.id,u.name,u.password,&u.isAdmin) == 4){
        printf("%-5d %-15s %-15s %-5d\n",u.id,u.name,u.password,u.isAdmin);
    }
    fclose(file);
}


