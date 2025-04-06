#include <stdio.h>
#include <stdlib.h>
#include "../http.h"


int main(void){
    char req[] = "GET / HTTP/1.1\r\nHost: example\r\nAccept-language:qq\r\n\r\nciao\r\nweeee\r\naooo";
    struct request r = get_request(req);
    set_header(r.hs, "wela", "oia");
    printf("%d\n", get_header_value_index(r.hs, "wela"));
    printf("%s\n", get_header_value(r.hs, "wela"));

    print_request(r);
    free_req(r);

    // free(r.hs->headers);
    // free(r.hs);

    return 0;
}