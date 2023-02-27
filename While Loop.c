#include <stdio.h>
/*A program that accepts a certain number of integers, calculates the average, and then displays the average of the numbers using a while loop */
int main() {
    int count, total, num;
    float avg;
    printf("Enter the number of integers: ");//The number of integers is printed on screen
    scanf("%d", &count);
    total = 0;
    while (count > 0) {
       printf("Enter an integer: ");
       scanf("%d", &num);
       total += num;
       count--;
   }

       avg = (float)total / (float)count;
       printf("Average = %.2f", avg);
       return 0;
}
