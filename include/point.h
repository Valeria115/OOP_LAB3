#pragma once

class Point {
public:
    Point() = default;
    Point(double x, double y);

    double x() const;
    double y() const;

    void setX(double newX);
    void setY(double newY);

    bool operator==(const Point& other) const;

private:
    double m_x = 0.0;
    double m_y = 0.0;
};