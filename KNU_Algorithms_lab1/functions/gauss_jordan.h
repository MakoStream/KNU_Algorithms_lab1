#pragma once
#include "../matrix.h"

// �����-������ ��� ��������� �������
void gaussJordanMethod(MatrixData& data) {

    //�������� ������� �� �����������
    if (data.m != data.n) {
        cout << "Matrix must be square." << endl;
        return;
    }

    //��������� �� ���������� ��������� ������� (A | E)
    MatrixData extendedMatrix(data.m, 2 * data.n);
    extendedMatrix.fillExtendedMatrix();

    //�������� �� �������������
    double pivot = 0;
    for (int i = 0; i < data.m; i++) {
        pivot = extendedMatrix.matrix[i][i];

        if (pivot == 0) {
            cout << "Cannot invert matrix: zero pivot at row " << i << endl;
            return;
        }

        //���� 1:��������� �������� �� ������� �������
        extendedMatrix.multiplyRowByNumber(i, 1.0 / pivot);

        //��� ��������� ��� ��������,�� �� �� ������� �������
        double factor = 0;
        for (int j = 0; j < data.m; j++) {
            if (j != i) {
                factor = extendedMatrix.matrix[j][i];
                extendedMatrix.substractRow(j, i, factor);
            }
        }
    }
}