#include "WorkerThread.hpp"

#include <iostream>
#include <thread>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <utility>
#include <filesystem>

namespace fs = std::filesystem;

extern Synchronizer SyncQ;

//Constructor
WorkerThread::WorkerThread(int WThCnt)
	: m_WorkerThreadCount(WThCnt)
{
}

// Destructor
WorkerThread::~WorkerThread()
{
}

void WorkerThread::m_CreateWorkerThreads()
{

	for (int i = 0; i < m_WorkerThreadCount; i++)
	{
		threads.emplace_back(&WorkerThread::m_FillTable, this);
	}

	for (std::thread& t : threads)
	{
		t.join();
	}

}

void WorkerThread::m_AddWordInTable(std::string word)
{
	// Insert word into Table if not present
	// If present then increase count by 1
	m_WThMutexObj.lock();
	auto it = Table.find(word);
	if (it == Table.end())
	{
		Table[word]++;
	}
	else
	{
		(it->second)++;
	}
	m_WThMutexObj.unlock();

}

void WorkerThread::m_FillTable()
{
	while (SyncQ.m_GetFileCount())
	{
		std::string filename = SyncQ.m_GetFrontFile();
		if (!(filename.empty()))
		{
			std::ifstream file;
			file.open(filename.c_str(), std::ifstream::in);
			std::string line;

			if (file.is_open())
			{
				while (std::getline(file, line))
				{
					std::size_t prev = 0, pos{};
					while ((pos = line.find_first_of("~`=!@#$%^&*)/\?-_|[,. }](_-+{;':\"></", prev)) != std::string::npos)
					{
						if (pos > prev)
						{
							m_AddWordInTable(line.substr(prev, pos - prev));
						}
						prev = pos + 1;
					}

					if (prev < line.length())
					{
						m_AddWordInTable(line.substr(prev, std::string::npos));
					}
				}

				file.close();
			}
			else
			{
				std::cout << "--Unable to Open File--: " << filename << "\n";
			}
		}
	}
}

std::multimap <int, std::string, std::greater<int> > WorkerThread::m_GetTableEntry()
{
	std::multimap <int, std::string, std::greater<int> > m_table;
	auto iter = Table.begin();
	for (; iter != Table.end(); iter++)
	{
		m_table.insert(std::make_pair(iter->second, iter->first));
	}
	return m_table;
}