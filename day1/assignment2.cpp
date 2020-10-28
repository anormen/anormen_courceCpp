//Implement the decryption function of Caeser Cipher with custom length key and decrypt the following – the
//mapplication should ask for a key between (0-26), and then the cipher text, and shall print the decryption.

#include <iostream>
#include <string>

int main ()
{

    int num = 0;

    std::string Cipher;
    std::cout << "Write in CAPITAL LETTERS word to decrypt";
    std::cout<< std::endl;
    std::getline(std::cin, Cipher);

    std::cout << "Write a key number between o and 26" <<std::endl;
    std:: cin >> num;
    int i = 0;
    while (Cipher[i] !='\0')
    {
        //65-90 ok values A-Z
        int newAscii = static_cast<int>(Cipher[i]) - num;

       if (newAscii < 65)
       {
           newAscii = newAscii + 26;
       }
        std::cout << (char) newAscii;
        i++;
    }
    std::cout<< std::endl;
 }

