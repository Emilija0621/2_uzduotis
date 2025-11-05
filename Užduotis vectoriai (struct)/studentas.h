#pragma once
#include<vector>
#include<string>

using std::string;
using std::vector;

struct studentas{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double galutinis_vidurkis;
    double galutinis_mediana;
};

studentas studentas_ivestis(bool atsitiktiniai_balai);
