#include <stdio.h>
#include "../http.h"
#include "../my_string.h"

int main(void){
    char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n";
    split_string(req, '\n');

    struct request r = init_request();

    char *method = NULL;
    char *url = NULL;
    char *version = NULL;
    char *token = _create_request_line(&method, &url, &version, req);

    r.version = version;
    r.method = method;
    r.url = url;

    struct head *h = NULL;
    _create_headers_from_request(token, &h);
    r.headers=h;

    return 0;
}