#pragma once
#include "../Executor/Command.h"
#include <iostream>

class ExitCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		exit(0);
	}

	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "exit";
	}
};