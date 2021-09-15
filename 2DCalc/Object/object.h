#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

class Object
{
protected:
    std::string label;
    std::string name;

public:
    Object(){};
    /*Object(std::string in_label, std::string in_name)
        : label(in_label), name(in_name){};*/
    std::string& getName();
    bool operator==(Object &other);
    //virtual bool compareWith(Object* other) = 0;
    virtual bool operator==(Object *other) = 0;

    friend std::ostream &operator<<(std::ostream &stream, Object &object);
    virtual ~Object(){};
};

#endif