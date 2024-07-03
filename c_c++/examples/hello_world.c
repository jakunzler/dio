#include <stdio.h>
#include <math.h>

int sum(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int a;
int b;
    

int main() {
    printf("Hello, World!\n");
    printf("This is the first C program made by Jonas Augusto Kunzler in this course.\n");

    /* ask for user input */
    printf("Enter two numbers!\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    /* print the sum */
    printf("Sum: %d\n", sum(a, b));

    /* print the subtraction */
    printf("Subtraction: %d\n", subtract(a, b));

    /* print the multiplication */
    printf("Multiplication: %d\n", multiply(a, b));

    /* print the division */
    printf("Division: %d\n", divide(a, b));

    printf("End of the program\n");

    /* wait for the user to press the ESC key */
    printf("Press 'q' key and Enter to exit\n");
    while (1) {
        int ch = getchar();
        if (ch == 113) { /* Enter key */
            break;
        }
    }
    return 0;
}

int sum(a, b) {
    return a + b;
}

int subtract(a, b) {
    return a - b;
}

int multiply(a, b) {
    return a * b;
}

int divide(a, b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}