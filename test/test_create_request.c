#include <stdio.h>
#include <stdlib.h>
#include "../http.h"


int main(void)
{
    char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n";
    struct request *r = NULL;
    printf("%p\n", &r);
    create_request(req, &r);
    printf("wee\n");
    printf("%p\n", r);
	printf("%d\n", sizeof(*r));

    return 0;
}