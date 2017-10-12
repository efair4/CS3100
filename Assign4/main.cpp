#include<iomanip>
#include<unistd.h>
#include<stdio.h>
#include<chrono>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>
#include "utilities.hpp"

void myHandler(int sigID) {
	std::cout<<"The signal id is: "<<sigID<<std::endl;
}

int main() {
	std::string input;
	std::vector<std::string> hist;
	char** argv;
	double totalTime = 0;
	int execute;
	int status;

	while(true) {
		
		std::cout<<"["<<getcwd(NULL,0)<<"]: ";
	//	sighandle_t signal(SIGINT,myHandler);
		
		std::getline(std::cin,input);
		argv = split(input);
		
		execute = inspectInput(hist, argv, totalTime);

		if(fork()){	
			auto start = std::chrono::system_clock::now();
			wait(&status);
			auto end = std::chrono::system_clock::now();
			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
			if(status == 0) {
				totalTime += diff.count();
			}
		}
		else {
			if(execute == 1) {
				execvp(argv[0],argv);
				std::cout<<"Invalid Command"<<std::endl;
			}
			
			exit(1);
		}
		
	  if(execute == 1 && status == 0 || execute == 3) {
			hist.push_back(getCommandString(argv));
  	}
		else if(execute == 2) {
			std::cout<<"Invalid Command"<<std::endl;
		}
	}
	return 0;
}
