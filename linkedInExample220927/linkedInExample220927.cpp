#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

    constexpr auto fileName = R"(c:\Jeux\AJL\D7.txt)";

    std::string myText;
    std::ifstream myReadFile(fileName);
    if (myReadFile.is_open()) {
      std::cout << "Error opening '" << fileName << "'\n";
      return 1;
    }

    myReadFile.seekg(0, myReadFile.end);
    int nombre = (int)(ceil)((double)(unsigned long int)myReadFile.tellg() / 9.);
    auto strMots7 = std::vector<std::string>(nombre, std::string{});
    myReadFile.seekg(0);

    int i = 0;
    while (getline(myReadFile, myText)) {
      strMots7[i] = myText;
      i++;
    }

    std::cout << strMots7[i - 1] << std::endl;
    
    myReadFile.close();
    std::cout << "Fin";
    
    return 0;
}
