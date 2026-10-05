#include <stdio.h>
#include <math.h>

void display_menu();
void add();
void subtract();
void multiply();
void divide();
void power();

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            power();
            break;
        case 0:
            printf("Bye!");
            break;
        default:
            printf("Invalid choice. Please choose from 1-5 (0 to exit).\n");
        }

    } while (choice != 0);
    return 0;
}

void display_menu() {
    printf("====== Pocket Calculor ======\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("0. Exit\n");
}

void add(){
    double x, y;
    printf("++++++++++++++++++++++++++\n");
    printf("Enter x, y: ");
    scanf("%lf %lf", &x, &y);

    printf("x + y = %.5lf\n", x+y);
}

void subtract(){
    double x, y;
    printf("----------------------\n");
    printf("Enter x, y: ");
    scanf("%lf %lf", &x, &y);

    printf("x - y = %.5lf\n", x-y);
}

void multiply(){
    double x, y;
    printf("************************\n");
    printf("Enter x, y: ");
    scanf("%lf %lf", &x, &y);

    printf("x * y = %.5lf\n", x*y);
}

void divide(){
    double x, y;
    printf("========================\n");
    printf("Enter x, y (y not equal 0): ");
    scanf("%lf %lf", &x, &y);
    if (y == 0){
        printf("Divided by 0, invalid\n");
        return;
    }
    printf("x / y = %.5lf\n", x/y);
}

void power(){
    double x, y;
    printf("========================\n");
    printf("Enter x, y: ");
    scanf("%lf %lf", &x, &y);
    if (x == 0 && y <= 0){
        printf("Divided by 0/Indeterminate, invalid\n");
        return;
    }
    printf("x^y = %.5lf\n", pow(x, y));
}