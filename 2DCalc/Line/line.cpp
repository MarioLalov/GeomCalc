#include "line.h"

Line::Line(std::string in_label, Point &point1, Point &point2)
{
    label = in_label;
    A = point2.getY() - point1.getY();
    B = point1.getX() - point2.getX();
    C = point1.getY() * (point2.getX() - point1.getX()) - point1.getX() * (point2.getY() - point1.getY());
}

Line::Line(std::string in_label, Point &point, Line &paralel)
{
    label = in_label;
    A = paralel.A;
    B = paralel.B;
    C = 0 - A * point.getX() - B * point.getY();
}

Point Line::getIntesection(Line &other)
{
    float x, y;
    y = (this->C * other.A - other.C * this->A) / (other.B * this->A - this->B * other.A);
    x = (0 - this->B * y - this->C) / this->A;

    return Point(this->label + "x" + other.label, x, y);
}

bool Line::sameHalfPlane(Point &point1, Point &point2)
{
    float firstMultiple, secondMultiple;
    firstMultiple = A * point1.getX() + B * point1.getY() + C;
    secondMultiple = A * point2.getX() + B * point2.getY() + C;

    return (firstMultiple * secondMultiple >= 0);
}

std::ostream &operator<<(std::ostream &stream, Line& line)
{
    stream << line.label << ": " << line.A << "x + " << line.B << "y + " << line.C << " = 0" << std::endl;

    return stream;
}