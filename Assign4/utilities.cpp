#include "utilities.hpp"

std::vector<char**> split(std::string s) {
	std::vector<std::string> result; //This is for normal input and the before-pipe commands
	std::vector<std::string> pipeResult; //This will hold the after-pipe commands
	std::vector<char**> argsVec; //A vector to hold the possible argument char**'s
	char** argv;
	char** argvPipe;
	std::istringstream istr(s);
	std::string item;
	bool pipeFlag=false;

	while(istr>>item) {
		if(item=="|") {
			pipeFlag = true;
			continue;
		}
		if(pipeFlag) {
			pipeResult.push_back(item);
		}
		else {
			result.push_back(item);
		}
	}

	argv = new char*[result.size()+1];

	for(int i=0;i<result.size();i++) {
		argv[i] = new char[result[i].length()];
		strcpy(argv[i],result[i].c_str());
	}
	argv[result.size()] = NULL;
	argsVec.push_back(argv);

	if(pipeResult.size() > 0) {
		argvPipe = new char*[pipeResult.size()+1];

		for(int j=0;j<pipeResult.size();j++) {
			argvPipe[j] = new char[pipeResult[j].length()];
			strcpy(argvPipe[j],pipeResult[j].c_str());
		}
		argvPipe[pipeResult.size()] = NULL;
		argsVec.push_back(argvPipe);
	}
	return argsVec;
}

std::string getCommandString(std::vector<char**> argsVec) {
	std::string entry;
	int count = 0;
	bool cont = true;
	char** argv = argsVec[0];
	char** argvPipe;

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

  if(argsVec.size() == 2) {
  	argvPipe = argsVec[1];
		cont = true;
		count = 0;
		while(cont) {
			if(argvPipe[count] != NULL) {
				count++;
			}
			else {
				cont = false;
			}
		}
		entry += "| ";
		for(int j=0;j<count;j++) {
			entry += argvPipe[j];
			entry += ' ';
		}
	}

	return entry;
}

int getCommandFromHistory(std::vector<std::string> hist, char** &argv, double &totalTime) {
	int num;
	int valid = 1;
	std::vector<char**> argsVec;
	try {
		num = std::stoi(argv[1]);
		if(num >= 1 && num <= hist.size() && argv[2] == NULL) {
			argsVec = split(hist[num-1]);
			if(argsVec.size() == 2) {
				valid = doPipe(hist, argsVec, totalTime);
			}
			else {
				argv = argsVec[0];
			}
			if(strcmp(argv[0], "cd") == 0) {
				valid = 4;
			}
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

int inspectInput(std::vector<std::string> hist, char** &argv, double &totalTime) {
	//1 means execute
	//2 means bad input
	//3 means custom command
	int value = 1;
	if(argv[0] == NULL) return 2;
	
	if(strcmp(argv[0], "^") == 0) {
		value = getCommandFromHistory(hist, argv, totalTime);
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

	return value;
}

int doPipe(std::vector<std::string> hist, std::vector<char**> &argsVec, double &totalTime) {
	const int	PIPE_COUNT = 2;
	const int PIPE_READ_END = 0;
	const int PIPE_WRITE_END = 1;
	const int STDIN = 0;
	const int STDOUT = 1;

	int pids[PIPE_COUNT];
	pipe(pids);

	int savedStdOut = dup(STDOUT);
	int savedStdIn = dup(STDIN);
	int execute;

	char** argv = argsVec[0];
	char** argvPipe = argsVec[1];
	if(inspectInput(hist,argv,totalTime) != 1 || inspectInput(hist,argvPipe,totalTime) != 1) {
		return 2;
	}

	pid_t pid = fork();
	if(pid == 0) {
		dup2(pids[PIPE_WRITE_END], STDOUT);
		execvp(argv[0], argv);
		exit(1);
	}

	pid_t pid2 = fork();
	if(pid2 == 0) {
		dup2(pids[PIPE_READ_END], STDIN);
		close(pids[PIPE_WRITE_END]);

		execvp(argvPipe[0], argvPipe);
		exit(1);
	}

	int status;
	auto start = std::chrono::system_clock::now();
	waitpid(pid, &status, 0);
	auto end = std::chrono::system_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
	if(status == 0) {
		totalTime += diff.count();
		execute = 3;
	}
	else {
		execute = 2;
	}

	close(pids[PIPE_WRITE_END]);
	close(pids[PIPE_READ_END]);

	start = std::chrono::system_clock::now();
	waitpid(pid2, &status, 0);
	end = std::chrono::system_clock::now();
	diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
	if(status == 0){
		totalTime += diff.count();
		execute = 3;
	}
	else {
		execute = 2;
	}

	dup2(savedStdOut, STDOUT);
	dup2(savedStdIn, STDIN);

	return execute;
}
