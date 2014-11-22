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
					cout << tokens.at(i);
				}
				cout << ";" << endl;
			}
			//INPUT
			else if (tokens.size() > 2 && tokens.at(0) == "ASK" && tokens.at(1) == "ABOUT") {
				cout << "cin >> " << tokens.at(3) << endl;
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

