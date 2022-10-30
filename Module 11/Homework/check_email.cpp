#include <iostream>
#include <tuple>


std::tuple<std::string, int> findFirstPart(std::string email)
{
    std::string firstPart;
    int i = 0;
    for (; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        firstPart += email[i];
    }
    return {firstPart, i};
}

std::string findSecondPart(std::string email, int indexOfAt)
{
    std::string secondPart;
    indexOfAt += 1;
    for (int i = indexOfAt; i < email.length(); i++)
    {
        secondPart += email[i];
    }
    return secondPart;
}

bool checkForPoint(std::string emailPart, int i)
{
    if (i == 0 && emailPart[i] == '.' || i == emailPart.length() - 1 && emailPart[i] == '.')
        return true;
    else if (i + 1 < emailPart.length())
    {
        if (emailPart[i] == '.' && emailPart[i + 1] == '.') return true;
    }
    return false;
}

bool checkFirstPart(std::string firstPart)
{
    std::string possibleChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'*+-/=?^_`{|}~;.";

    for (int i = 0; i < firstPart.length(); i++)
    {
        bool pointCheck = checkForPoint(firstPart, i);
        if (pointCheck) return false;

        bool faultyChar = true;
        for (int j = 0; j < possibleChars.length(); j++)
        {
            if (firstPart[i] == possibleChars[j])
            {
                faultyChar = false;
                break;
            }
        }
        if (faultyChar) return false;
    }
    return true;
}

bool checkSecondPart(std::string secondPart)
{
    std::string possibleChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.";
    for (int i = 0; i < secondPart.length(); i++)
    {
        bool pointCheck = checkForPoint(secondPart, i);
        if (pointCheck) return false;

        bool faultyChar = true;
        for (int j = 0; j < possibleChars.length(); j++)
        {
            if (secondPart[i] == possibleChars[j])
            {
                faultyChar = false;
                break;
            }
        }
        if (faultyChar) return false;
    }
    return true;
}

int main() {

    while (true)
    {
        std::string email;

        std::cout << "Enter email address: ";
        std::cin >> email;

        if (email == "quit") break;

        std::string firstPart;
        int indexOfAt;
        std::tie(firstPart, indexOfAt) = findFirstPart(email);
        std::string secondPart = findSecondPart(email, indexOfAt);

        bool firstPartCheck = checkFirstPart(firstPart);
        bool secondPartCheck = checkSecondPart(secondPart);

        if (
                (firstPartCheck && secondPartCheck)
                && (secondPart.length() > 0 && secondPart.length() <= 63)
                && (firstPart.length() > 0 && firstPart.length() <= 64)
                )
            std::cout << "Correct email." << std::endl;
        else std::cout << "Incorrect email." << std::endl;
    }
}