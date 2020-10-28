//Write a program which takes a positive number from user, and then fill in a 3-dimensional array of size [8,9,11]
// with random positive numbers smaller than the one user has provided – pretty print the array.


#include <iostream>


int main ()
{
    int num = 0;
    const int rx = 8;
    const int ry = 9;
    const int rz = 11;
    int DArray[8][9][11];

    std::cout << "Write a number between o and 100" <<std::endl;
    std:: cin >> num;

    for (int i=0; i<rx; i++)
   {
       for (int j=0; j<ry; j++)
       {
            for (int k=0; k<rz; k++)
           {
                DArray[i][j][k] = rand ()%(num);
           }
        }
   }
     std::cout << std::endl;
   for (int i = 0; i<rx; i++)
   {
       for (int j = 0; j<ry; j++)
       {
            for (int k = 0; k<rz; k++)
           {
                std::cout <<DArray[i][j][k]<<", ";

           }
           std::cout <<" |";
           std::cout << std::endl;
        }
        std::cout << std::endl;
   }
 }