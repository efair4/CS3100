#ifndef _UNORDERED_MAP_HPP_
#define _UNORDERED_MAP_HPP_

#include <unordered_map>
#include <mutex>
class UnorderedMap {
	public: 
		int getDigit(int);
		void insertDigit(int, int);
		
	private: 
		std::mutex m_mutex;
		std::unordered_map<int,int> m_map;
};

#endif
