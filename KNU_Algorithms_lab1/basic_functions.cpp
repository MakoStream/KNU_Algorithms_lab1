#include "basic_functions.h"

vector<string> split(const string& input) {
	vector<string> tokens;
	istringstream iss(input);
	string word;
	while (iss >> word) {
		tokens.push_back(word);
	};
	return tokens;
};


vector<double> split_d(const string& input) {
	vector<double> tokens;
	istringstream iss(input);
	string word;
	while (iss >> word) {
		tokens.push_back(stod(word));
	};
	return tokens;
};

void SaveMatrixToFile(const MatrixData& matrix, const string& filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Could not open file " << filename << " for writing." << endl;
		return;
	}
	file << matrix.m << " " << matrix.n << "\n";
	for (int i = 0; i < matrix.m; i++) {
		for (int j = 0; j < matrix.n; j++) {
			file << matrix.matrix[i][j];
			if (j < matrix.n - 1) file << " ";
		}
		file << "\n";
	}
	file.close();
};

MatrixData LoadMatrixFromFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Could not open file " << filename << " for reading." << endl;
		return MatrixData();
	}

	int m, n;
	file >> m >> n;
	MatrixData matrix(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			file >> matrix.matrix[i][j];
		}
	}
	file.close();
	return matrix;
};