#include <string.h>
#include <stdio.h>
#include <curl/curl.h>

void showHelp() {
    printf("duct help\n");
}

int main(int argc, char **argv) {
    if(argc < 2) {
	showHelp();
	return 0;
    }

    char *op = argv[1];

    if(strcmp(op, "send") == 0) {
	printf("send\n");
    }
    else if(strcmp(op, "listen") == 0) {
	printf("listen\n");
    }
    else if(strcmp(op, "flow") == 0) {
	printf("flow\n");
    }
    else {
	showHelp();
    }

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {

	curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}
