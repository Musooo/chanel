#include <stdio.h>
#include "../http.h"
#include "../my_string.h"

int main(void){
    char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n\nciao\nweeee\naooo";
    split_request_string_until_the_body(req, '\n');

    struct request r = init_request();

    char *token = _create_request_line(&(r.method), &(r.url), &(r.version), req);


    printf("%s\n", r.method);
    printf("%s\n", r.url);
    printf("%s\n", r.version);


    r.head_size = _create_headers_from_request(&token, &(r.headers)); //TO DO pass the size of the headers as a param of _create_headers_from_request
    printf("%s\n", r.headers[0].key);
    printf("%s\n", token);

    token = next_string(token);
    r.body = token;
    printf("%s\n", r.body);

    print_request(r);

    return 0;
}