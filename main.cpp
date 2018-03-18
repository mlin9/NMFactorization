#include <iostream>
#include "matrix.h"

using namespace std;

#include "environment.h"

int main() {
	sf::RenderWindow window( sf::VideoMode( 315, 315 ), "");
	Environment environment(&window);
	environment.start();
	
	
	Matrix X(10,10);
	Matrix U(10,10);
	Matrix A(10,10);
	
	X.init(9);
	U.init(3);
	A.init(2);
	
	cout << "Matrix X:" << endl;
	cin.get();
	cout << X.to_string() << endl;
	cin.get();
	cout << "Matrix U:" << endl;
	cin.get();
	cout << U.to_string() << endl;
	cin.get();
	cout << "Matrix A:" << endl;
	cin.get();
	cout << A.to_string() << endl;
	cin.get();
	
	cout << "U * A =" << endl;
	cin.get();
	cout << (U * A).to_string() << endl;
	cin.get();
	cout << "X - U * A = Result" << endl;
	cin.get();
	cout << (X - U * A).to_string() << endl;
	cin.get();
	
	Matrix Result(10,10);
	Result = X - U * A;
	
	cout << "frobenius(Result) = " << frobenius(Result) << endl;
	cin.get();
	
	int k, factor;
	cout << "NMFactorize: Please enter value of k = ";
	cin >> k;
	cout << endl << "NMFactorize: Please enter value of factor = ";
	cin >> factor;
	cout << endl << "NMFactorize(X, " << k << ", " << factor << ") =" << endl << endl;
	cin.get();
	vector<Matrix> factored;
	factored = NMFactorize(X, k, factor);
	
	int i = 0;
	cout << factored[i].to_string() << endl;
	i++;
	cout << factored[i].to_string() << endl;
	
	
	return 0;
}
