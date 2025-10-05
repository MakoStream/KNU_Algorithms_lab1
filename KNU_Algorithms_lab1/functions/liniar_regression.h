#pragma once
#include "../matrix.h"

// Liniar regression function
// returns the coefficients as a column matrix
// requares: matrix.h, basic_functions.h, gauss_jordan.h, shtrassen.h
MatrixData liniarRegression(const MatrixData& X, const MatrixData& Y) {
	if (X.m != Y.m || Y.n != 1) {
		throw invalid_argument("Incompatible dimensions for linear regression.");
	}

	int m = X.m; // number of samples
	int n = X.n; // number of features

	// (X^T * X)^-1 * X^T * Y - main formula

	//======================================================

	// Step 1: Compute X^T
	MatrixData XT = X.transpose();

	// Step 2: Compute X^T * X (shtrassen)

	// Step 3: Invert the result from Step 2 ( (X^T * X)^-1 ) (gauss_jordan)

	// Step 4: Compute X^T * Y (strassen)

	// Step 5: Multiply the results from Step 3 and Step 4 to get the coefficients ( (X^T * X)^-1 * X^T * Y ) (strassen)

	//======================================================
}