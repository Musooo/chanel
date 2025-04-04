#include <stdio.h>
#include "../http.h"
#include "../my_string.h"

int main(void){
    char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n";
    split_string(req, '\n');
    char *method = NULL;
    char *url = NULL;
    char *version = NULL;
    char *token = _create_request_line(&method, &url, &version, req);

    printf("%s\n", version);
    printf("%s\n", token);


    return 0;
}