#include "oco.hpp"

std::vector<Product *> BetterFiltler::filter(std::vector<Product *> items, Specification<Product> &spec)
{

    {
        std::vector<Product *> result;
        for (auto &e : items)
        {

            if (spec.is_satisfied(e))
                result.push_back(e);
        }

        return result;
    }
}

ColorSpecification::ColorSpecification(Color color) : color{color} {}

bool ColorSpecification::is_satisfied(Product *item)
{

    return this->color == item->color;
}

SizeSpecification::SizeSpecification(const Size size)
    : size{size} {}

bool SizeSpecification::is_satisfied(Product *item)
{

    return this->size == item->size;
}
