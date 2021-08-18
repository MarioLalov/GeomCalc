#define PI 3.14159265

#include "vector.h"
#include "math.h"

Vector::Vector(Point &in_start, Point &in_end)
{
    label = in_start.getLabel() + in_end.getLabel();
    x = in_end.getX() - in_start.getX();
    y = in_end.getY() - in_start.getY();
}

float Vector::orientation(Vector& other)
{
    return this->x*other.y - this->y*other.x;
}

float Vector::dotWith(Vector& other)
{
    return this->x*other.x + this->y*other.y;
}

float Vector::getLenght()
{
    return sqrt(dotWith(*this));
}

float Vector::angleBetween(Vector& other)
{
    return acos(this->dotWith(other)/(this->getLenght()*other.getLenght()));
}

