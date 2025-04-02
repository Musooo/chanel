#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

struct header
{
        struct head *headers;
};

struct body
{
        char *body;
};

struct request
{
        char *method[16];
        char *url[256];
        char *version[16];
        struct header h;
        /* the header and the body are separeted by a empty line*/
        struct body b;
};

int _create_request_line(char *method, char *url, char *version, char *token)
{
        char *req_line = strtok(token, " ");
        strcpy(method, req_line);
        req_line = strtok(NULL, " ");
        strcpy(url, req_line);
        req_line = strtok(NULL, " ");
        strcpy(version, req_line);
        req_line = strtok(NULL, " ");


        return 0;
}

int _create_headers_from_request(char *token, struct header* h)
{
}

struct head _divide_header(char *token)
{
        char *line = strtok(token, ":");
        char *key = malloc(strlen(line) + 1);
        strcpy(key, line);
        line = strtok(NULL, " ");
        char *value = malloc(strlen(line) + 1);
        strcpy(value, line);

        struct head h;

        h.key = key;
        h.value = value;

        return h;
}

int create_request(char *request_string)
{
        //printf("%s\n", request_string);
        char method[16];
        char url[256];
        char version[16];
        char *token = strtok(request_string, "\n");
        char *req_line = malloc(strlen(token)+1);
        strcpy(req_line, token);
        
        token = strtok(NULL, "\n");
        while (token)
        {
                printf("%s\n", token);
                token = strtok(NULL, "\n");
        }
        

        /* we work later on the request line because else it gives me problem and idk how to solve this so yea, but this should be fine*/
        _create_request_line(method, url, version, req_line);
        free(req_line);
        printf("%s\n", method);
        printf("%s\n", url);
        printf("%s\n", version);



        return 0;
}


