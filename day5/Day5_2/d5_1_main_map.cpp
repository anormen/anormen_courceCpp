
#include <iostream>
#include <cstdlib>
#include <map>

int main(){
    const int size_DataSet =10000;
    const int maxNr = 33;


    std::map<int, int> countedValues;



    // Generate the random numbers and count them put result in map
    for (int i = 0; i < size_DataSet; i++)
    {
        int randNr= (std::rand() %(maxNr +1) );
        countedValues[randNr]++;
    }


    // Find smallest and Largest
    int minOccurance = size_DataSet;
    int maxOccurance = 0;

    for (int i = 0; i < maxNr; i++ )
    {
        if (countedValues[i] > maxOccurance){maxOccurance =  countedValues[i];}
        if (countedValues[i] < minOccurance){minOccurance =  countedValues[i];}
    }
 // Print in increasing order by looping through
 std::cout <<" Nr " <<  "Occurance" << std::endl;
    for (int i = minOccurance; i < maxOccurance; i++)
    {
        for (int j = 0; j < size_DataSet; j++){
            if ( countedValues[j] == i)
           {
                std::cout << j <<" " <<  i << std::endl;
           }

        }
    }

    return 0;
}