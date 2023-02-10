#include <stdio.h>
#include <stdlib.h>

//A program that prints the alphabet in lowercase followed by a new line.(question 1)//

int main(void)
{
  char c;
  for (c = 'a'; c <= 'z'; c++) {
    printf("%c", c);
  }
  printf("\n");
  return 0;
}

