#include <string.h>

int beautifulSubstrings(char* s, int k) {
  // receives a string
  // analysis if all substrings not-empty is beatiful
  // if vowels == consonants and (vowels * consonants) % k == 0

  int vowels = 0;
  int consonants = 0;
  int num_of_beautiful_substrings = 0;
  // dividing in substrings

  for (int i = 0; i < strlen(s); i++) {
      for (int j = i; j < strlen(s); j++) {
          if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
              vowels++;
          else 
              consonants++; 

          if (vowels == consonants && (vowels * consonants) % k == 0)
              num_of_beautiful_substrings++;
      }
      vowels = consonants = 0;
  }

  return num_of_beautiful_substrings;
}