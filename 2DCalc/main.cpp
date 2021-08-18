#include "Vector/vector.h"
#include "Point/point.h"
#include "Polygon/polygon.h"

int main()
{
    Point A("A", 4, -1);
    Point B("B", 4, 4);
    Point C("C", -1, 1);
    Point D("D", 5, -3);
    Point E("E", -4, 1);
    Point F("F", 8, 6);
    Point G("G", 10, 2);
    Point M("M", 7, 2);

    std::vector<Point> points;
    points.push_back(A);
    points.push_back(B);
    points.push_back(E);
    points.push_back(F);
    points.push_back(G);
    points.push_back(D);
    points.push_back(C);

    Polygon poly(points);
    std::cout << poly.checkIfInside(M);
    std::cout << poly;
    //std::cout << poly.area();

    return 0;
}