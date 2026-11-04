#include <iostream>
#include <cmath>

float FindDistance(float x1, float y1, float x2, float y2);

int main() {
    float x1, y1, x2, y2;

    std::cout << "Enter coordinates of first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter coordinates of second point (x2 y2): ";
    std::cin >> x2 >> y2;

    float distance = FindDistance(x1, y1, x2, y2);

    std::cout << "Distance between the points: " << distance << std::endl;

}
float FindDistance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}