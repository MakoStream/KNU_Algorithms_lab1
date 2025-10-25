#include "gauss_jordan.h"
// Gauss - Jordan method to find inversed matrix
void gaussJordanMethod(MatrixData& data) {

    //checking if matrix is square
    if (data.m != data.n) {
        cout << "Matrix must be square." << endl;
        return;
    };

    //Creating and filling extended matrix (A | E)
    MatrixData extendedMatrix(data.m, 2 * data.n);
    extendedMatrix.fillExtendedMatrix();

    //Checking if matrix has non-zero determinant
    double pivot = 0;
    for (int i = 0; i < data.m; i++) {
        pivot = extendedMatrix.matrix[i][i];

        if (pivot == 0) {
            cout << "Cannot invert matrix: zero pivot at row " << i << endl;
            return;
        };

        //Step 1.Making all elements on main diagonal 1
        extendedMatrix.multiplyRowByNumber(i, 1.0 / pivot);

        //Zeroing all else elments
        double factor = 0;
        for (int j = 0; j < data.m; j++) {
            if (j != i) {
                factor = extendedMatrix.matrix[j][i];
                extendedMatrix.substractRow(j, i, factor);
            };
        };
    };
};