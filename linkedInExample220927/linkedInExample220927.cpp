#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello World!\n";
    string myText;
    ifstream MyReadFile("c:\\Jeux\\AJL\\D7.txt");
    if ((MyReadFile.rdstate() & ifstream::failbit))
      cout << "Error opening 'C:\\Jeux\\AJL\\D7.txt'\n";
    MyReadFile.seekg(0, MyReadFile.end);
    int nombre = (int)(ceil)((double)(unsigned long int)MyReadFile.tellg() / 9.);
    string* strMots7 = new string[nombre];
    MyReadFile.seekg(0);
    int i = 0;
    while (getline(MyReadFile, myText)) {
      strMots7[i] = myText;
      i++;
    }
    cout << strMots7[i - 1] << endl;
    MyReadFile.close();
    delete[] strMots7;
    cout << "Fin";
}
