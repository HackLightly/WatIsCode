#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


vector<string> splitString (string input) {
  istringstream iss(input);
  vector<string> tokens;
  copy(istream_iterator<string>(iss),
      istream_iterator<string>(),
      back_inserter(tokens));
  return tokens;
}

string ummRemover (string line) {
  int found = line.find("UMM");
  if (found != string::npos) {
    line = line.substr(0, found);
  }
  return line;
}

int main (int argc, char* argv[]) {
  string line;
  int lineNum = 0;
  try {
    while (getline(cin, line)) {
      lineNum++;
      if (line == "") continue;
      line = ummRemover(line); //ignore comments
      vector<string> tokens = splitString(line); //tokenize with space as delimiter

      //INCLUDE
      if (tokens.size() > 3 && tokens.at(0) == "DO" && tokens.at(1) == "I" &&
          tokens.at(2) == "NEED") {
        cout << "#include <" << tokens.at(3) << ">" << endl;
      }
      //DECLARATION
      else if (tokens.size() > 5 && tokens.at(0) == "I" && tokens.at(1) == "NEED" &&
          tokens.at(2) == "A" && tokens.at(4) == "CALLED") {
        cout << tokens.at(3) << " " << tokens.at(5) << ";" << endl;
      }
      //ASSIGNMENT
      else if (tokens.size() > 3 && tokens.at(1) == "SHOULD" && tokens.at(2) == "BE") {
        cout << tokens.at (0) << " = ";
        for (int i = 3; i < tokens.size(); i++) {
          cout << tokens.at(i) << " ";
        }
        cout << ";" << endl;
      }
      //INPUT
      else if (tokens.size() > 2 && tokens.at(0) == "ASK" && tokens.at(1) == "ABOUT") {
        cout << "std::cin >> " << tokens.at(3)  << ";" << endl;
      }
      //OUTPUT
      else if (tokens.size() > 2 && tokens.at(0) == "SHOW" && tokens.at(1) == "ME") {
        cout << "std::cout << ";
        for (int i = 2; i < tokens.size(); i++) {
          cout << tokens.at(i) << " ";
        }
        cout << " << std::endl;" << endl;
      }
      //WHILE
      else if (tokens.size() == 3 && tokens.at(0) == "WATER" && tokens.at(1) == "WATER" && tokens.at(2) == "WATER") {
        cout << "while (true) {" << endl;
      }
      else if (tokens.size() == 3 && tokens.at(0) == "RUN" && tokens.at(1) == "FROM" && tokens.at(2) == "GEESE") {
        cout << "break;" << endl;
      }
      else if (tokens.size() == 3 && tokens.at(0) == "LOOP" && tokens.at(1) == "LOOP" && tokens.at(2) == "LOOP") {
        cout << "}" << endl;
      }
      //FUNCTION DECLARATION
      else if (tokens.size() > 3 && tokens.at(1) == "FINDS" && tokens.at(2) == "A") {
        if (tokens.size() > 4 && tokens.at(4) == "FROM" && tokens.at(5) == "A" && tokens.at(7) == "CALLED") {
          cout << tokens.at(3) << " " << tokens.at(0) << "(";
          for (int i = 4; i < tokens.size(); i+= 5) {
            cout << tokens.at(i + 2) << " " << tokens.at(i + 4);
            if (i + 5 < tokens.size()) {
              cout << ", ";
            }
          }
          cout << ") {" << endl;
        }
        else {
          cout << tokens.at(3) << " " << tokens.at(0) << "() {" << endl;
        }
      }
      //FUNCTION END
      else if (tokens.size() > 1 && tokens.at(0) == "PLEASE" && tokens.at(1) == "WORK") {
        cout << "}" << endl;
      }
      else {
        throw string(line);
      }
    }
  }

  catch (string &msg) {
    cerr << "ERROR: Line number " << lineNum << ": \"" << msg << "\" is unsupported." << endl;
  }
}

