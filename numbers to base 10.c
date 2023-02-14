#include <stdio.h>



//a program that prints all single digit numbers of base 10 starting from 0, followed by a newline//

  int main(void)
{
    int p; // declare an integer variable called "p"//


    for (p = 0; p < 10; p++) // use a for loop to iterate through the numbers 0 to 9//

    {
        putchar(p + '0'); // use putchar() to print the current number, converted to a character, to the console//
    }

    putchar('\n'); // use putchar() to print a newline character to the console//


    return 0; // return 0 to indicate successful program execution//
}

