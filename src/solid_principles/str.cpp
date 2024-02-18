#include "srt.hpp"

void PersistentManager::save(const Journal *journal, const std::string &filename)

{

    std::ofstream ofs{filename};
    for (auto &e : journal->entries)
    {
        ofs << e << std::endl;
    }
}
