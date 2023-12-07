#include <iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base cases: return 0 and 1 for the first two numbers
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive call to find the preceding two numbers and add them
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;

  cout << "Input a number n to find the nth Fibonacci number: ";
  cin >> n;

    // Find the 10th Fibonacci number
    int result = fibonacci(n);
    cout << "The " << n << "th Fibonacci number is " << result << endl;
    return 0;
}