#include <stdio.h>
//A program that accepts a certain number of integers, calculate the average and then display the average of the numbers using a for loop
int main() {
   int count, total = 0, num;
   float avg;

   printf("Enter the number of integers: ");
   scanf("%d", &count);

   for (int i = 0; i < count; i++) {
      printf("Enter an integer: ");
      scanf("%d", &num);
      total += num;
   }

   avg = (float)total / (float)count;//Find Average
   printf("Average = %.2f", avg);

   return 0;
}
