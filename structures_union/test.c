// Structure Size Analysis.
#include <stdio.h>
#include <stdint.h>

// Check this to see results between padding and packing.
// #pragma pack(1)
// Ran on Mac M1 Pro chip - 256bit address bus.

int main()
{
    struct a1
    {
        short s;
        char c;
    };
    struct a1 struct1;
    printf("%lu\n", sizeof(struct1));

    struct a2
    {
        uint16_t a;
        uint32_t b;
        uint16_t c;
        uint16_t d;
    };
    struct a2 struct2; 
    printf("%lu\n", sizeof(struct2));
    printf ( "Address of a       = %u\n", &struct2.a); // this gets 4 bytes (2 bytes of paddding)
    printf ( "Address of b       = %u\n", &struct2.b);
    printf ( "Address of c       = %u\n", &struct2.c);
    printf ( "Address of d       = %u\n", &struct2.d);

    return 0;
}
