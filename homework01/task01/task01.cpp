#include <iostream>
#include <string>
#define MAX_ARR_SIZE 128

int main()
{
    int arr[MAX_ARR_SIZE], lenght;

    std::string sort;

    std::cin >> lenght;

    for (int i = 0; i < lenght; i++)
    {
        std::cin >> arr[i];
    }

    std::cin >> sort;

    if (sort == "ascending")
    {
        for (int i = 0; i < lenght; i++)
        {
            for (int j = i + 1; j < lenght; j++)
            {
                if (arr[i] > arr[j])
                {
                    arr[i] = arr[i] + arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] = arr[i] - arr[j];
                }
            }
        }

        for (int i = 0; i < lenght; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    else if (sort == "descending")
    {
        for (int i = 0; i < lenght; i++)
        {
            for (int j = i + 1; j < lenght; j++)
            {
                if (arr[i] < arr[j])
                {
                    arr[i] = arr[i] + arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] = arr[i] - arr[j];
                }
            }
        }

        for (int i = 0; i < lenght; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    else
    {
        std::cout << "Enter type of sorting";
    }
    

    return 0;
}
