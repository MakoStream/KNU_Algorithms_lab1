#include <iostream>
#include "basic_functions.h"
#include "matrix.h"
#include "Executor/CommandManager.h"

CommandsManager commandManager;

using namespace std;


int main() {
	setlocale(LC_ALL, "ukr");
	// Some commands:
	// help - show all commands
	// exit - exit the program
	// collection - show all collections
	// newMatrix <name> - create new matrix with name
	// showMatrix <name> - show matrix with name
	// loadMatrix <name> <filename> - load matrix from file
	// saveMatrix <name> <filename> - save matrix to file

	while (true) {
		std::string input;
		
		cout << "> ";
		getline(cin, input);
		if (input.empty()) continue;
		vector<string> args = split(input);
		commandManager.execute(args[0], args);
	
	};
	return 0;
}