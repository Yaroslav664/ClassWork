#include <iostream>
using namespace std;

class Figure {
public:
    string name;
    int square;
    int lineThinkness;
    string lineColor;
    string fillColor;

    Figure(string n, int s, int lt, string lc, string fc)
        : name(n), square(s), lineThinkness(lt), lineColor(lc), fillColor(fc) {}
};

class Rectangle : public Figure {
public:
    int width;
    int height;

    Rectangle(string n, int s, int lt, string lc, string fc, int w, int h)
        : Figure(n, s, lt, lc, fc), width(w), height(h) {}
};

class Circle : public Figure {
public:
    int radius;

    Circle(string n, int s, int lt, string lc, string fc, int r)
        : Figure(n, s, lt, lc, fc), radius(r) {}
};

class Triangle : public Figure {
public:
    int base;
    int height;

    Triangle(string n, int s, int lt, string lc, string fc, int b, int h)
        : Figure(n, s, lt, lc, fc), base(b), height(h) {}
};

int main() {
    Rectangle rectangle("Rectangle", 100, 2, "Black", "Red", 10, 5);
    Circle circle("Circle", 78, 1, "Blue", "Green", 6);
    Triangle triangle("Triangle", 25, 3, "Purple", "Yellow", 7, 4);

    cout << "Name: " << rectangle.name;
}
