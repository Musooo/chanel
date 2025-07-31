enum string_error
{
	MAX_CHAR_LENGTH_SUCCEEDED = -2,
	DIFFERENT_STRINGS,
	SUCCESS,
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

int len_n(char *string,  const int MAX_STRING_LENGTH)
{
	int tot = 0;
	while (*string!='\0' && tot<=MAX_STRING_LENGTH)
	{
		string++;
		tot++;
	}
	
	if (tot>=MAX_STRING_LENGTH)
	{
		return MAX_CHAR_LENGTH_SUCCEEDED; 
	}

	return tot;
}

int strcmp_homemade(char *string1, char *string2, const int MAX_STRING_LENGTH)
{
	int count = 0;
	/* consider removing the first control and only check the string length*/	
	while ((*string1!='\0' || *string2!='\0'))
	{	
		if (count>MAX_STRING_LENGTH)
		{
			return MAX_CHAR_LENGTH_SUCCEEDED;
		}

		if(*string1!=*string2)
		{
			return DIFFERENT_STRINGS;
		}

		if (*string1=='\0' && *string2=='\0')
		{
			break;
		}

		string1++;
		string2++;
		count ++;
	}


	return 0;
}
