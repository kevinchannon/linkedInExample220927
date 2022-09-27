#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

size_t calculateItemCount(std::ifstream& file) {
  file.seekg(0, std::ifstream::end);
  auto byteCount = file.tellg();
  file.seekg(0);

  return (byteCount / 9) + (byteCount % 9 != 0 ? 1 : 0);
}

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

    auto nombre = calculateItemCount(myReadFile);

    auto strMots7 = std::vector<std::string>(nombre, std::string{});
    myReadFile.seekg(0);

    int i = 0;
    while (getline(myReadFile, myText)) {
      strMots7[i] = myText;
      i++;
    }

    std::cout << strMots7[i - 1] << std::endl;
    std::cout << "Fin";
    
    return 0;
}
