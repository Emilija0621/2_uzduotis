#include<iostream>
#include<iomanip>
#include<vector>
#include<string>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::string;


struct studentas{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double galutinis_pazymys;
};


studentas studentas_ivestis();
double skaiciuoti_vidurki(const vector<int>& pazymiai);
double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas);


int main() {
    vector <studentas> grupe;
    int m;
    cout << "Kiek studentu yra grupeje? "; cin >> m;
    
    for (auto z=0; z<m; z++){
        grupe.push_back(studentas_ivestis());
    };
    
    for (auto &s : grupe) {
        s.galutinis_pazymys = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys);
    };
        
    cout << "Studentu informacija: " << endl;
    cout << setw(10) << left << "Vardas" << "|" << setw(15) << left << "Pavarde" << "|" << setw(5) << left << "Galutinis (Vid.) " << endl;
    cout << string(46, '-') << endl;
    
    for (auto past: grupe){
        cout << setw(10) << left << past.vardas << "|" << setw(15) << left << past.pavarde << "|";
        cout << setw(10) << past.galutinis_pazymys << endl;
    };
};


studentas studentas_ivestis(){
    int n, laikinas_paz;
    cout << "Sveiki!" << endl;
    studentas pirmas;
    cout << "Iveskite studento duomenis." << endl;
    cout << "Vardas: "; cin >> pirmas.vardas;
    cout << "Pavarde: "; cin >> pirmas.pavarde;
    cout << "Kiek pazymiu turi " << pirmas.vardas << " " << pirmas.pavarde << "? "; cin >> n;
    
    for (int a = 0; a<n; a++){
        cout << a + 1 << ": ";
        cin >> laikinas_paz;
        pirmas.pazymiai.push_back(laikinas_paz);
    };
    
    cout << "Iveskite egzamino pazymi: "; cin >> pirmas.egzamino_pazymys;
    return pirmas;
};


double skaiciuoti_vidurki(const vector<int>& pazymiai){
    if (pazymiai.empty()) return 0;
    double suma = 0;
    for (auto paz: pazymiai){
        suma += paz;
    };
    return suma / pazymiai.size();
};


double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas){
    double vidurkis = skaiciuoti_vidurki(pazymiai);
    return 0.4 * vidurkis + 0.6 * egzaminas;
};
