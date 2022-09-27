#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////////////////

constexpr auto fileWordLength = 7u;
constexpr auto lineEndingLength = 2u;
constexpr auto lineLength = fileWordLength + lineEndingLength;

///////////////////////////////////////////////////////////////////////////////

size_t calculateItemCount(std::ifstream& file) {
  file.seekg(0, std::ifstream::end);
  auto byteCount = file.tellg();
  file.seekg(0);

  return (byteCount / lineLength) + (byteCount % lineLength != 0 ? 1 : 0);
}

///////////////////////////////////////////////////////////////////////////////

std::vector<std::string> readItemsFromFile(std::ifstream& file) {
  auto out =
      std::vector<std::string>(calculateItemCount(file), std::string(7, '\0'));

  std::ranges::for_each(out, [&file](auto&& word) {
    file.read(word.data(), fileWordLength)
        .seekg(lineEndingLength, std::ifstream::cur);
  });

  return out;
}

///////////////////////////////////////////////////////////////////////////////

int main() {
  std::cout << "Hello World!\n";

  constexpr auto fileName = R"(c:\Jeux\AJL\D7.txt)";

  std::ifstream myReadFile(fileName);
  if (not myReadFile.is_open()) {
    std::cout << "Error opening '" << fileName << "'\n";
    return 1;
  }

  const auto strMots7 = readItemsFromFile(myReadFile);
  std::cout << strMots7.back() << std::endl;

  std::cout << "Fin";

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
