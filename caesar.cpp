#include <iostream>
#include <string>
#include <cctype>

char shiftChar(char c, int rshift)
{
    if (std::isupper(c))
    {
        c = ((c - 'A' + rshift) % 26) + 'A';
    }
    else if (std::islower(c))
    {
        c = ((c - 'a' + rshift) % 26) + 'a';
    }
    return c;
}

std::string caesarCipher(int shift, const std::string& sentence)
{
    std::string newSentence;
    for (char c : sentence)
    {
        if (std::isalpha(c))
        {
            newSentence += shiftChar(c, shift);
        }
        else
        {
            newSentence += c;
        }
    }
    return newSentence;
}

int main()
{
    std::cout << caesarCipher(7, "Abcd Efg") << '\n';
    return 0;
}
