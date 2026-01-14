#include <stdio.h>
#include "student.h"

int main(int argc,char *argv[]){
    if(argc < 2){
        printf("Please check the input files are provided\n");
        return 0;
    }

    FILE *f = fopen(argv[1],"r");
    if(!f){
        printf("error while opening file\n");
        return 0;
    }

    student students[MAX];
    int count = 0;

    while(fscanf(f,"%s %s", students[count].id, students[count].name) == 2){

        // ID & name validation
        if(!ID_Check(students[count].id))
            continue;

        if(Duplicate_Check(students, count, students[count].id))
            continue;

        if(!Name_Check(students[count].name))
            continue;

        students[count].total = 0;
        int ok = 1;

        for(int i = 0; i < SUBJECTS; i++){
            int minor, major;

            if(fscanf(f,"%d %d", &minor, &major) != 2){
                ok = 0;
                break;
            }

            // Range check
            if(minor < 0 || minor > 40 || major < 0 || major > 60){
                ok = 0;
            }

            // Store TOTAL marks per subject (0–100)
            students[count].marks[i][0] = minor + major;
            students[count].marks[i][1] = 0;   // unused, keep safe

            students[count].total += students[count].marks[i][0];
        }

        if(!ok){
            // discard this student completely
            continue;
        }

        students[count].percent = students[count].total / (float)SUBJECTS;

        // Grade + CGPA
        assignGrade(&students[count]);

        count++;
    }

    fclose(f);

    if(count == 0){
        printf("No valid student records found\n");
        return 0;
    }

    display(students, count);
    return 0;
}
