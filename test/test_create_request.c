#include <stdio.h>
#include "../http.h"


int main(void)
{
	char req[] = "GET / HTTP/1.1\nHost: example\nAccept-language:qq\n";
	create_request(req);

	return 0;
}
