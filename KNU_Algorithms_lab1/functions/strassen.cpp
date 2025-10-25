#include "strassen.h"

static MatrixData classicMul(const MatrixData& A, const MatrixData& B) {
    MatrixData C(A.m, B.n);
    for (int i = 0; i < A.m; ++i)
        for (int k = 0; k < A.n; ++k) {
            double a = A.matrix[i][k];
            for (int j = 0; j < B.n; ++j)
                C.matrix[i][j] += a * B.matrix[k][j];
        }
    return C;
}

static bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

static MatrixData addM(const MatrixData& X, const MatrixData& Y) {
    MatrixData Z(X.m, X.n);
    for (int i = 0; i < X.m; ++i)
        for (int j = 0; j < X.n; ++j)
            Z.matrix[i][j] = X.matrix[i][j] + Y.matrix[i][j];
    return Z;
}

static MatrixData subM(const MatrixData& X, const MatrixData& Y) {
    MatrixData Z(X.m, X.n);
    for (int i = 0; i < X.m; ++i)
        for (int j = 0; j < X.n; ++j)
            Z.matrix[i][j] = X.matrix[i][j] - Y.matrix[i][j];
    return Z;
}

static MatrixData cut(const MatrixData& M, int r0, int c0, int sz) {
    MatrixData S(sz, sz);
    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            S.matrix[i][j] = M.matrix[r0 + i][c0 + j];
    return S;
}

static void put(MatrixData& D, const MatrixData& S, int r0, int c0) {
    for (int i = 0; i < S.m; ++i)
        for (int j = 0; j < S.n; ++j)
            D.matrix[r0 + i][c0 + j] = S.matrix[i][j];
}

static MatrixData strassenRec(const MatrixData& A, const MatrixData& B, int cutoff) {
    int n = A.m;
    if (n <= cutoff) return classicMul(A, B);
    int k = n / 2;

    MatrixData A11 = cut(A, 0,   0,   k);
    MatrixData A12 = cut(A, 0,   k,   k);
    MatrixData A21 = cut(A, k,   0,   k);
    MatrixData A22 = cut(A, k,   k,   k);

    MatrixData B11 = cut(B, 0,   0,   k);
    MatrixData B12 = cut(B, 0,   k,   k);
    MatrixData B21 = cut(B, k,   0,   k);
    MatrixData B22 = cut(B, k,   k,   k);

    MatrixData M1 = strassenRec(addM(A11, A22), addM(B11, B22), cutoff);
    MatrixData M2 = strassenRec(addM(A21, A22), B11,            cutoff);
    MatrixData M3 = strassenRec(A11,            subM(B12, B22), cutoff);
    MatrixData M4 = strassenRec(A22,            subM(B21, B11), cutoff);
    MatrixData M5 = strassenRec(addM(A11, A12), B22,            cutoff);
    MatrixData M6 = strassenRec(subM(A21, A11), addM(B11, B12), cutoff);
    MatrixData M7 = strassenRec(subM(A12, A22), addM(B21, B22), cutoff);

    MatrixData C11 = addM(subM(addM(M1, M4), M5), M7);
    MatrixData C12 = addM(M3, M5);
    MatrixData C21 = addM(M2, M4);
    MatrixData C22 = addM(subM(addM(M1, M3), M2), M6);

    MatrixData C(n, n);
    put(C, C11, 0, 0);
    put(C, C12, 0, k);
    put(C, C21, k, 0);
    put(C, C22, k, k);
    return C;
}

MatrixData strassenMultiply(const MatrixData& A, const MatrixData& B, int cutoff = 2) {
    if (A.n != B.m) return MatrixData(0, 0);
    if (A.m != A.n || B.m != B.n || A.m != B.m) return MatrixData(0, 0);
    if (!isPowerOfTwo(A.m)) return MatrixData(0, 0);
    return strassenRec(A, B, cutoff);
}