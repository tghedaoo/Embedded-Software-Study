// Leetcode: String to Integer (atoi)
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2010/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

// My Solution
int myAtoi(char *s)
{
    bool negative = false;
    bool start_int_read = false;

    char *digits = (char *)malloc(sizeof(char) * 200); // as per question, max chars expected 200.

    // Part 1 parse out number.
    int pos = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!start_int_read)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '-')
            {
                negative = true;
                start_int_read = true;
            }
            else if (s[i] == '+')
            {
                negative = false;
                start_int_read = true;
            }
            else if (isdigit(s[i]))
            {
                digits[pos++] = s[i];
                start_int_read = true;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (!isdigit(s[i]))
            {
                break;
            }
            else
            {
                digits[pos++] = s[i];
            }
        }
    }
    digits[pos] = '\0';
    // Also check if there are no digits.
    if (pos == 0)
    {
        return 0;
    }

    // Get the integer.
    int output = 0;
    for (int i = 0; i < pos; i++)
    {
        // Important: [ASCII conversion] as its stored in char.
        int digit = digits[i] - '0'; 
        // Important: check for the overflow and underflow on the fly during calculation to avoid runtime errors.
        if ((output > INT_MAX / 10) || (output == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            return (negative) ? INT_MIN : INT_MAX;
        }
        output = 10 * output + digit;
    }

    // Free the malloced digits string.
    free(digits);
    return (negative) ? (-1 * output) : output;
}

// Leetcode Solution:
int myAtoi_leetcode(char* input) // C++ code: this is string input
{
    int sign = 1;
    int result = 0;
    int index = 0;
    // int n = input.size(); // C++ code: C needs to calculate this.
    int n = 10; // Just for compiling sake.

    // Discard all spaces from the beginning of the input string.
    while (index < n && input[index] == ' ')
    {
        index++;
    }

    // sign = +1, if it's positive number, otherwise sign = -1.
    if (index < n && input[index] == '+')
    {
        sign = 1;
        index++;
    }
    else if (index < n && input[index] == '-')
    {
        sign = -1;
        index++;
    }

    // Traverse next digits of input and stop if it is not a digit.
    // End of string is also non-digit character.
    while (index < n && isdigit(input[index])) 
    {
        int digit = input[index] - '0';

        // Check overflow and underflow conditions.
        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Append current digit to the result.
        result = 10 * result + digit;
        index++;
    }

    // We have formed a valid number without any overflow/underflow.
    // Return it after multiplying it with its sign.
    return sign * result;
}

int main()
{
    // printf("Testing with - '4193 with words'\n");
    // printf("%d\n", (int)myAtoi("4193 with words"));
    printf("Enter test string > ");
    char *input = (char *)malloc(sizeof(char) * 200);
    scanf("%s", input);
    printf("%d\n", (int)myAtoi(input));
    return 0;
}