#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

class Point
{
private:
    std::string label;
    float x;
    float y;

public:
    Point() 
        : x(0), y(0){};
    Point(std::string in_label, float in_x, float in_y)
        : label(in_label), x(in_x), y(in_y){};
    Point(const Point &other);

    float getX() const;
    float getY() const;
    std::string getLabel() const;
    Point &operator=(const Point &other);
    friend std::ostream &operator<<(std::ostream &stream, Point &point);
};

#endif