#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

    constexpr auto fileName = "c:\\Jeux\\AJL\\D7.txt";

    std::string myText;
    std::ifstream myReadFile(fileName);
    if (myReadFile.is_open()) {
      std::cout << "Error opening '" << fileName << "'\n";
      return 1;
    }

    myReadFile.seekg(0, myReadFile.end);
    int nombre = (int)(ceil)((double)(unsigned long int)myReadFile.tellg() / 9.);
    std::string* strMots7 = new std::string[nombre];
    myReadFile.seekg(0);

    int i = 0;
    while (getline(myReadFile, myText)) {
      strMots7[i] = myText;
      i++;
    }

    std::cout << strMots7[i - 1] << std::endl;
    
    myReadFile.close();
    delete[] strMots7;
    std::cout << "Fin";
    
    return 0;
}
