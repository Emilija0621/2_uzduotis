#include "spausdinimas.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;


void spausdinti_studentus(const vector<Studentas>& grupe, int pasirinkimas) {
    if (grupe.empty()) {
        cout << "Studentų sąrašas tuščias." << endl;
        return;
    }

    vector<Studentas> surusiuota = grupe;

    int rikiavimo_pasirinkimas = 0;
    while (true) {
        cout << "Pagal ką norite rikiuoti studentų duomenis?" << endl;
        cout << "1 - Pagal vardus" << endl;
        cout << "2 - Pagal pavardes" << endl;
        cout << "3 - Pagal galutinį pažymį" << endl;

        string ivestis;
        cin >> ivestis;

        try {
            rikiavimo_pasirinkimas = stoi(ivestis);
            if (rikiavimo_pasirinkimas < 1 || rikiavimo_pasirinkimas > 3) {
                cout << "Neteisingas pasirinkimas. Įveskite 1-3." << endl;
                continue;
            }
            break;
        } catch (...) {
            cout << "Netinkama įvestis. Bandykite dar kartą." << endl;
        }
    }

    if (rikiavimo_pasirinkimas == 1)
        sort(surusiuota.begin(), surusiuota.end(), comparePagalVarda);
    else if (rikiavimo_pasirinkimas == 2)
        sort(surusiuota.begin(), surusiuota.end(), comparePagalPavarde);
    else if (rikiavimo_pasirinkimas == 3) {
        if (pasirinkimas == 1)
            sort(surusiuota.begin(), surusiuota.end(), comparePagalVidurki);
        else if (pasirinkimas == 2)
            sort(surusiuota.begin(), surusiuota.end(), comparePagalMediana);
        else {
            int kuris = 0;
            while (true) {
                cout << "Pasirinkite pagal kurį galutinį pažymį rikiuoti:" << endl;
                cout << "1 - Pagal vidurkį" << endl;
                cout << "2 - Pagal medianą" << endl;

                string t;
                cin >> t;
                try {
                    kuris = stoi(t);
                    if (kuris < 1 || kuris > 2) {
                        cout << "Įveskite 1 arba 2." << endl;
                        continue;
                    }
                    break;
                } catch (...) {
                    cout << "Netinkama įvestis." << endl;
                }
            }

            if (kuris == 1)
                sort(surusiuota.begin(), surusiuota.end(), comparePagalVidurki);
            else
                sort(surusiuota.begin(), surusiuota.end(), comparePagalMediana);
        }
    }

    if (pasirinkimas == 1){
        cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavardė" << "|" << setw(5) << left << "Galutinis (Vid.)" << endl;
        cout << string(46, '-') << endl;
        for (auto past: surusiuota){
            cout << setw(12) << left << past.vardas() << "|" << setw(15) << left << past.pavarde() << "|";
            cout << setw(15) << fixed << setprecision(2) << past.galutinis_vidurkis() << endl;
        }
    } else if (pasirinkimas == 2) {
        cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavardė" << "|" << setw(5) << left << "Galutinis (Med.)" << endl;
        cout << string(46, '-') << endl;
        for (auto past: surusiuota){
            cout << setw(12) << left << past.vardas() << "|" << setw(15) << left << past.pavarde() << "|";
            cout << setw(15) << fixed << setprecision(2) << past.galutinis_mediana() << endl;
        }
    } else if (pasirinkimas == 3){
        cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavardė" << "|" << setw(5) << left << "Galutinis (Vid.)" << "|" << setw(5) << left << "Galutinis (Med.)" << endl;
        cout << string(61, '-') << endl;
        for (auto past: surusiuota){
//          Isvesties operatoriaus panaudojimas
            cout << past << endl;
        }
    }
}
