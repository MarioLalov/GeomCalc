#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <string>
#include "../Point/point.h"
#include "../Object/object.h"

class Line : public Object
{
private:
    //std::string label;
    float A;
    float B;
    float C;

    void setLabel(std::string &in_label);

public:
    Line(std::string in_label, Point &point1, Point &point2);
    Line(std::string in_label, Point &point, Line &paralel);

    Point *getIntesection(Line &other);
    bool sameHalfPlane(Point &point1, Point &point2);
    //bool compareWith(Object* other);
    bool operator==(Object *other);

    //friend std::ostream &operator<<(std::ostream &stream, Line& line);
};

#endif