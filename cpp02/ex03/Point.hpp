#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <sstream>

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(float const x, float const y);
        virtual ~Point();
        Point(Point const &other);
        Point &operator=(Point const &other);
        std::string putPoint() const;
        static int sign(Point const &p1, Point const &s2, Point const &s3);
};

std::ostream &operator<<(std::ostream &ost, Point const &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
