#include <iostream>
#include <string>

int main()
{
    // Variable to store user's name
    std::string name;
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Display greeting
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
