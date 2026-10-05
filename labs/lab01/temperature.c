#include <stdio.h>

int main(){
    float lower, upper, step;
    do {
        printf("Enter valid lower, upper, step: ");
        scanf("%f %f %f", &lower, &upper, &step);
    }while(step <= 0 || lower > upper);

    printf("Fahrenheit\tCelsius\n");
    for (float fahr = lower; fahr <= upper; fahr += step) {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%-10.0f\t%-7.1f\n", fahr, celsius);
    }
    return 0;
}