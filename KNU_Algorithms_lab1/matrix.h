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
    MatrixData();
    ~MatrixData();

    
    void show() const;
    void fillExtendedMatrix();
    void multiplyRowByNumber(int rowNumber, double number);
    void substractRow(int row1, int row2, double factor);
	MatrixData transpose();

};
