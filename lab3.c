#include <stdio.h>

#define espresso_beans 8
#define espresso_water 30
#define espresso_milk 0
#define espresso_chocolate 0
#define espresso_price 3.5

#define cappuccino_beans 8
#define cappuccino_water 30
#define cappuccino_milk 70
#define cappuccino_chocolate 0
#define cappuccino_price 4.5

#define mocha_beans 8
#define mocha_water 39
#define mocha_milk 160
#define mocha_chocolate 30
#define mocha_price 5.5 

#define admin_password "admin123"

void display_menu() {
    printf("1. order coffee\n");
    printf("2. admin mode\n");
    printf("3. exit\n");
}

void choice(int) {
    switch (choice) {
        case 1:
            order_coffee();
            break;
        case 2:
            admin_mode();
            break;
        case 3:
            exit(0);
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("choose an option: ");
        scanf("%d", &choice);
        choice(choice);
    }
    return 0;
}