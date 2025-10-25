#pragma once

#include "../include/figure.h"
#include "../include/point.h"

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(const Point& topL, const Point& topR, const Point& botL, const Point& botR);

    Point center() const override;  
    double area() const override;
    void print(std::ostream& os) const override; 
    void read(std::istream& is) override; 
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure& other) const override;

private:
    Point m_topL;
    Point m_topR;
    Point m_botL;
    Point m_botR;
};
