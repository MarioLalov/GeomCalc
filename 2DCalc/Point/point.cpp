#include "point.h"

Point::Point(const Point& other)
{
    this->label = other.label;
    this->x = other.x;
    this->y = other.y;
}

float Point::getX() const
{
    return x;
}

float Point::getY() const
{
    return y;
}

std::string Point::getLabel() const
{
    return label;
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->label = other.label;
        this->x = other.x;
        this->y = other.y;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &stream, Point& point)
{
    stream << point.label << "(" << point.x << "," << point.y << ")" << std::endl;

    return stream;
}