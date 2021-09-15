#ifndef COMMAND_H
#define COMMAND_H

#include "../Object/object.h"
#include "../Shape/shape.h"
#include "../Point/point.h"
#include "../Polygon/polygon.h"
#include "../Vector/vector.h"
#include "../Triangle/triangle.h"
#include "../Line/line.h"
#include <vector>
#include <string>
#include <typeinfo>

class CommandOperator
{
private:
    static CommandOperator *instance;

    std::string command;
    std::vector<std::string> params;
    std::vector<Object *> objects;

    CommandOperator(){};
    void setComand(std::string &input);
    Object *getObject(std::string &obj_name);
    bool validateType(const std::type_info &object, const std::type_info &type);
    bool checkForExistence(Object *current);

public:
    CommandOperator *getInstance();
    void initiateCommand(std::string &fullCommand);
    void print();
    ~CommandOperator();
};

bool getConfirmation(std::string question);
void toUpper(std::string &input);

#endif