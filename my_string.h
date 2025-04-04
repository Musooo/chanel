#ifndef MY_STRING_H
#define MY_STRING_H

int split_string(char *string, char char_where_to_split);
int split_request_string_until_the_body(char *string, char char_where_to_split);
char* next_string(char *string);


#endif