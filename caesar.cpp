#include <iostream>
#include <string>
#include <cctype>
#include "vigenere.h"

char shiftChar(char c, char key) {
  int shift;
  if (islower(key)) {
    shift = key - 'a';
  }
  else if (isupper(key)) {
    shift = key - 'A';
  }
  else {
    return c;
  }

  if (isupper(c)) {
    c = (c - 'A' + shift) % 26 + 'A';
  }
  else if (islower(c)) {
    c = (c - 'a' + shift) % 26 + 'a';
  }
  return c;
}

std::string encryptVigenere(const std::string& plaintext, const std::string& keyword) {
  std::string ciphertext;
  int keyIndex = 0;
  for (char c : plaintext) {
    if (isalpha(c)) {
      ciphertext += shiftChar(c, keyword[keyIndex]);
      keyIndex = (keyIndex + 1) % keyword.length();
    }
    else {
      ciphertext += c;
    }
  }
  return ciphertext;
}
