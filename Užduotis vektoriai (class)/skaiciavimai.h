#pragma once
#include<vector>
#include "studentas.h"

using std::vector;

int galutiniai_pazymiai(vector<Studentas>& grupe);
double skaiciuoti_mediana(const vector<int>& pazymiai);
double skaiciuoti_vidurki(const vector<int>& pazymiai);
double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas, bool naudoti_mediana = false);

