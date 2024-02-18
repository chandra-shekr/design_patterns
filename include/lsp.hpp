
//! Liskov's Substituion Principle

#pragma once

struct Rectangle
{

protected:
    int width, height;

public:
    Rectangle(int, int);
    /// @brief get width
    /// @return width
    ///
    /// @attention you have to include the const qualifier in the definition
    ///
    /// [stackoverflow](https://stackoverflow.com/questions/38182986/const-method-repeat-in-implementation)
    int getWidth() const;
    virtual void setWidth(int);
    int getHeight() const;
    virtual void setHeight(int);
    int area() const;
} typedef Rectangle;

struct Square : public Rectangle
{
public:
    Square(int);

    /// @attention Violates Liskov's Substitution Principle
    void setWidth(int) override;
    void setHeight(int) override;
} typedef Square;

/// @brief a function that processes Rectangle type
void process(Rectangle &r);