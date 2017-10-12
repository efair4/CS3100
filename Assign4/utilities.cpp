#include "utilities.hpp"

char** split(std::string s) {
	std::vector<std::string> result;
	char** argv;
	std::istringstream istr(s);
	std::string item;

	while(istr>>item) {
		result.push_back(item);
	}

	argv = new char*[result.size()+1];

	for(int i=0;i<result.size();i++) {
		argv[i] = new char[result[i].length()];
		strcpy(argv[i],result[i].c_str());
	}
	argv[result.size()] = NULL;
	return argv;
}

std::string getCommandString(char** argv) {
	std::string entry;
	int count = 0;
	bool cont = true;

	while(cont) {
		if(argv[count] != NULL) {
			count++;
		}
		else {
			cont = false;
		}
	}
	for(int i=0;i<count;i++) {
		entry += argv[i];
		entry += ' ';
	}
	return entry;
}

int getCommandFromHistory(std::vector<std::string> hist, char** &argv) {
	int num;
	int valid = 1;
	try {
		num = std::stoi(argv[1]);
		if(num >= 1 && num <= hist.size() && argv[2] == NULL) {
			argv = split(hist[num-1]);
		}
		else {
			valid = 2;
		}
	} catch(...) {
			valid = 2;
	}
	return valid;
}

void printHistory(std::vector<std::string> hist) {
	std::cout<<"\n------CommandHistory------"<<std::endl;
	for(int i=0;i<hist.size();i++) {
		std::cout<<i+1<<" - "<<hist[i]<<std::endl;
	}
	std::cout<<"\n";
}

int inspectInput(std::vector<std::string> hist, char** &argv, double totalTime) {
	//1 means execute
	//2 means bad input
	//3 means custom command
	if(argv[0] == NULL) return 2;
	
	if(strcmp(argv[0], "^") == 0) {
		return getCommandFromHistory(hist, argv);
	}

	if(strcmp(argv[0], "exit") == 0) {
		exit(0);
	}

	if(strcmp(argv[0], "history") == 0 && argv[1] == NULL) {
		printHistory(hist);
		return 3;
	}

	if(strcmp(argv[0], "ptime") == 0 && argv[1] == NULL) {
		std::cout<<"Total time spent executing child processes: "<<std::setprecision(4)<<std::fixed<<(totalTime/1000.0)<<" seconds"<<std::endl;
		return 3;
	}

	if(strcmp(argv[0], "cd") == 0) {
		int thing;
		if(argv[1] != NULL && argv[2] == NULL) {
			std::string newDir = argv[1];
			try {
				thing = chdir(newDir.c_str());
			} catch(...) {
				return 2;
			}
			if(thing < 0) return 2;
			return 3;
		}
		else {
			return 2;
		}
	}

	return 1;
}
