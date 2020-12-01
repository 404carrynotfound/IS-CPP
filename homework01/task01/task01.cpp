#include <iostream>
#include <string>
#define MAX_ARR_SIZE 128

enum class order {
    ASCENDING,
    DESCENDING
};

order eval_order(std::string);

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

    if (eval_order(sort) == order::ASCENDING)
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
    else if (eval_order(sort) == order::DESCENDING)
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

order eval_order(std::string ord) 
{
    if (ord == "ascending") {
        return order::ASCENDING;
    }
    else if (ord == "descending") {
        return order::DESCENDING;
    }
}