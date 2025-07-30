#ifndef MY_STRING_H
#define MY_STRING_H



enum string_error
{
	MAX_CHAR_LENGTH_SUCCEEDED = -1,
	DIFFERENT_STRINGS = -2,
};
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
/* it's a stlen but you pass a max length +1 that the string can assume (if the max is 4 the max word length is gonna be 3 not 4) */
int len_n(char *string, const int max_length);
int strcmp_homemade(char *string1, char *string2, const int max_string_length);


#endif
