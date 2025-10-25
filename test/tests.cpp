#include <gtest/gtest.h>
#include "../include/rectangle.h"
#include "../include/square.h"
#include "../include/trapezoid.h"
#include "../include/point.h"
#include "../include/figureArray.h"


TEST(RectangleTest, Constructor) {
    Point p1(0, 0), p2(3, 3); 
    Rectangle rect(p1, p2);
    
    EXPECT_EQ(rect.area(), 9); 
    EXPECT_EQ(rect.center().x(), 1.5);
    EXPECT_EQ(rect.center().y(), 1.5);
}

TEST(RectangleTest, CopyConstructor) {
    Point p1(0, 0), p2(3, 3); 
    Rectangle rect1(p1, p2);
    Rectangle rect2 = rect1;
    
    EXPECT_EQ(rect1.area(), rect2.area());
    EXPECT_TRUE(rect1.equals(rect2));  
}

TEST(RectangleTest, MoveConstructor) {
    Point p1(0, 0), p2(3, 3);
    Rectangle rect1(p1, p2);
    Rectangle rect2 = std::move(rect1);
    
    EXPECT_EQ(rect2.area(), 9);
    EXPECT_EQ(rect2.center().x(), 1.5);
    EXPECT_EQ(rect2.center().y(), 1.5);
}


TEST(SquareTest, Constructor) {
    Point p1(0, 0);
    Square square(p1, 4.0); 
    
    EXPECT_EQ(square.area(), 16); 
    EXPECT_EQ(square.center().x(), 2);  
    EXPECT_EQ(square.center().y(), -2);  
}

TEST(SquareTest, Comparison) {
    Point p1(0, 0);
    Square square1(p1, 4.0);
    Square square2(p1, 4.0);
    Square square3(p1, 5.0);
    
    EXPECT_TRUE(square1.equals(square2)); 
    EXPECT_FALSE(square1.equals(square3));  
}


TEST(TrapezoidTest, Constructor) {
    Point p1(0, 0), p2(5, 0), p3(2, -3), p4(7, -3); 
    Trapezoid trap(p1, p2, p3, p4);
    
    EXPECT_EQ(trap.area(), 15);  
    EXPECT_EQ(trap.center().x(), 3.5); 
    EXPECT_EQ(trap.center().y(), -1.5); 
}


TEST(TrapezoidTest, PrintOutput) {
    Point p1(0, 0), p2(5, 0), p3(2, -3), p4(7, -3);
    Trapezoid trap(p1, p2, p3, p4);
    
    std::ostringstream oss;
    trap.print(oss);
    EXPECT_EQ(oss.str(), "Treapezoid: (top left:(0, 0), top rigth: (5, 0), bottom left: (2, -3), bottom right: (7, -3))");
}

TEST(FigureArrayTest, TotalArea) {
    Point p1(0, 0), p2(3, 3);
    Rectangle rect(p1, p2); 
    Square square(p1, 2.0); 
    Point p3(1, -4), p4(3, -4); 
    Trapezoid trap(p1, p2, p3, p4);  

    FigureArray figureArray;
    figureArray.addFigure(std::make_unique<Rectangle>(rect));
    figureArray.addFigure(std::make_unique<Square>(square));
    figureArray.addFigure(std::make_unique<Trapezoid>(trap));

    EXPECT_EQ(figureArray.totalArea(), 27.5);  
}

TEST(FigureArrayTest, RemoveFigure) {
    Point p1(0, 0), p2(4, -3);
    Rectangle rect(p1, p2);
    Square square(p1, 2.0);

    FigureArray figureArray;
    figureArray.addFigure(std::make_unique<Rectangle>(rect));
    figureArray.addFigure(std::make_unique<Square>(square));

    EXPECT_EQ(figureArray.size(), 2);

    figureArray.removeFigure(0);
    EXPECT_EQ(figureArray.size(), 1);
    EXPECT_EQ(figureArray.getFigure(0)->area(), 4);
}

TEST(TrapezoidTest, ReadInput) {
    std::istringstream input("0 0 5 0 2 -3 7 -3");
    Trapezoid trap(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0));
    
    trap.read(input);
    
    EXPECT_EQ(trap.area(), 15); 
    EXPECT_EQ(trap.center().x(), 3.5); 
    EXPECT_EQ(trap.center().y(), -1.5); 
}
