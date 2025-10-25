#pragma once

#include "../include/figure.h"
#include "../include/point.h"
#include <iostream>
#include <istream>
#include <memory>
#include <ostream>

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(const Point& topL, const Point& botR);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure& other) const override;

protected:
    Point m_topL;
    Point m_botR;
};