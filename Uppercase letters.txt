#include <stdio.h>

int main() {
    char ch;

    printf("Enter a lowercase character: ");
    scanf("%c", &ch);

    // Check if the character is a lowercase letter
    if (ch >= 'a' && ch <= 'z') {
        // Convert the lowercase letter to uppercase
        ch = ch - 32;
        printf("The uppercase equivalent is: %c\n", ch);
    }
    else {
        printf("Invalid input. Please enter a lowercase letter.\n");
    }

    return 0;
}
