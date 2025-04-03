int split_string(char *string, char char_where_to_split)
{
        while (*string!='\0')
        {
                if (*string == char_where_to_split)
                {
                        *string='\0';
                }
                string++;
        }

        return 0;
}

char* next_string(char *string)
{
        while (*string!='\0')
        {
                string++;
        }
        string++;
        return string++;
        
}