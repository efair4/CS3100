#include <iostream>
#include <iomanip>
#include "compute-fib.hpp"
#include "compute-e.hpp"
#include "compute-pi.hpp"
//I found the following statement at this address:
// https://gist.github.com/illescasDaniel/62367e4f10832cb8aed85177acd4277f
#define guard(_condition) if (bool(_condition)){}

void printHelp() {
        std::cout<<"Invalid Parameter"<<std::endl;
        std::cout<<"---Assignment 1 Help---"<<std::endl;
        std::cout<<"-fib [n] : Compute the fibonacci of [n]. [n] can range from 0 to 40"<<std::endl;
        std::cout<<"-e [n] : Compute the value of 'e' using [n] iterations. [n] can range from 1 to 30"<<std::endl;
        std::cout<<"-pi [n] : Compute pi to [n] digits. [n] can range from 1 to 10"<<std::endl;
}

int main(int argc, char* argv[]) {
       std::string param1;
       int param2;
       if(argc == 3) {
            param1 = argv[1];
            try {
                param2 = std::stoi(argv[2]);
       	    }catch(...) {
                printHelp();
                return 0;
            }
       }
       if(param1 == "fib" || param1 == "-fib") {
           guard(param2 >= 0 && param2 <= 40) else {
               printHelp();
               return 0;
           }
           std::cout<<"Element "<<param2<<" in the Fibonacci sequence is "<< findFib(param2)<<std::endl;
       }
       else if(param1 == "e" || param1 == "-e") {
            guard(param2 >= 1 && param2 <= 30) else {
                printHelp();
                return 0;
            }
            std::cout<<"The approximation of e using "<<param2<<" iterations of a Taylor Series is "<<findE(param2)<<std::endl;
        }
        else if(param1 == "pi" || param1 == "-pi") {
            guard(param2 >= 1 && param2 <= 10) else {
                printHelp();
                return 0;
            }
            std::cout<<std::fixed<<"Pi to "<<param2<<" decimal places is "<<std::setprecision(param2)<<findPi()<<std::endl;
        }
        else {
            printHelp();
        }

        return 0;
}
