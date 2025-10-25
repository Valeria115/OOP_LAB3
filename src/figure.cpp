#include "../include/figure.h"

#include <iostream>
#include <cmath>

using namespace std;


ostream& operator<<(ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

istream& operator>>(istream& is, Figure& fig) {
    fig.read(is); 
    return is;
}

bool operator==(const Figure& a, const Figure& b) {
    return a.equals(b);
}

Figure::operator double() const {
    return area();
}