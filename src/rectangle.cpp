#include "../include/rectangle.h"
#include <iostream>
#include <cmath>
#include <istream>
#include <memory>
#include <ostream>

using namespace std;

Rectangle::Rectangle(const Point& topL, const Point& botR)
    : m_topL(topL), m_botR(botR) {}

Point Rectangle::center() const {
    double centerX = (m_topL.x() + m_botR.x()) / 2;
    double centerY = (m_topL.y() + m_botR.y()) / 2;
    return Point(centerX, centerY);
}

double Rectangle::area() const {
    double width = abs(m_botR.x() - m_topL.x());
    double height = abs(m_botR.y() - m_topL.y());
    return width * height;
}

void Rectangle::print(ostream& os) const {
    os << "Rectangle: Top left(" << m_topL.x() << ", " << m_topL.y() << ") "
    << "Bottom right(" << m_botR.x() << ", " << m_botR.y() << ") ";
}

void Rectangle::read(istream& is) {
    double x1, y1, x2, y2;
    is >> x1 >> y1 >> x2 >> y2;
    m_topL = Point(x1, y1);
    m_botR = Point(x2, y2);
}

unique_ptr<Figure> Rectangle::clone() const {
    return make_unique<Rectangle>(*this);
}

bool Rectangle::equals(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (otherRectangle == nullptr) {
        return false;
    }
    return (m_topL == otherRectangle->m_topL) && (m_botR == otherRectangle->m_botR);
}
