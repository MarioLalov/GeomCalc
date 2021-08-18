#ifndef VECTOR_H
#define VECTOR_H

#include "../Point/point.h"
#include <string>

class Vector
{
private:
    std::string label;
    float x;
    float y;

public:
    Vector(std::string in_label, float in_x, float in_y) 
        : label(in_label), x(in_x), y(in_y){};
    Vector(Point &in_start, Point &in_end);
    
    float dotWith(Vector &other);
    float getLenght();
    float angleBetween(Vector &other);
    float orientation(Vector &other);
};

#endif