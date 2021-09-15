#include "object.h"

std::string& Object::getName()
{
    return name;
}

bool Object::operator==(Object &other)
{
    return this->name == other.name || other == this; 
}

std::ostream &operator<<(std::ostream &stream, Object &object)
{
    stream << object.label << std::endl;

    return stream;
}