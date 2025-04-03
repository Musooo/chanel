#include <stdio.h>
#include "../my_string.h"

int main()
{
        char msg[] = "oi-ii-io";
        split_string(msg, '-');
        printf("%s\n", msg);
        char *ptrf = next_string(msg);
        printf("%s\n", ptrf); // this is gona print ii
        ptrf = next_string(ptrf);
        printf("%s\n", ptrf); // this is gona print oi
}