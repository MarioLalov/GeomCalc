#include "command.h"

CommandOperator *CommandOperator::instance = nullptr;

bool CommandOperator::checkForExistence(Object *current)
{
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        if (*current == *objects[i])
        {
            return true;
        }
    }

    return false;
}

void CommandOperator::setComand(std::string &input)
{
    std::string param;
    command.clear();
    params.clear();

    std::size_t endPos;
    std::size_t startPos;

    //get command
    endPos = input.find(' ');
    command = input.substr(0, endPos);

    //make command in upper case
    toUpper(command);

    //get parameters
    while (endPos < input.length())
    {
        while (input[endPos + 1] == ' ')
        {
            endPos++;
        }

        startPos = endPos + 1;

        if (input[startPos] == '"')
        {
            startPos += 1;
            endPos = input.find('"', startPos);

            param = input.substr(startPos, endPos - startPos);

            endPos++;
        }
        else
        {
            endPos = input.find(' ', startPos);

            param = input.substr(startPos, endPos - startPos);
        }

        params.push_back(param);
    }
}

Object *CommandOperator::getObject(std::string &obj_name)
{
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i]->getName() == obj_name)
        {
            return objects[i];
        }
    }

    return nullptr;
}

bool validateType(const std::type_info &object, const std::type_info &type)
{
    return (object.hash_code() == type.hash_code());
}

CommandOperator *CommandOperator::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CommandOperator();
    }

    return instance;
}

void toUpper(std::string &input) //make whole string to upper
{
    for (std::size_t i = 0; i < input.length(); i++)
    {
        input[i] = std::toupper(input[i]);
    }
}

//Create point A 2 3
//create line through A through B
//create line paralel a through A

void CommandOperator::initiateCommand(std::string &fullCommand)
{
    setComand(fullCommand);

    if (command == "CREATE")
    {
        Object *cur = nullptr;

        toUpper(params[0]);

        if (params[0] == "POINT")
        {
            if (params.size() == 1)
            {
                cur = new Point;

                if (checkForExistence(cur))
                {
                    throw std::invalid_argument("Object already created!");
                }
                objects.push_back(cur);
            }
            else if (params.size() == 4)
            {
                //TODO: error handling for stoi
                cur = new Point(params[1], std::stof(params[2]), std::stof(params[3]));

                if (checkForExistence(cur))
                {
                    throw std::invalid_argument("Object already created!");
                }
                objects.push_back(cur);
            }
            else
            {
                throw std::invalid_argument("Invalid arguments for POINT");
            }
        }
        else if (params[0] == "LINE")
        {
            if (params.size() == 6)
            {
                Object *paralel = nullptr;
                Object *point1 = nullptr;
                Object *point2 = nullptr;
                bool paralel_used = false;

                for (int i = 2; i < 6; i += 2)
                {
                    toUpper(params[i]);
                    if (params[i] == "PARALEL" && !paralel_used)
                    {
                        paralel_used = true;
                        paralel = getObject(params[i + 1]);
                    }
                    else if (params[i] == "THROUGH")
                    {
                        if (point1)
                        {
                            point2 = getObject(params[i + 1]);
                        }
                        else
                        {
                            point1 = getObject(params[i + 1]);
                        }
                    }
                    else
                    {
                        throw std::invalid_argument("Invalid arguments for LINE");
                    }
                }

                if (!paralel)
                {
                    if (typeid(*point1) != typeid(Point) ||
                        typeid(*point2) != typeid(Point))
                    {
                        throw std::invalid_argument("Invalid arguments for LINE");
                    }

                    Point *p1 = dynamic_cast<Point *>(point1);
                    Point *p2 = dynamic_cast<Point *>(point2);

                    cur = new Line(params[1], *p1, *p2);

                    if (checkForExistence(cur))
                    {
                        throw std::invalid_argument("Object already created!");
                    }
                    objects.push_back(cur);
                }
                else if (point1)
                {
                    //error

                    Point *p1 = dynamic_cast<Point *>(point1);
                    Line *l = dynamic_cast<Line *>(paralel);

                    cur = new Line(params[1], *p1, *l);

                    if (checkForExistence(cur))
                    {
                        throw std::invalid_argument("Object already created!");
                    }
                    objects.push_back(cur);
                }
                else if (point2)
                {
                    //error

                    Point *p2 = dynamic_cast<Point *>(point2);
                    Line *l = dynamic_cast<Line *>(paralel);

                    cur = new Line(params[1], *p2, *l);

                    if (checkForExistence(cur))
                    {
                        throw std::invalid_argument("Object already created!");
                    }
                    objects.push_back(cur);
                }
                else
                {
                    throw std::invalid_argument("Invalid arguments for LINE");
                }
            }
            else
            {
                throw std::invalid_argument("Invalid arguments for LINE");
            }
        }
        else if (params[0] == "VECTOR")
        {
            if (params.size() == 4)
            {
                //error for stof
                cur = new Vector(params[1], std::stof(params[2]), std::stof(params[3]));

                throw std::invalid_argument("Too many arguments for VECTOR");
            }
            else if (params.size() == 3)
            {
                Object *point;
                Point *points[2];

                std::size_t cnt = 0;
                for (std::size_t i = 1; i < params.size(); i++)
                {
                    point = getObject(params[i]);

                    if (!point || typeid(*point) != typeid(Point))
                    {
                        throw std::invalid_argument("All arguments for VECTOR must be points");
                    }

                    points[cnt] = dynamic_cast<Point *>(point);
                    cnt++;
                }

                cur = new Vector(*points[0], *points[1]);

                if (checkForExistence(cur))
                {
                    throw std::invalid_argument("Object already created!");
                }
                objects.push_back(cur);
            }
        }
        else if (params[0] == "TRIANGLE")
        {
            if (params.size() != 4)
            {
                throw std::invalid_argument("Too many arguments for TRIANGLE");
            }

            Object *point = nullptr;
            Point *points[3];

            std::size_t cnt = 0;
            for (std::size_t i = 1; i < params.size(); i++)
            {
                point = getObject(params[i]);

                if (!point || typeid(*point) != typeid(Point))
                {
                    throw std::invalid_argument("All arguments for TRIANGLE must be points");
                }

                points[cnt] = dynamic_cast<Point *>(point);
                cnt++;
            }

            cur = new Triangle(points[0], points[1], points[2]);

            if (checkForExistence(cur))
            {
                throw std::invalid_argument("Object already created!");
            }
            objects.push_back(cur);
        }
        else if (params[0] == "POLYGON")
        {
            std::vector<Point *> points;
            Object *point;

            for (std::size_t i = 1; i < params.size(); i++)
            {
                point = getObject(params[i]);

                if (!point || typeid(*point) != typeid(Point))
                {
                    throw std::invalid_argument("All arguments for POLYGON must be points");
                }

                points.push_back(dynamic_cast<Point *>(point));
            }

            cur = new Polygon(points);

            if (checkForExistence(cur))
            {
                throw std::invalid_argument("Object already created!");
            }
            objects.push_back(cur);
        }
        else
        {
            throw std::invalid_argument("Unknown object: " + params[0]);
        }
    }
    else if (command == "GET")
    {
        toUpper(params[0]);

        if (params[0] == "INTERSECTION")
        {
            if (params.size() == 3)
            {
                Object *line1 = getObject(params[1]);
                Object *line2 = getObject(params[2]);

                if (typeid(*line1).hash_code() != typeid(Line).hash_code() ||
                    typeid(*line2).hash_code() != typeid(Line).hash_code())
                {
                    throw std::invalid_argument("All arguments must be lines");
                }

                Line *l1 = dynamic_cast<Line *>(line1);
                Line *l2 = dynamic_cast<Line *>(line2);

                Point *intersect = new Point();
                intersect = l1->getIntesection(*l2);
                //TODO: check if it exists
                std::cout << *intersect;

                if (getConfirmation("Do you want to save this point?"))
                {
                    Object* cur = intersect;
                    if(checkForExistence(cur))
                    {
                        throw std::invalid_argument("Point already exists");
                    }

                    objects.push_back(intersect);
                }
            }
            else
            {
                throw std::invalid_argument("Invalid arguments for INTERSECTION");
            }
        }
        else if (params[0] == "AREA")
        {
            Object* cur = getObject(params[1]);

            if(typeid(*cur).hash_code() != typeid(Polygon).hash_code() &&
                typeid(*cur).hash_code() != typeid(Triangle).hash_code())
            {
                throw std::invalid_argument("Invalid arguments for AREA");
            }

            Shape* shape = dynamic_cast<Shape*>(cur);

            std::cout << "area of " << shape->getName() << " = " << shape->area() << std::endl;
        }
    }
}

void CommandOperator::print()
{
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        std::cout << *objects[i];
    }
}

CommandOperator::~CommandOperator()
{
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }
}

bool getConfirmation(std::string question)
{
    char answer;

    std::cout << question << "(Y/N): ";
    std::cin >> answer;

    return toupper(answer) == 'Y';
}