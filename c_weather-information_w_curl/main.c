#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function for curl
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // Print the received data
    printf("%.*s", (int)(size * nmemb), ptr);
    return size * nmemb;
}

int main(void) {
    // Initialize curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing curl\n");
        return 1;
    }

    // Set the URL for the weather API
    char url[100];
    sprintf(url, "https://wttr.in/Fayetteville,%%20AR?format=3");

    // Set the curl options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing curl request: %s\n", curl_easy_strerror(res));
        return 1;
    }

    // Cleanup curl
    curl_easy_cleanup(curl);

    return 0;
}

