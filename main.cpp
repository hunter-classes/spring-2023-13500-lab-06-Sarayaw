#include <iostream>
#include "caeser.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  std::cout << "Looking at a computer screen to long can hurt your head.\n";
  (encryptCaesar("ur lying!", 2) == "ur lying!"); ? std::cout << "-> Success!\n"  : std::cout << "-> Failed\n";

  return 0;
}
