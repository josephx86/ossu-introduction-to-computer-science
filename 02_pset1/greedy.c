/**
* Joseph Unworried
* Problem Set 1: Greedy change dispenser
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get amount of change owed from user
    float change = -1;
    printf("O hai! ");
    do
    {
        printf("How much change is owed? ");
        change = GetFloat();
    } while (change < 0);
    
    // Calculate the minimum number of coins using integer division
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    const int QUARTER = 25, DIME = 10, NICKEL = 5;
    int cents = (int) round(change * 100);
    while (cents > 0)
    {
        if (cents >= QUARTER)
        {
            quarters = cents / QUARTER; 
            cents -= quarters * QUARTER;
        }
        else if (cents >= DIME)
        {
            dimes = cents / DIME;
            cents -= dimes * DIME;
        }
        else if (cents >= NICKEL)
        {
            nickels = cents / NICKEL;
            cents -= nickels * NICKEL;
        }
        else
        {
            pennies = cents;
            cents = 0;
        }
    }
    
    int coinCount = quarters + dimes + nickels + pennies;
    printf("%d\n", coinCount);
}
