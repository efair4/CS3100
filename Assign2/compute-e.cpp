#include "compute-e.hpp"
//The following function was found at 
//www.geeksforgeeks.org/program-to-efficiently-calculate-ex/
float findE(int num) {
        float sum = 1.0;
        for(int i = num -1; i > 0; --i) {
                sum = 1 + 1 * sum / i;
        }
        return sum;
}
