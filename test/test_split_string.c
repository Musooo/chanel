#include <stdio.h>
#include "../my_string.h"

int main()
{
        char msg[] = "oi-ii-ii";
        split_string(msg, '-');
        printf("%s\n", msg);
        printf("%s\n", msg+3);
}