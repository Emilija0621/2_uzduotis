#include "studentas.h"
#include<list>

using std::list;

int galutiniai_pazymiai(list<studentas>& grupe);
double skaiciuoti_mediana(list<int> pazymiai);
double skaiciuoti_vidurki(const list<int>& pazymiai);
double skaiciuoti_galutinis_pazymys(const list<int>& pazymiai, int egzaminas, bool naudoti_mediana = false);
