#ifndef _QUEUE_HPP_	
#define _QUEUE_HPP_

#include <mutex>
#include <queue>
class Queue {
	public:
		void insertElement(int);
		bool isEmpty();
		int getFront();
	private:	
		std::mutex m_mutex;
		std::queue<int> m_queue;
};

#endif
