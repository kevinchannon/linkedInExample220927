#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

constexpr auto fileWordLength = 7u;
constexpr auto lineEndingLength = 2u;
constexpr auto lineLength = fileWordLength + lineEndingLength;

size_t calculateItemCount(std::ifstream& file) {
  file.seekg(0, std::ifstream::end);
  auto byteCount = file.tellg();
  file.seekg(0);

  return (byteCount / lineLength) + (byteCount % lineLength != 0 ? 1 : 0);
}

int main() {
  std::cout << "Hello World!\n";

  constexpr auto fileName = R"(c:\Jeux\AJL\D7.txt)";

  std::ifstream myReadFile(fileName);
  if (myReadFile.is_open()) {
    std::cout << "Error opening '" << fileName << "'\n";
    return 1;
  }

  auto strMots7 = std::vector<std::string>(calculateItemCount(myReadFile));

  std::string myText;
  std::ranges::generate(strMots7, [&myReadFile, &myText]() {
    std::getline(myReadFile, myText);
    return myText;
  });

  std::cout << strMots7.back() << std::endl;

  std::cout << "Fin";

  return 0;
}
