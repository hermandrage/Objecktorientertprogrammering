
#include "utilities.hpp" 
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int randomWithLimits(int øvregrense, int nedregrense){
    return ((rand())%((øvregrense+1)-nedregrense))+nedregrense;
}
