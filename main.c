/*
 county library management system
 by Patrick Mwania
 Feb 2022
 MIT license
 C89 Compiler
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Patron {
    char name[100];
    char email[50];
    char password[30];
    int is_staff;
};

// Function declarations
void add_patron();
int menu();
void execute_action(int action);
void save_patron(struct Patron patron);
void view_patrons();

int main()
{
    while(1) {
        printf("COUNTY LIBRARY SYSTEM\n");
        printf("Welcome Mr. patrick\n");
        execute_action(menu());
        printf("Press any key to continue");
        getch();
        system("cls");
    }
    return 0;
}

void add_patron() {
    struct Patron patron;
    printf("Enter name: ");
    getchar();
    gets(patron.name);
    printf("Enter Email: ");
    gets(patron.email);
    printf("Enter initial password: ");
    gets(patron.password);
    printf("Enter 1 if staff 0 otherwise");
    scanf("%d",&patron.is_staff);
    save_patron(patron);
    printf("%s added\n",patron.name);
}

int menu() {
    int action;
    printf("Select an action below\n");
    printf("1. Add new Patron\n");
    printf("2. View all patrons\n");
    printf("3. View all Books\n");
    printf("4. Add new Book\n");
    printf("Your action: ");
    scanf("%d",&action);
    if(action < 1 || action > 4) {
        printf("Invalid Action. Try again\n");
    }
    return action;
}

void execute_action(int action) {
    switch(action) {
    case 1:
        add_patron();
        break;
    case 2:
        printf("list of all patrons\n");
        view_patrons();
        break;
    case 3:
        printf("list of all books\n");
        break;
    case 4:
        printf("adding a new book\n");
        break;
    default: printf("Invalid action.\n");
    }
}

void save_patron(struct Patron patron) {
    FILE *fp;
    fp = fopen("patrons","a+b");
    fwrite(&patron,sizeof(struct Patron),1,fp);
    fclose(fp);
}

void view_patrons() {
   FILE *fp;
   struct Patron patron;
   fp = fopen("patrons","r+b");
   printf("%-30s%-30s%-10s\n","NAME","EMAIL","IS STAFF");
   while(!feof(fp)){
    fread(&patron,sizeof(struct Patron),1,fp);
    printf("%-30s",patron.name);
    printf("%-30s",patron.email);
    printf("%-10d\n",patron.is_staff);
   }
}


}
