#include "../include/figureArray.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>

using namespace std;

FigureArray::FigureArray() : m_size(0), m_figures(nullptr) {}

FigureArray::~FigureArray() {
    for (size_t i = 0; i < m_size; ++i) {
        delete m_figures[i];
    }
    delete[] m_figures;
}

void FigureArray::addFigure(unique_ptr<Figure> figure) {
    if (m_size == 0) {
        m_figures = new Figure*[1];
    } else {
        increaseArray();
    }

    m_figures[m_size] = figure.release();
    ++m_size;
}

Figure* FigureArray::getFigure(size_t idx) const {
    if (idx >= m_size) {
        throw out_of_range("Index out of range");
    }
    return m_figures[idx];
}

void FigureArray::removeFigure(size_t idx) {
    if (idx >= m_size) {
        throw out_of_range("Index out of range");
    }
    delete m_figures[idx];
    
    for (size_t i = idx; i < m_size - 1; ++i) {
        m_figures[i] = m_figures[i + 1];
    }

    --m_size;
}

void FigureArray::printFigures() const {
    for (size_t i = 0; i < m_size; ++i) {
        m_figures[i]->print(cout);
        cout << endl;
    }
}

double FigureArray::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < m_size; ++i) {
        total += m_figures[i]->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return m_size;
}

void FigureArray::increaseArray() {
    Figure** newFigures = new Figure*[m_size + 1];

    for (size_t i = 0; i < m_size; ++i) {
        newFigures[i] = m_figures[i];
    }
    delete[] m_figures;
    m_figures = newFigures;
}
