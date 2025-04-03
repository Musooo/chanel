#include "../http.h"
#include <stdio.h>


int main(void){
    char token[] = "Accept: */*";
    //printf("%s\n", token);
    struct head h = _divide_header(token);
    printf("%s:%s\n", h.key, h.value);
    printf("%s\n", token);

    return 0;
}
