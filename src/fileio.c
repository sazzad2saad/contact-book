#include<stdio.h>
#include<string.h>
#include "fileio.h"
#include "contacts.h"

#define FILE_PATH "data//contacts.dat"
#define CSV_PATH "data//contatcs.csv" 

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
void export(Contact *contacts, int count){
    FILE *fptr = fopen(CSV_PATH,"w");
    if(!fptr){
        printf("Error Creating CSV file...");
        return;
    }

    fprintf(fptr,"Name,Number,Email\n");
    for(int i = 0; i< count; i++){
        fprintf(fptr,"%s,%s,%s\n",contacts[i].name, contacts[i].number, contacts[i].email);
    }

    fclose(fptr);
    printf("Contact has been exported Successfully!");
}

// Worked............