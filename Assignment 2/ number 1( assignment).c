#include <stdio.h>
//a program that prints the alphabet in lowercase, followed by a new line(Question 1)//

int main()
{
  char c;
  for (c = 'a'; c <= 'z'; c++) {
    printf("%c", c);
  }
  printf("\n");
  return 0;
}
