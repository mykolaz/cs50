#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize height
    int height;

    // Perform the loop to ensure we get a number between 1 and 8
    do 
    {
        height = get_int("How high do you need the wall?: \n");
        if (height < 1) 
        {
            printf("Need to enter higher height than: %d\n", height);
        } 
        else if (height > 8) 
        {
            printf("Need to enter lower height than: %d\n", height);
        }
    } 
    while (height < 1 && height > 8);
    
    // Run a for loop (known value)
    for (int i = 1; i <= height; i++) 
    {

        for (int p = 0; p < (height - i); p++) 
        {
            printf(" ");
        }
    
        for (int c = 0; c < i; c++) 
        {
            printf("#");
        }
        printf("\n");
    }

}
