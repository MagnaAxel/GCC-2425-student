#include <string>
#include <math.h>

#ifndef _CHAPTER_O_POINT_2D_HPP_
#define _CHAPTER_O_POINT_2D_HPP_

class Point2D
{
private:
    float x, y;

public:
    static int count;
    int num;

    Point2D(): x(0), y(0) { num = ++count; };
    Point2D(const float& x, const float& y) : x(x), y(y) { num = ++count; };
    Point2D(const Point2D& p) : x(p.x), y(p.y) { num = ++count; };
    ~Point2D() {};

    void translate(const float& tx, const float& ty){ x, y = tx, ty; };
    float absciss(){ return x; };
    float ordinate(){ return y; };

    void homothety(const float& factor) { x, y *= factor, factor; }; 
    float rho() { return sqrt(x * x + y * y); };
    float theta() { return atan2(y, x); };
    void rotate(const float& angle) {
        x = x * cos(angle) - y * sin(angle);
        y = x * sin(angle) + y * cos(angle);
    };

    friend std::ostream& operator<<(std::ostream& os, const Point2D& p) { return os << "x:" + std::to_string(p.x) + " y:" + std::to_string(p.y) + " num:" + std::to_string(p.num); };
    std::string toString() { return std::string( "x:" + std::to_string(x) + " y:" + std::to_string(y) ); };
};

#endif // _CHAPTER_O_POINT_2D_HPP_

/*
2.i Count est statique, il est partagé par toutes les instances. Son role est de compter le nombre de points créés.

3.a Elles doivent être privées pour des raisons de sécurité, maintenabilité et évolutivité.

3.b Cela permet de protéger les données tout en les rendant accessibles au classes descendantes.
*/