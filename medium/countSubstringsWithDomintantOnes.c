#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// count >= (strlen(s)-count)
int numberOfSubstrings(char* s) {
  int len = strlen(s);
  int* prefixOnes = (int*)malloc((len + 1) * sizeof(int));
  int i, j, numberOfSub = 0, count, substringLength;

  prefixOnes[0] = 0;
  for (i = 1; i <= len; i++) {
    prefixOnes[i] = prefixOnes[i-1] + (s[i-1] == '1' ? 1 : 0);
  }

  for (i = 0; i < len; i++) {
    for (j = i + 1; j <= len; j++) {
      count = prefixOnes[j] - prefixOnes[i]; 
      substringLength = j - i - count; //minus count is to optimize the next comparation
      if (count >= (substringLength) * (substringLength)) {
        numberOfSub++;
      }
    }
  }

  free(prefixOnes);
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
O(n^3) solution -> my first try

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
 */