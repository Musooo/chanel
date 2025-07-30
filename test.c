#include "http.h"
#include "my_string.h"
#include <pthread.h>
#include <string.h> // temp solution for strcmp (i know how to do it, i'm gonna do it later)



enum error
{
	URL_DIFFERENT,
	VERSION_DIFFERENT,
	METHOD_DIFFERENT,
};

void test_res_print(int res, int res_i_expect, int test_num, char *test_type)
{
	if(res != res_i_expect)
		printf("\033[1;31merror %s N:%d in testing\n", test_type, test_num);
	else
		printf("\033[1;32mtest %s N:%d passed\n",  test_type, test_num);
}


int test_create_request_line(char *req_line, char *url_result, char *version_result, char *method_result)
{
	char *url, *version, *method;
	_create_request_line(&method, &url, &version, req_line);
	
	if (strcmp(url, url_result))
		return URL_DIFFERENT;
	if (strcmp(version, version_result))
		return VERSION_DIFFERENT;
	if (strcmp(method, method_result))
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

int main(void)
{
	pthread_t thread_create_req_line;
	pthread_create(&thread_create_req_line, NULL, tests_create_req_line, NULL);
	pthread_join(thread_create_req_line, NULL);
	
	return EXIT_SUCCESS;
}
