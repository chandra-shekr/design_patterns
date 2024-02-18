#pragma once

#include <string>
#include <vector>

/// @brief color specification
///
/// enum for specification filtering
enum Color
{

    Green,
    Red,
    Yellow,
    Blue

};

/// @brief size specification
///
/// enum for size specification filtering
enum Size
{

    Large,
    Medium,
    Small
};

/// @brief an abstract product type
struct Product
{

    /// @brief product name
    std::string name;
    /// @brief product color
    Color color;
    /// @brief product size
    Size size;
};

/// @brief An interface for product specification
///
///
/// @tparam T product type
///
/// ### Enterprise Factory Interface
///
template <typename T>
struct Specification
{

    virtual bool is_satisfied(T *item) = 0;

    /// @brief constructs AndSpecification while filtering using two specifications
    /// @param other
    /// @return AndSpecification
    AndSpecification<T> operator&&(Specification<T> &&other)
    {

        return AndSpecification<T>(*this, other);
    };
};

/// @brief A filter interface for filtering products based on specification
/// @tparam T
template <typename T>
struct Filter
{

    virtual std::vector<T *> filter(std::vector<T *> items, Specification<T> &spec) = 0;
};

/// @brief a better filter type based on 'Enterprise Factory;
struct BetterFiltler : Filter<Product>
{

    /// @brief filters products based on specifications
    /// @param items Product type
    /// @param spec  Specification type
    /// @return
    std::vector<Product *> filter(std::vector<Product *> items, Specification<Product> &spec) override;
} typedef BetterFiltler;

/// @brief color specification
struct ColorSpecification : Specification<Product>
{
private:
    Color color;

public:
    /// @note will not let users from using default constructors
    ColorSpecification(Color color);
    /// @brief checks whether a product satisfies the specification
    /// @param item
    /// @return bool
    bool is_satisfied(Product *item) override;
} typedef ColorSpecification;

/// @brief size specification
struct SizeSpecification : Specification<Product>
{

private:
    Size size;

public:
    /// @note No, it is not .The explicit keyword is only permitted in the header.My gcc says :
    ///
    /// [stackoverflow](https://stackoverflow.com/questions/273630/if-i-use-explicit-constructor-do-i-need-to-put-the-keyword-in-both-h-and-cpp)
    explicit SizeSpecification(const Size size);
    bool is_satisfied(Product *itemp) override;
} typedef SizeSpecification;

/// @brief filtering with AND logic
/// @tparam T
template <typename T>
struct AndSpecification : Specification<T>
{

private:
    Specification<T> &first;
    Specification<T> &second;

public:
    AndSpecification(Specification<T> &first,
                     Specification<T> &second) : first{first},
                                                 second{second} {};
    /// @brief checks whether first and second specs are satisfied
    /// @param item
    /// @return bool
    bool is_satisfied(T *item) override
    {

        return first.is_satisfied(item) && second.is_satisfied(item);
    };
};

/// @note C+11 feature to 'typedef' a template.
///
/// Previously, typedef  declaration in C++ cannot be a template.
///
/// [stackoverflow](https://stackoverflow.com/questions/19192122/template-declaration-of-typedef-typename-footbar-bar)