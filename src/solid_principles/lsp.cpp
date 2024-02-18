#include <iostream>
#include "lsp.hpp"

Rectangle::Rectangle(int width,
                     int height) : width{width},
                                   height{height}
{
}

// Don't forget to include the 'const' keyword
int Rectangle::getWidth() const
{

    return this->width;
}

void Rectangle::setWidth(int width)
{

    this->width = width;
}

int Rectangle::getHeight() const
{

    return this->height;
}

void Rectangle::setHeight(int height)
{

    this->height = height;
}

int Rectangle::area() const
{

    return this->width * this->height;
}

void process(Rectangle &r)
{

    int width = r.getWidth();
    r.setHeight(10);

    std::cout << "expected area = " << (width * 10)
              << ", got area = "
              << r.area() << std::endl;
}

Square::Square(int size) : Rectangle(size, size) {}

void Square::Square::setHeight(int height)
{

    this->width = this->height = height;
}

void Square::Square::setWidth(int width)
{

    this->width = this->height = width;
}