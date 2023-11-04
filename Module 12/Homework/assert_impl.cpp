#include <cassert>
#include <iostream>

float travelTime(float distance, float speed) {
    assert(speed > 0);
    return distance / speed;
}

int main() {
    std::cout << "Enter traveled distance: ";
    float dist;
    std::cin >> dist;
    std::cout << "Enter speed: ";
    float speed;
    std::cin >> speed;
    float time = travelTime(dist, speed);
    std::cout << "You traveled for " << time << std::endl;
    return 0;
}
