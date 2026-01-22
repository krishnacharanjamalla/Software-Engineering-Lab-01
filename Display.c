#include "Display.h"
#include "String_Functions.h"
#include <stdio.h>
void Display(student s[], int count){
    float avg = 0;
    float high = s[0].percent;
    float low  = s[0].percent;

    int g[8] = {0};   

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("ID\tName\tS1\tS2\tS3\tS4\tS5\tTotal\t\tPercentage\tGrade\tCGPA\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < count; i++){

        printf("%s\t%s\t", s[i].id, s[i].name);

        for(int j = 0; j < SUBJECTS; j++){
            printf("%d\t",                
                s[i].marks[j][0]+
                s[i].marks[j][1]);
        }

        printf("%d/500\t\t%.2f\t\t%s\t%.2f\n",
            s[i].total,
            s[i].percent,
            s[i].grade,
            s[i].cgpa
        );

        avg += s[i].percent;
        if(s[i].percent > high) high = s[i].percent;
        if(s[i].percent < low)  low  = s[i].percent;

        if(stringCompare(s[i].grade,"O")) g[0]++;
        else if(stringCompare(s[i].grade,"A+")) g[1]++;
        else if(stringCompare(s[i].grade,"A")) g[2]++;
        else if(stringCompare(s[i].grade,"B+")) g[3]++;
        else if(stringCompare(s[i].grade,"B")) g[4]++;
        else if(stringCompare(s[i].grade,"C")) g[5]++;
        else if(stringCompare(s[i].grade,"D")) g[6]++;
        else g[7]++;
    }

    printf("-------------------------------------------------------------------------------------------------\n");

    printf("Class Average Percentage : %.2f\n", avg / count);
    printf("Highest Percentage       : %.2f\n", high);
    printf("Lowest Percentage        : %.2f\n", low);

    printf("\nNumber of Students in Each Grade:\n");
    printf("O  : %d\n", g[0]);
    printf("A+ : %d\n", g[1]);
    printf("A  : %d\n", g[2]);
    printf("B+ : %d\n", g[3]);
    printf("B  : %d\n", g[4]);
    printf("C  : %d\n", g[5]);
    printf("D  : %d\n", g[6]);
    printf("F  : %d\n", g[7]);
}
