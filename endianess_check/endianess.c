#include <stdio.h>

int main()
{
    // Check for system's endianess.
    int i = 1; // 4 bytes mostly. If 0x01 (LSB) is at the lowest address, its little endian. 
    char* x = (char*)&i;
    if(*x)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian\n");
        // network byte order. Before transferring data on network, data is first converted to network byte order (big endian).
    }  

    // Char array to int and vice versa

    return 0;
}