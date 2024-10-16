#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define espresso_beans 8
#define espresso_water 30
#define espresso_milk 0
#define espresso_chocolate 0
float espresso_price = 3.5;

#define cappuccino_beans 8
#define cappuccino_water 30
#define cappuccino_milk 70
#define cappuccino_chocolate 0
float cappuccino_price = 4.5;

#define mocha_beans 8
#define mocha_water 39
#define mocha_milk 160
#define mocha_chocolate 30
float mocha_price = 5.5; 

#define admin_password "admin123"

void display_menu();
void order_coffee();
void admin_mode();
void show_ingredients();
void restock_ingredients();
void update_price();

int beans = 300, water = 800, milk = 300, chocolate = 200;
float total_amount = 0.0;

int main() {
    srand(time(NULL));
    int option;
    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                order_coffee();
                break;
            case 2:
                admin_mode();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("1. Order Coffee\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
}

void order_coffee() {
    int choice;
    float payment;

    while (1) {
        printf("Coffee options:\n");
        printf("1. Espresso - AED %.2f\n", espresso_price);
        printf("2. Cappuccino - AED %.2f\n", cappuccino_price);
        printf("3. Mocha - AED %.2f\n", mocha_price);
        printf("0. Exit to main menu\n");
        printf("Choose your coffee: ");
        scanf("%d", &choice);

        if (choice == 0) return;

        int beans_used = 0, water_used = 0, milk_used = 0, chocolate_used = 0;
        float price = 0.0;

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
                printf("Error, please choose a valid option.\n");
                continue;
        }

        if (beans < beans_used || water < water_used || milk < milk_used || chocolate < chocolate_used) {
            printf("Unavailable due to temporarily insufficient ingredients.\n");
            continue;
        }

        printf("You selected: %s - AED %.2f. Would you like to confirm? (Y/N): ", 
            (choice == 1 ? "Espresso" : choice == 2 ? "Cappuccino" : "Mocha"), price);
        
        char confirm;
        scanf(" %c", &confirm);
        if (confirm != 'Y') continue;

        payment = 0.0;
        while (payment < price) {
            printf("Insert coin: ");
            float coin;
            scanf("%f", &coin);

            if (coin == 1.0 || coin == 0.5) {
                payment += coin;
            } else {
                printf("Please enter a valid coin.\n");
            }
        }

        beans -= beans_used;
        water -= water_used;
        milk -= milk_used;
        chocolate -= chocolate_used;
        total_amount += price;

        printf("You bought a coffee for AED %.2f. You paid AED %.2f. Change: AED %.2f\n", 
               price, payment, payment - price);
        
        if (beans <= 50 || water <= 50 || milk <= 50 || chocolate <= 10) {
            printf("Alert: Low ingredient level!\n");
        }
    }
}

void show_ingredients() {
    printf("Current ingredients:\n");
    printf("Beans: %d grams\n", beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Chocolate: %d ml\n", chocolate);
    printf("Total sales: AED %.2f\n", total_amount);
}

void restock_ingredients() {
    beans = rand() % 100 + 100;
    water = rand() % 500 + 300;
    milk = rand() % 200 + 100;
    chocolate = rand() % 50 + 10;
    printf("Ingredients replenished:\n");
    printf("Beans: %d grams\n", beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Chocolate: %d ml\n", chocolate);
}

void update_price() {
    int coffee_choice;
    float new_price;
    printf("Select coffee type to change price:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Mocha\n");

    scanf("%d", &coffee_choice);
    
    printf("Enter new price: ");
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
            printf("Error: Invalid coffee choice.\n");
            return;
    }
    printf("Updated successfully.\n");
}

void admin_mode() {
    char password[8];  
    printf("Please input the admin password: ");
    scanf("%s", password);
    
    if (strcmp(password, admin_password) == 0) {
        printf("Welcome, admin.\n");
    } else {
        printf("Incorrect password.\n");
        return;
    }

    int user_selection;
    while (1) {
        printf("Admin Control Panel:\n");
        printf("1: Display the quantity of each ingredient in the machine and the total sale amount\n");
        printf("2: Replenish ingredients in the machine\n");
        printf("3: Change coffee price\n");
        printf("0: Exit\n");
        printf("Choose an option: ");
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
                printf("error, please choose a valid option.\n");
        }
    }
}
