#include <iostream>
#include "basic_functions.h"
#include "matrix.h"

// test commit

using namespace std;


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
	MatrixData currentMatrix(3, 3, 1);
	currentMatrix.show();

	while (true) {
		std::string input;
		
		cout << "> ";
		getline(cin, input);
		if (input.empty()) continue;
		vector<string> args = split(input);

	
	};
	return 0;
}