#include <iostream>

using namespace std;

//param a – the base integer (to be raised to a power).
//param n – the power
//pre: a > 0
//post: return the value of a raised to the nth power.
int power(int base, int exponent) {
    // Base Case 1: if the exponent is 0, return 1
    if (exponent == 0) {
        return 1;
    }
    // Base Case 2: if the exponent is 1, return the base
    if (exponent == 1) {
        return base;
    }
    // Recursive Case: return the base multiplied by the result of the function with the base and exponent - 1
    return base * power(base, exponent - 1);
}


int main() {
    int base = 2;
    int exponent = 5;
    cout << base << " raised to the power of " << exponent << " is " << power(base, exponent) << endl;
    return 0;
}