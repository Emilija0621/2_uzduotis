#include "failu_generavimas.h"
#include "skaiciavimai.h"
#include "atsitiktiniu_generavimas.h"
#include<fstream>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include "laikas.h"

using std::endl;
using std::ofstream;
using std::cout;
using std::cin;
using std::invalid_argument;
using std::fixed;
using std::ostringstream;
using std::setprecision;
using std::partition;
using std::make_move_iterator;


void sugeneruoti_faila(const string& failo_pavadinimas, int studentu_kiekis, int nd_pazymiu_kiekis) {

    ostringstream buffer;

    buffer << "Vardas Pavarde ";
    for (int k = 1; k <= nd_pazymiu_kiekis; k++) {
        buffer << "ND" << k << " ";
    }
    buffer << "Egzaminas\n";

    for (int i = 1; i <= studentu_kiekis; i++) {
        buffer << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < nd_pazymiu_kiekis; j++) {
            buffer << generuoti_atsitiktini_bala() << " ";
        }
        buffer << generuoti_atsitiktini_bala() << "\n";
    }

    ofstream out(failo_pavadinimas);
    if (!out.is_open()) {
        cout << "Nepavyko sukurti failo: " << failo_pavadinimas << endl;
        return;
    }
    out << buffer.str();
    out.close();

    cout << "Sugeneruotas failas: " << failo_pavadinimas << " (" << studentu_kiekis << " studentų, po "<< nd_pazymiu_kiekis << " ND)" << endl;
}



void failo_generavimo_pasirinkimas() {

    int studentu_kiekio_pasirinkimas = 0;

    while (true) {
        cout << "Pasirinkite failo dydį: " << endl;
        cout << "1 - 1 000 studentų" << endl;
        cout << "2 - 10 000 studentų" << endl;
        cout << "3 - 100 000 studentų" << endl;
        cout << "4 - 1 000 000 studentų" << endl;
        cout << "5 - 10 000 000 studentų" << endl;
        cout << "Įveskite pasirinkimą: " << endl;

        string kiekio_pasirinkimas;
        cin >> kiekio_pasirinkimas;

        try {
            studentu_kiekio_pasirinkimas = stoi(kiekio_pasirinkimas);

            if (studentu_kiekio_pasirinkimas < 1 || studentu_kiekio_pasirinkimas > 5) {
                cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 5." << endl;
                continue;
            }
            break;
        } catch (const invalid_argument&) {
            cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 5." << endl;
        }
    }

    int studentu_kiekis = 0;
    string failo_pavadinimas;

    if (studentu_kiekio_pasirinkimas == 1) {
        studentu_kiekis = 1000;
        failo_pavadinimas = "atsitiktiniai_studentai1000.txt";
    } else if (studentu_kiekio_pasirinkimas == 2) {
        studentu_kiekis = 10000;
        failo_pavadinimas = "atsitiktiniai_studentai10000.txt";
    } else if (studentu_kiekio_pasirinkimas == 3) {
        studentu_kiekis = 100000;
        failo_pavadinimas = "atsitiktiniai_studentai100000.txt";
    } else if (studentu_kiekio_pasirinkimas == 4) {
        studentu_kiekis = 1000000;
        failo_pavadinimas = "atsitiktiniai_studentai1000000.txt";
    } else if (studentu_kiekio_pasirinkimas == 5) {
        studentu_kiekis = 10000000;
        failo_pavadinimas = "atsitiktiniai_studentai10000000.txt";
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }


    int nd_generavimo_pasirinkimas = 0;

    while (true) {

        cout << "Ar norite pasirinkti ND pažymių kiekį? " << endl;
        cout << "1 - Įvesti savo norimą kiekį." << endl;
        cout << "2 - Generuoti atsitiktinai." << endl;

        string nd_generavimas;
        cin >> nd_generavimas;

        try {
            nd_generavimo_pasirinkimas = stoi(nd_generavimas);

            if (nd_generavimo_pasirinkimas < 1 || nd_generavimo_pasirinkimas > 2) {
                cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 2." << endl;
                continue;
            }
            break;
        } catch (const invalid_argument&) {
            cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 2." << endl;
        }
    }

    int nd_pazymiu_kiekis = 0;
    if (nd_generavimo_pasirinkimas == 1){

        while (true) {

            cout << "Kiek norite sugeneruoti ND pažymių (vienam studentui)?" << endl;
            string nd;
            cin >> nd;

            try {
                nd_pazymiu_kiekis = stoi(nd);
                if (nd_pazymiu_kiekis < 1) {
                    cout << "Turi būti teigiamas skaičius. Bandykite dar kartą." << endl;
                    continue;
                }
                break;
            } catch (const invalid_argument&) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių." << endl;
            }
        }
    } else if (nd_generavimo_pasirinkimas == 2){

        nd_pazymiu_kiekis = generuoti_atsitiktini_nd_kieki();
    }
    
    laikas t;
    t.reset();

    sugeneruoti_faila(failo_pavadinimas, studentu_kiekis, nd_pazymiu_kiekis);
    
    cout << "Sukurta per " << t.elapsed() << " sekundžių" << endl;

}


void padalinimo_1_strategija(vector<studentas> &grupe, vector<studentas> &vargsiukai, vector<studentas> &kietiakai, int pagal_kuri_galutini){
    
    if (pagal_kuri_galutini == 1) {
        for (auto &s : grupe) {
            if (s.galutinis_vidurkis < 5.0)
                vargsiukai.push_back(s);
            else
                kietiakai.push_back(s);
        }
    } else {
        for (auto &s : grupe) {
            if (s.galutinis_mediana < 5.0)
                vargsiukai.push_back(s);
            else
                kietiakai.push_back(s);
        }
    }
}



void padalinimo_2_strategija(vector<studentas> &grupe, vector<studentas> &vargsiukai, int pagal_kuri_galutini){
    
    if (pagal_kuri_galutini == 1){
        
        sort(grupe.begin(), grupe.end(), [](auto &a, auto &b){
            return a.galutinis_vidurkis > b.galutinis_vidurkis;
        });
        
        while (!grupe.empty()) {
            
            const studentas &s = grupe.back();
            
            if (s.galutinis_vidurkis < 5.0) {
                vargsiukai.push_back(s);
                grupe.pop_back();
            } else
                break;
        }
        grupe.shrink_to_fit();
        
    } else if (pagal_kuri_galutini == 2){
        
        sort(grupe.begin(), grupe.end(), [](auto &a, auto &b){
            return a.galutinis_mediana > b.galutinis_mediana;
        });
        
        while (!grupe.empty()) {
            
            const studentas &s = grupe.back();
            
            if (s.galutinis_mediana < 5.0) {
                vargsiukai.push_back(s);
                grupe.pop_back();
            } else
                break;
        }
        grupe.shrink_to_fit();
    }
}

void padalinimo_3_strategija(vector<studentas>& grupe, vector<studentas>& vargsiukai, vector<studentas>& kietiakai, int pagal_kuri_galutini ) {
    
    auto kriterijus = partition(grupe.begin(), grupe.end(), [pagal_kuri_galutini] (const studentas& s) {
        if (pagal_kuri_galutini == 1) {
            return s.galutinis_vidurkis < 5.0;
        } else {
            return s.galutinis_mediana < 5.0;
        }
    });
    
    vargsiukai.assign(make_move_iterator(grupe.begin()),
    make_move_iterator(kriterijus));
    kietiakai.assign(make_move_iterator(kriterijus),
    make_move_iterator(grupe.end()));
}



int pasirinkti_strategija() {
    int strategija = 0;
    while (true) {
        cout << "Pasirinkite studentų padalijimo strategiją: " << endl;
        cout << "1 - pirma strategija (du konteineriai)" << endl;
        cout << "2 - antra strategija (vienas konteineris)" << endl;
        cout << "3 - trečia strategija (optimizuota 1 strategija)" << endl;

        string pasirinkimas;
        cin >> pasirinkimas;

        try {
            strategija = stoi(pasirinkimas);
            if (strategija < 1 || strategija > 3) {
                cout << "Neteisingas pasirinkimas. Įveskite 1 arba 3." << endl;
                continue;
            }
            break;
        } catch (...) {
            cout << "Įvesta netinkama reikšmė. Įveskite 1 arba 3." << endl;
        }
    }
    return strategija;
}

void pagal_ka_rusiuoti(vector<studentas> &vargsiukai, vector<studentas> &kietiakai, int pagal_kuri_galutini){
    int pagal_kokia_rusiuoti = 0;
    while (true) {
        cout << "Pasirinkite, pagal ką rūšiuoti failus: " << endl;
        cout << "1 - pagal vardą" << endl;
        cout << "2 - pagal pavardę" << endl;
        if (pagal_kuri_galutini == 1)
            cout << "3 - pagal galutinį vidurkį" << endl;
        else
            cout << "3 - pagal galutinę medianą" << endl;

        string rusiuoti;
        cin >> rusiuoti;

        try {
            pagal_kokia_rusiuoti = stoi(rusiuoti);
            if (pagal_kokia_rusiuoti < 1 || pagal_kokia_rusiuoti > 3) {
                cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 3." << endl;
                continue;
            }
            break;
        } catch (...) {
            cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 3." << endl;
        }
    }
    
    laikas t;
    t.reset();
    
    if (pagal_kokia_rusiuoti == 1) {
        
        sort(vargsiukai.begin(), vargsiukai.end(), [](auto &a, auto &b){
            return a.vardas < b.vardas;
        });
        sort(kietiakai.begin(), kietiakai.end(), [](auto &a, auto &b){
            return a.vardas < b.vardas;
        });
        
    } else if (pagal_kokia_rusiuoti == 2) {
        
        sort(vargsiukai.begin(), vargsiukai.end(), [](auto &a, auto &b){
            return a.pavarde < b.pavarde;
        });
        sort(kietiakai.begin(), kietiakai.end(), [](auto &a, auto &b){
            return a.pavarde < b.pavarde;
        });
        
    } else if (pagal_kokia_rusiuoti == 3) {
        
        if (pagal_kuri_galutini == 1) {
            
            sort(vargsiukai.begin(), vargsiukai.end(), [](auto &a, auto &b){
                return a.galutinis_vidurkis > b.galutinis_vidurkis;
            });
            sort(kietiakai.begin(), kietiakai.end(), [](auto &a, auto &b){
                return a.galutinis_vidurkis > b.galutinis_vidurkis;
            });
            
        } else {
            
            sort(vargsiukai.begin(), vargsiukai.end(), [](auto &a, auto &b){
                return a.galutinis_mediana > b.galutinis_mediana;
            });
            sort(kietiakai.begin(), kietiakai.end(), [](auto &a, auto &b){
                return a.galutinis_mediana > b.galutinis_mediana;
            });
        }
    }
    cout << "Rūšiavimas užtruko: " << t.elapsed() << " sekundžių" << endl;
}


void padalinti_ir_isvesti_studentus(vector<studentas>& grupe) {
    if (grupe.empty()) {
        cout << "Studentų duomenų dar nėra." << endl;
        return;
    }

    for (auto &s : grupe) {
        s.galutinis_vidurkis = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, false);
        s.galutinis_mediana = skaiciuoti_galutinis_pazymys(s.pazymiai, s.egzamino_pazymys, true);
    }
    
    int strategija = pasirinkti_strategija();
    
    int pagal_kuri_galutini;
    while (true) {
        cout << "Pasirinkite pagal ką norite atskirti studentus į failus: " << endl;
        cout << "1 - galutinį pažymį pagal vidurkį" << endl;
        cout << "2 - galutinį pažymį pagal medianą" << endl;
        string pasirinkimas;
        cin >> pasirinkimas;

        try {
            pagal_kuri_galutini = stoi(pasirinkimas);
            if (pagal_kuri_galutini < 1 || pagal_kuri_galutini > 2) {
                cout << "Neteisingas pasirinkimas. Įveskite 1 arba 2." << endl;
                continue;
            }
            break;
        } catch (...) {
            cout << "Įvesta netinkama reikšmė. Įveskite 1 arba 2." << endl;
        }
    }
    
    if (strategija == 1) {
        
        vector<studentas> kietiakai;
        vector<studentas> vargsiukai;
        
        laikas t;
        t.reset();
        padalinimo_1_strategija(grupe, vargsiukai, kietiakai, pagal_kuri_galutini);
        cout << "Studentai padalinti į dvi grupes per " << t.elapsed() << " sekundžių" << endl;
        
        pagal_ka_rusiuoti(vargsiukai, kietiakai, pagal_kuri_galutini);
        
        string failas_vargsiukai;
        string failas_kietiakai;

        if (pagal_kuri_galutini == 1) {
            failas_vargsiukai = "vargsiukai_vidurkis.txt";
            failas_kietiakai = "kietiakai_vidurkis.txt";
            
        } else if (pagal_kuri_galutini == 2) {
            failas_vargsiukai = "vargsiukai_mediana.txt";
            failas_kietiakai = "kietiakai_mediana.txt";
        }
        
        t.reset();
        isvesti_padalintus_i_faila(vargsiukai, failas_vargsiukai, pagal_kuri_galutini);
        cout << "Vargsiukų failą išvedė per " << t.elapsed() << " sekundžių" << endl;
        t.reset();
        isvesti_padalintus_i_faila(kietiakai, failas_kietiakai, pagal_kuri_galutini);
        cout << "Kietiakų failą išvedė per " << t.elapsed() << " sekundžių" << endl;
        
    } else if (strategija == 2) {

        vector<studentas> vargsiukai;
        vector<studentas> grupe1 = grupe;
        
        laikas t1;
        t1.reset();
        padalinimo_2_strategija(grupe1, vargsiukai, pagal_kuri_galutini);
        cout << "Studentai padalinti į dvi grupes per " << t1.elapsed() << " sekundžių" << endl;
        
        pagal_ka_rusiuoti(vargsiukai, grupe1, pagal_kuri_galutini);
        
        string failas_vargsiukai;
        string failas_kietiakai;

        if (pagal_kuri_galutini == 1) {
            failas_vargsiukai = "vargsiukai_vidurkis.txt";
            failas_kietiakai = "kietiakai_vidurkis.txt";
            
        } else if (pagal_kuri_galutini == 2) {
            failas_vargsiukai = "vargsiukai_mediana.txt";
            failas_kietiakai = "kietiakai_mediana.txt";
        }
        t1.reset();
        isvesti_padalintus_i_faila(vargsiukai, failas_vargsiukai, pagal_kuri_galutini);
        cout << "Vargsiukų failą išvedė per " << t1.elapsed() << " sekundžių" << endl;
        t1.reset();
        isvesti_padalintus_i_faila(grupe1, failas_kietiakai, pagal_kuri_galutini);
        cout << "Kietiakų failą išvedė per " << t1.elapsed() << " sekundžių" << endl;
    } else {
        
        vector<studentas> grupe2 = grupe;
        vector<studentas> kietiakai;
        vector<studentas> vargsiukai;
        
        laikas t;
        t.reset();
        padalinimo_3_strategija(grupe2, vargsiukai, kietiakai, pagal_kuri_galutini);
        cout << "Studentai padalinti į dvi grupes per " << t.elapsed() << " sekundžių" << endl;
        
        pagal_ka_rusiuoti(vargsiukai, kietiakai, pagal_kuri_galutini);
        
        string failas_vargsiukai;
        string failas_kietiakai;

        if (pagal_kuri_galutini == 1) {
            failas_vargsiukai = "vargsiukai_vidurkis.txt";
            failas_kietiakai = "kietiakai_vidurkis.txt";
            
        } else if (pagal_kuri_galutini == 2) {
            failas_vargsiukai = "vargsiukai_mediana.txt";
            failas_kietiakai = "kietiakai_mediana.txt";
        }
        
        t.reset();
        isvesti_padalintus_i_faila(vargsiukai, failas_vargsiukai, pagal_kuri_galutini);
        cout << "Vargsiukų failą išvedė per " << t.elapsed() << " sekundžių" << endl;
        t.reset();
        isvesti_padalintus_i_faila(kietiakai, failas_kietiakai, pagal_kuri_galutini);
        cout << "Kietiakų failą išvedė per " << t.elapsed() << " sekundžių" << endl;
    }
}



void isvesti_padalintus_i_faila(const vector<studentas>& grupe, const string& failo_pavadinimas, int pagal_kuri_galutini) {

    ostringstream buferis;

    if (pagal_kuri_galutini == 1) {
        buferis << "Vardas Pavarde Galutinis_pažymys(vidurkis)\n";
        for (auto &s : grupe) {
            buferis << s.vardas << " " << s.pavarde << " " << fixed << setprecision(2) << s.galutinis_vidurkis << "\n";
        }
    } else {
        buferis << "Vardas Pavarde Galutinis_pažymys(mediana)\n";
        for (auto &s : grupe) {
            buferis << s.vardas << " " << s.pavarde << " " << fixed << setprecision(2) << s.galutinis_mediana << "\n";
        }
    }

    ofstream out(failo_pavadinimas);
    if (!out.is_open()) {
        cout << "Nepavyko sukurti failo: " << failo_pavadinimas << endl;
        return;
    }

    out << buferis.str();
    out.close();
    cout << "Išvestas failas: " << failo_pavadinimas << endl;
}



