#include <stdio.h>
#include "../my_string.h"

int main()
{
        char msg[] = "oi-ii-io";
        split_string(msg, '-');
        printf("%s\n", msg);
        printf("%s\n", next_string(msg)); // this is gona print ii
        printf("%s\n", msg); //this print oi
}