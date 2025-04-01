#ifndef HTTP_H
#define HTTP_H

struct request {
        char *method;
        char *url;
        char *version;
        header h;
        body b;
};

struct header{
        char *heads;
};

struct body{
        char *body;
};

#endif
