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
    int option;
    while (1) {
        display_menu();
        printf("choose an option: ");
        scanf("%d", &option);
        option(option);
    }
    return 0;
}

int beans = 300, water = 800, milk = 300, chocolate = 200;
float total_amount = 0.0;

void ordercoffee(){

    int choice;
        while (1) {
            printf("Coffee options:\n");
            printf("1. espresso - AED %.2f\n", espresso_price);
            printf("2. cappuccino - AED %.2f\n", cappuccino_price);
            printf("3. mocha - AED %.2f\n", mocha_price);
            printf("choose your coffee: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                beans_used = espresso_beans;
                water_used = espresso_water;
                price = espresso_price;

                break;

            case 2:
                beans_used = cappuccino_beans;
                water_used = cappuccino_water;
                milk_used = cappuccino_milk;
                price = cappuccino_price;

                break;

            case 3:
                beans_used = mocha_beans;
                water_used = mocha_water;
                milk_used = mocha_milk;
                chocolate_used = mocha_chocolate;
                price = mocha_price;

                break;

            default:
                printf("error, please choose a valid option ");
                continue;
            }

            if (beans < beans_used || water < water_used || milk < milk_used || chocolate < chocolate_used) {
                printf("unavailable due to temporarily insufficient ingredients.\n");
                continue;
            }

            printf("You selected: %s - AED %.2f. would you like to confirm? (Y/N): " choice, price);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm != 'Y')
            continue;

            while (payment < price) {
            printf("insert coin: ");
            float coin;
            scanf("%f", &coin);

            if (coin == 1.0 || coin == 0.5) {
                payment += coin;
            } 

            else {
                printf("please enter a valid coin\n");
            }

            beans -= beans_used;
            water -= water_used;
            milk -= milk_used;
            chocolate -= chocolate_used;
            
            printf("You bought a coffee for AED %.2f. You paid AED %.2f. Change: AED %.2f\n", price, payment, payment - price);
}


void show_ingredients() {
    printf("current ingredients:\n");
    printf("beans: %d grams\n", beans);
    printf("water: %d ml\n", water);
    printf("milk: %d ml\n", milk);
    printf("chocolate: %d ml\n", chocolate);
    printf("total sales: aed %.2f\n", total_amount);
}

void restock_ingredients() {
    beans = rand() % 100 + 50;
    water = rand() % 100 + 50;
    milk = rand() % 200 + 50;
    chocolate = rand() % 50 + 10;
    printf("ingredients replenished.\n");
}

void update_price() {
    int coffee_choice;
    float new_price;
    printf("select coffee type to change price:\n");
    printf("1. espresso\n");
    printf("1. cappuccino\n");
    printf("1. mocha\n");

    scanf("%d", &coffee_choice);
    
    printf("enter new price: ");
    scanf("%f", &new_price);
    
    switch (coffee_choice) {
        case 1:
            espresso_price = new_price;
            break;
        case 2:
            cappuccino_price = new_price;
            break;
        case 3:
            mocha_price = new_price;
            break;
        default:
            printf("error\n");
            return;
    }
    printf("updated successfully.\n");
}

void admin() {
    char password[8];
    printf("please input the admin password: ");
    scanf("%s", password);
    
    if (strcmp(password, admin_password) == 0) {
        printf("welcome admin\n");
    } else {
        printf("incorrect password.\n");
    }

    int user_selection;
    while (1) {
        printf("admin Control Panel:\n");
        printf("1: Display the quantity of each ingredient in the machine and the total sale amount\n");
        printf("2: Replenish ingredients in the machine\n");
        printf("3: Change coffee price\n");
        printf("0. exit\n");
        printf("choose an option: ");
        scanf("%d", &user_selection);
        
        switch (user_selection) {
            case 1:
                show_ingredients();
                break;
            case 2:
                restock_ingredients();
                break;
            case 3:
                update_price();
                break;
            case 0:
                return;
            default:
                printf("error, please choose a valid option\n");
        }
    }
}
