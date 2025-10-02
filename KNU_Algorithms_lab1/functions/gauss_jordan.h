#pragma once
#include "../matrix.h"

// Гаусс-Жордан для обернення матриці
void gaussJordanMethod(MatrixData& data) {

    //перевірка матриці на квадратність
    if (data.m != data.n) {
        cout << "Matrix must be square." << endl;
        return;
    }

    //Створення та заповнення розширеної матриці (A | E)
    MatrixData extendedMatrix(data.m, 2 * data.n);
    extendedMatrix.fillExtendedMatrix();

    //Перевірка на невиродженість
    double pivot = 0;
    for (int i = 0; i < data.m; i++) {
        pivot = extendedMatrix.matrix[i][i];

        if (pivot == 0) {
            cout << "Cannot invert matrix: zero pivot at row " << i << endl;
            return;
        }

        //крок 1:обнулення елементів на головній діагоналі
        extendedMatrix.multiplyRowByNumber(i, 1.0 / pivot);

        //тут обнулення всіх елементів,які не на головній діагоналі
        double factor = 0;
        for (int j = 0; j < data.m; j++) {
            if (j != i) {
                factor = extendedMatrix.matrix[j][i];
                extendedMatrix.substractRow(j, i, factor);
            }
        }
    }
}