#include "polygon.h"
#include <algorithm>

Polygon::Polygon(std::vector<Point *> &in_vertices)
{
    vertices = in_vertices;

    label = "poly(";
    for (std::size_t i = 0; i < vertices.size(); i++)
    {
        label += vertices[i]->getLabel();
        name += vertices[i]->getName();
    }
    label += ")";

    triagonalise();
}

bool Polygon::checkIfEar(std::size_t startIndex, std::vector<Point *> &curVertices)
{
    std::size_t first, second, third;

    first = startIndex;
    startIndex++;
    if (startIndex > curVertices.size())
        startIndex = 0;
    second = startIndex;
    startIndex++;
    if (startIndex > curVertices.size())
        startIndex = 0;
    third = startIndex;

    Triangle current(curVertices[first], curVertices[second], curVertices[third]);

    for (std::size_t i = 0; i < curVertices.size(); i++)
    {
        if (i == first || i == second || i == third)
            continue;

        if (current.checkIfInside(*curVertices[i]))
        {
            return false;
        }
    }

    //find whether angle is [0, pi) or [pi, 2pi)
    Vector v1(*curVertices[second], *curVertices[first]);
    Vector v2(*curVertices[second], *curVertices[third]);

    return (v1.orientation(v2) > 0);
}

void Polygon::triagonalise()
{
    std::vector<Point *> buffer = vertices;

    while (buffer.size() > 3)
    {
        for (std::size_t i = 0; i < buffer.size(); i++)
        {
            std::size_t index, first, second, third;
            index = i;
            first = index;
            index++;
            if (index > buffer.size())
                index = 0;
            second = index;
            index++;
            if (index > buffer.size())
                index = 0;
            third = index;

            //check if current is an ear
            if (checkIfEar(first, buffer))
            {
                triangles.push_back(Triangle(buffer[first], buffer[second], buffer[third]));
                buffer.erase(buffer.begin() + second);
                break;
            }
        }
    }

    triangles.push_back(Triangle(buffer[0], buffer[1], buffer[2]));

/*    for (std::size_t i = 0; i < triangles.size(); i++)
    {
        std::cout << triangles[i];
    }*/
}

bool Polygon::checkIfInside(Point &point)
{
    for (std::size_t i = 0; i < triangles.size(); i++)
    {
        if (triangles[i].checkIfInside(point))
        {
            return true;
        }
    }

    return false;
}

float Polygon::area()
{
    float area = 0;

    for (std::size_t i = 0; i < triangles.size(); i++)
    {
        area += triangles[i].area();
    }

    return area;
}

bool Polygon::operator==(Object *other)
{
    if (typeid(*other).hash_code() != typeid(Polygon).hash_code())
    {
        return false;
    }

    Polygon *p_other = dynamic_cast<Polygon *>(other);

    return p_other->vertices == this->vertices;
}

/*std::ostream& operator<<(std::ostream& stream, Polygon& polygon)
{
    stream << polygon.label << std::endl;

    return stream;
}*/