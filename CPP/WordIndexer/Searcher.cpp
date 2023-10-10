#include "Searcher.hpp"

#include <iostream>
#include <filesystem>
#include <string>   

namespace fs = std::filesystem;

// Access the Queue
extern Synchronizer SyncQ;

// Filter to search only .txt files
static const std::string filter = ".txt";

extern bool SearchComplete;

Searcher::Searcher()
{
}

Searcher::~Searcher()
{
}

int Searcher::m_StartSearch(std::string filepath)
{
    std::string path(filepath);
    std::string ext(filter);
    for (auto& p : fs::recursive_directory_iterator(path))
    {
        if (p.path().extension() == ext)
        {
            SyncQ.m_AddFileName(p.path().string());
        }
    }

    SearchComplete = true;
    return 0;
}