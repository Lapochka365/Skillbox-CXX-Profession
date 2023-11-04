#include <iostream>

const int APARTS_COUNT = 10;

int main() {
    std::string aparts[APARTS_COUNT];
    for (int i = 0; i < APARTS_COUNT; i++) {
        std::cout << "Enter the apartments owner surname:" << std::endl;
        std::cin >> aparts[i];
    }
    do {
        std::cout << "Enter the apartments number:" << std::endl;
        int n;
        std::cin >> n;
        if (n > APARTS_COUNT) {
            std::cout
                << "The apartments number exceeds maximum count of apartments"
                << std::endl;
        } else if (n < 1) {
            std::cout << "The apartments number cannot below 1" << std::endl;
        } else {
            std::cout << aparts[n - 1] << std::endl;
        }
    } while (true);
    return 0;
}
