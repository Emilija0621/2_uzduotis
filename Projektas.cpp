#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<random>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::fixed;
using std::setprecision;
using std::sort;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;



struct studentas{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double galutinis_vidurkis;
    double galutinis_mediana;
};


studentas studentas_ivestis(bool atsitiktiniai_balai);
double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas, bool naudoti_mediana = false);
double skaiciuoti_mediana(vector<int> pazymiai);
double skaiciuoti_vidurki(const vector<int>& pazymiai);
int generuoti_atsitiktini_bala();


int main() {
    vector <studentas> grupe;
    int pasirinkimas1;
    
    while (true) {
        cout << "Pasirinkite veiksmą:\n";
        cout << "1 - Įvesti studenta su turimais duomenimis\n";
        cout << "2 - Įvesti vardą ir pavardę, bet balus generuoti atsitiktinai\n";
        cout << "3 - Spausdinti studentų rezultatus\n";
        cout << "4 - Išeiti\n";
        cin >> pasirinkimas1;
        
        if (pasirinkimas1 == 1) {
            grupe.push_back(studentas_ivestis(false));
        } else if (pasirinkimas1 == 2){
            grupe.push_back(studentas_ivestis(true));
        } else if (pasirinkimas1 == 3){
            
            if (grupe.empty()) {
                    cout << "Studentų duomenų dar nėra.\n";
                    continue;
                }
            
            int pasirinkimas;
            cout << "Pasirinkite kaip noresite skaiciuoti galutini ivertininima" << endl;
            cout << "1 - su vidurkiu \n2 - su mediana\n3 - noriu gauti abejais budais suskaiciuotus ivertinimus" << endl;
            cin >> pasirinkimas;
            
            for (auto &s : grupe) {
                s.galutinis_vidurkis = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, false);
                s.galutinis_mediana = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, true);
            }
            
            cout << "Studentu informacija: " << endl;
            
            if (pasirinkimas == 1){
                cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavarde" << "|" << setw(14) << left << "Galutinis (Vid.)" << endl;
                cout << string(46, '-') << endl;
                for (auto past: grupe){
                    cout << setw(12) << left << past.vardas << "|" << setw(15) << left << past.pavarde << "|";
                    cout << setw(14) << fixed << setprecision(2) << past.galutinis_vidurkis << endl;
                }
            } else if (pasirinkimas == 2) {
                cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavarde" << "|" << setw(5) << left << "Galutinis (Med.)" << endl;
                cout << string(46, '-') << endl;
                for (auto past: grupe){
                    cout << setw(12) << left << past.vardas << "|" << setw(15) << left << past.pavarde << "|";
                    cout << setw(14) << fixed << setprecision(2) << past.galutinis_mediana << endl;
                }
            } else if (pasirinkimas == 3){
                cout << setw(12) << left << "Vardas" << "|" << setw(15) << left << "Pavarde" << "|" << setw(5) << left << "Galutinis (Vid.)" << "|" << setw(5) << left << "Galutinis (Med.)" << endl;
                cout << string(55, '-') << endl;
                for (auto past: grupe){
                    cout << setw(12) << left << past.vardas << "|" << setw(15) << left << past.pavarde << "|";
                    cout << setw(15) << fixed << setprecision(2) << past.galutinis_vidurkis << "|" << setw(10) << fixed << setprecision(2) << past.galutinis_mediana << endl;
                }
            }
        } else if (pasirinkimas1 == 4) {
            cout << "Programa baigta.\n";
            break;
        } else {
            cout << "Neteisingas pasirinkimas.\n";
        }
    }
}



studentas studentas_ivestis(bool atsitiktiniai_balai){
    string ivestis;
    studentas pirmas;
    cout << "Sveiki!" << endl;
    cout << "Iveskite studento duomenis." << endl;
    cout << "Vardas: "; cin >> pirmas.vardas;
    cout << "Pavarde: "; cin >> pirmas.pavarde;

    if (atsitiktiniai_balai){
        int kiek;
        cout << "Kiek norite sugeneruoti pazymiu?" << endl; cin >> kiek;
        for (int i=0; i<kiek; i++){
            pirmas.pazymiai.push_back(generuoti_atsitiktini_bala());
        }
        pirmas.egzamino_pazymys = generuoti_atsitiktini_bala();
    } else {
        cout << "Iveskite studento pazymius (parasykite baigta, kai baigete)"<< endl;
        while (true){
            cout << pirmas.pazymiai.size() + 1 << ". ";
            cin >> ivestis;
            if (ivestis == "baigta"){
                break;
            }
            int konvertuota = stoi(ivestis);
            pirmas.pazymiai.push_back(konvertuota);
        }
        
        cout << "Iveskite egzamino pazymi: "; cin >> pirmas.egzamino_pazymys;
    }
    return pirmas;
}


double skaiciuoti_vidurki(const vector<int>& pazymiai){
    if (pazymiai.empty()) return 0;
    double suma = 0;
    for (auto paz: pazymiai){
        suma += paz;
    }
    return suma / pazymiai.size();
}


double skaiciuoti_mediana(vector<int> pazymiai){
    if (pazymiai.empty()) return 0;
    sort(pazymiai.begin(), pazymiai.end());
    auto n = pazymiai.size();
    
    if (n % 2 == 1) {
            return pazymiai[n / 2];
        } else {
            return (pazymiai[n / 2 - 1] + pazymiai[n / 2]) / 2.0;
        }
}


double skaiciuoti_galutinis_pazymys(const vector<int>& pazymiai, int egzaminas, bool naudoti_mediana){
    double galutinis = 0;
    if (naudoti_mediana){
        galutinis = skaiciuoti_mediana(pazymiai) * 0.4 + egzaminas * 0.6;
    } else {
        galutinis = skaiciuoti_vidurki(pazymiai) * 0.4 + egzaminas * 0.6;
    }
    return galutinis;
}


int generuoti_atsitiktini_bala(){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}



