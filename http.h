#ifndef HTTP_H
#define HTTP_H

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

enum head_name
{
        ACCEPT,
        CONTENT_ENCODING,
        CONTENT_LENGTH,
        CONTENT_TYPE,
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

struct header
{
        struct head *headers;
};

struct head
{
        enum head_name head_key;
        char *value;
};

struct body
{
        char *body;
};

#endif
