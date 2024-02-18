
//! This is the module level doc
//!
//! Author: Shekar
//!
//! Copyright: 20xx-22xx
//!
//! - Make sure to use this to describe the module
//! - Make sure to mention everything about the module here
//! - Always try to use '//!' to keep up with rust-style doc :)

#pragma once

#include <string>

/// @brief This is the brief description
///
/// This is a detailed description
/// ### Example
/// ```
///     Foo *earth = new Foo;
/// ```
class Foo
{

public:
    /// @brief constructor foo
    Foo();

    /// @brief a method that **answers everything**
    /// @param question
    /// @return direction to *life, universe and a good restaurant*
    /// ### Level 3 Markdown heading
    /// @note it's a little side-note.  Make sure to ask the right questions
    int bar(int);

    /// @brief philosophically perverted method. If you can't bear it, just invoke ~Foo()
    /// @param doesnt_matter
    /// @return depression
    /// @note make sure to take the antidepressants
    /// @warning don't let another method near it. It'll render it completely dysfunctional.
    std::string marvin(int doesnt_matter);

    /// @brief destructor foo
    ///
    /// calls the deconstructor when the instance goes out of scope
    /// @see Foo()
    /// @attention make sure that vogons don't invoke it
    ///
    /// ```cpp
    /// float qux(int){
    ///     return 3.14;
    /// }
    /// extern int SOME_GLOBAL = 42;
    /// ```
    ~Foo();
};