#pragma once
#include "../Executor/Command.h"
#include <iostream>
#include "../basic_functions.h"

class CollectionCommand : public Command {
	vector<Collection> collections;

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		if (collections.size() < 1) {
			cout << "No collections available.\n";
			return;
		};
		cout << "Collection of matrix:\n";
		for (const auto& a : collections) {
			cout << a.name << " ("<<a.matrix.n << "x" << a.matrix.m << "\n";
		};
		return;
	}

	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "collection";
	}
};