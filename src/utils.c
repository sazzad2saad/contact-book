#include<stdio.h>
#include<string.h>
#include "utils.h"

void getLine(char *string, int size){
    fgets(string, size, stdin);
    string[strcspn(string,"\n")] = 0;
}