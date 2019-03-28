#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <curl/curl.h>

char * geturl(char * word);
int curl(char * url);

int main(int argc, char const *argv[]) {

  char * word = "amo";
  char * miniurl = "en.wiktionary.org";
  char * url = geturl(word);
  printf("%s\n", url);
  curl(url);
  printf("%s\n", "end");
  free(url);
  return 0;
}

int curl(char * url)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

char * geturl(char * word) {
  char * urlstart = "en.wiktionary.org/wiki/";
  char * urlend = "";
  int fullen = strlen(urlstart) + strlen(word) + strlen(urlend) + 1;
  char * fullurl = malloc(fullen);
  strcpy(fullurl, urlstart);
  strcat(fullurl, word);
  strcat(fullurl, urlend);
  return fullurl;
}
