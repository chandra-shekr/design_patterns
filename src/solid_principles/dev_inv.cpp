#include <iostream>
#include <ranges>
#include "dep_inv.hpp"

std::vector<Person> Relationship::get_all_children_of_(const std::string &name)
{

    std::vector<Person> children;
    for (auto &&[first, relation, last] : this->relations)
    {
        if (first.name == name && relation == Relations::parent)
        {
            children.push_back(last);
        }
    }
    return children;
}

void Relationship::add_parend_and_child(const Person &parent, const Person &child)
{
    relations.push_back({parent, Relations::parent, child});
    relations.push_back({child, Relations::child, parent});
}

Research::Research(RelationshipBrowser &browser, const std::string &name)
{

    for (auto &child : browser.get_all_children_of_(name))
    {

        std::cout << name << " has children " << std::endl
                  << "\t" << child.name << std::endl;
    }
}