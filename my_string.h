#ifndef MY_STRING_H
#define MY_STRING_H

/*
    this function use the fact that a string in c
    is a continue block of memory that end with '\0',
    and so by substituting the characther that we want with '\0'
    we create a function like pythons .split(),
    were every item of the string is still next to each other. 
    this function returns the number of item in the array.
*/
int split_string(char *string, char char_where_to_split);
int split_request_string_until_the_body(char *string, char char_where_to_split);
char* next_string(char *string);


#endif