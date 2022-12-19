#include <stdio.h>
#include <limits.h>

int foo(unsigned char x);

int main()
{
    printf("%d\n", INT_MAX);
    printf("%d\n", CHAR_MAX);
    printf("%d\n", foo(CHAR_MAX));
    return 0;
}

int foo(unsigned char x)
{
    int value = 2147483600;
    value += x; // overflow behaviour undefined in C ?
    if(value < 2147483600) // if compiler optimization happens here, it will never get evaluated.
        printf("blah\n");
    return value;
}