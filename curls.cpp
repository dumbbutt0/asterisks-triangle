#include <iostream>
#include <curl/curl.h>

void curled()
{
    //pointer to CURL struct
    CURL *curl; 
    // store result in res
    CURLcode res;   
    //Make a global curn env
    curl_global_init(CURL_GLOBAL_DEFAULT);
    //initialize curl
    curl = curl_easy_init();
    //if successful
    if(curl){
        //set URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "https://dumbbutt.tech");
        //make HTTP request
        res = curl_easy_perform(curl);
        //clean CURL handle
        curl_easy_cleanup(curl);
    }
    //clean the gloabal curl env
    curl_global_cleanup();
}

int main()
{
    curled();
    return 0;
}