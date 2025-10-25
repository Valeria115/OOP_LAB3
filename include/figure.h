#pragma once

#include <cstddef>
#include <memory>  
#include <iosfwd>    
#include "point.h"


class Figure {
public:
    Figure() = default;
    virtual ~Figure() = default;

    Figure(const Figure&) = default;
    Figure& operator=(const Figure&) = default;
    Figure(Figure&&) noexcept = default;
    Figure& operator=(Figure&&) noexcept = default;

    // virtual method
    virtual Point center() const = 0;
    virtual double area() const = 0;
    explicit operator double() const;
    
    //input and output
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    //cloning (polimorf)
    virtual std::unique_ptr<Figure> clone() const = 0;

    virtual bool equals(const Figure& other) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
    friend bool operator==(const Figure& a, const Figure& b);

protected:
    static double polygon_signed_area(const Point* pts, std::size_t n);
    static Point polygon_centroid(const Point* pts, std::size_t n);
    static double triangle_area(const Point& a, const Point& b, const Point& c);

};
