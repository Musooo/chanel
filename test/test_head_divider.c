#include "../http.h"
#include <stdio.h>


int main(void){
    char token[] = "Accept: */*";
    //printf("%s\n", token);
    struct head h = _divide_header(token);
    printf("%s: %s", h.key, h.value);

    return 0;
}
