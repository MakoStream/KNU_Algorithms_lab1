#include "matrix.h"
#include "basic_functions.h"


MatrixData::MatrixData(int m, int n) {
    if (m <= 0 || n <= 0) throw std::invalid_argument("Matrix size must be > 0");

    this->m = m;
    this->n = n;

    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }
    return;
}

MatrixData::MatrixData(bool empty) {
    m = 0;
    n = 0;
    matrix = nullptr;
}

// consgtructor with protocol for filling matrix with numbers + validation
MatrixData::MatrixData(int m, int n, int protocol) {
    this->m = m;
    this->n = n;

    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        vector<double> rowValues;
        while (true) {
            cout << "Filling row " << i << "> ";
            string tokens;
            getline(cin, tokens);

            rowValues = split_d(tokens);

            if (rowValues.size() != n) {
                cerr << "Error: Expected " << n << " values, but got " << rowValues.size() << ". Please re-enter the row." << endl;
            }
            else {
                break;
            }
        }

        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rowValues[j];
        }
    }
}

// Contructor without parameters + validation
MatrixData::MatrixData() {
    do {
        cout << "Matrix rows (must be >= 1): ";
        cin >> m;
        cout << "Matrix columns (must be >= 1): ";
        cin >> n;

        if (m <= 1 || n <= 1) {
            cout << "Error: Both dimensions must be greater than 0. Try again.\n";
        }
    } while (m <= 1 || n <= 1);

    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        vector<double> rowValues;
        while (true) {
            cout << "Filling row " << i << "> ";
            string tokens;
            getline(cin, tokens);

            rowValues = split_d(tokens);

            if (rowValues.size() != n) {
                cerr << "Error: Expected " << n << " values, but got " << rowValues.size() << ". Please re-enter the row." << endl;
            }
            else {
                break;
            }
        }

        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rowValues[j];
        }
    }
    return;
}



// Freeing consumed memory
MatrixData::~MatrixData() {
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Showing matrix
void MatrixData::show() const {
    for (int i = 0; i < m; i++) {
        cout << "| ";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "|\n";
    }
}

// Filling extended matrix (A | E)
void MatrixData::fillExtendedMatrix() {
    MatrixData extended(m, 2 * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            extended.matrix[i][j] = matrix[i][j];
        }
        for (int j = n; j < extended.n; j++) {
            extended.matrix[i][j] = (i == j - n) ? 1.0 : 0.0;
        }
    }
}

// Multiplying row by number
void MatrixData::multiplyRowByNumber(int rowNumber, double number) {
    for (int j = 0; j < n; j++) {
        matrix[rowNumber][j] *= number;
    }
}

// Substraction (row1 - factor * row2)
void MatrixData::substractRow(int row1, int row2, double factor) {
    for (int j = 0; j < n; j++) {
        matrix[row1][j] -= factor * matrix[row2][j];
    }
}


MatrixData MatrixData::transpose() {
    MatrixData transposed(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed.matrix[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

MatrixData* MatrixData::copy() {
	MatrixData* copied = new MatrixData(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			copied->matrix[i][j] = matrix[i][j];
		}
	}
	return copied;
}

MatrixData MatrixData::copy_full() {
    MatrixData copied(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            copied.matrix[i][j] = matrix[i][j];
        }
    }
    return copied;
}