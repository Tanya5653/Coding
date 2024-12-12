#include<iostream>
#include<cmath>
using namespace std;

// Function for modular addition
int modularAdd(int a, int b, int mod) {
    return ((a % mod) + (b % mod)) % mod;
}

// Function for modular subtraction
int modularSubtract(int a, int b, int mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

// Function for modular multiplication
int modularMultiply(int a, int b, int mod) {
    return ((a % mod) * (b % mod)) % mod;
}

// Function for modular exponentiation
int modularExponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1)
            result = (result * base) % mod;

        // exp must be even now
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    int a, b, mod;

    // Input values for testing
    cout << "Enter values for a, b, and mod: ";
    cin >> a >> b >> mod;

    // Modular addition
    cout << "Modular Addition: " << modularAdd(a, b, mod) << endl;

    // Modular subtraction
    cout << "Modular Subtraction: " << modularSubtract(a, b, mod) << endl;

    // Modular multiplication
    cout << "Modular Multiplication: " << modularMultiply(a, b, mod) << endl;

    // Modular exponentiation
    cout << "Enter the base and exponent for modular exponentiation: ";
    int base, exp;
    cin >> base >> exp;
    cout << "Modular Exponentiation: " << modularExponentiation(base, exp, mod) << endl;

    return 0;
}
