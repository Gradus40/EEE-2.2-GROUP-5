#include <stdio.h>
//A program that prints all numbers of base 16 in lowercase followed by a new line//

int main(void)
{
    for(int p = '0' ;p<='9' ;p++)
        putchar(p);
    for(int p = 'a';p<='f';p++)
    putchar(p);
    putchar('\n');

    return 0;
}
