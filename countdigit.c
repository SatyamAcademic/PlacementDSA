// Program: Count digits of a number using recursion

#include <stdio.h>

// Function to count number of digits using recursion
int countDigits(int num)
{
    // Base case:
    // If number becomes 0, stop recursion
    if (num == 0)
    {
        return 0;
    }

    // Recursive case:
    // Remove last digit (num / 10) and add 1 to count
    return 1 + countDigits(num / 10);
}

int main()
{
    int n;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Edge case handling:
    // If user enters 0, it has 1 digit
    if (n == 0)
    {
        printf("Number of digits: 1\n");
    }
    else
    {
        // Convert negative number to positive
        if (n < 0)
        {
            n = -n;
        }

        // Function call and output
        printf("Number of digits: %d\n", countDigits(n));
    }

    return 0;
}