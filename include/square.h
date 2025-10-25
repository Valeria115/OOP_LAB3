#pragma once

#include "../include/rectangle.h"
#include "point.h"

class Square : public Rectangle {
public:
    Square() = default;
    Square(const Point& topL, double sideLen);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure& other) const override;

    double side() const { return m_sideLen; }

private:
    double m_sideLen = 0.0;
};