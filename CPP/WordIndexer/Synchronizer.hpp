#pragma once

#include <string>
#include <mutex>
#include <queue>

class Synchronizer
{
public:
	Synchronizer();
	~Synchronizer();

	// To write filename in Queue
	void m_AddFileName(std::string);

	// Reads the filename and returns it from Queue
	std::string m_GetFrontFile(void);

	// Get the number of files present in Queue
	size_t m_GetFileCount();

	// Get the number of files processed by Queue
	int m_GetProcessedFileCount();

private:
	// Mutex object to synchronize Queue
	std::mutex m_QMutexObj;

	// Synchronized Queue to be read by Processor and Searcher Threads
	std::queue <std::string> m_Queue;

	// Stores the number of files processed by Queue
	int m_CountFile;

};
