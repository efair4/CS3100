#include "Queue.hpp"

void Queue::insertElement(int element) {
	m_queue.push(element);
}

bool Queue::isEmpty() {
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_queue.empty();
}

int Queue::getFront() {
	std::lock_guard<std::mutex> lock(m_mutex);
	int front = m_queue.front();
	m_queue.pop();
	return front;
}
