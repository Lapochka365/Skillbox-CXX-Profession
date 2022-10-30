#include <iostream>
#include <cmath>

int countDots(std::string ip_address)
{
    int counter = 0;
    for (int i = 0; i < ip_address.length(); i++)
    {
        if (ip_address[i] == '.')
            counter += 1;
    }
    return counter;
}

std::string getPartIPaddress(std::string ip_address, int octet_num)
{
    std::string part_of_address;
    int cur_octet = 0;
    for (int i = 0; i < ip_address.length(); i++)
    {
        if (ip_address[i] == '.')
            cur_octet += 1;
        else if (octet_num == cur_octet)
            part_of_address += ip_address[i];
        if (octet_num < cur_octet)
            break;
    }
    return part_of_address;
}

bool checkOctetOfIPaddress(std::string octet_part_of_ip)
{
    bool valid_octet = true;
    int octet_sum = 0;

    if (
            octet_part_of_ip.length() == 0
            || octet_part_of_ip.length() > 3
            || (octet_part_of_ip.length() > 1 && octet_part_of_ip[0] == '0')
            )
        return false;

    for (int i = 0; i < octet_part_of_ip.length() && valid_octet; i++)
    {
        if (octet_part_of_ip[i] < '0' || octet_part_of_ip[i] > '9')
            valid_octet = false;
        octet_sum += (octet_part_of_ip[i] - '0') * (int)std::pow(10., octet_part_of_ip.length() - 1 - i);
    }

    if (octet_sum > 255)
        valid_octet = false;
    return valid_octet;
}

int main()
{
    while (true)
    {
        std::string ip_address;

        std::cout << "Enter the IP-address: ";
        std::cin >> ip_address;
        if (ip_address == "quit")
            break;

        bool valid_address = true;

        int count_of_dots = countDots(ip_address);
        if (count_of_dots != 3)
            valid_address = false;
        else
        {
            for (int i = 0; i < 4 && valid_address; i++)
            {
                std::string n_part_address = getPartIPaddress(ip_address, i);
                if (!checkOctetOfIPaddress(n_part_address))
                    valid_address = false;
            }
        }
        if (valid_address)
            std::cout << "Valid IP-address." << std::endl;
        else
            std::cout << "Invalid IP-address." << std::endl;
    }
}