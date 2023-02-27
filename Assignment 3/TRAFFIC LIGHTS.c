#include <stdio.h>

int main()

(

char color;

printf("Enter a character representing the color of traffic light: ");

scanf("%c", &color):

switch(color)
{

case 'R': printf("Stop\n");

break;

case 'Y': printf("Get ready\n");

break;

case 'G': printf("Move\n");

break;

default: printf("Invalid Entry\n");

}

return 0;
