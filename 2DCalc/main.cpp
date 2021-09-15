//#include "Point/point.h"
//#include "Vector/vector.h"
//#include "Line/line.h"
//#include "Polygon/polygon.h"
#include "Command/command.h"

int main()
{
    /*Point A("A", 4, -1);
    Point B("B", 4, 4);
    Point C("C", -1, 1);
    Point D("D", 5, -3);
    Point E("E", -4, 1);
    Point F("F", 8, 6);
    Point G("G", 10, 2);
    Point M("M", 7, 2);
    std::cout << "as";

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
    std::cout << poly;*/
    //std::cout << poly.area();
    //std::cin >> a;
    std::string command;
    CommandOperator *com = com->getInstance();
    //std::cout << "out";

    while (true)
    {
        std::getline(std::cin, command);
        if (command == "end")
            break;

        try
        {
            com->initiateCommand(command);
            command.clear();
        }
        catch (const std::invalid_argument &err)
        {
            std::cout << err.what() << std::endl;
        }
    }

    com->print();

    return 0;
}