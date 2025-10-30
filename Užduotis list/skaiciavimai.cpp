#include "skaiciavimai.h"
#include "studentas.h"
#include<algorithm>
#include<iostream>
#include<string>
#include<list>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::advance;


double skaiciuoti_vidurki(const list<int>& pazymiai){
    if (pazymiai.empty()) return 0;
    double suma = 0;
    for (auto paz: pazymiai){
        suma += paz;
    }
    return suma / pazymiai.size();
}


double skaiciuoti_mediana(list<int> pazymiai){
    if (pazymiai.empty()) return 0;
    
    pazymiai.sort();
    
    auto n = pazymiai.size();
    auto m = pazymiai.begin();
    

    if (n % 2 == 1) {
        advance(m, n/2);
        return *m;
    } else {
        auto m1 = pazymiai.begin();
        advance(m1, n/2 - 1);
        auto m2 = m1;
        ++ m2;
        
        return (*m1 + *m2) / 2.0;
        }
}


double skaiciuoti_galutinis_pazymys(const list<int>& pazymiai, int egzaminas, bool naudoti_mediana){
    double galutinis = 0;

    if (naudoti_mediana){
        galutinis = skaiciuoti_mediana(pazymiai) * 0.4 + egzaminas * 0.6;
    } else {
        galutinis = skaiciuoti_vidurki(pazymiai) * 0.4 + egzaminas * 0.6;
    }
    return galutinis;
}

int galutiniai_pazymiai(list<studentas>& grupe) {
    if (grupe.empty()) {
        cout << "Studentų duomenų dar nėra." << endl;
        return 0;
    }

    int pasirinkimas;
    while (true) {
        cout << "Pasirinkite, kaip norėsite skaičiuoti galutinį įvertinimą:" << endl;
        cout << "1 - su vidurkiu\n2 - su mediana\n3 - noriu gauti abejais būdais suskaičiuotus įvertinimus" << endl;

        string ivestis;
        cin >> ivestis;

        try {
            pasirinkimas = stoi(ivestis);
            if (pasirinkimas < 1 || pasirinkimas > 3) {
                cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 3." << endl;
                continue;
            }
            break;
        } catch (const invalid_argument&) {
            cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 3." << endl;
        }
    }

    for (auto &s : grupe) {
        s.galutinis_vidurkis = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, false);
        s.galutinis_mediana = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, true);
    }

    return pasirinkimas;
}


