#include <stdio.h>
#include "../http.h"
#include "../my_string.h"

int main(void){
    char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n";
    split_string(req, '\n');

    struct request r = init_request();

    char *token = _create_request_line(&(r.method), &(r.url), &(r.version), req);


    printf("%s\n", r.method);
    printf("%s\n", r.url);
    printf("%s\n", r.version);


    _create_headers_from_request(token, &(r.headers));
    printf("%s\n", r.headers[0].key);

    return 0;
}