#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    
    // Initialize variables
    int change = 0;
    int coins = 0;
    int coin_remainder = 1;
    int coin_25 = 0;
    int coin_10 = 0;
    int coin_5 = 0;
    int coin_1 = 0;

    do 
    {
        change = get_int("What is the change: ");
    } 
    while (change < 0);

    printf("Change is: %d\n", change);
    
    while (change > 0) 
    {
        if (change >= 25) 
        {
            printf("Remaining change is more than 25c\n");

            coin_remainder = change % 25;
            printf("25c Remainder %d\n", coin_remainder);

            coin_25 = (change - coin_remainder) / 25;
            printf("25c coins used: %d\n", coin_25);

            coins = coins + coin_25;
            printf("Total coins: %d\n", coins);

            change = change - coin_25 * 25;
        } 
        else if (change < 25 && change >= 10) 
        {
            coin_remainder = change % 10;
            printf("10c Remainder %d\n", coin_remainder);

            coin_10 = (change - coin_remainder) / 10;
            printf("10c coins used: %d\n", coin_10);

            coins = coins + coin_10;
            printf("Total coins: %d\n", coins);

            change = change - coin_10 * 10;
            printf("Remaining Change: %d\n", change);
        } 
        else if (change < 10 && change >= 5) 
        {
            coin_remainder = change % 5;
            coin_5 = (change - coin_remainder) / 5;
            coins = coins + coin_5;
            change = change - coin_5 * 5;
        } 
        else 
        {
            coin_remainder = change % 1;
            coin_1 = (change - coin_remainder) / 1;
            coins = coins + coin_1;
            change = coins - coin_1 * 1;
        }    
    }
    printf("%d Coins change!\n", coins);
}
