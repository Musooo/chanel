#ifndef HTTP_H
#define HTTP_H

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
enum head_name
{
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
        char *method;
        char *url;
        char *version;
        struct header h;
        /* the header and the body are separeted by a empty line*/
        struct body b;
};

struct head _divide_header(char *token);
int _create_request_line(char *method, char *url, char *version, char *line);
int _create_headers_from_request(char *token, struct header *h);
int create_request(char *request_string, struct request **req);

#endif
