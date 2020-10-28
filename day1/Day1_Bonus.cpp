//Write a program which can guess the number that user is thinking of – between 1-128 – you can ask
// anything you want up to 7 times.

#include <iostream>
#include <string>

int main ()
{

    int num = 0;

    std::string Cipher;
    std::cout << "Think of a number between 1 - 128 \n";

    int maxNr = 128;
    int minNr = 0;

    for (int i =0 ; i < 7 ; i++)
    {
        char answer;
        int question = (maxNr - minNr)/2 + minNr +1;
        std::cout << "Are your number smaller than " << question << "[y/n] \n";
        std::cin >> answer;
        if ( answer == 'y')
        {
            maxNr = question-1;
        }
        else
        {
            minNr = question;
        }
        std::cout << "Min  " << minNr << "  Max" << maxNr <<"\n";
    }
    std::cout << "You where thinking of " << (minNr) << "\n";
    std::cout << "You where thinking of " << (maxNr) << "\n";

 }

