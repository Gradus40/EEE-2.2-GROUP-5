#include<stdio.h>

int main()
{
    char name[20];
    float programming, maths, O_S, average;
    char grade;
    char remark[20];
    
    printf("Enter the name of the student: ");
    scanf("%s", name);
    
    printf("Enter marks in Programming: ");
    scanf("%f", &programming);
    
    printf("Enter marks in Maths: ");
    scanf("%f", &maths);
    
    printf("Enter marks in O/S: ");
    scanf("%f", &O_S);
    
    average = (programming + maths + O_S) /;
    
    if(average >= 80)
        grade = '1';
    else if(average >= 60 && average < 80)
        grade = '3';
    else if(average >= 40 && average < 60)
        grade = '5';
    else if(average >= 0 && average < 40)
        grade = '7';
    
    if(grade == '1')
        strcpy(remark, "Distinction");
    else if(grade == '3')
        strcpy(remark, "Credit");
    else if(grade == '5')
        strcpy(remark, "Pass");
    else if(grade == '7')
        strcpy(remark, "Fail");
    
    printf("Name of the student: %s\n", name);
    printf("Average marks of the student: %.2f\n", average);
    printf("Grade of the student: %c\n", grade);
    printf("Remark of the student: %s\n", remark);
    
    return 0;
}
