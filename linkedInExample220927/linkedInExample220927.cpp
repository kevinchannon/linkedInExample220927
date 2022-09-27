#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

    std::string myText;
    std::ifstream MyReadFile("c:\\Jeux\\AJL\\D7.txt");
    if ((MyReadFile.rdstate() & std::ifstream::failbit)) {
      std::cout << "Error opening 'C:\\Jeux\\AJL\\D7.txt'\n";
      return 1;
    }

    MyReadFile.seekg(0, MyReadFile.end);
    int nombre = (int)(ceil)((double)(unsigned long int)MyReadFile.tellg() / 9.);
    std::string* strMots7 = new std::string[nombre];
    MyReadFile.seekg(0);

    int i = 0;
    while (getline(MyReadFile, myText)) {
      strMots7[i] = myText;
      i++;
    }

    std::cout << strMots7[i - 1] << std::endl;
    
    MyReadFile.close();
    delete[] strMots7;
    std::cout << "Fin";
    
    return 0;
}
