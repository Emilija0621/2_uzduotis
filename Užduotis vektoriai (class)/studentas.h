#pragma once
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::istream;


class Studentas{
private:
    string vardas_;
    string pavarde_;
    vector<int> pazymiai_;
    int egzamino_pazymys_;
    double galutinis_vidurkis_;
    double galutinis_mediana_;
    
public:
    Studentas() : egzamino_pazymys_(0), galutinis_vidurkis_(0), galutinis_mediana_(0){}
    Studentas(istream& is);
    inline string vardas() const {return vardas_;}
    inline string pavarde() const {return pavarde_;}
    inline double galutinis_vidurkis() const {return galutinis_vidurkis_;}
    inline double galutinis_mediana() const {return galutinis_mediana_;}
    inline double egzamino_pazymys() const {return egzamino_pazymys_;}
    
    void set_galutinis_vidurkis(double v) {galutinis_vidurkis_ = v;}
    void set_galutinis_mediana(double v) {galutinis_mediana_ = v;}
    void setVardas(const string& v) {vardas_ = v;}
    void setPavarde(const string& p) {pavarde_ = p;}
    void setPazymiai(const vector<int>& p) {pazymiai_ = p;}
    void setEgzaminoPazymys(int e) {egzamino_pazymys_ = e;}
    
    
    double galutinis_balas(double (*) (const vector<int>&)) const;
    istream& readStudent(istream&, bool atsitiktiniai_balai = false);
    };

bool comparePagalMediana(const Studentas&, const Studentas&);
bool comparePagalVidurki(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgzamina(const Studentas&, const Studentas&);


