#include "studentas.h"
#include "atsitiktiniu_generavimas.h"
#include<iostream>
#include<cctype>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::invalid_argument;


studentas studentas_ivestis(bool atsitiktiniai_balai){

    string ivestis;
    studentas pirmas;
    cout << "Įveskite studento duomenis." << endl;

    while (true){
        cout << "Vardas: "; cin >> pirmas.vardas;
        bool tikriname = true;
        for (char c: pirmas.vardas){
            if(!isalpha(c)){
                tikriname = false;
                break;
            }
        }
        if(tikriname) break;
                cout << "Vardas turi būti sudarytas tik iš raidžių." << endl;
    }

    while (true){
        cout << "Pavardė: "; cin >> pirmas.pavarde;
        bool tikriname = true;
        for (char c: pirmas.pavarde){
            if(!isalpha(c)){
                tikriname = false;
                break;
            }
        }
        if(tikriname) break;
                cout << "Pavardė turi būti sudarytas tik iš raidžių." << endl;
    }

    if (atsitiktiniai_balai){

        int kiek;
        while (true) {
            cout << "Kiek norite sugeneruoti pažymių? ";
            string ivestis;
            cin >> ivestis;

            try {
                kiek = stoi(ivestis);
                if (kiek < 1) {
                    cout << "Turi būti teigiamas skaičius. Bandykite dar kartą." << endl;
                    continue;
                }
                break;
            } catch (const invalid_argument&) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių." << endl;
            }
        }

            for (int i=0; i<kiek; i++){
                pirmas.pazymiai.push_back(generuoti_atsitiktini_bala());
            }

            pirmas.egzamino_pazymys = generuoti_atsitiktini_bala();

        } else {
            cout << "įveskite studento pažymius (parašykite baigta, kai baigėte)"<< endl;

            while (true){
                cout << pirmas.pazymiai.size() + 1 << ". ";
                cin >> ivestis;
                if (ivestis == "baigta"){
                    break;
                }
                try {
                    int konvertuota = stoi(ivestis);
                    if (konvertuota < 1 || konvertuota > 10) {
                        cout << "Balas turi būti nuo 1 iki 10. Bandykite dar kartą." << endl;
                        continue;
                    }
                    pirmas.pazymiai.push_back(konvertuota);
                } catch (const invalid_argument&) {
                    cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 10 arba 'baigta'." << endl;
                }
            }

            while (true) {
                cout << "Įveskite egzamino pažymį: ";
                string ivestis;
                cin >> ivestis;

                try {
                    int egzaminas = stoi(ivestis);
                    if (egzaminas < 1 || egzaminas > 10) {
                        cout << "Egzamino pažymys turi būti nuo 1 iki 10. Bandykite dar kartą." << endl;
                        continue;
                    }
                    pirmas.egzamino_pazymys = egzaminas;
                    break;
                } catch (const invalid_argument&) {
                    cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 10." << endl;
                }
            }
        }
        return pirmas;
}

