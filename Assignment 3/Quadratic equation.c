#include <stdio.h>
#include <math.h>
// a C program that reads a,b and c in a quadratic equation , determines the roots, displays a,b and c as well as the roots//
int main() {
    double a, b, c, discriminant, root1, root2;

    printf("Enter the values of a, b, and c in the quadratic equation (ax^2 + bx + c = 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate the discriminant
    discriminant = b*b - 4*a*c;

    // Check if the roots are real or complex
    if (discriminant >= 0) {
        // Calculate the roots
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);

        printf("a = %lf, b = %lf, c = %lf\n", a, b, c);
        printf("Root 1 = %lf\n", root1);
        printf("Root 2 = %lf\n", root2);
    }
    else {
        // Calculate the real and imaginary parts of the complex roots
        double realPart = -b / (2*a);
        double imaginaryPart = sqrt(-discriminant) / (2*a);

        printf("a = %lf, b = %lf, c = %lf\n", a, b, c);
        printf("Root 1 = %lf + %lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %lf - %lfi\n", realPart, imaginaryPart);
    }

    return 0;
}
