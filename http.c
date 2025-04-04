#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

enum status
{
        CONTINUE = 100,
        SWITCHING_PROTOCOLS,
        EARLY_HINTS,
        OK = 200,
        CREATED,
        ACCEPTED,
        NON_AUTHORITATIVE_INFORMATION,
        NO_CONTENT,
        RESET_CONTENT,
        PARTIAL_CONTENT,
        MULTI_STATUS,
        ALREADY_REPORTED,
        IM_USED = 226,
        MULTIPLE_CHOICE = 300,
        BAD_REQUEST = 400,
        UNAUTHORIZED,
        PAYMENT_REQUIRED,
        FORBIDDEN,
        NOT_FOUND,
        INTERNAL_SERVER_ERROR = 500,
};

struct head
{
        char *key;
        char *value;
};

struct request
{
        char *method;
        char *url;
        char *version;
        struct head *headers;
        int head_size;
        /* the header and the body are separeted by a empty line*/
        char *body;
};

struct request init_request(){
        struct request r = (struct request) 
        {
                .method = NULL,
                .url = NULL,
                .version = NULL,
                .headers = NULL,
                .head_size = 0,
                .body = NULL
        };

        return r;
}

int _add_a_header_to_the_header_arr(struct head **headers, struct head h, int *size)
{
        *headers = (struct head*) realloc(*headers, (*size+1) * sizeof(h));
        (*headers)[*size] = h;
        (*size)++;
        return 0;
}

char* _create_request_line(char **method, char **url, char **version, char *token)
{
        split_string(token, ' ');
        *method = token;
        token = next_string(token);

        *url = token;
        token = next_string(token);

        *version = token;
        token = next_string(token);


        return token;
}


struct head _divide_header(char *token)
{
        char *line = malloc(strlen(token)+1);
        strcpy(line, token);
        split_string(line, ':');
        char *key = malloc(strlen(line) + 1);
        strcpy(key, line);
        line = next_string(line);
        char *value = malloc(strlen(line) + 1);
        strcpy(value, line);

        struct head h;

        h.key = key;
        h.value = value;

        return h;
}

int _create_headers_from_request(char **token, struct head **head)
{
        int size = 0;
        while (**token && **token != '\0'){
                printf("%s\n", *token);
                struct head h = _divide_header(*token);
                *token = next_string(*token);
                _add_a_header_to_the_header_arr(head,h,&size);
        }

        return size;
}

int print_request(struct request r)
{

        printf("%s\n", r.method);
        printf("%s\n", r.url);
        printf("%s\n", r.version);
        for (int i = 0; i<r.head_size; i++){
                printf("%s:", r.headers[i].key);
                printf("%s\n", r.headers[i].value);
        }
        printf("%s\n", r.body);

        return 0;
}/*TO DO: need to know where the starting string ends, so find the original \0 and then save everything between the space and the last \0*/