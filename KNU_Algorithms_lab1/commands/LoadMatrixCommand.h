#pragma once

#include "../Executor/Command.h"
#include "../basic_functions.h"
#include "../matrix.h"


class LoadMatrixCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		if (args.size() < 3) {
			std::cout << "Usage: loadMatrix <name> <filename>\n";
			return;
		};
		MatrixData matrix = LoadMatrixFromFile(args[2]);
		cout << matrix.m << "x" << matrix.n << endl;
		if (matrix.n == 0 || matrix.m == 0) {
			std::cout << "Failed to load matrix from " << args[2] << ".mtrx\n";
			return;
		};
		collections.push_back({ args[1], matrix.copy() });
	}

	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "loadMatrix";
	}
};