#include <stdio.h>

int main() {
    char name[50];
    float english, math, science, average;

    printf("Enter student name: ");
    fgets(name, 50, stdin);

    printf("Enter English marks: ");
    scanf("%f", &english);

    printf("Enter Mathematics marks: ");
    scanf("%f", &math);

    printf("Enter Science marks: ");
    scanf("%f", &science);

    average = (english + math + science) / 3.0;

    printf("Name: %s", name);
    printf("Average mark: %.2f\n", average);

    return 0;
}

