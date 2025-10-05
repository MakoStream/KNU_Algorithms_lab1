#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include "../matrix.h"

static inline int nextPow2(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

static MatrixData classicMultiply(const MatrixData& A, const MatrixData& B) {
    assert(A.n == B.m);
    MatrixData C(A.m, B.n);
    for (int i = 0; i < A.m; ++i) {
        for (int k = 0; k < A.n; ++k) {
            double aik = A.matrix[i][k];
            if (aik == 0.0) continue;
            for (int j = 0; j < B.n; ++j) {
                C.matrix[i][j] += aik * B.matrix[k][j];
            }
        }
    }
    return C;
}

static MatrixData add(const MatrixData& X, const MatrixData& Y) {
    assert(X.m == Y.m && X.n == Y.n);
    MatrixData Z(X.m, X.n);
    for (int i = 0; i < X.m; ++i)
        for (int j = 0; j < X.n; ++j)
            Z.matrix[i][j] = X.matrix[i][j] + Y.matrix[i][j];
    return Z;
}

static MatrixData sub(const MatrixData& X, const MatrixData& Y) {
    assert(X.m == Y.m && X.n == Y.n);
    MatrixData Z(X.m, X.n);
    for (int i = 0; i < X.m; ++i)
        for (int j = 0; j < X.n; ++j)
            Z.matrix[i][j] = X.matrix[i][j] - Y.matrix[i][j];
    return Z;
}

static MatrixData slice(const MatrixData& M, int r0, int c0, int r1, int c1) {
    MatrixData S(r1 - r0, c1 - c0);
    for (int i = 0; i < S.m; ++i)
        for (int j = 0; j < S.n; ++j)
            S.matrix[i][j] = M.matrix[r0 + i][c0 + j];
    return S;
}

static void place(MatrixData& D, const MatrixData& S, int r0, int c0) {
    for (int i = 0; i < S.m; ++i)
        for (int j = 0; j < S.n; ++j)
            D.matrix[r0 + i][c0 + j] = S.matrix[i][j];
}

static MatrixData padToSquare(const MatrixData& X, int P) {
    MatrixData R(P, P);
    for (int i = 0; i < X.m; ++i)
        for (int j = 0; j < X.n; ++j)
            R.matrix[i][j] = X.matrix[i][j];
    return R;
}

static MatrixData crop(const MatrixData& X, int rows, int cols) {
    MatrixData R(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            R.matrix[i][j] = X.matrix[i][j];
    return R;
}

static MatrixData strassenRec(const MatrixData& A, const MatrixData& B, int cutoff) {
    int n = A.m;
    assert(A.m == A.n && B.m == B.n && A.m == B.m);
    if (n <= cutoff) return classicMultiply(A, B);
    int k = n / 2;
    MatrixData A11 = slice(A, 0, 0, k, k);
    MatrixData A12 = slice(A, 0, k, k, n);
    MatrixData A21 = slice(A, k, 0, n, k);
    MatrixData A22 = slice(A, k, k, n, n);
    MatrixData B11 = slice(B, 0, 0, k, k);
    MatrixData B12 = slice(B, 0, k, k, n);
    MatrixData B21 = slice(B, k, 0, n, k);
    MatrixData B22 = slice(B, k, k, n, n);
    MatrixData M1 = strassenRec(add(A11, A22), add(B11, B22), cutoff);
    MatrixData M2 = strassenRec(add(A21, A22), B11, cutoff);
    MatrixData M3 = strassenRec(A11, sub(B12, B22), cutoff);
    MatrixData M4 = strassenRec(A22, sub(B21, B11), cutoff);
    MatrixData M5 = strassenRec(add(A11, A12), B22, cutoff);
    MatrixData M6 = strassenRec(sub(A21, A11), add(B11, B12), cutoff);
    MatrixData M7 = strassenRec(sub(A12, A22), add(B21, B22), cutoff);
    MatrixData C11 = add(sub(add(M1, M4), M5), M7);
    MatrixData C12 = add(M3, M5);
    MatrixData C21 = add(M2, M4);
    MatrixData C22 = add(sub(add(M1, M3), M2), M6);
    MatrixData C(n, n);
    place(C, C11, 0, 0);
    place(C, C12, 0, k);
    place(C, C21, k, 0);
    place(C, C22, k, k);
    return C;
}

inline MatrixData strassenMultiply(const MatrixData& A, const MatrixData& B, int cutoff = 64) {
    if (A.n != B.m) {
        std::cout << "Dimension mismatch: A is " << A.m << "x" << A.n << ", B is " << B.m << "x" << B.n << std::endl;
        return MatrixData(0, 0);
    }
    int m = A.m, k = A.n, n = B.n;
    int P = nextPow2(std::max({m, k, n}));
    MatrixData Ap = padToSquare(A, P);
    MatrixData Bp = padToSquare(B, P);
    MatrixData Cp = strassenRec(Ap, Bp, cutoff);
    return crop(Cp, m, n);
}