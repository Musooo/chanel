
enum string_error
{
	MAX_CHAR_LENGTH_SUCCEEDED = -1,
	DIFFERENT_STRINGS = -2,
};


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

int len_n(char *string, const int max_length)
{
	int tot = 0;
	while (*string!='\0' && tot<=max_length)
	{
		string++;
		tot++;
	}
	
	if (tot>=max_length)
	{
		return MAX_CHAR_LENGTH_SUCCEEDED; 
	}

	return tot;
}


int strcmp_homemade(char *string1, char *string2, const int max_string_length)
{
	int count = 0;
	int is_char_the_same = 0; /* 0 = same, 1 = not same, 2 = string to long */
	while (*string1!='\0' && *string2!='\0' && count<=max_string_length)
	{
		if(*string1!=*string2)
		{
			return DIFFERENT_STRINGS;
		}
		string1++;
		string2++;
		count ++;
	}

	if (count>=max_string_length)
	{
		return MAX_CHAR_LENGTH_SUCCEEDED;
	}

	return 0;
}
