// Sibros interview question.

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

uint8_t get_num(char input)
{
    if(input >= '0' && input <= '9')
        return (input - '0');
    
    if(input >= 'a' && input <= 'f')
        return (input - 'a') + 10;

    if(input >= 'A' && input <= 'F')
        return (input - 'A') + 10; 

    return 16;
}

bool hex_2_byte(uint8_t* output, char* input, size_t input_size)
{
    int cursor = 0;
    int output_index = 0;
    while(input[cursor] != '\0')
    {
        if(input[cursor] == 'x')
        {
            char char_1 = input[cursor + 1];
            uint8_t result = get_num(char_1);
            if(result == 16)
            {
                return false;
            }

            char char_2 = input[cursor + 2];
            uint8_t current_num = get_num(char_2);
            if(current_num == 16)
            {
                cursor += 2;
            } 
            else
            {
                result = (result << 4) | current_num;
                cursor +=3;
            }           
            
            output[output_index++] = result;      
        }
        else
        {
            ++cursor;
        }
    }
    return true;
}

void converter(char* input, size_t input_size)
{
    uint8_t* output = (uint8_t*)malloc(sizeof(uint8_t) * input_size);

    if(hex_2_byte(output, input, input_size))
    {
        for(int i = 0; i < input_size; i++)
        {
            printf("%x ", output[i]);
        }
        printf("\n");
    }
    else
    {
        printf("invalid hex string\n");   
    }

    free(output);
}

int main()
{
    char* input1 = "0xf1, 0x12, 0xa3";
    converter(input1, 3);

    char* input2 = "0xf1, 0x01, 0xC, 0x02";
    converter(input2, 4);

    char* input3 = "0xf1, 0x12, 0x";
    converter(input3, 3);

    char* input4 = "0xf1, 0x12, x10, xA";
    converter(input4, 4);

    return 0;
}


