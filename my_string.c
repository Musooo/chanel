int split_string(char *string, char char_where_to_split)
{
        int count = 0;
        while (*string!='\0')
        {
                if (*string == char_where_to_split)
                {
                        *string='\0';
                        count++;
                }
                string++;
        }
        count++; /* this because the last word is not consider*/
        return count;
}

int split_request_string_until_the_body(char *string, char char_where_to_split)
{
        int same_char_consequential = 0;
        while (*string!='\0')
        {
                if (same_char_consequential==2)
                {
                        //*string='\0';
                        return 0;
                }else if (*string == char_where_to_split)
                {
                        *string='\0';
                        same_char_consequential+=1;
                }else if (*string != '\r')
                        same_char_consequential=0;
                string++;
        }

        return 0;
}/* */

char* next_string(char *string)
{
        while (*string!='\0')
        {
                string++;
        }
        string++;
        return string++;
        
}