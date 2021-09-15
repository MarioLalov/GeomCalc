#ifndef VECTOR_H
#define VECTOR_H

#include "../Point/point.h"
#include "../Object/object.h"
#include <string>

class Vector : public Object
{
private:
    //std::string label;
    float x;
    float y;

public:
    Vector(std::string &in_label, float in_x, float in_y);
    Vector(Point &in_start, Point &in_end);

    bool operator==(Object *other);
    float dotWith(Vector &other);
    float getLenght();
    float angleBetween(Vector &other);
    float orientation(Vector &other);
};

#endif