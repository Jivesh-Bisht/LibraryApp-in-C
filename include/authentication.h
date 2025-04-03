#ifndef AUTHENTICATION
#define AUTHENTICATION

int printUsers();
int addUser(char name[50],char password[50]);
int removeUser(char name[50]);
int checkUser(char name[50]);
int checkPassword(char password[50]);

#endif