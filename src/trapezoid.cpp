#include "../include/trapezoid.h"

#include <iostream>
#include <cmath>
#include <ostream>

using namespace std;

Trapezoid::Trapezoid(const Point& topL, const Point& topR, const Point& botL, const Point& botR)
    : m_topL(topL), m_topR(topR), m_botL(botL), m_botR(botR) {}


Point Trapezoid::center() const {
    double x1 = m_topL.x(), y1 = m_topL.y();
    double x2 = m_topR.x(), y2 = m_topR.y();
    double x3 = m_botR.x(), y3 = m_botR.y();
    double x4 = m_botL.x(), y4 = m_botL.y();
    
    double centerX = (x1 + x2 + x3 + x4) / 4.0;
    double centerY = (y1 + y2 + y3 + y4) / 4.0;
    
    return Point(centerX, centerY);
}


double Trapezoid::area() const {
    double x1 = m_topL.x(), y1 = m_topL.y();
    double x2 = m_topR.x(), y2 = m_topR.y();
    double x3 = m_botR.x(), y3 = m_botR.y();
    double x4 = m_botL.x(), y4 = m_botL.y();
    double area = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
    
    return area;
}



void Trapezoid::print(ostream& os) const {
    os << "Treapezoid: (" << "top left:(" << m_topL.x() << ", " << m_topL.y() << "), "
    << "top rigth: (" << m_topR.x() << ", " << m_topR.y() << "), "
    << "bottom left: (" << m_botL.x() << ", " << m_botL.y() << "), "
    << "bottom right: (" << m_botR.x() << ", " << m_botR.y() << "))";

}

void Trapezoid::read(istream& is) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    m_topL = Point(x1, y1);
    m_topR = Point(x2, y2);
    m_botL = Point(x3, y3);
    m_botR = Point(x4, y4);
}

unique_ptr<Figure> Trapezoid::clone() const {
    return make_unique<Trapezoid>(*this);
}

bool Trapezoid::equals(const Figure& other) const {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (!otherTrapezoid) return false;

    return (m_topL== otherTrapezoid->m_topL && m_topR == otherTrapezoid->m_topR &&
        m_botL == otherTrapezoid->m_botL && m_botR == otherTrapezoid->m_botR);
}
