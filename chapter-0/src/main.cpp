#include <iostream>
#include "../include/Point2D.hpp"

int Point2D::count = 0;

int main()
{
    Point2D p = Point2D(3, 2);
    std::cout << "absciss:" << p.absciss() << " ordinate:" << p.ordinate() << std::endl;
    return 0;
}