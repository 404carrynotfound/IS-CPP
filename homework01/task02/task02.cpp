#include <iostream>
#include <cmath>
#define MAX_ARR_SIZE 128

void dec_to_binary(int num)
{
	int binary_arr[MAX_ARR_SIZE], counter = 0;
	
	while (num != 0)
	{
		binary_arr[counter] = num % 2;
		counter++;
		num /= 2;
	}

	for (int i = counter - 1; i >= 0; i--)
	{
		std::cout << binary_arr[i];
	}
	std::cout << std::endl;
}

int main()
{
	int lenght, sum = 0, arr[MAX_ARR_SIZE];
	std::cin >> lenght;

	for (size_t i = 0; i < lenght; i++)
	{
		std::cin >> arr[i];
		sum += arr[i];
		dec_to_binary(arr[i]);
	}

	std::cout << sum << std::endl;
	dec_to_binary(sum);
	
	double avg = sum / lenght;

	std::cout << std::floor(avg) << std::endl;
	dec_to_binary(floor(avg));

	return 0;
}