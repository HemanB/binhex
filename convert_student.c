#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

void binHex (char *src, char *dst, size_t max);
void hexBin (char *src, char *dst, size_t max);

void binHex (char src[], char dst[], size_t max)
{
  // Convert binary to hexadecimal
  if ((max%4)!=0) {
    dst[0]='\0';
    fprintf(stderr, "Error: Invalid binary input.\n");
  }

  int i=0;
  int j=0;

  for (i=0;i<(max-1);i++) {
    if ((src[i]=='\0')||((src[i]!='0')&&(src[i]!='1'))||(src[i]=='\n')) {
      break;
    }
  }
  int end = i;
  int k=end/4;
  dst[k]='\0';
  for (i=(end-1);i>=0;i-=4) {
    k--;
    int value = 0;
    for (j=0;j<4;j++){
      if (j==0){
        value+=(1*(src[i-j]-'0'));
      } 
      if (j==1){
        value+=(2*(src[i-j]-'0'));
      }
      if (j==2){
        value+=(4*(src[i-j]-'0'));
      }
      if (j==3){
        value+=(8*(src[i-j]-'0'));
      }
      if ((value>=0)&&(value<=9)) {
        dst[k]='0'+ value;
      }
      if ((value>=10)&&(value<=15)) {
        dst[k]='a'+ (value-10);
      }
    }
  }
}

void hexBin(char src[], char dst[], size_t max)
{
  // Convert hexadecimal to binary
  int i;
  int j;
  for (i=0;i<(max-1);i++) {
    if ((src[i]=='\0')||(((src[i]<'a')||(src[i]>'f'))&&((src[i]<'0')||(src[i]>'9')))||(src[i]=='\n')) {
      break;
    }
  }
  int end = i;
  int k = end*4;
  dst[k]='\0';
  for (j=(end-1);j>=0;j--){
    int value = 0;
    if (src[j] >= '0' && src[j] <= '9') {
      value = src[j] - '0';
    } else if (src[j] >= 'a' && src[j] <= 'f') {
      value = 10 + (src[j] - 'a');
    }
    k--;
    dst[k] = (value % 2) ? '1' : '0';
    k--;
    dst[k] = ((value/2) % 2) ? '1' : '0';
    k--;
    dst[k] = ((value/4) % 2) ? '1' : '0';
    k--;
    dst[k] = ((value/8) % 2) ? '1' : '0';
  }
}
