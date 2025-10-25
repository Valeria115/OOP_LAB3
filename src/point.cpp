#include "../include/point.h"

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::x() const {
    return m_x;
}

double Point::y() const {
    return m_y;
}

void Point::setX(double newX) {
    m_x = newX;
}

void Point::setY(double newY) {
    m_y = newY;
}

bool Point::operator==(const Point& other) const {
    return m_x == other.m_x && m_y == other.m_y;
}