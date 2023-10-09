#pragma once

#include "Synchronizer.hpp"

#include <string>
#include <map>
#include <thread>
#include <mutex>
#include <vector>


class WorkerThread
{
public:
	WorkerThread(int);

	~WorkerThread();

	// Create Worker Threads
	void m_CreateWorkerThreads();

	// Entry of words into the Table
	void m_FillTable();

	// Return sorted Table
	std::multimap<int, std::string, std::greater<int> > m_GetTableEntry();

private:
	// To add each word of each file in the Table
	void m_AddWordInTable(std::string);
	std::map <std::string, int> Table;

	// Mutex object to synchronize the threads
	std::mutex m_WThMutexObj;
	const int m_WorkerThreadCount;
	std::vector <std::thread> threads;

};