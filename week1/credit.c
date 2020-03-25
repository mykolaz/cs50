#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // Initialize some variables
    long cc_number = 0;
    int odd_sum = 0;
    int even_sum = 0;
    int cc_length = 0;
    char cc_type[12]; // Max is MASTERCARD < 10;
    int cc_remainder = 0;
    bool valid = false; // Guilty until proven innocent

    // Grab the credit card number
    cc_number = get_long("Please enter a credit card number: ");

    // Determine the length of cc_number
    cc_length = floor(log10(labs(cc_number))) + 1;
    
    // Initialize some variables post grab of cc
    // get the divisor neede to get the remainder
    long divisor = pow(10,cc_length - 1); 
    // Initialize array with length of cc number
    int cc_num[cc_length];

    // Allocate cc to an array for validation
    // reverse numbers right away for easier processing
    for(int i = cc_length - 1; i >= 0; i--) {
       
        // Grab the next num
        cc_remainder = cc_number / divisor;

        // Allocate remainder to the array
        cc_num[i] = cc_remainder;

        // Deprecate the cc number by remainder * divisor
        cc_number = cc_number - divisor*cc_remainder;

        // Reduce the divisor by factor of 10
        divisor /= 10;

    }

    // Validate the correctness of the credit card
    // Split every other number and add them together
    for (int i = 0; i < cc_length; i++) {
                
        if (i % 2 != 0)
        {
            // Perform addition to odd numbers
            printf("Odd Number: %d\n", cc_num[i]);
            int product_sum = cc_num[i] * 2;

            if (product_sum >= 10)
            {
                int product_remainder = product_sum % 10;
                printf("Product remainder: %d\n", product_remainder);
                printf("Adding to sum: %d\n", product_remainder + product_sum/10);
                odd_sum += product_remainder + product_sum / 10;

            } else 
            {
                odd_sum += cc_num[i] * 2;
            }
                
        } else 
        {
            printf("Even Number: %d\n", cc_num[i]);
            even_sum += cc_num[i];
        }
    }
    printf("\n");
    printf("Even Sum: %d\n", even_sum);
    printf("Odd Sum: %d\n", odd_sum);
    int total_sum = even_sum + odd_sum;
    printf("Remainder: %d", total_sum % 10);

    if ((even_sum + odd_sum) % 10 == 0) {
        
        valid = true;
    }


    // Begin checks
    // Amex = 15 && Starts with 34 or 37
    // Master Card = 16 && Starts with 51, 52, 53, 54, 55
    // VISA = 13 or 16 && starts with 4

    if (cc_length == 15) 
    {
        if (cc_num[cc_length-1] == 3) 
        {
            if (cc_num[cc_length-2] == 4 | cc_num[cc_length-2] ==7) 
            {
                strcpy(cc_type,"AMEX\n");
            } else 
            {
                strcpy(cc_type,"INVALID\n");
                valid = false;
            }
        } else 
        {
            strcpy(cc_type,"INVALID\n");
            valid = false;
        }
    } else if (cc_length == 13) 
    {
        if (cc_num[cc_length-1] == 4)
        {
            strcpy(cc_type,"VISA\n");
        } else 
        {
            strcpy(cc_type,"INVALID\n");
            valid = false;
        }
        
    } else if (cc_length == 16) 
    {
        if (cc_num[cc_length-1] == 4) 
        {
            strcpy(cc_type,"VISA\n");
        } else if (cc_num[cc_length-1] == 5) 
        {
            // Identify Master Card 
            if (cc_num[cc_length-2] >= 1 && cc_num[cc_length-2] <= 5)
            {
                strcpy(cc_type,"MASTERCARD\n");
            } else
            {
                strcpy(cc_type,"INVALID\n");
                valid = false;
            }
        } else 
        {
            strcpy(cc_type,"INVALID\n");
            valid = false;
        }
    } else 
    {
        strcpy(cc_type,"INVALID\n");
        valid = false;
    }

    
    if (valid == true) 
    {   
        printf("VALID\n");
        printf("Credit Card: %s", cc_type);
    } else 
    {
        printf("INVALID\n");
    }

}
