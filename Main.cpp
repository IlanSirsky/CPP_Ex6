#include <iostream>
#include <stdexcept>

#include "sources/League.hpp"

using namespace std;
using namespace basketball;

double randomTalent(){
    return (double)rand() / RAND_MAX;
}

int main(){
    League* l = new League();
    l->startLeague();
    l->statistics(5);
}
