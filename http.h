/*
        this library takes inspiration from the libraries HTTPUrlConnection, HTTPServletRequest, HTTPServletResponse
        in creating http request and response messages easily and having getter and setter style to work with them
*/
#ifndef HTTP_H
#define HTTP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

/*
        this maybe usefull for the response implementation
*/
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
        this represent a header which is compose by a key field and a value of the field
*/
struct head
{
        char *key;
        char *value;
};

/*
        this struct represent the composition of a http request.
        compose by the http method (e.g. GET,POST,PUT,ECC...).
        the url which specified which resource we want to access.
        the version of http that we are using.
        then we have a list of header with a head_size fields so that we now how many header we have,
        this is going to be usefull for some future must have function
        remember that in http requests and responses the header and body are separated by a empty line.

*/
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

/*
        this function initialize an empty request struct
*/
struct request init_request();
/*
        as already said, function that starts with the character "_" are not made as the primary object of being
        used by user but as private function for the library, of course if the fit your uses case use them. 
*/
/*
        this function is used so that given a string that is an header it divide the key from the value,
        using ":" as the separator, and saves them in our head structure
*/
struct head _divide_header(char *token);
/*
        this function is used to add an header to the array of headers,
        we use a ** so that we can modified the pointer of the header,
        we have to pass it like this because when we pass a variable to a function
        it clones it, so if we pass the pointer to the pointer we can change the memory adders
        without the need to pass it back, i'm gonna use this for other function to
*/
int _add_a_header_to_the_header_arr(struct head **headers, struct head h, int *size);
/*
        this function is used to associate the first line of the request to the
        request struct field method, url and version,
        this because in a request the first line must have that exact structure
*/
char* _create_request_line(char **method, char **url, char **version, char *line);
int _create_headers_from_request(char **token, struct head **h);
int print_request(struct request r);
struct request get_request(char *req);

#endif
