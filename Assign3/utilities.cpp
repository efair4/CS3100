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

bool getCommandFromHistory(std::vector<std::string> hist, char** &argv) {
	int num;
	bool valid = true;
	try {
		num = std::stoi(argv[1]);
		if(num >= 1 && num < hist.size()) {
			argv = split(hist[num-1]);
		}
		else {
			valid = false;
		}
	} catch(...) {
			valid = false;
	}
	if(valid && strcmp(argv[0], "^") == 0) {
		return getCommandFromHistory(hist, argv);
	}
	else {
		return valid;
	}
}

void printHistory(std::vector<std::string> hist) {
	std::cout<<"------CommandHistory------"<<std::endl;
	for(int i=0;i<hist.size()-1;i++) {
		std::cout<<i+1<<" - "<<hist[i]<<std::endl;
	}
}
