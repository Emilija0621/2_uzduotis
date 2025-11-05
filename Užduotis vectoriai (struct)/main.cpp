#include "studentas.h"
#include "skaiciavimai.h"
#include "spausdinimas.h"
#include "failu_skaitymas.h"
#include "failu_generavimas.h"
#include<iostream>
#include<vector>
#include<string>
#include "laikas.h"


using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;

int main() {
    vector<studentas> grupe;
    int pasirinkimas1;

    while (true) {
        while (true) {
            cout << "Pasirinkite veiksmą: " << endl;
            cout << "1 - Įvesti studentą su turimais duomenimis" << endl;
            cout << "2 - Įvesti vardą ir pavardę, bet pažymius generuoti atsitiktinai" << endl;
            cout << "3 - Spausdinti studentų rezultatus" << endl;
            cout << "4 - Nuskaityti studentų duomenis iš failo" << endl;
            cout << "5 - Atsitiktinai generuoti studentų duomenis į failus" << endl;
            cout << "6 - Padalinti studentus į dvi grupes (vargšiukai ir kietiakai) ir išvesti į atskirus failus" << endl;
            cout << "7 - Išeiti" << endl;

            string ivestis;
            cin >> ivestis;

            try {
                pasirinkimas1 = stoi(ivestis);
                if (pasirinkimas1 < 1 || pasirinkimas1 > 7) {
                    cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 7." << endl;
                    continue;
                }
                break;
            } catch (const invalid_argument&) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 7." << endl;
            }
        }

        if (pasirinkimas1 == 1) {
            grupe.push_back(studentas_ivestis(false));
            
            cout << "Studento objektas saugomas adresu: " << &grupe.back() << endl;

        } else if (pasirinkimas1 == 2) {
            grupe.push_back(studentas_ivestis(true));
            
            cout << "Studento objektas saugomas adresu: " << &grupe.back() << endl;

        } else if (pasirinkimas1 == 3) {

            int pasirinkimas = galutiniai_pazymiai(grupe);
            spausdinti_studentus(grupe, pasirinkimas);

        } else if (pasirinkimas1 == 4) {
            cout << "Įveskite failo pavadinimą: ";
            string failas;
            cin >> failas;
            
            laikas t;
            t.reset();
            
            nuskaityti_duomenis_is_failo(failas, grupe);
            
            cout << "Failo nuskaitytas per " << t.elapsed() << " sekundžių" << endl;

        } else if (pasirinkimas1 == 5) {
            failo_generavimo_pasirinkimas();

        } else if (pasirinkimas1 == 6) {
            padalinti_ir_isvesti_studentus(grupe);

        } else if (pasirinkimas1 == 7) {
            cout << "Programa baigta." << endl;
            break;

        } else {
            cout << "Neteisingas pasirinkimas." << endl;
        }
    }
}
