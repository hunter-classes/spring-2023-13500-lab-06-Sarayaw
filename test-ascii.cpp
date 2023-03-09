#include <iostream>
#include <cctype>
#include <string>

std::string convert(const std::string& str) {
  std::string output;
  for(const auto& c : str) {
    output += c;
    output += "\t";
    output += std::to_string(static_cast<int>(c));
    output += "\n";
  }
  return output;
}

int main() {
  std::cout << "Test 1\n";
  std::cout << convert("Hello World") << '\n';
  
  std::cout << "Test 2\n";
  std::cout << convert("I have to study") << '\n';
  
  std::cout << "Test 3\n";
  std::cout << convert("i want to sleep") << '\n';

  return 0;
}
