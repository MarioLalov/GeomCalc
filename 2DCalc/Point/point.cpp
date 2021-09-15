#include "point.h"
#include <sstream>

Point::Point(std::string in_label, float in_x, float in_y)
{
    std::stringstream ss;
    ss << in_x;
    label = in_label + "(" + ss.str() + ",";
    ss = std::stringstream();
    ss << in_y;
    label += ss.str() + ")";

    name  = in_label;
    x = in_x;
    y = in_y;
}

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

bool Point::operator==(Object *other)
{
    if (typeid(*other).hash_code() != typeid(Point).hash_code())
    {
        return false;
    }

    Point *p_other = dynamic_cast<Point *>(other);

    return p_other->x == this->x &&  p_other->y == this->y;
}

/*std::ostream &operator<<(std::ostream &stream, Point& point)
{
    stream << point.label << "(" << point.x << "," << point.y << ")" << std::endl;

    return stream;
}*/