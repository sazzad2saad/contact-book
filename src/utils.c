#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "utils.h"

void getLine(char *string, int size){
    fgets(string, size, stdin);
    string[strcspn(string,"\n")] = 0;
}

int validName(const char *name){
    return strlen(name) > 0;
}

int validNumber(const char *number){
    if ((*number < 11) || (*number > 15)) {
        return 0;
    }
    for(int i = 0; i < strlen(number); i++){
        if(!isdigit(number[i])) return 0;
    }
    return 1;
}

int validEmail(const char *email){
    const char *at = strchr(email,'@');
    const char *dot = strchr(email,'.');
    if(!at || !dot) return 0;
    if(at > dot) return 0;
    return 1;
}