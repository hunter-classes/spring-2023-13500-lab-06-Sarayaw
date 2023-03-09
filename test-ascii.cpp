#include <iostream>
#include <string>

void asciiValue()
{
    std::string sentence;                      
    std::cout << "Input" << std::endl;          
    getline(std::cin, sentence);                

    for (char c : sentence)                      
    {
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }
}

int main()
{
    asciiValue();
    return 0;
}
