#include <iostream>
#include <iomanip>
#include "VecXd.h"
#include "VecXd.cpp"    // must be added

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void testVector() {
	VecXd<int> a, b, c;											// Example I/O:
	int width = 15;

	cout << "Input vector a\n";
	cin >> a;													// In: 3 1 2 3

	cout << "Input vector b\n";
	cin >> b;													// In: 3 4 5 6

	cout << setw(width) << "Vector a: " << a << endl;
	cout << setw(width) << "Vector b: " << b << endl;

	c = a + b;
	cout << setw(width) << "c = a + b: " << c << endl;			// Out: 5 7 9

	cout << setw(width) << "b + c: " << b + c << endl;			// Out: 9 12 15

	VecXd<int> d = a + c;
	cout << setw(width) << "d = a + c: " << d << endl;			// Out: 6 9 12

	d += b;
	cout << setw(width) << "d = a + b + c: " << d << endl;      // Out: 10 14 18

	VecXd<double> x;

	cout << "Input vector x\n";
	cin >> x;													// In: 2 1.2 3.4
	cout << setw(width) << "Vector x: " << x << endl;

	x = x;
	cout << setw(width) << "Vector x + x: " << x + x << endl;	// Out: 2.4 6.8
}

// Sample Run
/*
Input vector a
3 1 2 3
Input vector b
3 4 5 6
     Vector a: 1 2 3
     Vector b: 4 5 6
    c = a + b: 5 7 9
        b + c: 9 12 15
    d = a + c: 6 9 12
d = a + b + c: 10 14 18
Input vector x
2 1.2 3.4
     Vector x: 1.2 3.4
 Vector x + x: 2.4 6.8
*/

int main() {
	testVector();
	//system (" pause " );
	return 0;
}
