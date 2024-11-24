#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sumFirstN(const vector<int>& arr, int n) {
    // Base case: if n is 0, return 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: return the sum of the first n-1 elements plus the nth element
    return arr[n - 1] + sumFirstN(arr, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5;

    int result = sumFirstN(arr, n);
    cout << "Sum of the first " << n << " integers: " << result << endl;

    return 0;
}