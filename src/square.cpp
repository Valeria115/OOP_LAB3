#include "../include/square.h"

#include <iostream>
#include <istream>
#include <memory>

using namespace std;

Square::Square(const Point& topL, double sideLen)
    : Rectangle(topL, Point(topL.x() + sideLen, topL.y() - sideLen)), m_sideLen(sideLen) {}

Point Square::center() const {
    double centerX = m_topL.x() + m_sideLen / 2;
    double centerY = m_topL.y() - m_sideLen / 2;
    return Point(centerX, centerY);
}

double Square::area() const {
    return m_sideLen * m_sideLen;
}

void Square::print(ostream& os) const {
    os << "Square: top left(" << m_topL.x() << ", " << m_topL.y() << ") "
    << "Side length(" << m_sideLen << ") ";
}

void Square::read(istream& is) {
    double x, y, side;
    is >> x >> y >> side;
    m_topL = Point(x, y);
    m_sideLen = side;
}

unique_ptr<Figure> Square::clone() const {
    return make_unique<Square>(*this);
}

bool Square::equals(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare == nullptr) {
        return false;
    }

    return (m_topL == otherSquare->m_topL) && (m_sideLen == otherSquare->m_sideLen);
}