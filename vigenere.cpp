#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"

// Shift the character by the given shift value, and wrap around the alphabet if necessary
char shiftKeyChar(char c, int &rshift) {
    if (isupper(c)) { // If the character is uppercase
        c = c + rshift; // Shift the character's value by the shift value
        if (c > 'Z') { // If the character's ASCII value is greater than 'Z' after the shift
            c = c - 'Z' + 'A' - 1; // Wrap around the alphabet
        }
    } else if (islower(c)) { // If the character is lowercase
        c = c + rshift; // Shift the character's ASCII value by the shift value
        if (c > 'z') { // If the character's ASCII value is greater than 'z' after the shift
            c = c - 'z' + 'a' - 1; // Wrap around the alphabet
        }
    }
    return c;
}

// Encrypt the plaintext using the Vigenere cipher with the given keyword
std::string encryptVigenere(const std::string& plaintext, const std::string& keyword) {
    std::string newSent;
    int keyIndex = 0;
    for (char c : plaintext) { // Loop through each character in the plaintext
        if (isalpha(c)) { // If the character is a letter
            char shifted = shiftKeyChar(c, keyword[keyIndex] - 'a'); // Shift the character by the corresponding shift value
            newSent += shifted; // Add the shifted character to the new sentence
            keyIndex = (keyIndex + 1) % keyword.length(); // Move to the next letter in the keyword
        } else {
            newSent += c; // If the character is not a letter, add it to the new sentence as is
        }
    }
    return newSent;
}

int main() {
    std::cout << encryptVigenere("ABCDEFGHI", "aabbcc") << std::endl;
    return 0;
}
