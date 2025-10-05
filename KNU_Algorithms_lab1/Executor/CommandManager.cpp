#include "CommandManager.h"
#include <iostream>
// include command headers here
#include "../commands/HelpCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/CollectionCommad.h"
#include "../commands/NewMatrixCommand.h"
#include "../commands/SaveMatrixCommand.h"
#include "../commands/ShowMatrixCommand.h"
#include "../commands/LoadMatrixCommand.h"
//======================

	// Some commands:
	// help - show all commands (+)
	// exit - exit the program
	// load <filename> - load a file *.mtx with a matrix
	// save <filename> - save the current matrix to a file *.mtx
	// print - print the current matrix
	// add <filename> - add a matrix from a file *.mtx to the current matrix
	// func <function> - apply a function to the current matrix (functions: #MUST BE HERE#)


CommandsManager::CommandsManager() {
	// Here you can register all your commands after including their headers from the "commands" folder (../commands/<header_name>) // Makar
		// Example:
		// commands.push_back(std::make_unique<HelpCommand>());
		// commands.push_back(std::make_unique<ExitCommand>());
		// commands.push_back(std::make_unique<LoadCommand>());

    commands.push_back(std::make_unique<HelpCommand>());
	commands.push_back(std::make_unique<ExitCommand>());
	commands.push_back(std::make_unique<CollectionCommand>());
	commands.push_back(std::make_unique<NewMatrixCommand>());
	commands.push_back(std::make_unique<SaveMatrixCommand>());
	commands.push_back(std::make_unique<ShowMatrixCommand>());
	commands.push_back(std::make_unique<LoadMatrixCommand>());

}

void CommandsManager::execute(std::string& cmdName, std::vector<std::string>& args) {
    for (auto& cmd : commands) {
        if (cmd->name() == cmdName) {
            cmd->execute(args);
            return;
        }
    }
    std::cout << "Невідома команда: " << cmdName << "\n";
}