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

struct headers
{
        struct head *headers;
        int head_size;
};

struct request
{
        char *method;
        char *url;
        char *version;
        struct headers *hs;
        /* the header and the body are separeted by a empty line*/
        char *body;
};

struct response
{
        char *version;
        char *status_number;
        char *status_msg;
        struct headers *hs;
        /* the header and the body are separeted by a empty line*/
        char *body;
};

struct request init_request()
{
        struct request r = (struct request) 
        {
                .method = NULL,
                .url = NULL,
                .version = NULL,
                .hs = malloc(sizeof(struct headers)),
                .body = NULL
        };

        if (r.hs)
        {
                r.hs->headers = NULL;
                r.hs->head_size = 0;
        }

        return r;
}
struct response init_response()
{
        struct response resp = (struct response)
        {
                .version = NULL,
                .status_number = NULL,
                .status_msg = NULL,
                .hs = malloc(sizeof(struct headers)),
                .body = NULL,
        };

        if (resp.hs)
        {
                resp.hs->headers = NULL;
                resp.hs->head_size = 0;
        }

        return resp;
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

/* MEMORY LEAK HERE*/
struct head _divide_header(char *token)
{
        split_string(token, ':');
        struct head h;
        h.key = token;
        token = next_string(token);
        h.value = token;
        
        return h;
}

int _create_headers_from_request(char **token, struct headers *headers)
{
        while (**token && **token != '\0' && **token!='\r'){

                struct head h = _divide_header(*token);
                *token = next_string(*token);
                *token = next_string(*token);
                _add_a_header_to_the_header_arr(&(headers->headers),h,&(headers->head_size));
        }
        *token = next_string(*token);
        return 0;
}

int print_request(struct request r)
{
        printf("%s\n", r.method);
        printf("%s\n", r.url);
        printf("%s\n", r.version);
        for (int i = 0; i<r.hs->head_size; i++){
                printf("%s:", r.hs->headers[i].key);
                printf("%s\n", r.hs->headers[i].value);
        }
        printf("%s\n", r.body);

        return 0;
}/*TO DO: need to know where the starting string ends, so find the original \0 and then save everything between the space and the last \0*/

struct request get_request(char *req)
{
        struct request r = init_request();
        split_request_string_until_the_body(req, '\n');

        char *token = _create_request_line(&(r.method), &(r.url), &(r.version), req);
        _create_headers_from_request(&token, r.hs); //TO DO pass the size of the headers as a param of _create_headers_from_request

        //token = next_string(token);
        r.body = token;

        return r;
}

int free_req(struct request r)
{
        free(r.hs->headers);
        free(r.hs);
        return 0;
}