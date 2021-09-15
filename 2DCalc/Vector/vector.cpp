#define PI 3.14159265

#include "vector.h"
#include "math.h"

Vector::Vector(std::string& in_label, float in_x, float in_y)
{
    label = "v" + in_label;
    name = in_label;
    x = in_x;
    y = in_y;
}

Vector::Vector(Point &in_start, Point &in_end)
{
    name = in_start.getName() + in_end.getName();
    label = "v" + in_start.getLabel() + in_end.getLabel();
    x = in_end.getX() - in_start.getX();
    y = in_end.getY() - in_start.getY();
}

float Vector::orientation(Vector& other)
{
    return this->x*other.y - this->y*other.x;
}

bool Vector::operator==(Object *other)
{
    if (typeid(*other).hash_code() != typeid(Vector).hash_code())
    {
        return false;
    }

    Vector *v_other = dynamic_cast<Vector *>(other);

    return v_other->x == this->x && v_other->y == this->y;
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

