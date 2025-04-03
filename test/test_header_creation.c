#include <stdio.h>
#include <string.h>
#include "../http.h"



int main(void){
    char req[] = "Host: example\nAccept-language:qq\n";
    struct head *h = NULL;
    _create_headers_from_request(req, &h);
    printf("%s\n", h[0].key);

    return 0;
}