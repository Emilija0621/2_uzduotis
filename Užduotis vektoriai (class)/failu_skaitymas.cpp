#include "failu_skaitymas.h"
#include "skaiciavimai.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::istringstream;

void nuskaityti_duomenis_is_failo(const string& failo_pavadinimas, vector<Studentas>& grupe){
    ifstream in(failo_pavadinimas);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failo_pavadinimas << endl;
        return;
    }

    stringstream buferis;
    buferis << in.rdbuf();
    in.close();

    string eilute;
    if (!getline(buferis, eilute)) {
        cout << "Failas " << failo_pavadinimas << " tuščias arba netinkamas." << endl;
        return;
    }

    size_t eil_nr = 1;

    istringstream antraste(eilute);
    vector<string> stulpeliai;
    string stulp;
    while (antraste >> stulp) stulpeliai.push_back(stulp);
    size_t nd_kiekis = stulpeliai.size() - 3;

    while (getline(buferis, eilute)) {
        ++eil_nr;
        if (eilute.empty()) continue;

        istringstream iss(eilute);
        
        Studentas duomenys;
        string vardas;
        string pavarde;

        if (!(iss >> vardas >> pavarde)) {
            cout << "Praleista eilutė " << eil_nr << "." << " (nerastas vardas/pavardė): " << eilute << endl;
            continue;
        }
        
        duomenys.setVardas(vardas);
        duomenys.setPavarde(pavarde);

        vector<int> nd_pazymiai;
        
        bool klaida = false;

        for (size_t i = 0; i < nd_kiekis; i++) {
            int nd;
            if (!(iss >> nd) || nd < 1 || nd > 10) {
                cout << "Praleista eilutė " << eil_nr << "." << " (netinkamai įvesti studento duomenys): " << eilute << endl;
                klaida = true;
                break;
            }
            nd_pazymiai.push_back(nd);
        }

        if (klaida) continue;

        duomenys.setPazymiai(nd_pazymiai);
        
        int egz;
        if (!(iss >> egz) || egz < 1 || egz > 10) {
            cout << "Praleista eilutė " << eil_nr << "." << " (netinkamai įvesti studento duomenys): " << eilute << endl;
            continue;
        }
        
        duomenys.setEgzaminoPazymys(egz);
        duomenys.apskaiciuotiGalutinius();
        grupe.push_back(duomenys);
    }

    cout << "Duomenų nuskaitymas baigtas." << endl;
};

