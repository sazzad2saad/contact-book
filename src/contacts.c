#include<stdio.h>
#include<string.h>
#include "contacts.h"
#include "utils.h"

void addContact(Contact *contacts, int * count){
    if (*count >= MAX_CONTACTS){
        printf("Contatct list is FULL!\n");
        return;
    }

    Contact contact;
    do{
        printf("Enter name: "); getLine(contact.name, 50);
        if(!validName(contact.name)){
            printf("Name cannot be empty!");
        }
    } while (!validName(contact.name));

    do{
        printf("Enter number: "); getLine(contact.number, 16);
        if(!validNumber(contact.number)){
            printf("Give a Valid number");
        }
    } while (!validNumber(contact.number));
    
    do{
        printf("Enter Email: "); getLine(contact.email, 50);
        if(!validEmail(contact.email)){
            printf("Give a valid Email!");
        }
    }while (!validEmail(contact.email));
    
    contacts[*count] = contact;
    (*count)++;
    printf("Contact added successfully!\n");
}

void listContact(Contact *contacts, int count){
    if(count == 0){
        printf("No contact Available!\n");
        return;
    }
    printf("Contact List\n");
    for(int i = 0; i < count; i++){
        printf("%.2i. %s | %s | %s\n", i + 1, contacts[i].name, contacts[i].number, contacts[i].email);
    }
}

void searchContact(Contact *contacts, int count){
    char name[50];
    do{
        printf("Enter name: "); getLine(name, 50);
        if(!validName(name)){
            printf("Name cannot be empty!");
        }
    } while (!validName(name));

    for(int i = 0; i < count; i++){
        if(strcasecmp(contacts[i].name,name) == 0){
            printf("Found: %s | %s | %s\n",contacts[i].name, contacts[i].number,contacts[i].email);
            return;
        }
    }
}

void editContact(Contact *contacts, int count){
    char name[50];
    do{
        printf("Enter name: "); getLine(name, 50);
        if(!validName(name)){
            printf("Name cannot be empty!");
        }
    } while (!validName(name));

    for (int i = 0; i < count; i++){
        if(strcasecmp(contacts[i].name, name) == 0){
            printf("Editting %s...", contacts[i].name);

            do{
                printf("Enter number: "); getLine(contacts[i].number, 16);
                if(!validNumber(contacts[i].number)){
                    printf("Give a Valid number");
                }
            } while (!validNumber(contacts[i].number));
            
            do{
                printf("Enter Email: "); getLine(contacts[i].email, 50);
                if(!validEmail(contacts[i].email)){
                    printf("Give a valid Email!");
                }
            } while (!validEmail(contacts[i].email));

            return;
        }
    }
}

void deleteContact(Contact *contacts, int *count){
    char name[50]; 
    do{
        printf("Enter name: "); getLine(name, 50);
        if(!validName(name)){
            printf("Name cannot be empty!");
        }
    } while (!validName(name));

    for (int i = 0; i < *count; i++){
        if(strcasecmp(contacts[i].name, name) == 0){
            for(int j = i; j < *count - 1 ; j++){
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact Deleted\n");
            return;
        }
    }
    return;
}

// Using Quick Sort for sorting
void swap(Contact *x, Contact *y){
    Contact temp = *x;
    *x = *y;
    *y = temp;
}

int partition(Contact *contacts, int low, int high){
    char *pivot = contacts[high].name;
    int i = (low - 1);
    for(int j = low; j < high; j++){
        if(strcasecmp(contacts[j].name, pivot) <= 0){
            i++;
            swap(&contacts[i], &contacts[j]);
        }
    }
    swap(&contacts[i + 1], &contacts[high]);
    return i + 1;
}

void quickSort(Contact *contacts, int low, int high ){
    if(low < high){
        int pi = partition(contacts, low, high);

        quickSort(contacts, low, pi - 1);
        quickSort(contacts, pi + 1, high);
    }
}

void sortContact(Contact *contacts, int count){
    if(count > 1){
        quickSort(contacts, 0, count - 1);
    }
    printf("Contacts are sorted!\n");
    return;
}