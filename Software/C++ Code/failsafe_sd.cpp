// g++ -o <name-you-want-to-give> source.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

void writeFile(void){
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "2015,2552;2016,5212;2017,5821,2018,5319;2019,5819;2020,644;2021,107;2022,45";
  myfile.close();
}

string readFile(void){
  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("example.txt");
  string raw;
  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    raw = myText;
  }

  cout << raw << endl;

  // Close the file
  MyReadFile.close();
  return raw;
}


char *result[] splitPoints(string raw){
  int n = raw.length();

  // declaring character array
  char myString[n + 1];

  // copying the contents of the
  // string to char array
  strcpy(myString, raw.c_str());
  char *answers[8];
  char *p = strtok(myString, ";");
  int i = 0;
  while (p) {
      printf ("Token: %s\n", p);
      answers[i] = p;
      i++;
      p = strtok(NULL, ";");
  }
  cout << answers;
  return answers;
}

int main () {
  string raw_data = readFile();
  char *points[] = splitPoints(raw_data);
  return 0;
}