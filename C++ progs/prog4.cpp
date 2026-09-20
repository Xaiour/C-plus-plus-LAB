#include <iostream>
using namespace std;

class Shape {
private:
    double radius;
    double length;
    double width;

public:
    Shape(double r) {
        radius = r;
        length = 0;
        width = 0;
        cout << "Constructor: Circle object created." << endl;
    }
    Shape(double l, double w) {
        radius = 0;
        length = l;
        width = w;
        cout << "Constructor: Rectangle object created." << endl;
    }
    void calculateCirclePerimeter() {
        double perimeter = 2 * 3.14159 * radius;
        cout << "Perimeter of Circle: " << perimeter << endl;
    }
    void calculateRectanglePerimeter() {
        double perimeter = 2 * (length + width);
        cout << "Perimeter of Rectangle: " << perimeter << endl;
    }
    ~Shape() {
        cout << "Destructor: Shape object destroyed." << endl;
    }
};

int main() {
    Shape c(7.0);
    c.calculateCirclePerimeter();
    
    cout << "----------------------------------" << endl;

    Shape r(10.0, 5.0);
    r.calculateRectanglePerimeter();
    
    cout << "----------------------------------" << endl;

    return 0;
}