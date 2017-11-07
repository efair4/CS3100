#include<iomanip>
#include<unistd.h>
#include<stdio.h>
#include<chrono>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>
#include "utilities.hpp"

void ctrlCHandler(int sigID) {
	std::cout<<"\nEnter 'exit' to quit the shell."<<std::endl;
	std::cout<<"["<<getcwd(NULL,0)<<":] "<<std::flush;
}

int main() {
	std::string input;
	std::vector<std::string> hist;
	std::vector<char**> argsVec;
	char** argv;
	char** argvPipe;
	double totalTime = 0;
	int execute;
	int status;

	while(true) {		
		std::cout<<"["<<getcwd(NULL,0)<<":] ";
	  signal(SIGINT,ctrlCHandler);
		
		std::getline(std::cin,input);
		argsVec = split(input);
		argv = argsVec[0];
		if(argsVec.size() == 2) {
			execute = doPipe(hist, argsVec, totalTime);
		}
		else {		
			execute = inspectInput(hist, argv, totalTime);
		}

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
			hist.push_back(getCommandString(argsVec));
  	}
		else if(execute == 2) {
			std::cout<<"Invalid Command"<<std::endl;
		}
	}
	return 0;
}
