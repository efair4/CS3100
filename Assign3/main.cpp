#include<iomanip>
#include<unistd.h>
#include<stdio.h>
#include<chrono>
#include<sys/wait.h>
#include<sys/types.h>
#include "utilities.hpp"

int main() {
	std::string input;
	std::vector<std::string> hist;
	char** argv;
	auto totalTime = 0;
	bool execute;
	int status;

	while(true) {
		execute = true;
		status = 0;
		std::cout<<"[cmd]: ";
		std::getline(std::cin,input);
		argv = split(input);
		
		if(argv[0] == NULL) {
			execute = false;
		}

		if(execute && strcmp(argv[0], "^") == 0) {
			execute = getCommandFromHistory(hist, argv);
		}

		if(execute && strcmp(argv[0], "exit") == 0) {
			exit(0);
		}
		else if(execute && strcmp(argv[0],"history") == 0) {
			printHistory(hist);
		}
		else if(execute && strcmp(argv[0], "ptime") == 0) {
			std::cout<<"Total time spent executing child processes: "<<std::setprecision(4)<<std::fixed<<(totalTime/1000.0)<<" seconds"<<std::endl;
		}
		else if(fork()){	
			auto start = std::chrono::system_clock::now();
			wait(&status);
			auto end = std::chrono::system_clock::now();
			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
			totalTime += diff.count();
		}
		else {
			if(execute) {
				execvp(argv[0],argv);
				std::cout<<"Invalid Command"<<std::endl;
			}
			else {
				std::cout<<"Invalid Command"<<std::endl;
			}
			exit(1);
		}

	  if(status == 0) {
			hist.push_back(getCommandString(argv));
  	}	
	}
	return 0;
}
