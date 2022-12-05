#include "logger.h"

void logIt(char* who, const char* string, ...)
{
    time_t now = time(NULL);
    printf("[%s] : [%s] : ", asctime(localtime(&now)), who);

    // For variablle number of arguments. 
    // https://en.cppreference.com/w/c/variadic

    va_list args;
    va_start(args, string); // string is the parameter preceding variable args.
    printf(string, args);
    va_end(args);
}