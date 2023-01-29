# PERIPHERALS

## SPI
[SPI Concept](https://drive.google.com/file/d/1z0A16wexfO6Rfo72raM7ty6bA3RYJgjL/view?usp=share_link) <br />
[SPI speed and clocking issues](https://hackaday.com/2016/07/01/what-could-go-wrong-spi/)
[SPI bus/cable length issues](https://electronics.stackexchange.com/questions/203072/spi-bus-length)

Lots of pins. But bi-directional.

Steps:
* slave line goes low first. (CS)
* master starts clock and bits are traded.
* data exchanged byte by byte.

Issues that cause capacitance increase:
* inter-line. clk and data lines close to each other.
* line length. more length, more capacitance.
* shielding of wires.

Capacitance of cable/bus increases with distance. This causes slow growth of voltages and doesn't reach the desired level and we dont get a defined clock in high speeds (100 MHz). In low speeds, we do get time to grow to the levels so its fine. 

## I2C
[I2C Concept](https://drive.google.com/file/d/1nDCR9Tn-c3cm4nS6NZ7bzwgCTOnTdxeF/view?usp=share_link)

Less pins and compact. Not bi-directional. 
There is some overhead with I2C; for
every 8 bits of data to be sent, one extra bit of meta data (the "ACK/NACK" bit, which we'll discuss later) must be transmitted.

## UART
asynchronous. no clock. must agree on a data rate. (baud rates)