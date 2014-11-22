#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

string tempFileName = "wic_temp_file.cc";

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
  ifstream file;
  ofstream out(tempFileName);
  if (argc < 2) {
    cerr << "ERROR: No input file specified." << endl;
    return 0;
  }
  file.open(argv[1]);
  if (file.is_open()) {
    string line;
    int lineNum = 0;
    while (getline(file, line)) {
      lineNum++;
      if (line == "") continue;
      line = ummRemover(line); //ignore comments
      vector<string> tokens = splitString(line); //tokenize with space as delimiter

      //INCLUDE
      if (tokens.size() > 3 && tokens.at(0) == "DO" && tokens.at(1) == "I" &&
          tokens.at(2) == "NEED") {
        out << "#include <" << tokens.at(3) << ">" << endl;
      }
      //DECLARATION
      else if (tokens.size() > 5 && tokens.at(0) == "I" && tokens.at(1) == "NEED" &&
          tokens.at(2) == "A" && tokens.at(4) == "CALLED") {
        out << tokens.at(3) << " " << tokens.at(5) << ";" << endl;
      }
      //ASSIGNMENT
      else if (tokens.size() > 3 && tokens.at(1) == "SHOULD" && tokens.at(2) == "BE") {
        out << tokens.at (0) << " = ";
        for (int i = 3; i < tokens.size(); i++) {
          out << tokens.at(i) << " ";
        }
        out << ";" << endl;
      }
      //INPUT
      else if (tokens.size() > 2 && tokens.at(0) == "ASK" && tokens.at(1) == "ABOUT") {
        out << "std::cin >> " << tokens.at(2)  << ";" << endl;
      }
      //OUTPUT
      else if (tokens.size() > 2 && tokens.at(0) == "SHOW" && tokens.at(1) == "ME") {
        out << "std::cout << ";
        for (int i = 2; i < tokens.size(); i++) {
          out << tokens.at(i) << " ";
        }
        out << " << std::endl;" << endl;
      }
      //WHILE
      else if (tokens.size() == 3 && tokens.at(0) == "WATER" && tokens.at(1) == "WATER" && tokens.at(2) == "WATER") {
        out << "while (true) {" << endl;
      }
      //BREAK
      else if (tokens.size() == 3 && tokens.at(0) == "RUN" && tokens.at(1) == "FROM" && tokens.at(2) == "GEESE") {
        out << "break;" << endl;
      }
      //END LOOP
      else if (tokens.size() == 3 && tokens.at(0) == "LOOP" && tokens.at(1) == "LOOP" && tokens.at(2) == "LOOP") {
        out << "}" << endl;
      }
      //FUNCTION DECLARATION
      else if (tokens.size() > 3 && tokens.at(1) == "FINDS" && tokens.at(2) == "A") {
        if (tokens.size() > 4 && tokens.at(4) == "FROM" && tokens.at(5) == "A" && tokens.at(7) == "CALLED") {
          out << tokens.at(3) << " " << tokens.at(0) << "(";
          for (int i = 4; i < tokens.size(); i+= 5) {
            out << tokens.at(i + 2) << " " << tokens.at(i + 4);
            if (i + 5 < tokens.size()) {
              out << ", ";
            }
          }
          out << ") {" << endl;
        }
        else {
          out << tokens.at(3) << " " << tokens.at(0) << "() {" << endl;
        }
      }
      //FUNCTION END
      else if (tokens.size() > 1 && tokens.at(0) == "PLEASE" && tokens.at(1) == "WORK") {
        out << "}" << endl;
      }
      //IF
      else if (tokens.size() > 2 && tokens.at(0) == "I" && tokens.at(1) == "THINK") {
        out << "if (";
        for (int i = 2; i < tokens.size(); i++) {
          out << tokens.at(i) << " ";
        }
        out << ") {" << endl;
      }
      //ELSE IF
      else if (tokens.size() > 2 && tokens.at(0) == "OR" && tokens.at(1) == "MAYBE") {
        out << "} else if (";
        for (int i = 2; i < tokens.size(); i++) {
          out << tokens.at(i) << " ";
        }
        out << ") {" << endl;
      }
      //ELSE
      else if (tokens.size() == 2 && tokens.at(0) == "I" && tokens.at(1) == "LIED") {
        out << "} else {" << endl;
      }
      //END IF
      else if (tokens.size() == 1 && tokens.at(0) == "RIGHT?") {
        out << "}" << endl;
      }
      //RETURN
      else if (tokens.size() > 2 && tokens.at(0) == "I" && tokens.at(1) == "CALCULATED") {
        out << "return ";
        for (int i = 2; i < tokens.size(); i++) {
          out << tokens.at(i) << " ";
        }
        out << ";" << endl;
      }
      else {
        // Anything else (function call)
        out << line << ";" << endl;
      }
    }
  }
  else {
    cerr << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  out.close();
  return 0;
}
