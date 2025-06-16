// Simple Calculator
// -----------------
// Goal: Build a basic calculator that performs addition, subtraction, multiplication and division.
// Trains: float input/output, scanf with multiple values, switch-case, basic error handling.

#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("\nEnter two real numbers and the desired operation:\n(Example: 2.5 + 8.2)\n\n");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+':
            printf("Sum: %f\n", a + b);
            break;
        case '-':
            printf("Subtraction: %f\n", a - b);
            break;
        case '*':
        case '.':
            printf("Multiplication: %f\n", a * b);
            break;
        case '/':
        case ':':
            if (b == 0)
                printf("ERROR! Division by zero.\n");
            else
                printf("Division: %f\n", a / b);
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}
