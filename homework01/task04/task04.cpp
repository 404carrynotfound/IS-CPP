#include <iostream>
#include <string>
#include <cmath>
#define MAX_ARR_SIZE 16

double deter = 0;

double determ(int dim, double mat[MAX_ARR_SIZE][MAX_ARR_SIZE]);

int main()
{
    int dimentions, row, col;
    double matrix[MAX_ARR_SIZE][MAX_ARR_SIZE][MAX_ARR_SIZE];
    std::cin >> dimentions >> row >> col;
    
    for (int i = 0; i < dimentions; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                std::cin >> matrix[i][j][k];
            }
        }
    }
    std::cout << "Cubic matrix is saved." << std::endl;
    std::cout << std::endl;
    std::string operation;
    std::cin >> operation;
   
    if (operation == "sum")
    {
        for (int i = 0; i < dimentions; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    std::cout << matrix[i][j][k] + matrix[i][j][k] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
    else if (operation == "transpose")
    {
        for (int i = 0; i < dimentions; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    std::cout << matrix[i][k][j]<< " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
    else if (operation == "super")
    {
        double sum = 0;
        for (int i = 0; i < dimentions; i++)
        {
            sum *= determ(row, matrix[i]);
        }
    }
    else if (operation == "hyper")
    {
        double multi = 1;
        for (int i = 0; i < dimentions; i++)
        {
            multi *= determ(row, matrix[i]);
        }
    }
    else if (operation == "flat")
    {
        double flat_matrix[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0 };
        for (int i = 0; i < dimentions; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    flat_matrix[j][k] += matrix[i][j][k];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << flat_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

double determ(int dim, double matrix[MAX_ARR_SIZE][MAX_ARR_SIZE]) 
{
    int temp_i, i, j, temp_j;
    double submat[MAX_ARR_SIZE][MAX_ARR_SIZE];
    if (dim == 2) 
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else 
    {
        for (int d = 0; d < dim; d++) 
        {
            temp_i = 0;
            for (i = 1; i < dim; i++)
            {
                temp_j = 0;
                for (j = 0; j < dim; j++)
                {
                    if (j == d)
                    {
                        continue;
                    }
                    submat[temp_i][temp_j] = matrix[i][j];
                    temp_j++;
                }
                temp_i++;
            }
            deter = deter + (pow(-1, d) * matrix[0][d] * determ(dim - 1, submat));
        }
    }
    return deter;
}