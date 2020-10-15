#include <iostream>
using namespace std;

int main()
{
	int a, b;
    cout << "Enter 2 numbers";
    cin >> a >> b;

	a = a + b;
	b = a - b;
	a = a - b;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}