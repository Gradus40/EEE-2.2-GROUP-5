#include <stdio.h>

int main() {
    int rows = 5; // number of rows

    for (int i = 1; i <= rows; i++) {//Loop on each column in current row
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                printf("W ");//printing w with space after w
            } else {
                printf("W");
            }
        }
        printf("\n");//Move to a new line after printing row
    }

    return 0;
}
