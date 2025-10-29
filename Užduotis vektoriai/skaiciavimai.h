#include "studentas.h"
#include<vector>

using std::vector;

int galutiniai_pazymiai(vector<studentas>& grupe);
double skaiciuoti_mediana(vector<int> pazymiai);
double skaiciuoti_vidurki(const vector<int>& pazymiai);
double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas, bool naudoti_mediana = false);
