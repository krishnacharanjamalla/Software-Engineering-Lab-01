#include "Preprocessing.h"

int ID_Check(char id[]){
    for(int i = 0; id[i] != '\0'; i++){
        int ch = (int)id[i];

        if(!((ch >= 48 && ch <= 57) ||   // 0-9
             (ch >= 65 && ch <= 90) ||   // A-Z
             (ch >= 97 && ch <= 122)))  // a-z
        {
            return 0;   // invalid ID
        }
    }
    return 1;           // valid ID
}


int Name_Check(char name[]){
    for(int i = 0; name[i] != '\0'; i++){
        int ch = (int)name[i];
        if(!((ch >= 65 && ch <= 90) ||   // A-Z
             (ch >= 97 && ch <= 122)))  // a-z
        {
            return 0;   // invalid name
        }
    }
    return 1;           // valid name
}

int Duplicate_Check(student s[], int count, char id[]){
    for(int i=0;i<count;i++){
        if(stringCompare(s[i].id,id))
            return 1;
    }
    return 0;
}
