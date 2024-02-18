#include <iostream>
#include "intro.hpp"

Foo::Foo()
{

    std::cout << "constructor called" << std::endl;
}

Foo::~Foo()
{

    std::cout << "destructor called" << std::endl;
}

int Foo::bar(int question)
{

    return 42;
}

std::string Foo::marvin(int doesnt_matter)
{

    return std::string("don't talk to me about life");
}