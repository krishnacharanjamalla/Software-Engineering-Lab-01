#include "Grading.h"
#include "String_Functions.h"

void assignGrade(student *s){
    float sum = 0.0;
    int totalCredits = 0;
    int failed = 0;

    int credits[SUBJECTS] = {3, 4, 3, 3, 2};

    for(int i = 0; i < SUBJECTS; i++){

        int subjectTotal = s->marks[i][0];
        int gp = 0;

        if(subjectTotal >= 90){
            stringCopy(s->subGrade[i], "O");  gp = 10;
        }
        else if(subjectTotal >= 85){
            stringCopy(s->subGrade[i], "A+"); gp = 9;
        }
        else if(subjectTotal >= 75){
            stringCopy(s->subGrade[i], "A");  gp = 8;
        }
        else if(subjectTotal >= 65){
            stringCopy(s->subGrade[i], "B+"); gp = 7;
        }
        else if(subjectTotal >= 60){
            stringCopy(s->subGrade[i], "B");  gp = 6;
        }
        else if(subjectTotal >= 55){
            stringCopy(s->subGrade[i], "C");  gp = 5;
        }
        else if(subjectTotal >= 50){
            stringCopy(s->subGrade[i], "D");  gp = 4;
        }
        else{
            stringCopy(s->subGrade[i], "F");
            gp = 0;
            failed = 1;
        }

        sum += gp * credits[i];
        totalCredits += credits[i];
    }

    s->cgpa = (float)sum / totalCredits;

    // Overall grade
    if(failed){
        stringCopy(s->grade, "F");
        return;
    }

    if(s->cgpa >= 9.0)      stringCopy(s->grade,"O");
    else if(s->cgpa >= 8.5) stringCopy(s->grade,"A+");
    else if(s->cgpa >= 7.5) stringCopy(s->grade,"A");
    else if(s->cgpa >= 6.5) stringCopy(s->grade,"B+");
    else if(s->cgpa >= 6.0) stringCopy(s->grade,"B");
    else if(s->cgpa >= 5.5) stringCopy(s->grade,"C");
    else if(s->cgpa >= 5.0) stringCopy(s->grade,"D");
    else                    stringCopy(s->grade,"F");
}
