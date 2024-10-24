#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// count >= (strlen(s)-count)
int numberOfSubstrings(char* s) {
  int i, j, k, count, numberOfSub, len;
  i = 0;
  len = strlen(s);
  j = len;
  count = numberOfSub = 0;

  while (j > 0) {
    for (k = i; k < j+i; k++) {
      if (s[k] == '1')
        count++;
    }
    if (count >= (j-count)*(j-count)) {
      numberOfSub++;
    }
    count = 0;
    if (k + 1 > len) {
      i = 0;
      j--;
    } 
    else
      i++;
  }

  return numberOfSub;
}

int main () {
  char *s;
  int n;

  scanf(" %d", &n);

  s = (char*) malloc(sizeof(char) * (n+1));

  scanf("%s", s);
  printf("%d\n", numberOfSubstrings(s));

  free(s);

  return 0;
}
/**
1 -> 1
2 -> 3
3 -> 6
4 -> 10
5 ->
 */

 /*
 int numberOfSubstrings(char* s) {
  int i, j, k, count, numberOfSub, len;
  i = 0;
  len = strlen(s);
  j = len;
  count = numberOfSub = 0;

  while (j > 0) {
    printf("analyzing s[%d] to s[%d]...\n", i, j-1+i);
    for (k = i; k < j+i; k++) {
      if (s[k] == '1')
        count++;
    }
    printf("count = %d | zeros = %d | cmp = %d\n", count, j - count, (j-count)*(j-count));
    if (count >= (j-count)*(j-count)) {
      printf("\nLOL s[%d] to s[%d]\n",  i, j-1+i);
      numberOfSub++;
    }
    count = 0;
    printf("\n\n");
    if (k + 1 > len) {
      i = 0;
      j--;
      printf("\tproximo intervalo de %d em %d\n", j, j);
    } 
    else
      i++;
  }

  return numberOfSub;
}
 */