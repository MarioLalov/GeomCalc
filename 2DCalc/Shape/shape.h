#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include "../Object/object.h"
#include "../Point/point.h"

class Shape : public Object
{

public:
    Shape(){};
    /*Shape(std::string in_label, std::string in_name)
        : Object(in_label, in_name){};*/

    virtual bool checkIfInside(Point &point) = 0;
    virtual float area() = 0;
};

#endif