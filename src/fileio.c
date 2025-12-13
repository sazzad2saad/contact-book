#include<stdio.h>
#include<string.h>
#include "fileio.h"
#include "contacts.h"

#define FILE_PATH "data//contacts.dat"

void loadContacts(Contact *contacts, int *count){
    FILE *fptr = fopen(FILE_PATH,"rb");
    if(!fptr) return;

    *count = fread(contacts, sizeof(Contact), MAX_CONTACTS, fptr);
    fclose(fptr);
}

void saveContact(Contact *contact, int count){
    FILE *fptr = fopen(FILE_PATH,"wb");
    if(!fptr){
        printf("Error Saving File!\n");
        return;
    }

    fwrite(contact, sizeof(Contact), count, fptr);
    fclose(fptr);
    printf("Contact Saved Successfully!\n");
}