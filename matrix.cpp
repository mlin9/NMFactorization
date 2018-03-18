#include "matrix.h"

/***** CONSTRUCTORS *****/
Matrix::Matrix()
{

}

Matrix::Matrix(int input_width,int input_height)
{
	width = input_width;
	height = input_height;
	matrix = new double*[input_width];
	for(int i = 0; i < input_width; i++)
	    matrix[i] = new double[input_height];
}

Matrix::~Matrix()
{
	for(int i = 0; i < width; i++)
    	delete[] matrix[i];
	delete[] matrix;
}

/***** END CONSTRUCTORS *****/

/***** OPERATORS *****/

//Matrix Matrix::operator+(const Matrix& operand) const
//POSTCONDITIONS: The sum of two matrices is returned.
Matrix Matrix::operator+(const Matrix& operand)
{
	init(operand.width, operand.height);
	
	Matrix result(this->width, this->height);
	
	for(int y = 0; y < this->height; y++)
	{
		for(int x = 0; x < this->width; x++)
		{
			result.matrix[x][y] = this->matrix[x][y] + operand.matrix[x][y];
		}
	}
	
	return result;
}

//Matrix Matrix::operator-(const Matrix& operand) const
//POSTCONDITIONS: The difference of two matrices is returned.
Matrix Matrix::operator-(const Matrix& operand) const
{
	//Condition check for a matrix of the same size
	assert(operand.width == this->width && operand.height == this->height);

	Matrix result(this->width, this->height);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			result.matrix[x][y] = this->matrix[x][y] - operand.matrix[x][y];
		}
	}
	
	return result;
}

//Matrix Matrix::operator*(const Matrix& operand) const
//POSTCONDITIONS: The product of two matrices is returned.
Matrix Matrix::operator*(const Matrix& operand) const
{
	//Condition check for a matrix of the same size
	assert(operand.width == this->width && operand.height == this->height);

	Matrix result(this->width, this->height);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			result.matrix[x][y] = this->matrix[x][y] * operand.matrix[x][y];
		}
	}
	
	return result;
}

//Matrix Matrix::operator/(const Matrix& operand) const
//POSTCONDITIONS: The dividend of two matrices is returned.
Matrix Matrix::operator/(const Matrix& operand) const
{
	//Condition check for a matrix of the same size
	assert(operand.width == this->width && operand.height == this->height);

	Matrix result(this->width, this->height);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			result.matrix[x][y] = this->matrix[x][y] / operand.matrix[x][y];
		}
	}
	
	return result;
}

//Matrix Matrix::operator=(const Matrix& operand) const
//POSTCONDITIONS: Changes the values of this matrix to operand matrix.
void Matrix::operator=(const Matrix& operand) const
{
	//Condition check for a matrix of the same size
	assert(operand.width == this->width && operand.height == this->height);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			this->matrix[x][y] = operand.matrix[x][y];
		}
	}
}

/***** END OPERATORS *****/

/***** PUBLIC FUNCTIONS *****/

//void init(int input_width, int input_height)
//POSTCONDITIONS: matrix[width][height] is declared.
void Matrix::init(int input_width, int input_height)
{
	width = input_width;
	height = input_height;
	matrix = new double*[input_width];
	for(int i = 0; i < input_width; i++)
	    matrix[i] = new double[input_height];
}
//void Matrix::init(int_input)
//PRECONDITIONS: matrix[width][height] is declared.
//POSTCONDITIONS: matrix[x][y] is initialized to double input.
void Matrix::init(double input)
{
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			matrix[x][y] = input;
		}
	}
}

//string Matrix::to_string()
//PRECONDITIONS: matrix[width][height] is declared.
//POSTCONDITIONS: matrix[x][y] is output to a string.
string Matrix::to_string()
{
	string result;
	string buffer;

	for(int y = 0; y < height; y++)
	{		
		for(int x = 0; x < width; x++)
		{
			buffer = std::to_string(matrix[x][y]);
			result += '[' + buffer + ']';
		}
		
		result += '\n';
	}
	
	return result;
}

/***** END PUBLIC FUNCTIONS *****/

/***** EXTERNAL FUNCTIONS *****/

//float frobenius(Matrix A)
//PRECONDITIONS: matrix[width][height] is declared.
//POSTCONDITIONS: The frobenius value is returned.
double frobenius(Matrix &A)
{
	double result = 0;
	
	for(int y = 0; y < A.height; y++)
	{
		for(int x = 0; x < A.width; x++)
		{
			result += pow(A.matrix[x][y], 2.0);
		}
	}
	
	return sqrt(result);
}

//vector<Matrix> NMFactorize(Matrix &A, int k, int factor)
//PRECONDITIONS: 0 < k < A.width and 0 < k < A.height
//POSTCONDITIONS: Factor matrices X and Y are returned.
vector<Matrix> NMFactorize(Matrix &A, int k, int factor)
{
	assert(k < A.width && k < A.height && k > 0);

	vector<Matrix> XYMatrices(2);
	XYMatrices[0].init(A.width, k);
	XYMatrices[1].init(k, A.height);
	
	for(int y = 0; y < k; y++)
	{
		for(int x = 0; x < A.width; x++)
		{
			XYMatrices[0].matrix[x][y] = A.matrix[x][y]/(factor * k);
		}
	}
	
	for (int y = 0; y < A.height; y++)
	{
		for(int x = 0; x < k; x++)
		{
			XYMatrices[1].matrix[x][y] = A.matrix[x][y]/(factor);
		}
	}
	
	return XYMatrices;
}

Matrix NMMultiply(Matrix &X, Matrix &Y)
{
	int width = max(X.width, Y.width);
	int height = max(X.height, Y.height);
	
	double buffer;
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			
		}
	}
	
}
/***** END EXTERNAL FUNCTIONS *****/
