# ENDIANESS
[Source](https://www.geeksforgeeks.org/little-and-big-endian-mystery/)

This how the bytes are ordered in memory. <br />
Very important especially when dealing with sockets. <br />
Crux of it - Check the starting address.
* BIG - Most Significant BYTE (MSB)
* LITTLE - Less Significant BYTE (LSB)

```
// Consider a 4 byte integer.
int32_t a = 0xABCDEFGH;

// Big Endian
start address -> AB CD EF GH

// Little Endian
start address -> GH EF CD AB
```
[Code to check for endianess](endianess.c)

Considerations:
* Machines mostly little endian. Helps expansion typecasting.
* Network Byte Order (Socket Comms) is big endian.
* Typecasting scenarios where the size of datatype changes.
