#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};

class Line : public Point {
public:
    Point p1;
    Point p2;
    double length;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {
        length = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

int main() {
    Point point1(1, 2);
    Point point2(4, 6);

    Line line(point1, point2);

    cout << "Line Length: " << line.length;
}
