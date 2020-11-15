#include <iostream>

using namespace std;

int main()
{
	unsigned long int number, counter = 0;

	cin >> number;
	
	while(number != 1)
	{
		if ((number - 1) % 2 == 0)
		{
			number = (number - 1) / 2;
		}
		else 
		{
			number = (number - 1) * 3 + 1;
		}
		counter++;
	}
	cout << counter;


	return 0;
}