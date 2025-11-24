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


void rule_of_three() {
    cout << "--------- Rule of three testas ---------\n\n";

    Studentas s1, s2;

    cin >> s1;
    cout << "Ivedete studenta s1." << endl;

    cin >> s2;
    cout << "Ivedete studenta s2" << endl;

    cout << "--- Pradiniai studentu duomenys ---" << endl;

    cout << left << setw(10) << "Nr"<< setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(18) << "Galutinis (Vid.)" << setw(18) << "Galutinis (Med.)" << endl;
    cout << string(76, '-') << endl;

    cout << left << setw(10) << "s1" << setw(15) << s1.vardas() << setw(15) << s1.pavarde() << setw(18) << fixed << setprecision(2) << s1.galutinis_vidurkis()<< setw(18) << fixed << setprecision(2) << s1.galutinis_mediana() << endl;

    cout << left << setw(10) << "s2"<< setw(15) << s2.vardas()<< setw(15) << s2.pavarde()<< setw(18) << fixed << setprecision(2) << s2.galutinis_vidurkis()<< setw(18) << fixed << setprecision(2) << s2.galutinis_mediana() << endl << endl;
    
    cout << "Patikriname ar studentu duomenys sutampa (s1 == s2): " << (s1 == s2 ? "True" : "False") << endl << endl;

    cout << "Pakeiciame studenta s2 i s1 (s2 = s1)." << endl << endl;
    s2 = s1;

    cout << "Patikriname ar studentu duomenys sutampa (s1 == s2): " << (s1 == s2 ? "True" : "False") << endl << endl;

    cout << "Sukuriam nauja studenta s4 is s1 (s4(s1))." << endl << endl;
    Studentas s3(s1);

    cout << "Patikriname ar studentu duomenys sutampa (s1 == s4): " << (s1 == s3 ? "True" : "False") << endl << endl;

    cout << "-------------- Testo pabaiga --------------"<< endl;
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



