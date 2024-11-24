#include <iostream>
#include <string>
#include <vector>

using namespace std;


int sumToN(int n) {
    // Base case: if n is 0, return 0
    if (n == 1) {
        return 1;
    }
    // Recursive case: return the sum of the first n-1 elements plus the nth element
    return n + sumToN(n - 1);
}

int main() {
    int n = 5;
    std::cout << "Sum of numbers from 1 to " << n << " is: " << sumToN(n) << std::endl;
    return 0;
}

