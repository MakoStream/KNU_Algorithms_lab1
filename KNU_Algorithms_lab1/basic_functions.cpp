#include "basic_functions.h"

std::vector<Collection> collections;

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
    ofstream file(filename + ".mtrx", ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << ".mtrx for writing." << endl;
        return;
    }

    // Спочатку записуємо розміри
    file.write(reinterpret_cast<const char*>(&matrix.m), sizeof(int));
    file.write(reinterpret_cast<const char*>(&matrix.n), sizeof(int));

    // Потім всі елементи рядок за рядком
    for (int i = 0; i < matrix.m; i++) {
        file.write(reinterpret_cast<const char*>(matrix.matrix[i]), sizeof(double) * matrix.n);
    }

    file.close();
}

MatrixData LoadMatrixFromFile(const string& filename) {
    ifstream file(filename + ".mtrx", ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << ".mtrx for reading." << endl;
        return MatrixData(true);; // порожня матриця
    }

    int m, n;
    file.read(reinterpret_cast<char*>(&m), sizeof(int));
    file.read(reinterpret_cast<char*>(&n), sizeof(int));

    MatrixData matrix(m, n);

    for (int i = 0; i < m; i++) {
        file.read(reinterpret_cast<char*>(matrix.matrix[i]), sizeof(double) * n);
    }
    //matrix.show();

    file.close();
    return matrix;
}

MatrixData* selectMatrixByName(const string& name) {
	for (auto& collection : collections) {
		if (collection.name == name) {
			return collection.matrix;
		};
	};
	return nullptr;
};