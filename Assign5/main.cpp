#include<iostream>
#include<thread>
#include "ComputePiDigit.hpp"
#include "Queue.hpp"
#include "UnorderedMap.hpp"

bool getTask(Queue& q, int& index) {
	if(!q.isEmpty()) {
		std::cout<<"."<<std::cout.flush();
		index = q.getFront();
		return true;
	}
	return false;
}

void printPi(UnorderedMap& computedDigits) {
	std::cout<<"\n3"<<'.'<<std::cout.flush();
	for(int index = 1; index <= 1000; index++) {
		std::cout<<" "<<computedDigits.getDigit(index)<<" "<<std::cout.flush();
	}
	std::cout<<std::endl;
}

void doWork(Queue& queue, UnorderedMap& computedDigits) {
	int index;
	while(getTask(queue, index)) {
		int digit = computePiDigit(index);
		computedDigits.insertDigit(index, digit);
	}
	
}

int main() {
	int numThreads = std::thread::hardware_concurrency();
	std::vector<std::thread> threadVec;
	Queue taskQueue;
	UnorderedMap computedDigits;

	for(int ind = 1; ind <= 1000; ind++) {
		taskQueue.insertElement(ind);
	}

	for(int i = 0; i < numThreads; i++) {
		threadVec.push_back(std::thread(doWork, std::ref(taskQueue), std::ref(computedDigits)));
	}

	for(int j = 0; j < numThreads; j++) {
		threadVec[j].join();
	}

	printPi(computedDigits);

	return 0;
}
