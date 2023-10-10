#pragma once

#include "Synchronizer.hpp"

#include <string>

class Searcher
{
public:
	Searcher();
	~Searcher();

	int m_StartSearch(std::string);
};