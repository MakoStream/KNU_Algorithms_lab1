#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// test commit

using namespace std;

vector<string> split(const string& input) {
	vector<string> tokens;
	istringstream iss(input);
	string word;
	while (iss >> word) {
		tokens.push_back(word);
	};
	return tokens;
};

int main() {
	setlocale(LC_ALL, "ukr");
	// Some commands:
	// help - show all commands
	// exit - exit the program
	// load <filename> - load a file *.mtx with a matrix
	// save <filename> - save the current matrix to a file *.mtx
	// print - print the current matrix
	// add <filename> - add a matrix from a file *.mtx to the current matrix
	// func <function> - apply a function to the current matrix (functions: #MUST BE HERE#)
	while (true) {
		std::string input;
		
		cout << "> ";
		getline(cin, input);
		if (input.empty()) continue;
		vector<string> args = split(input);

	
	};
	return 0;
}