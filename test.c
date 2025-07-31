#include "my_string.h"
#include "http.h"
#include <pthread.h>
// temp solution for strcmp (i know how to do it, i'm gonna do it later)

enum error
{
	URL_DIFFERENT,
	VERSION_DIFFERENT,
	METHOD_DIFFERENT,
};

void test_res_print(int res, int res_i_expect, int test_num, char *test_type)
{
	if(res != res_i_expect)
		printf("\033[1;31merror %s N:%d in testing expected:%d got:%d\n", test_type, test_num, res_i_expect, res);
	else
		printf("\033[1;32mtest %s N:%d passed\n",  test_type, test_num);
}

void* test_strcmp(void *args)
{
	int test_n = 0;
	char text_type[] = "strcmp test";
	char tooLongStr[] = "qoqoqoqoqoqoqooqoqoqoqoqoqooqoq";
	char stringN[] = "hello";
	char stringSheldon[] = "bazingaa";
	char string3[] = "helloo";

	test_res_print(strcmp_homemade(stringN, stringN, 100), 0, test_n, text_type);
	test_n++;	
	
	test_res_print(strcmp_homemade(stringN, string3, 100), DIFFERENT_STRINGS, test_n, text_type);
	test_n++;

	test_res_print(strcmp_homemade(tooLongStr, tooLongStr, 5), MAX_CHAR_LENGTH_SUCCEEDED, test_n, text_type);
	test_n++;

	test_res_print(strcmp_homemade(stringN, string3, 5), DIFFERENT_STRINGS, test_n, text_type);
	test_n++;

	return 0;
}


int test_create_request_line(char *req_line, char *url_result, char *version_result, char *method_result)
{
	char *url, *version, *method;
	_create_request_line(&method, &url, &version, req_line);
	
	if (strcmp_homemade(url, url_result,1024))
		return URL_DIFFERENT;
	if (strcmp_homemade(version, version_result, 1024))
		return VERSION_DIFFERENT;
	if (strcmp_homemade(method, method_result,1024))
		return METHOD_DIFFERENT;
	return 0;
}

void* tests_create_req_line(void *args)
{
	char test_type[] = "create_request_line";
	int test_n = 0;
	
	char s1[] = "we oi ww";
	char s2[] = "oi";
	char s3[] = "ww";
	char s4[] = "we";

	test_res_print(test_create_request_line(s1, s2, s3, s4), 0, test_n, test_type);
	test_n++;
	
	test_res_print(test_create_request_line(s1, s3, s3, s4), URL_DIFFERENT, test_n, test_type);
	test_n++;
	
	test_res_print(test_create_request_line(s1, s2, s2, s4), VERSION_DIFFERENT, test_n, test_type);
	test_n++;
	
	test_res_print(test_create_request_line(s1, s2, s3, s2), METHOD_DIFFERENT, test_n, test_type);

	return 0;
}

void* test_len(void *args)
{
	int test_n = 0;
	char test_type[] = "string length test";
	char string[] = "4444";

	test_res_print(len_n(string, 10), 4, test_n, test_type);
	test_n++;

	test_res_print(len_n(string, 3), MAX_CHAR_LENGTH_SUCCEEDED, test_n, test_type);
	test_n++;

	return 0;
}

int main(void)
{
	pthread_t thread_create_req_line, thread_strcmp, thread_len;
	
	pthread_create(&thread_create_req_line, NULL, tests_create_req_line, NULL);
	pthread_create(&thread_strcmp, NULL, test_strcmp, NULL);
	pthread_create(&thread_len, NULL, test_len, NULL);

	pthread_join(thread_len, NULL);
	pthread_join(thread_create_req_line, NULL);
	pthread_join(thread_strcmp, NULL);
	
	return EXIT_SUCCESS;
}
