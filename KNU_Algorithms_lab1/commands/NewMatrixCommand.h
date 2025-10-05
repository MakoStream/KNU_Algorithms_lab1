#pragma once
#include "../Executor/Command.h"
#include <iostream>
#include "../matrix.h"
#include "../basic_functions.h"

class NewMatrixCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		if (args.size() < 2) {
			std::cout << "Usage: newMatrix <name>\n";
			return;
		};
		MatrixData matrix;
		collections.push_back({args[1], matrix.copy()});
	}

	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "newMatrix";
	}
};