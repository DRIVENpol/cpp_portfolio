// The Extended Euclidean Algorithm is an extension of the Euclidean Algorithm, 
// which is used to find the greatest common divisor (GCD) of two integers. In addition to finding the GCD
#include <iostream>

using namespace std;

// Function to implement Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a = 35, b = 15;
    int x, y;
    int gcd = extendedEuclidean(a, b, x, y);

    cout << "The GCD of " << a << " and " << b << " is " << gcd << endl;

    // x, y  for 35x + 15y = gcd(35, 15)
    cout << "Coefficients: x = " << x << ", y = " << y << endl;

    return 0;
}
// The GCD of 35 and 15 is 5