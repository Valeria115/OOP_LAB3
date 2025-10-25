#include <iostream>
#include "include/figureArray.h"
#include "include/square.h" 
#include "include/rectangle.h"
#include "include/trapezoid.h" 
#include "include/point.h" 

using namespace std;

int main() {
    
    Point p1(0, 0); 
    Point p2(4, -3); 

    Rectangle rect(p1, p2);

    Square square(p1, 2.0);

    Point p3(0, -4);
    Point p4(4, -4);
    Trapezoid trap(p1, p2, p3, p4);

    FigureArray figureArray;

    figureArray.addFigure(make_unique<Rectangle>(rect));
    figureArray.addFigure(make_unique<Square>(square));
    figureArray.addFigure(make_unique<Trapezoid>(trap));

    cout << "Figures in the array:" << endl;
    figureArray.printFigures();

    cout << "\nTotal Area of all Figures: " << figureArray.totalArea() << endl;

    if (*figureArray.getFigure(0) == *figureArray.getFigure(1)) {
        cout << "\nThe first and second figures are equal." << endl;
    } else {
        cout << "\nThe first and second figures are not equal." << endl;
    }

    unique_ptr<Figure> clonedSquare = figureArray.getFigure(1)->clone();
    cout << "\nCloned Square:" << endl;
    cout << *clonedSquare << endl;

    return 0;
}
