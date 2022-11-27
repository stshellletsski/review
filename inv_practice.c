#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    string name;
    float price;
}
item;

// Use with command line arguments following pattern: name price name price... 
int main(int argc, string argv[])
{
    // Define n-element array food of item type where n = argc/2 rounded down
    item food[(argc - 1) / 2];
    int n = 1;
    // Loops through every second argument argv and assign argv[n], argv[n+1] to n/2 element of food, rounded down
    while (n < argc)
    {
        food[(n - 1) / 2].name = argv[n];
        food[(n - 1) / 2].price = atof(argv[n + 1]);
        n += 2;
    }
    for (int i = 0; i < (argc - 1) / 2; i++)
    {
        printf("food: %s\nprice: %.2f\n", food[i].name, food[i].price);
        printf("\n");
    }
}
