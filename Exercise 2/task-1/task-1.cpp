#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	
	cin >> num1 >> num2;

	for (int i = num1	; i <= num2; i++)
	{
		switch (i)
		{
			 case 1: cout << "one" <<endl; break;
			 case 2: cout << "two" << endl; break;
			 case 3: cout << "three" << endl; break;
			 case 4: cout << "four" << endl; break;
			 case 5: cout << "five" << endl; break;
			 case 6: cout << "six" << endl; break;
			 case 7: cout << "seven" << endl; break;
			 case 8: cout << "eight" << endl; break;
			 case 9: cout << "nine" << endl; break;
			 case 0: cout << "zero" << endl; break;
			 default: cout << (i % 2 == 0 ? "even" : "odd") << endl; break;
		}
	}


}

