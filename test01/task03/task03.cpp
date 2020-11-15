#include <iostream>
#define MAX_ARR_SIZE 128

using namespace std;

int main()
{
	int numbers , temp, multi = 1, counter = 0;
	int arr_numbers[MAX_ARR_SIZE];
	bool flag = false;
	
	cin >> numbers;

	
	for (int i = 0; i < numbers; i++)
	{
		cin >> arr_numbers[i];
	}

	for (int i = 0; i < numbers; i++)
	{
		int num_lenght = 0;
		temp = arr_numbers[i];
		while (temp != 0)
		{
			temp /= 10;
			num_lenght++;
		}
		
		for (int j = 1; j < numbers - 1; j++)
		{
			temp = arr_numbers[i];

			while (temp % 10 == arr_numbers[j])
			{
				cout << "yes" << endl;
				for (int h = 0; h < numbers; h++)
				{
					multi *= arr_numbers[i];
				}
				cout << multi / 2;
				flag = true;
			}
			temp /= 10;
			
			if (flag)
			{
				break;
			}
			/*if (temp == arr_numbers[j])
			{
				cout << "yes"<<endl;
				for (int h = 0; h < numbers; h++)
				{
					multi *= arr_numbers[i];
				}
				cout << multi / 2;
			}
			else if (temp % 10 == arr_numbers[j])
			{
				cout << "yes" << endl;
				for (int h = 0; h < numbers; h++)
				{
					multi *= arr_numbers[i];
				}
				cout << multi / 2;
			}*/
		}
		if (flag)
		{
			break;
		}
	}

	if (!flag)
	{
		cout << "no";
	}
	return 0;
}
