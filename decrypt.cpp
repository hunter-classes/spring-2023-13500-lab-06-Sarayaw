#include <iostream>
#include <string>
#include <cctype>
#include "decrypt.h"

std::string decryptCaesar(const std::string& ciphertext, int rshift) {
  std::string plaintext;
  for (char c : ciphertext) {
    plaintext += decryptCaesarChar(c, rshift);
  }
  return plaintext;
}

std::string decryptVigenere(const std::string& ciphertext, const std::string& keyword) {
  std::string plaintext;
  int key = 0;
  int max = keyword.length();
  for (char c : ciphertext) {
    if (isalpha(c)) {
      plaintext += decryptVigenereChar(c, keyword[key]);
      key = (key + 1) % max;
    } else {
      plaintext += c;
    }
  }
  return plaintext;
}

char decryptCaesarChar(char c, int rshift) {
  if (!isalpha(c)) { //return the same character if it is not a letter
    return c;
  }
  if (isupper(c)) { //Range of A-Z is 65(A) to 90(Z)
    c = (c - rshift - 'A' + 26) % 26 + 'A'; //Modulus is used to wrap around alphabet
  } else if (islower(c)) { //Range of a-z is 97(a) to 122(z)
    c = (c - rshift - 'a' + 26) % 26 + 'a'; //Modulus is used to wrap around alphabet
  }
  return c;
}

char decryptVigenereChar(char c, char key) {
  if (!isalpha(c)) { //return the same character if it is not a letter
    return c;
  }
  int shift = tolower(key) - 'a';
  if (isupper(c)) { //Range of A-Z is 65(A) to 90(Z)
    c = (c - shift - 'A' + 26) % 26 + 'A'; //Modulus is used to wrap around alphabet
  } else if (islower(c)) { //Range of a-z is 97(a) to 122(z)
    c = (c - shift - 'a' + 26) % 26 + 'a'; //Modulus is used to wrap around alphabet
  }
  return c;
}
