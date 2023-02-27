#include <stdio.h>

int main() {
    float length, width, perimeter, area;

    do {
        printf("Enter length of rectangle (non-negative): ");
        scanf("%f", &length);

        printf("Enter width of rectangle (non-negative): ");
        scanf("%f", &width);
    } while (length < 0 || width < 0);

    perimeter = 2 * (length + width);
    area = length * width;

    printf("Perimeter of rectangle: %.2f\n", perimeter);
    printf("Area of rectangle: %.2f\n", area);

    return 0;
}
