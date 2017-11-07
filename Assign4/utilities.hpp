#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<chrono>
#include<sys/wait.h>
#include<sys/param.h>
#include<unistd.h>

std::vector<char**> split(std::string);
std::string getCommandString(std::vector<char**>);
int getCommandFromHistory(std::vector<std::string>, char** &, double &);
void printHistory(std::vector<std::string>);
int inspectInput(std::vector<std::string>, char** &, double &);
int doPipe(std::vector<std::string>, std::vector<char**> &, double &);

#endif
