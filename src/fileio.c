#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cJSON.h"
#include "fileio.h"
#include "contacts.h"

#define JSON_PATH "data//contacts.json"
#define CSV_PATH "data/contacts.csv"


void loadContacts(Contact *contacts, int *count){
    FILE *fptr = fopen(JSON_PATH,"r");
    if(!fptr) return;

    fseek(fptr, 0, SEEK_END);
    long len = ftell(fptr);
    rewind(fptr);


    char *data = malloc(len + 1);
    fread(data, 1, len, fptr);
    data[len] = '\0';
    fclose(fptr);


    cJSON *root = cJSON_Parse(data);
    free(data);


    if (!root) return;


    int n = cJSON_GetArraySize(root);
    *count = 0;
    
    for (int i = 0; i < n && i < MAX_CONTACTS; i++) {
        cJSON *obj = cJSON_GetArrayItem(root, i);

        cJSON *name = cJSON_GetObjectItem(obj, "name");
        cJSON *number = cJSON_GetObjectItem(obj, "number");
        cJSON *email = cJSON_GetObjectItem(obj, "email");

        if (cJSON_IsString(name) && cJSON_IsString(number) && cJSON_IsString(email)) {
            strcpy(contacts[i].name, name->valuestring);
            strcpy(contacts[i].number, number->valuestring);
            strcpy(contacts[i].email, email->valuestring);
            (*count)++;
        }

    }

    cJSON_Delete(root);
}

void saveContact(Contact *contacts, int count){

    cJSON *root = cJSON_CreateArray();


    for (int i = 0; i < count; i++) {
        cJSON *obj = cJSON_CreateObject();


        cJSON_AddStringToObject(obj, "name", contacts[i].name);
        cJSON_AddStringToObject(obj, "number", contacts[i].number);
        cJSON_AddStringToObject(obj, "email", contacts[i].email);

        cJSON_AddItemToArray(root, obj);
    }

    char *json = cJSON_Print(root);

    FILE *fptr = fopen(JSON_PATH,"w");
    if(!fptr){
        printf("Error Saving File!\n");
        free(json);
        cJSON_Delete(root);
        return;
    }

    fprintf(fptr, "%s", json);
    fclose(fptr);

    free(json);
    cJSON_Delete(root);

    printf("Contact Saved Successfully!\n");
}


void export(Contact *contacts, int count) {
    FILE *fp = fopen(CSV_PATH, "w");
    if (!fp) {
        printf("Error creating CSV file\n");
        return;
    }

    fprintf(fp, "Name,Number,Email\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%s\n",
                contacts[i].name,
                contacts[i].number,
                contacts[i].email);
    }

    fclose(fp);
    printf("Contacts exported successfully!\n");
}


// Worked............