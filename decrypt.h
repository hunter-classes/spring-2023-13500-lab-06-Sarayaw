#pragma once

char decryptCaesarChar(char c, int rshift);

char decryptVigenereChar(char c, char key);

std::string decryptCaesar(std::string ciphertext, int rshift);

std::string decryptVigenere(std::string ciphertext, std::string keyword);
