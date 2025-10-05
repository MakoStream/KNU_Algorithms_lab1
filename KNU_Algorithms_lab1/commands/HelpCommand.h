#pragma once
#include "../Executor/Command.h"
#include <iostream>

class HelpCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		std::cout << "Available commands:\n";
		std::cout << "help - show all commands\n";
    }

	std::string name() const override { // the name of the command. Required for command manager to identify the command
        return "help";
    }
};