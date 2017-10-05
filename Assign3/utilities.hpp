#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<cstring>

char** split(std::string);
std::string getCommandString(char**);
bool getCommandFromHistory(std::vector<std::string>, char** &);
void printHistory(std::vector<std::string>);

#endif
