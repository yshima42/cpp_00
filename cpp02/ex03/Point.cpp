#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point::Point(Point const &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
        const_cast<Fixed &>(_x) = other._x;
        const_cast<Fixed &>(_y) = other._y;
    }
    return *this;
}

int Point::sign(Point const &p1, Point const &p2, Point const &p3)
{
    int r = ((p1._x - p3._x) * (p2._y - p3._y) - (p2._x - p3._x) * (p1._y - p3._y)).getRawBits();
    return (r > 0) - (r < 0);
}

std::string Point::putPoint() const
{
    std::stringstream s;
    s << "(" << this->_x.toFloat() << "," << this->_y.toFloat() << ")";
    return s.str();
}

std::ostream& operator<<(std::ostream &ost, Point const &point)
{
    ost << point.putPoint();
    return ost;
}
