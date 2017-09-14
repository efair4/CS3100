#include "compute-fib.hpp"
int findFib(int num) {
        if(num <= 1) {
                return 1;
        }
        else {
                return (findFib(num - 1) + findFib(num - 2));
        }
}
