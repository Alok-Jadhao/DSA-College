#include <iostream>
#include <cmath> // For pow() and log2()
using namespace std;

// Function declarations
double linear(int n) { return n; }
double quadratic(int n) { return n * n; }
double exponential(int n) { return pow(2, n); }
double logarithmic(int n) { return (n > 0) ? log2(n) : 0; } // Avoid log2(0)
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

int main() {
    // Input range
    int max_n_general = 100; // For functions like linear, quadratic, etc.
    int max_n_factorial = 15; // For factorial to avoid large numbers
    
    cout << "n\tLinear\tQuadratic\tExponential\tLogarithmic\tFactorial\n";
    
    // Generate values
    for (int n = 0; n <= max_n_general; ++n) {
        // For factorial and exponential, limit range to 15
        if (n > max_n_factorial) {
            cout << n << "\t" << linear(n) << "\t" << quadratic(n) << "\t" << exponential(n) 
                 << "\t" << logarithmic(n) << "\tN/A\n";
        } else {
            cout << n << "\t" << linear(n) << "\t" << quadratic(n) << "\t" << exponential(n) 
                 << "\t" << logarithmic(n) << "\t" << factorial(n) << "\n";
        }
    }
    return 0;
}

