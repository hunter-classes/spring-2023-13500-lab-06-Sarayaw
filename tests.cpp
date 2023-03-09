#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caeser.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here
TEST_CASE("Caesar Cipher Theory Tests") {
  SUBCASE("Basic") {
    CHECK(encryptCaesar("ur lying!", 2) == "ur lying!");  
  }
}

TEST_CASE("Decrypt Caesar Cipher Theory Tests") {
  SUBCASE("Basic") {
    CHECK(decryptCaesar("stop it", 2) == "stop it");
  }
}

TEST_CASE("Vigenere Cipher Theory Tests") {
  SUBCASE("Basic") {
    CHECK(encryptVigenere("Hello, World!", "CAKE") == "Jevpq, Wyvnd!");

  }
}

TEST_CASE("Decrypt Vigenere Cipher Theory Tests") {
  SUBCASE("Basic") {
    CHECK(decryptVigenere("Jevpq, Wyvnd!","cake") == "Hello, World!");
  }

}
