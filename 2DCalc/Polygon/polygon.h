#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include "../Point/point.h"
#include "../Line/line.h"
#include "../Triangle/triangle.h"
#include "../Vector/vector.h"
#include "../Shape/shape.h"

class Polygon : public Shape
{
private:
    std::vector<Point*> vertices;
    std::vector<Triangle> triangles;

    bool checkIfEar(std::size_t startIndex, std::vector<Point*> &curVertices);
    void triagonalise();

public:
    Polygon(std::vector<Point*> &in_vertices);
    bool checkIfInside(Point &point);
    //bool compareWith(Object &other);
    bool operator==(Object *other);
    float area();

    //friend std::ostream& operator<<(std::ostream& stream, Polygon& polygon);
};

#endif