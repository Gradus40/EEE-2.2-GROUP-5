#include <stdio.h>
/*a program that prints the alphabet in lowercase, printing all letters except q and e, followed by a new line.*/

int main(void)
{

    char c;

    for (c = 'a'; c <= 'z'; c++)
    {
        /* exclude q and e while printing*/
        if (c != 'q' && c != 'e')
        {
            putchar(c);
        }
    }

    putchar('\n');

    return (0);
}
