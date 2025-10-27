#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;


struct MatrixData {
    double** matrix;
    int m;
    int n;

    MatrixData(int m, int n);

    MatrixData(int m, int n, int protocol); // for making filled matrix with numbers // Makar
    MatrixData(int code); // used if something gone wrong in gauss-gordan method (Mykola) 
    MatrixData();
    ~MatrixData();
	MatrixData(bool empty); // for making empty matrix // Makar

    
    void show() const;
    MatrixData extendMatrix();
    MatrixData getInverseMatrix();//(Mykola)
    void multiplyRowByNumber(int rowNumber, double number);
    void substractRow(int row1, int row2, double factor);
	MatrixData transpose() const;//Added const to fix an error (Mykola)
	MatrixData* copy();
    MatrixData copy_full();

    MatrixData(const MatrixData& other) {
        m = other.m;
        n = other.n;
        matrix = new double* [m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new double[n];
            for (int j = 0; j < n; j++)
                matrix[i][j] = other.matrix[i][j];
        }
    }

    MatrixData& operator=(const MatrixData& other) {
        if (this == &other) return *this;
        for (int i = 0; i < m; i++)
            delete[] matrix[i];
        delete[] matrix;

        m = other.m;
        n = other.n;
        matrix = new double* [m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new double[n];
            for (int j = 0; j < n; j++)
                matrix[i][j] = other.matrix[i][j];
        }
        return *this;
    };


};
