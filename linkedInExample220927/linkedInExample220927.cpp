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
constexpr auto fileName = R"(c:\Jeux\AJL\D7.txt)";

///////////////////////////////////////////////////////////////////////////////

inline void readFileAndPrintFinalLine(std::ifstream& file);
inline std::vector<std::string> readItemsFromFile(std::ifstream& file);
inline size_t calculateItemCount(std::ifstream& file);

///////////////////////////////////////////////////////////////////////////////

int main() {
  std::cout << "Hello World!\n";

  std::ifstream myReadFile(fileName);
  if (not myReadFile.is_open()) {
    std::cout << "Error opening '" << fileName << "'\n";
    return 1;
  }

  readFileAndPrintFinalLine(myReadFile);

  std::cout << "Fin";

  return 0;
}

///////////////////////////////////////////////////////////////////////////////

void readFileAndPrintFinalLine(std::ifstream& file) {
  const auto strMots7 = readItemsFromFile(file);
  if (strMots7.empty()) {
    return;
  }

  std::cout << strMots7.back() << std::endl;
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

size_t calculateItemCount(std::ifstream& file) {
  file.seekg(0, std::ifstream::end);
  auto byteCount = file.tellg();
  file.seekg(0);

  return (byteCount / lineLength) + (byteCount % lineLength != 0 ? 1 : 0);
}

///////////////////////////////////////////////////////////////////////////////
