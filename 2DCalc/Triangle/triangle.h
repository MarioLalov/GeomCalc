#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Point/point.h"
#include "../Line/line.h"
#include "../Vector/vector.h"
#include <iostream>
#include <string>

class Triangle
{
private:
    std::string label;
    Point A;
    Point B;
    Point C;

public:
    Triangle();
    Triangle(Point &in_A, Point &in_B, Point &in_C)
        : label(in_A.getLabel() + in_B.getLabel() + in_C.getLabel()), A(in_A), B(in_B), C(in_C){};

    bool checkIfInside(Point &point);
    float area();
    friend std::ostream &operator<<(std::ostream &stream, Triangle &triangle);
};

#endif