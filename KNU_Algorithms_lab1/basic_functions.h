#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "matrix.h"

using namespace std;

struct Collection {
	string name;
	MatrixData* matrix;
};

extern vector<Collection> collections;

vector<string> split(const string& input);
vector<double> split_d(const string& input);
void SaveMatrixToFile(const MatrixData& matrix, const string& filename);
MatrixData LoadMatrixFromFile(const string& filename);
MatrixData* selectMatrixByName(const string& name);