#include <iostream>
#include <stdexcept>
using namespace std;

struct MatrixData {
    double** matrix;
    int m;
    int n;

    MatrixData(int m, int n);
    MatrixData();
    ~MatrixData();

    void show() const;
    void fillExtendedMatrix();
    void multiplyRowByNumber(int rowNumber, double number);
    void substractRow(int row1, int row2, double factor);

};

MatrixData::MatrixData(int m, int n) {
    if (m <= 1 || n <= 1) {
        cerr << "Error: Matrix dimensions must be greater than 1." << endl;
        exit(1);
    }

    this->m = m;
    this->n = n;

    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }
}

// Contructor without parameters + validation
MatrixData::MatrixData() {
    do {
        cout << "Matrix rows (must be > 1): ";
        cin >> m;
        cout << "Matrix columns (must be > 1): ";
        cin >> n;

        if (m <= 1 || n <= 1) {
            cout << "Error: Both dimensions must be greater than 1. Try again.\n";
        }
    } while (m <= 1 || n <= 1);

    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
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
