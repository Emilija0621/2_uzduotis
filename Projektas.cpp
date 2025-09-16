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

struct studentas{
    string vardas;
    string pavarde;
    vector <int> pazimys;   // resizable array
    int egzamino;
    double galutinis;
};

studentas studentas_ivestis();

int main() {
    vector <studentas> grupe;
    cout << "Kiek studentu yra grupeje? ";
    int m;
    cin >> m;
    for (auto z = 0; z < m; z++) {
        grupe.push_back(studentas_ivestis());     // prideda reiksme i gala vektoriaus
    };
    cout << "studento informacija: " << endl;
    for (auto past: grupe) {
        cout << setw(10) << left << past.vardas << "|" << setw(15) << right << past.pavarde << "|";
        for (auto& a: past.pazimys) {
            cout << setw(3) << a << "|";
        };
        cout << setw(5) << past.egzamino << "|" << setw(10) << past.galutinis << endl;
    };
}



studentas studentas_ivestis() {
    int n, laik_paz, sum = 0;
    cout << "sveiki" << endl;
    studentas pirmas;
    cout << "iveskite stundento duomenis: " << endl;
    cout << "vardas: "; cin >> pirmas.vardas;
    cout << "pavarde: "; cin >> pirmas.pavarde;
    cout << "kiek pazymiu turi? " << pirmas.vardas << " " << pirmas.pavarde << ": "; cin >> n;
    for (int a = 0; a < n; a++) {
        cout << a + 1 << ": "; cin >> laik_paz;
        pirmas.pazimys.push_back(laik_paz);
        sum += laik_paz;   // sum += pirmas.pazimys[a]
    };
    cout << "iveskite egzamino pazymi: "; cin >> pirmas.egzamino;
    pirmas.galutinis = double (sum) / double (n) * 0.4 + pirmas.egzamino * 0.6;
    return pirmas;
}
    
