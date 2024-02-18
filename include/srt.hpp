
#pragma once

#include <vector>
#include <string>
#include <fstream>

/// @brief a journal entry
///
/// Add entries to the journal
struct Journal
{
    /// @brief journal title
    std::string title;
    /// @brief journal entires
    std::vector<std::string> entries;
} typedef Journal;

/// @brief a persistent manager
///
/// A manager that saves recorded entires
///
/// This is the most robust and reliable way to implement persistence
/// - All the persistent code are in a single place
struct PersistentManager
{
public:
    /// @brief method to save recorded entires
    /// @param journal Journal
    /// @param filename
    /// @attention The key is to use the static keyword only in the header file, not in the source file!
    /// [stack overflow](https://stackoverflow.com/questions/5373107/how-to-implement-static-class-member-functions-in-cpp-file)
    ///
    static void save(const Journal *journal, const std::string &filename);
} typedef PersistentManager;