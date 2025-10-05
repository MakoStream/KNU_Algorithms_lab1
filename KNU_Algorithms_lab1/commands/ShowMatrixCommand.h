#pragma once

#include "../Executor/Command.h"
#include "../basic_functions.h"


class ShowMatrixCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		if (args.size() < 2) {
			std::cout << "Usage: showMatrix <name>\n";
			return;
		};
		for (const auto& a : collections) {
			if (a.name == args[1]) {
				a.matrix->show();
				return;
			}
		}
		std::cout << "Matrix with name " << args[1] << " not found.\n";
		return;
	}

	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "showMatrix";
	}
};