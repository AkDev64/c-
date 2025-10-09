#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string str = "Welcome to GeeksForGeeks";
  // string str2 = "1 bobo olhando outro que só olha de volta";
  //  Open a binary file for writing
  ofstream file("fileBin.bin", ios::binary);

  // Check if the file is open
  if (!file) {
    cerr << "Error opening the file for writing.";
    return 1;
  }

  // Write the length of the string (size) to file first
  size_t strLength = str.length();
  // size_t strLength2 = str2.length();
  // file.write(reinterpret_cast<const char *>(&strLength), sizeof(strLength));
  // file.write(reinterpret_cast<const char *>(&strLength2),
  // sizeof(strLength2));

  // Write the string to the binary file
  file.write(str.c_str(), strLength);
  // file.write(str2.c_str(), strLength2);

  // Close the file
  file.close();

  return 0;
}
