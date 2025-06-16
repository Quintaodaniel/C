// Temperature Converter
// ---------------------
// Goal: Convert temperatures between Celsius, Fahrenheit, and Kelvin.
// Trains: function usage, float calculations, switch-case, and basic user input validation.

#include <stdio.h>

void fromCelsius(float temp) {
    printf("In Fahrenheit: %.2f\n", (temp * 9.0/5.0) + 32);
    printf("In Kelvin: %.2f\n", temp + 273.15);
}

void fromFahrenheit(float temp) {
    printf("In Celsius: %.2f\n", (temp - 32) * 5.0/9.0);
    printf("In Kelvin: %.2f\n", ((temp - 32) * 5.0/9.0) + 273.15);
}

void fromKelvin(float temp) {
    printf("In Celsius: %.2f\n", temp - 273.15);
    printf("In Fahrenheit: %.2f\n", (temp - 273.15) * 9.0/5.0 + 32);
}

int main() {
    float temperature;
    int choice;

    printf("Select the temperature unit:\n");
    printf("[1] Celsius\n[2] Fahrenheit\n[3] Kelvin\n\n");
    printf("Choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter the temperature: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\n");

    switch (choice) {
        case 1:
            fromCelsius(temperature);
            break;
        case 2:
            fromFahrenheit(temperature);
            break;
        case 3:
            fromKelvin(temperature);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
