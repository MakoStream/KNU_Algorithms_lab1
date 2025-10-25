#pragma once
#include "../Executor/Command.h"
#include <iostream>
#include "../basic_functions.h"
#include "../functions/strassen.h"
#include "../functions/gauss_jordan.h"
#include "../functions/liniar_regression.h"

class FuncCommand : public Command {

public:
	void execute(const std::vector<std::string>& args) override { // here we will implement the logic of the command
		

		string matrix_name;
		MatrixData* result = nullptr;
		if (args[1] == "strassen") { // func <function_name(strassen)> <matrix_1_name> <matrix_2_name> <save_into_name>
			if (args.size() < 5) { return; };
			MatrixData* matrix1 = nullptr;
			MatrixData* matrix2 = nullptr;
			for (auto& a : collections) {
				if (a.name == args[2]) {
					matrix1 = a.matrix;
					break;
				}
			}
			for (auto& a : collections) {
				if (a.name == args[3]) {
					matrix2 = a.matrix;
					break;
				}
			}
			if (!matrix1 || !matrix2) {
				cerr << "Error: one of the matrices not found" << endl;
				return;
			}
			//matrix1->show(); matrix2->show();
			matrix_name = args[4];
			result = new MatrixData(strassenMultiply(*matrix1, *matrix2));
			result->show();
		}
		else if (args[1] == "gauss_jordan") { // func <function_name(gauss_jordan)> <matrix_name> <save_into_name>
			if (args.size() < 4) { return; };
			for (const auto& a : collections) {
				if (a.name == args[2]) {
					result = a.matrix;
					break;
				}
			}
			matrix_name = args[3];
			gaussJordanMethod(*result);
			result->show();
		}
		else if (args[1] == "liniar_regression") { // func <function_name(liniar_regression)> <matrix_1_name> <matrix_2_name> <save_into_name>
			if (args.size() < 5) { return; };
			MatrixData matrix1(false);
			MatrixData matrix2(false);
			for (const auto& a : collections) {
				if (a.name == args[2]) {
					matrix1 = a.matrix;
					break;
				}
			}
			for (const auto& a : collections) {
				if (a.name == args[3]) {
					matrix2 = a.matrix;
					break;
				}
			}
			matrix_name = args[4];
			//result = liniarRegression(matrix1, matrix2);
		};
		collections.push_back({ matrix_name, result });
		cout << "debug 3" << endl;
		return;
	};
	std::string name() const override { // the name of the command. Required for command manager to identify the command
		return "func";
	}
};