
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM_TOPPINGS 5
#define NUM_BASES 4
#define MAX_NAME 100
#define MAX_PHONE 20
char *BASES[NUM_BASES] = {"Thin", "Deep Pan", "Stuffed", "Whole Wheat"};
char *TOPPINGS[NUM_TOPPINGS] = {"Onions", "Tomatoes", "Pepperoni", "Cheese", "Olives"};
int base_prices[NUM_BASES] = {350, 400, 300, 500};
int topping_prices[NUM_TOPPINGS] = {30, 30, 50, 20, 30};

typedef struct pizza
{
    int base;
    int topping[NUM_TOPPINGS];
} pizza;
typedef struct order
{
    int order_id;
    char *customer_name;
    char *customer_phone;
    struct pizza *p;
    int price;
} order;

order *new_order(int order_id, char *customer_name, char *customer_phone, pizza *pizza, int price)
{
    order *o = NULL;
    // Allocate memory for the new order
    o = (order *)malloc(sizeof(order));
    o->order_id = order_id;
    o->customer_name = customer_name;
    o->customer_phone = customer_phone;
    o->p = pizza;
    o->price = price;
    // Set its datamembers as per the parameters to this function
    return o;

}
void print_pizza(pizza *p)
{
    printf("The pizza you ordered is as follows:\n");
    printf("Base: %s\n", BASES[p->base]);
    printf("Toppings:\n");
    for (int i = 0; i < NUM_TOPPINGS; i++)
    {
        if (p->topping[i] == 1)
        {
            printf("%s\n", TOPPINGS[i]);
        }
    }


}

void print_order(order *o)
{
    printf("Order placed successfully. Order details are as follows:\n");
    printf("Order ID: %d\n", o->order_id);
    printf("Customer Name: %s\n", o->customer_name);
    printf("Customer Phone: %s\n", o->customer_phone);
    print_pizza(o->p);
    printf("Total Price: %d\n", o->price);
    
}
void destroy_pizza(pizza *p)
{
    // Free the pizza
    free(p);
    p = NULL;
}
void complete_order(order *o)
{
    // destroy the pizza
    destroy_pizza(o->p);
    printf("Order %d completed successfully.\n", o->order_id);
    free(o);
    o = NULL;
}
pizza *new_pizza(int base, int toppings[])
{
    pizza *p = NULL;
    // Allocate memory for the new pizza
    p = (pizza *)malloc(sizeof(pizza));
    p->base=base;
    for (int i = 0; i < NUM_TOPPINGS;i++)
        p->topping[i] = toppings[i];

    // Set its datamembers as per the parameters to this function
    return p;
}

int calculate_price(pizza *p)
{
    int total_price = 0;
    total_price += base_prices[p->base];
    for (int i = 0; i < NUM_TOPPINGS; i++)
    {
        if (p->topping[i] == 1)
        {
            total_price += topping_prices[i];
        }
    }

        return total_price;
}

// The main() has been provided. You do not need to modify it
int main()
{
    // Create a new pizza
    int toppings[NUM_TOPPINGS];
    // User input
    int base = -1;
    while (base < 0 || base >= NUM_BASES)
    {
        printf("The available bases are:\n");
        for (int i = 0; i < NUM_BASES; i++)
        {
            printf("%d. %s\n", i, BASES[i]);
        }
        printf("Enter the base number: ");
        scanf("%d", &base);
    }
    printf("Please enter the toppings. Enter 1 if the topping is present, 0 otherwise.\n");
    for (int i = 0; i < NUM_TOPPINGS; i++)
    {
        printf("Do you want %s? (1 for yes, 0 for no)", TOPPINGS[i]);
        scanf("%d", &toppings[i]);
        while (toppings[i] != 0 && toppings[i] != 1)
        {
            printf("Invalid input. Please enter 1 or 0.\n");
            i--;
            printf("Do you want %s? (1 for yes, 0 for no)", TOPPINGS[i]);
            scanf("%d", &toppings[i]);
        }
    }
    pizza *p = new_pizza(base, toppings);
    print_pizza(p);
    // Create a new order
    int order_id = 001;
    char customer_name[MAX_NAME];
    char customer_phone[MAX_PHONE];
    printf("Enter the customer name: ");
    scanf("%s", customer_name);
    printf("Enter the customer phone number: ");
    scanf("%s", customer_phone);
    order *o = new_order(order_id, customer_name, customer_phone, p, calculate_price(p));
    print_order(o);
    // Complete the order
    complete_order(o);
    return 0;
}

