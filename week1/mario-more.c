#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // initialize height
    int height = 0;

    do 
    {
        height = get_int("Specify height: ");
    } 
    while (height < 1 | height > 8);

    for (int i = 1; i <= height; i++) {

        // Print the first grouping of spaces
        for (int p = 0; p < (height - i); p++) 
        {
            printf(" ");
        }

        // Print the first grouping of #s
        for (int n = 0; n < i; n++) {
            printf("#");
        }

        // Print the separator
        printf(" ");

        // Print the second grouping of #s
        for (int n2 = 0; n2 < i; n2++) {
            printf("#");
        }

        // Finish the second pyramid
        for (int p2 = 0; p2 < (height - i); p2++) 
        {
            printf(" ");
        }
        printf("\n");
    }

}
