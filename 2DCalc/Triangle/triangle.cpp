#include "triangle.h"
#include "math.h"

Triangle::Triangle(Point *in_A, Point *in_B, Point *in_C)
{
    label  = "tri(" + in_A->getLabel() + in_B->getLabel() + in_C->getLabel() + ")";
    name  = in_A->getName() + in_B->getName() + in_C->getName();
    A = in_A;
    B = in_B;
    C = in_C;
}

bool Triangle::checkIfInside(Point &point)
{
    return (Line("a", *A, *B).sameHalfPlane(*C, point) &&
            Line("b", *B, *C).sameHalfPlane(*A, point) &&
            Line("c", *A, *C).sameHalfPlane(*B, point));
}

bool Triangle::operator==(Object *other)
{
    if (typeid(*other).hash_code() != typeid(Triangle).hash_code())
    {
        return false;
    }

    Triangle *t_other = dynamic_cast<Triangle *>(other);

    return t_other->A == this->A &&  t_other->B == this->B && t_other->C == this->C;
}

float Triangle::area()
{
    Vector v1(*A, *B);
    Vector v2(*A, *C);

    float side1 = v1.getLenght();
    float side2 = v2.getLenght();
    float angle = v1.angleBetween(v2);

    return 0.5*side1*side2*sin(angle);
}

/*std::ostream &operator<<(std::ostream &stream, Triangle& triangle)
{
    stream << triangle.label << std::endl; 
    /*stream << "--------------------" << std::endl;
    stream << triangle.A << std::endl;
    stream << triangle.B << std::endl;
    stream << triangle.C << std::endl;
    stream << "--------------------" << std::endl;*/

    //return stream;
//}