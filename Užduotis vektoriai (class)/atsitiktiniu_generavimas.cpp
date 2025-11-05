#include "atsitiktiniu_generavimas.h"
#include<random>

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int generuoti_atsitiktini_nd_kieki() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 20);
    return dis(gen);
}

int generuoti_atsitiktini_bala(){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

