// Structure Size Analysis.
#include <stdio.h>
#include <stdint.h>

// Check this to see results between padding and packing.
// #pragma pack(1)
// Ran on Mac M1 Pro chip - 256bit address bus.
// Compiler is 32 bit.

int main()
{
    struct a1
    {
        short s;
        char c;
    };
    struct a1 struct1;
    printf("%lu\n", sizeof(struct1)); // 4(padding), 3(packing)

    struct a2
    {
        uint16_t a; // this gets 4 bytes (2 bytes of paddding)
        uint32_t b;
        uint16_t c;
        uint16_t d;
    };
    struct a2 struct2;
    printf("%lu\n", sizeof(struct2)); // 12(padding), 10(packing)
    // printf ( "Address of a       = %u\n", &struct2.a);
    // printf ( "Address of b       = %u\n", &struct2.b);
    // printf ( "Address of c       = %u\n", &struct2.c);
    // printf ( "Address of d       = %u\n", &struct2.d);

    struct a3
    {
        short a;   // 2 bytes
        char b;    // 1 byte
        int c : 1; // 1 bit
        int d : 4; // 4 bit
        // 3 bits padded. -> 1 byte complete formed.
        // so here, 32 bits / 4 bytes accessed per CPU cyle.
        int e : 7; // 7 bit
        // this is the next CPU cycle. This picks up 32 bits.
        // since we want a good memory access in next cycle, 25 bits a padded.
    };
    struct a3 struct3;
    printf("%lu\n", sizeof(struct3));
    printf("Address of a       = %u\n", &struct3.a);
    printf("Address of b       = %u\n", &struct3.b);
    // It's not possible to access bit-fields through &.
    // printf ( "Address of c       = %u\n", &struct3.c);
    // printf ( "Address of d       = %u\n", &struct3.d);
    // printf ( "Address of e       = %u\n", &struct3.e);

    struct a4
    {
        int a : 8;
        int b : 10;
        int c : 12;
        int d : 4;
        int e : 3;
        //   int f:18;   //sizeof struct becomes 12 because 4+3+18 - 25 bits. 1 CPU access only for this. And the other for char.
        int f : 17; // sizeof struct becomes 8, because 4+3+17 - 24 bits exact and 1 byte for char. 1 CPU access does it all.
        char g;
    };
    struct a4 struct4;
    printf("%lu\n", sizeof(struct4));
    printf("Address of a       = %u\n", &struct4.g);

    // 32 bit addressable. but still padding.
    // Therefore, padding happens as per the widest member.
    struct a5
    {
        uint32_t a; // 4 bytes padding
        uint64_t b;
        uint32_t c;
        uint32_t d;
    };
    struct a5 struct5;
    printf("%lu\n", sizeof(struct5)); // 24(padding), 20(packing)
    printf ( "Address of a       = %u\n", &struct5.a);
    printf ( "Address of b       = %u\n", &struct5.b);
    printf ( "Address of c       = %u\n", &struct5.c);
    printf ( "Address of d       = %u\n", &struct5.d);

    return 0;
}
