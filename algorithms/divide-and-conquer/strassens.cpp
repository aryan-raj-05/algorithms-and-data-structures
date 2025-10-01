#include <iostream>
#include <vector>

using std::vector;
template <typename T> using matrix = vector<vector<T>>;

// prints matrix of any type
template <typename T>
void printMatrix(const matrix<T>& A) {
	for (const auto& row : A) {
		for (const auto& val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

namespace naive {
	// returns the order of the matrix
	// if the matrix is invalid or empty, it returns {-1, -1}
	template <typename T>
	vector<int> orderMat(const matrix<T>& A) {
		if (A.empty())	return {-1, -1};

		int a = static_cast<int>(A.size());
		int b = static_cast<int>(A[0].size());

		for(const auto& x : A) {
			if (static_cast<int>(x.size()) != b) {
				return {-1, -1};
			}
		}

		return {a, b};
	}

	// matrix multiplication as per the definition,
	// row by column method
	template <typename T>
	matrix<T> defMul(const matrix<T>& A, const matrix<T>& B) {
		vector<int> ordA = orderMat(A); // [m x n]
		vector<int> ordB = orderMat(B); // [n x p]

		if (ordA[1] != ordB[0] || ordA[1] == -1 || ordB[1] == -1) {
			std::cerr << "Multiplication is not defined\n";
			return {};
		}

		int m = ordA[0], n = ordA[1], p = ordB[1];
		matrix<T> C(m, vector<T>(p, 0));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < p; j++)
				for (int k = 0; k < n; k++)
					C[i][j] += A[i][k] * B[k][j];

		return C;
	}
}

namespace strasn {
	/*
	strassen's matrix multiplication method

	say we have, 
	matrices, X and Y, both of order (n x n), we can write them as,
	X = [A, B],		and, Y = [E, F],
		[C, D]				 [G, H]
	where, A, B, C, D, E, F, G, H are sub-matrices of the order (n/2 x n/2)

	now, we need to calculate 7 different products in a recursive way, those are
	P1 = A * (F - H)
	P2 = (A + B) * H
	P3 = (C + D) * E
	P4 = D * (G - E)
	P5 = (A + D) * (E + H)
	P6 = (B - D) * (G + H)
	P7 = (A - C) * (E + F)

	Now, the result of matrix multiplication X.Y is

	X.Y = [P5 + P4 - P2 + P6    P1 + P2],
		  [P3 + P4              P1 + P5 - P3 - P7]

	*/

	// adds two square matrices of same order
	template<typename T>
	matrix<T> addMat(const matrix<T> &A, const matrix<T> &B, int sign = 1) {
		// assume that input is valid and both are square matrices
		int n = static_cast<int>(A.size());
		matrix<T> C(n, vector<T>(n));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				C[i][j] = A[i][j] + sign * B[i][j];
		return C;
	}

	template<typename T> 
	matrix<T> strassenMatMul(const matrix<T>& X, const matrix<T>& Y) {
		// for simplicity order of both A and B will be assumed as n x n
		int n = static_cast<int>(X.size());
		if (n <= 2)	return naive::defMul(X, Y);
		int mid = n / 2;

		matrix<T> A(mid, vector<T>(mid)), B(mid, vector<T>(mid));
		matrix<T> C(mid, vector<T>(mid)), D(mid, vector<T>(mid));
		matrix<T> E(mid, vector<T>(mid)), F(mid, vector<T>(mid));
		matrix<T> G(mid, vector<T>(mid)), H(mid, vector<T>(mid));

		for(int i = 0; i < mid; i++) {
			for(int j = 0; j < mid; j++) {
				A[i][j] = X[i][j];
				B[i][j] = X[i][j + mid];
				C[i][j] = X[i + mid][j];
				D[i][j] = X[i + mid][j + mid];

				E[i][j] = Y[i][j];
				F[i][j] = Y[i][j+mid];
				G[i][j] = Y[i+mid][j];
				H[i][j] = Y[i+mid][j+mid];
			}
		}

		matrix<T> p1 = strassenMatMul(A, addMat(F, H, -1));
		matrix<T> p2 = strassenMatMul(addMat(A, B), H);
		matrix<T> p3 = strassenMatMul(addMat(C, D), E);
		matrix<T> p4 = strassenMatMul(D, addMat(G, E, -1));
		matrix<T> p5 = strassenMatMul(addMat(A, D), addMat(E, H));
		matrix<T> p6 = strassenMatMul(addMat(B, D, -1), addMat(G, H));
		matrix<T> p7 = strassenMatMul(addMat(A, C, -1), addMat(E, F));

		matrix<T> C11 = addMat(addMat(p5, p4), addMat(p6, p2, -1));
		matrix<T> C12 = addMat(p1, p2);
		matrix<T> C21 = addMat(p3, p4);
		matrix<T> C22 = addMat(addMat(p5, p1), addMat(p3, p7), -1);

		matrix<T> res(n, vector<T>(n));

		for(int i = 0; i < mid; i++) {
			for(int j = 0; j < mid; j++) {
				res[i][j] = C11[i][j];
				res[i][j + mid] = C12[i][j];
				res[i + mid][j] = C21[i][j];
				res[i + mid][j + mid] = C22[i][j];
			}
		}

		return res;
	}
}
