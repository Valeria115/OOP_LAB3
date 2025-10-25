#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include "figure.h"


class FigureArray {
public:
    FigureArray();
    ~FigureArray();

    FigureArray(const FigureArray&) = delete;
    FigureArray& operator=(const FigureArray&) = delete;
    FigureArray(FigureArray&&) = delete;
    FigureArray& operator=(FigureArray&&) = delete;

    void addFigure(std::unique_ptr<Figure> figure);

    Figure* getFigure(std::size_t index) const;
    void removeFigure(std::size_t index);

    void printFigures() const;

    double totalArea() const;

    std::size_t size() const;

private:
    Figure** m_figures;
    std::size_t m_size;

    void increaseArray();
};

