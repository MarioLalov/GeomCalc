#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Point/point.h"
#include "../Line/line.h"
#include "../Vector/vector.h"
#include "../Shape/shape.h"

#include <iostream>
#include <string>

class Triangle : public Shape
{
private:
    Point* A;
    Point* B;
    Point* C;

public:
    Triangle();
    Triangle(Point* in_A, Point* in_B, Point* in_C);

    bool checkIfInside(Point &point) override;
    //bool compareWith(Object *other) override;
    bool operator==(Object *other);
    float area();
    //friend std::ostream &operator<<(std::ostream &stream, Triangle &triangle);
};

#endif