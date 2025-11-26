#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;
using std::swap;

#include "zmogus.h"


class Studentas: public Zmogus {
private:
    vector<int> pazymiai_;
    int egzamino_pazymys_;
    double galutinis_vidurkis_;
    double galutinis_mediana_;
    
public:
    Studentas() : Zmogus("", ""), egzamino_pazymys_(0), galutinis_vidurkis_(0), galutinis_mediana_(0){}
    Studentas(istream& is, bool atsitiktiniai_balai);
    
    //Kopijavimo konstruktorius (copy constructor)
    Studentas(const Studentas& stud)
        : Zmogus(stud.vardas_, stud.pavarde_),
          pazymiai_(stud.pazymiai_),
          egzamino_pazymys_(stud.egzamino_pazymys_),
          galutinis_vidurkis_(stud.galutinis_vidurkis_),
          galutinis_mediana_(stud.galutinis_mediana_)
    {}
    
    //Priskyrimo operatorius (copy assignment)
    Studentas& operator=(const Studentas& stud) {
        if (this == &stud) return *this;
        
        vardas_ = stud.vardas_;
        pavarde_ = stud.pavarde_;
        pazymiai_ = stud.pazymiai_;
        egzamino_pazymys_ = stud.egzamino_pazymys_;
        galutinis_vidurkis_ = stud.galutinis_vidurkis_;
        galutinis_mediana_ = stud.galutinis_mediana_;

        return *this;
    }
    
    //Destruktorius (destructor)
    ~Studentas(){
        pazymiai_.clear();
        
        egzamino_pazymys_ = 0;
        galutinis_mediana_ = 0.0;
        galutinis_vidurkis_ = 0.0;
    }
    
    bool operator==(const Studentas& s) const {
        return vardas_ == s.vardas_ &&
               pavarde_ == s.pavarde_ &&
               pazymiai_ == s.pazymiai_ &&
               egzamino_pazymys_ == s.egzamino_pazymys_ &&
               galutinis_vidurkis_ == s.galutinis_vidurkis_ &&
               galutinis_mediana_ == s.galutinis_mediana_;
    }

    // Implementuoja abstrakčias Zmogus klasės funkcijas
    string vardas() const override {return vardas_;}
    string pavarde() const override {return pavarde_;}
    
    inline double egzamino_pazymys() const {return egzamino_pazymys_;}
    inline double galutinis_vidurkis() const {return galutinis_vidurkis_;}
    inline double galutinis_mediana() const {return galutinis_mediana_;}
    
    void setVardas(const string& v) {vardas_ = v;}
    void setPavarde(const string& p) {pavarde_ = p;}
    void setPazymiai(const vector<int>& p) {pazymiai_ = p;}
    void setEgzaminoPazymys(int e) {egzamino_pazymys_ = e;}
    void apskaiciuotiGalutinius();
    
    istream& readStudent(istream&, bool atsitiktiniai_balai = false);
    
    //Ivesties operatorius
    friend istream& operator>>(istream& is, Studentas& s);
    //Isvesties operatorius
    friend ostream& operator<<(ostream& os, const Studentas& s);
    
};

bool comparePagalMediana(const Studentas&, const Studentas&);
bool comparePagalVidurki(const Studentas&, const Studentas&);
bool comparePagalVarda(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);

void rule_of_three();
