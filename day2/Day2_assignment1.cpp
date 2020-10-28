//Write a program which takes a positive number from user, and then fill in a 3-dimensional array of size [8,9,11]
// with random positive numbers smaller than the one user has provided – pretty print the array.
// Modify your first assignment from yesterday to receive the dimensions of the arrays from the user.

#include <iostream>


int main ()
{
    int num = 0;

    int rx;
    int ry;
    int rz;

    std::cout << "Give the three dimensions of the 3-dimesnional array" <<std::endl;
    std::cin >> rx;
    std::cin >> ry;
    std::cin >> rz;

    std::cout << "Write the max nr for random filling Array" <<std::endl;
    std:: cin >> num;

    // Allocated the 3D Array and fill it
    int*** D3Array = new int**[rx];
    for(int i(0); i < rx; ++i)
    {
        D3Array[i] = new int*[ry];

        for(int j(0); j < ry; ++j)
        {
            D3Array[i][j] = new int[rz];

            for(int k(0); k < rz; ++k)
            {
                D3Array[i][j][k]= rand ()%(num);
            }
        }
    }
    // Print the 3D Array
    std::cout << std::endl;
    for (int i = 0; i<rx; i++)
    {
       for (int j = 0; j<ry; j++)
       {
            for (int k = 0; k<rz; k++)
           {
                std::cout <<D3Array[i][j][k]<<", ";

           }
           std::cout <<" |";
           std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    // Release the 3D Array memory
    for (int i = 0; i < rx; ++i)
    {
        for (int j = 0; j < ry; ++j)
        {
            delete [] D3Array[i][j];
        }
        delete [] D3Array[i];
    }
    delete [] D3Array;
 }
