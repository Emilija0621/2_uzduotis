#include "studentas.h"
#include "funkcijos.h"
#include "skaiciavimai.h"
#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::invalid_argument;
using std::istream;
using std::stoi;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;


Studentas::Studentas(istream& is, bool atsitiktiniai_balai = false) {
  readStudent(is, atsitiktiniai_balai);
}

void Studentas::apskaiciuotiGalutinius() {
    galutinis_vidurkis_ = skaiciuoti_galutinis_pazymys(pazymiai_, egzamino_pazymys_, false);
    galutinis_mediana_ = skaiciuoti_galutinis_pazymys(pazymiai_, egzamino_pazymys_, true);
}


istream& operator>>(istream& in, Studentas& s) {
    cout << "Įveskite studento duomenis." << endl;
    while (true){
        cout << "Vardas: "; in >> s.vardas_;
        if (tikrintiVarda(s.vardas_)) break;
    }
    
    while (true){
        cout << "Pavardė: "; in>> s.pavarde_;
        if (tikrintiPavarde(s.pavarde_)) break;
    }
    
    s.pazymiai_.clear();
    
    cout << "Įveskite studento pažymius (parašykite 'baigta', kai baigėte):" << endl;
    string ivestis;
    int balas;
    
    while (true) {
        cout << s.pazymiai_.size() + 1 << ". ";
        in >> ivestis;
        if (ivestis == "baigta") break;
        if (tikrintiPazymi(ivestis, balas)) {
            s.pazymiai_.push_back(balas);
        }
    }
    while (true) {
        cout << "Įveskite egzamino pažymį: ";
        in >> ivestis;
        if (tikrintiPazymi(ivestis, balas)) {
            s.egzamino_pazymys_ = balas;
            break;
        }
    }
    s.apskaiciuotiGalutinius();
    return in;
}


ostream& operator<<(ostream& out, const Studentas& s) {
    out << setw(12) << left << s.vardas() << "|" << setw(15) << left << s.pavarde() << "|" << setw(15) << fixed << setprecision(2) << s.galutinis_vidurkis() << "|" << setw(15) << fixed << setprecision(2) << s.galutinis_mediana();
    return out;
}



istream& Studentas::readStudent(istream& is, bool atsitiktiniai_balai) {
    cout << "Įveskite studento duomenis." << endl;

    while (true){
        cout << "Vardas: ";
        is >> vardas_;
        if (tikrintiVarda(vardas_)) break;
    }

    while (true){
        cout << "Pavardė: ";
        is >> pavarde_;
        if (tikrintiPavarde(pavarde_)) break;
    }

    pazymiai_.clear();
    string ivestis;
    int balas;

    if (atsitiktiniai_balai) {
        int kiek;
        while (true) {
            cout << "Kiek norite sugeneruoti pažymių? ";
            is >> ivestis;
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

        for (int i = 0; i < kiek; i++) {
            pazymiai_.push_back(generuoti_atsitiktini_bala());
        }

        egzamino_pazymys_ = generuoti_atsitiktini_bala();

    } else {
        cout << "Įveskite studento pažymius (parašykite 'baigta', kai baigėte):" << endl;
        while (true) {
            cout << pazymiai_.size() + 1 << ". ";
            is >> ivestis;
            if (ivestis == "baigta") break;
            if (tikrintiPazymi(ivestis, balas)) {
                pazymiai_.push_back(balas);
            }
        }

        while (true) {
            cout << "Įveskite egzamino pažymį: ";
            is >> ivestis;
            if (tikrintiPazymi(ivestis, balas)) {
                egzamino_pazymys_ = balas;
                break;
            }
        }
    }

    apskaiciuotiGalutinius();
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

bool comparePagalVarda(const Studentas& a, const Studentas& b) {
    return a.vardas() < b.vardas();
}



