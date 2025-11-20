#include "funkcijos.h"
#include<random>
#include<iostream>
#include<string>


using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::string;
using std::endl;
using std::cout;


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


bool tikrintiVarda(const string& vardas) {
    for (char c : vardas) {
        if (!isalpha(c)) {
            cout << "Vardas turi būti sudarytas tik iš raidžių." << endl;
            return false;
        }
    }
    return true;
}

bool tikrintiPavarde(const string& pavarde) {
    for (char c : pavarde) {
        if (!isalpha(c)) {
            cout << "Pavardė turi būti sudaryta tik iš raidžių." << endl;
            return false;
        }
    }
    return true;
}

bool tikrintiPazymi(const string& ivestis, int& pazymys) {
    try {
        pazymys = stoi(ivestis);
    } catch (...) {
        cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 10." << endl;
        return false;
    }

    if (pazymys < 1 || pazymys > 10) {
        cout << "Pažymys turi būti nuo 1 iki 10. Bandykite dar kartą." << endl;
        return false;
    }

    return true;
}



