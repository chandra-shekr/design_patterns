//! Dependency Inversion Principle
//! - High-level modules should not depend on low-level modules
//! - Details should depend on abstractions

#pragma once

#include <string>
#include <vector>
#include <tuple>

enum Relations
{

    parent,
    child,
    sibling
};

struct Person
{

    std::string name;
};

/// @brief An abstraction
///
/// Both **high-level** modules and **low-level** modules
/// should depend on this.
struct RelationshipBrowser
{

    virtual std::vector<Person> get_all_children_of_(const std::string &) = 0;
};

/// @brief A **low-level** module
struct Relationship : RelationshipBrowser
{
    std::vector<std::tuple<Person, Relations, Person>> relations;

    void add_parend_and_child(const Person &parent, const Person &child);
    std::vector<Person> get_all_children_of_(const std::string &) override;
};

struct Research
{
    Research(RelationshipBrowser &, const std::string &);
};