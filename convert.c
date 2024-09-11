#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

extern void binHex(char src[], char dst[], size_t max);
extern void hexBin(char src[], char dst[], size_t max);

#define MAXLINE 64
char linebuf[MAXLINE];
char result[MAXLINE];

int main (int argc, char **argv) 
{ 
  char opt;
  char *sin;
  bool binaryToHex;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [-b|-h]\n", argv[0]);
    return EXIT_SUCCESS;
  }
  while ((opt = getopt(argc, argv, "bh")) != -1) {
    switch (opt) {
      case 'b':
        binaryToHex = true;
        break;
      case 'h':
        binaryToHex = false;
        break;
      default:
        fprintf(stderr, "Usage: %s [-b|-h]\n", argv[0]);
        return EXIT_SUCCESS;
    }
  }
  sin = fgets(linebuf, MAXLINE, stdin);
  while (sin != NULL) {
    if (binaryToHex)
      binHex(linebuf, result, MAXLINE);
    else
      hexBin(linebuf, result, MAXLINE);
    printf("%s\n", result);
    sin = fgets(linebuf, MAXLINE, stdin);
  }
  return EXIT_SUCCESS;
}
