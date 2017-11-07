#include "UnorderedMap.hpp"

int UnorderedMap::getDigit(int index) {
	std::unordered_map<int,int>::const_iterator digitObject = m_map.find (index);
	return digitObject->second;
}
		
void UnorderedMap::insertDigit(int index, int digit) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_map.insert({index, digit});
}
