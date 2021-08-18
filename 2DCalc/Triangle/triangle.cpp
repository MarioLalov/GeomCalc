#include "triangle.h"
#include "math.h"

bool Triangle::checkIfInside(Point &point)
{
    return (Line("a", A, B).sameHalfPlane(C, point) &&
            Line("b", B, C).sameHalfPlane(A, point) &&
            Line("c", A, C).sameHalfPlane(B, point));
}

float Triangle::area()
{
    Vector v1(A, B);
    Vector v2(A, C);

    float side1 = v1.getLenght();
    float side2 = v2.getLenght();
    float angle = v1.angleBetween(v2);

    return 0.5*side1*side2*sin(angle);
}

std::ostream &operator<<(std::ostream &stream, Triangle& triangle)
{
    stream << triangle.label << std::endl; 
    /*stream << "--------------------" << std::endl;
    stream << triangle.A << std::endl;
    stream << triangle.B << std::endl;
    stream << triangle.C << std::endl;
    stream << "--------------------" << std::endl;*/

    return stream;
}