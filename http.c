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

/*
enum head_name{
        ACCEPT,
        CONTENT_ENCODING,
        CONTENT_LENGTH,
        CONTENT_TYPE,
};
*/


struct head
{
        char *key;
        char *value;
};

// struct header
// {
//         struct head *headers;
// };

// struct body
// {
//         char *body;
// };

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

int _create_headers_from_request(char *token, struct head **head)
{
        int size = 0;
        // char *header_string = malloc(strlen(token)+1);
        // strcpy(header_string, token);
        // split_string(header_string, '\n');
        while (*token){
                struct head h = _divide_header(token);
                token = next_string(token);
                _add_a_header_to_the_header_arr(head,h,&size);
        }

        return size;
}/* there and in func _divide_header remember to free the mem, could use a mem arena to allocate the req and resp and free it one at the end but idk*/


/* not working it returns with the right memory address but it's not the same size idk to fix in the future*/
// int create_request(char *request_string, struct request *req)
// {
//         struct request *r = (struct request*)malloc(sizeof(struct request));
//         r->h.headers = NULL;
//         r->b.body = NULL;
//         //printf("%s\n", request_string);
//         char *token = strtok(request_string, "\n");
//         char *req_line = malloc(strlen(token)+1);
//         strcpy(req_line, token);
        
//         token = strtok(0, "\n");
//         while (token)
//         {
//                 printf("%s\n", token);
//                 token = strtok(0, "\n");
//         }
        
//         /* we work later on the request line because else it gives me problem and idk how to solve this so yea, but this should be fine*/
//         _create_request_line(r->method, r->url, r->version, req_line);
//         free(req_line);
//         printf("%s\n", r->method);
// 	printf("%s\n", r->url);
// 	printf("%s\n", r->version);
//         printf("%p\n", r);
//         return 0;
// }


