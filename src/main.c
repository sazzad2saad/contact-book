#include<stdio.h>
#include<stdlib.h>
#include "color.h"
#include "contacts.h"
#include "fileio.h"
// #include "temp.c"

#define RESET     "\033[0m"

int show_menu(void);

int main(void){
   colored_window();
   
   Contact contacts[MAX_CONTACTS];
   int count = 0;

   loadContacts(contacts, &count);


   int choice;
   do{
      choice = show_menu();

      //scanf("%i",&choice);

      switch (choice)
      {
      case 1:
         addContact(contacts, &count); break;
      case 2:
         listContact(contacts, count);break;
      case 3:
         searchContact(contacts, count); break;
      case 4:
         editContact(contacts, count); break;
      case 5:
         deleteContact(contacts, &count); break;
      case 6:
         sortContact(contacts, count); break;
      case 7:
         export(contacts, count); break;
      case 0:
         saveContact(contacts, count); printf("Saved and Exiting"); break;
      default:
         printf("Invalid Choice!"); //White: "\e[0;97m" RED: "\033[1;31m"
         break;
      }
   } while (choice !=0);
   



   printf(RESET);
   return 0;
}

int show_menu(void){
    
   printf("Contact Book\n");
   printf("1. Add Contact\n");
   printf("2. List Contact\n");
   printf("3. Search Contact\n");
   printf("4. Edit Contact\n");
   printf("5. Delete Contact\n");
   printf("6. Sort Contact\n");
   printf("7. Export in CSV \n");
   printf("0. EXIT\n");

   int choice; scanf("%i",&choice);

   return choice;
}