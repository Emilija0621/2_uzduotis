#pragma once
#include<list>
#include<string>

using std::string;
using std::list;

struct studentas{
    string vardas;
    string pavarde;
    list<int> pazymiai;
    int egzamino_pazymys;
    double galutinis_vidurkis;
    double galutinis_mediana;
};

studentas studentas_ivestis(bool atsitiktiniai_balai);
