#include <iostream>
using namespace std;
int count_digit(int number);
bool isPalindrome(int num);
int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	if (isPalindrome(n))
		cout << "Yes, " << n << " is a palindrome\n";
	else
		cout << "No, " << n << " is not a palindrome\n";
	return 0;
}
