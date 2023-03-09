#include <iostream>
#include <string>
#include <cctype>
#include "vigenere.h"

char shiftChar(char c, char key) {
  char output = c;
  int shift = 0;
  
  if (islower(key)) {
    shift = key - 'a';
  }
  else if (isupper(key)) {
    shift = key - 'A';
  }

  if (isalpha(c)) {
    if (isupper(c)) { // Range of A-Z is 65(A) to 90(Z)
      if ((c+shift) > 'Z') { // If out of bounds
        output = 'A' + (c+shift-'[');
      } else {
        output = c + shift;
      }
    } else if (islower(c)) { // Range of a-z is 97(a) to 122(z)
      if ((c + shift) > 'z') { // If out of bounds
        output = 'a' + (c+shift - '{');
      } else {
        output = c + shift;
      }
    }
  }
  return output;
}

std::string encryptVigenere(std::string plaintext, std::string keyword) {
  int keyIndex = 0;
  int max = keyword.length();
  for (int i = 0; i < plaintext.length(); i++) {
    if(isalpha(plaintext[i])) {
      plaintext[i] = shiftChar(plaintext[i], keyword[keyIndex]);
      keyIndex = (keyIndex + 1) % max;
    }
  }
  return plaintext;
}
