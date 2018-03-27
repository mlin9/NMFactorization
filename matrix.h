/* 

*/

#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Matrix
{
	public:
		//CONSTRUCTORS
		Matrix();
		Matrix(int input_width, int input_height);
		~Matrix();
		//OPERATORS
		Matrix operator+(const Matrix&) const;
		Matrix operator-(const Matrix&) const;
		Matrix operator*(const Matrix&) const;
		Matrix operator/(const Matrix&) const;
		void operator=(const Matrix&);
		//PUBLIC FUNCTIONS
		void init(int input_width, int input_height);
		void init(double input);
		void clone(Matrix &input);
		string to_string();
		int width;
		int height;
		double **matrix;
};

//EXTERNAL FUNCTIONS
double frobenius(Matrix &A);
vector<Matrix> NMFactorize(Matrix &A, int k, int factor);
Matrix NMMultiply(Matrix &U, Matrix &A);
Matrix BasisMatrix(Matrix &A);

#endif
