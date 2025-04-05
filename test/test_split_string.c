#include <stdio.h>
#include "../my_string.h"

int main()
{
        char msg[] = "GET / HTTP/1.1\r\nHost: example\r\nAccept-language:qq\r\n\r\nciao\r\nweeee\r\naooo";
        split_request_string_until_the_body(msg, '\n');
        printf("%s\n", msg);
        printf("%s\n", next_string(msg));
        printf("%s\n", next_string(next_string(msg)));
        printf("%s\n", next_string(next_string(next_string(msg))));
        printf("%s\n", next_string(next_string(next_string(next_string(msg)))));
        printf("%s\n", next_string(next_string(next_string(next_string(next_string(msg))))));

        return 0;
}