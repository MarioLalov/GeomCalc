#include "line.h"
#include <sstream>

void Line::setLabel(std::string &in_label)
{
    std::stringstream ss;
    ss << A;
    label = in_label + ": " + ss.str() + "x + ";
    ss = std::stringstream();
    ss << B;
    label += ss.str() + "y + ";
    ss = std::stringstream();
    ss << C;
    label += ss.str() + " = 0";
}

Line::Line(std::string in_label, Point &point1, Point &point2)
{
    A = point2.getY() - point1.getY();
    B = point1.getX() - point2.getX();
    C = point1.getY() * (point2.getX() - point1.getX()) - point1.getX() * (point2.getY() - point1.getY());

    name = in_label;
    setLabel(in_label);
}

Line::Line(std::string in_label, Point &point, Line &paralel)
{
    A = paralel.A;
    B = paralel.B;
    C = 0 - A * point.getX() - B * point.getY();

    name = in_label;
    //label = in_label + ": " + std::to_string(A) + "x + " + std::to_string(B) + "y + " + std::to_string(C) + " = 0";
    setLabel(in_label);
}

Point* Line::getIntesection(Line &other)
{
    //throw when paralel
    float x, y;
    y = (this->C * other.A - other.C * this->A) / (other.B * this->A - this->B * other.A);
    x = (0 - this->B * y - this->C) / this->A;

    Point* intersect = new Point(this->name + "x" + other.name, x, y);

    return intersect;
}

bool Line::sameHalfPlane(Point &point1, Point &point2)
{
    float firstMultiple, secondMultiple;
    firstMultiple = A * point1.getX() + B * point1.getY() + C;
    secondMultiple = A * point2.getX() + B * point2.getY() + C;

    return (firstMultiple * secondMultiple >= 0);
}

bool Line::operator==(Object *other)
{
    if (typeid(*other).hash_code() != typeid(Line).hash_code())
    {
        return false;
    }

    Line *l_other = dynamic_cast<Line *>(other);

    return l_other->A == this->A &&  l_other->B == this->B && l_other->C == this->C;
}

/*std::ostream &operator<<(std::ostream &stream, Line &line)
{
    stream << line.label << ": " << line.A << "x + " << line.B << "y + " << line.C << " = 0" << std::endl;

    return stream;
}*/