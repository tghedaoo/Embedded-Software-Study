// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
// Solution: https://leetcode.com/problems/valid-parentheses/solutions/173832/valid-parentheses/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// SOLUTION: Use a STACK. O(n) time and O(n) space
bool isValid(char * s)
{
    int size = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        size++;
        i++;
    }

    char* stack = (char*)malloc(sizeof(char) * size);
    int stack_pos = 0;
    
    i = 0; // This is not a good way of doing it. Consider a different variable for iterator.
    while (s[i] != '\0')
    {
        char current_s = s[i];
        if(current_s == '(' || current_s == '{' || current_s == '[')
        {
            stack[stack_pos] = s[i];
            stack_pos++;
        }
        else
        {
            char current_stack_char = stack[stack_pos-1];
            if((current_stack_char == '(' && current_s == ')') || (current_stack_char == '{' && current_s == '}') || (current_stack_char == '[' && current_s == ']'))
            {
                stack_pos--;
            }
            else
            {
                return false;
            }
        }
        i++;
    }

    free(stack);
    return (stack_pos != 0) ? false:true;
}

void print(bool input)
{
    if(input)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}

int main()
{
    print(isValid("(]"));
    return 0;
}