#ifndef COMPOSITION_H
#define COMPOSITION_H

#include "../Shape/shape.h"
#include <vector>

class Composition
{
protected:
    std::vector<Shape> shapes;
};

class SectionComposition : public Composition
{
};

class UnionComposition : public Composition
{
};

#endif