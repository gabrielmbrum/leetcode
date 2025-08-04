#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int longest = 0, j, k;
    bool repetiu = false;

    for (int i = 0; i < strlen(s); i++) {
        j = i+1;
        while (j < (int)strlen(s) && s[i] != s[j]) {
            //puts("ta la");
            if (j - i >= 2) {
                //puts("ta no j - i");
                k = j-1;
                while (k > i) {
                    //puts("ta no k > i");
                    if (s[k] == s[j]) {
                        repetiu = true;
                        break;
                    }
                    k--;
                }
                if (repetiu == true) {
                    repetiu = false;
                    break;
                }
            }
            j = j+1;
            //printf("adicionou no j -> %d\n", j);
        }

        longest = j - i > longest ? j - i : longest;
        if (longest == strlen(s) - 1) break;
    }

    return longest;
}

int main () {
	char *s;
	scanf("%s", s);
	printf("result: %d\n", lengthOfLongestSubstring(s));

	return 0;
}
