
#include "student.h"

int stringCompare(char a[], char b[]){
    int i=0;
    while(a[i] && b[i]){
        if(a[i]!=b[i]) return 0;
        i++;
    }
    return a[i]==b[i];
}

void stringCopy(char d[], char s[]){
    int i=0;
    while(s[i]){
        d[i]=s[i];
        i++;
    }
    d[i]='\0';
}
