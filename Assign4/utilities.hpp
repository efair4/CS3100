#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<sys/param.h>
#include<unistd.h>

char** split(std::string);
std::string getCommandString(char**);
int getCommandFromHistory(std::vector<std::string>, char** &);
void printHistory(std::vector<std::string>);
int inspectInput(std::vector<std::string>, char** &, double);

#endif
