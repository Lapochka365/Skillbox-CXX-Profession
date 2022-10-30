#include <iostream>


std::string encrypt_caesar(std::string text, int cipherParam)
{
    std::string encryptedText;
    for (int i = 0; i < text.length(); i++)
    {
        if ((int) text[i] >= 65 && (int) text[i] <= 90)
        {
            int newPos = (((int) text[i] - (int) 'A') + cipherParam) % 26;
            if (newPos < 0)
            {
                newPos = ((int) 'Z' + 1) + newPos;
            }
            else
            {
                newPos = (int) 'A' + newPos;
            }
            encryptedText += (char) newPos;
        }
        else if ((int) text[i] >= 97 && (int) text[i] <= 122)
        {
            int newPos = (((int) text[i] - (int) 'a') + cipherParam) % 26;
            if (newPos < 0)
            {
                newPos = ((int) 'z' + 1) + newPos;
            }
            else
            {
                newPos = (int) 'a' + newPos;
            }
            encryptedText += (char) newPos;
        }
        else
        {
            encryptedText += text[i];
        }
    }
    return encryptedText;
}


std::string decrypt_caesar(std::string encryptedText, int cipherParam)
{
    return encrypt_caesar(encryptedText, -cipherParam);
}


int main() {
    std::string textToEncode;
    int cipherParam;

    std::cout << "Enter the text to encode:";
    std::getline(std::cin, textToEncode);
    std::cout << "Enter the parameter of the cipher:";
    std::cin >> cipherParam;

    std::string encryptedText = encrypt_caesar(textToEncode, cipherParam);
    std::cout << std::endl;
    std::cout << "The encrypted text is: ";
    std::cout << encryptedText << std::endl;
    std::cout << "The decrypted text is: ";
    std::cout << decrypt_caesar(encryptedText, cipherParam) << std::endl;

    return 0;
}