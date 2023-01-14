#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b)
{
    int alen = strlen(a);
    int blen = strlen(b);

    int reslen = (alen > blen) ? alen : blen;
    // To have a first byte as carry and the last byte as ender.
    reslen+=2; 
    char *res = (char*)malloc(sizeof(char) * reslen);
    // Note : 
    // Leetcode fails without this ender. It throws seg fault.
    // This might not be the case in C++.
    res[reslen-1] = '\0'; 
    
    int carry = 0;

    int a_iter = alen-1;
    int b_iter = blen-1;
    int res_iter = reslen-2;

    while (a_iter >= 0 || b_iter >= 0)
    {
        int val_a = (a_iter >= 0) ? (a[a_iter] - '0') : 0;
        int val_b = (b_iter >= 0) ? (b[b_iter] - '0') : 0;
        
        int sum = (val_a ^ val_b ^ carry);
        carry = (val_a & val_b) | (val_a & carry) | (carry & val_b);

        res[res_iter] = sum + '0';
        
        b_iter--;
        a_iter--;
        res_iter--;
    }    
    res[0] = carry + '0';
    return (carry) ? res : res+1;
}

int main()
{
    printf("%s\n", addBinary("11","1"));
    printf("%s\n", addBinary("1010","1011"));
    printf("%s\n", addBinary("0","0"));

    return 0;
}