#include "studentas.h"
#include "atsitiktiniu_generavimas.h"
#include "skaiciavimai.h"
#include<iostream>
#include<cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::invalid_argument;
using std::istream;
using std::stoi;


Studentas::Studentas(std::istream& is) {
  readStudent(is);
}

double Studentas::galutinis_balas(double (*skaiciavimo_funkcija)(const vector<int>& pazymiai)) const {
    if (skaiciavimo_funkcija) {
        return skaiciavimo_funkcija(pazymiai_) * 0.4 + egzamino_pazymys_ * 0.6;
    } else {
        return 0;
    }
}

istream& Studentas::readStudent(istream& is, bool atsitiktiniai_balai) {
    cout << "Įveskite studento duomenis." << endl;
    while (true){
        cout << "Vardas: "; is >> vardas_;
        bool tikriname = true;
        for (char c: vardas_){
            if(!isalpha(c)){
                tikriname = false;
                break;
            }
        }
        if(tikriname) break;
        cout << "Vardas turi būti sudarytas tik iš raidžių." << endl;
    }
    
    while (true){
        cout << "Pavardė: "; is >> pavarde_;
        bool tikriname = true;
        for (char c: pavarde_){
            if(!isalpha(c)){
                tikriname = false;
                break;
            }
        }
        if(tikriname) break;
        cout << "Pavardė turi būti sudarytas tik iš raidžių." << endl;
    }
    
    pazymiai_.clear();
    
    if (atsitiktiniai_balai) {
        
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
            } catch (...) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių." << endl;
            }
        }
        
        for (int i = 0; i < kiek; i++){
            pazymiai_.push_back(generuoti_atsitiktini_bala());
        }
        
        egzamino_pazymys_ = generuoti_atsitiktini_bala();
    } else {
        
        cout << "Įveskite studento pažymius (parašykite 'baigta', kai baigėte):" << endl;
        string ivestis;
        
        while (true) {
            cout << pazymiai_.size() + 1 << ". ";
            is >> ivestis;
            if (ivestis == "baigta"){
                break;
            }
            try {
                int konvertuota = stoi(ivestis);
                if (konvertuota < 1 || konvertuota > 10){
                    cout << "Balas turi būti nuo 1 iki 10. Bandykite dar kartą." << endl;
                    continue;
                }
                pazymiai_.push_back(konvertuota);
            } catch (...) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 10 arba 'baigta'." << endl;
            }
        }
        
        while (true) {
            cout << "Įveskite egzamino pažymį: ";
            is >> ivestis;
            try {
                int egzaminas = stoi(ivestis);
                if (egzaminas < 1 || egzaminas > 10) {
                    cout << "Egzamino pažymys turi būti nuo 1 iki 10. Bandykite dar kartą." << endl;
                    continue;
                }
                egzamino_pazymys_ = egzaminas;
                break;
            } catch (...) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 10." << endl;
            }
        }
    }
    return is;
}


bool comparePagalVidurki(const Studentas& a, const Studentas& b) {
    return a.galutinis_vidurkis() > b.galutinis_vidurkis();
}

bool comparePagalMediana(const Studentas& a, const Studentas& b) {
    return a.galutinis_mediana() > b.galutinis_mediana();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde() < b.pavarde();
}

bool comparePagalEgzamina(const Studentas& a, const Studentas& b) {
    return a.egzamino_pazymys() > b.egzamino_pazymys();
}

