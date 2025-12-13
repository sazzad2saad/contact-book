#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 500

typedef struct 
{
    char name[50];
    char number[16];
    char email[50];
}Contact;


void addContact(Contact *, int *);
void listContact(Contact *, int);
void searchContact(Contact *, int);
void editContact(Contact *, int);
void deleteContact(Contact *, int *);
void sortContact(Contact *, int);


#endif