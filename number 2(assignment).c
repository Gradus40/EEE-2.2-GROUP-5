#include <stdio.h>
//a program that prints the alphabet in lowercase, and then in uppercase, followed by a new line//
int main()
{
   char c;
   for (c = 'a'; c <= 'z'; c++) {
    putchar(c);
  }
   for (c = 'A'; c <= 'Z'; c++) {
    putchar(c);
  }
   putchar('\n');
   return 0;
}
