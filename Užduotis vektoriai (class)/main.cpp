#include "studentas.h"
#include "skaiciavimai.h"
#include "spausdinimas.h"
#include "failu_skaitymas.h"
#include "failu_generavimas.h"
#include "laikas.h"
#include<iostream>
#include<vector>
#include<string>
#include<type_traits>

using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;
using std::is_abstract;
using std::boolalpha;

int main() {
    cout << boolalpha;
    cout << "Zmogus abstrakti? "<< is_abstract<Zmogus>::value << endl;
    cout << "Studentas abstrakti? " << is_abstract<Studentas>::value << endl;

    vector<Studentas> grupe;
    int pasirinkimas1;

    while (true) {
        while (true) {
            cout << "Pasirinkite veiksmą: " << endl;
            cout << "1 - Įvesti studentą su turimais duomenimis" << endl;
            cout << "2 - Įvesti vardą ir pavardę, bet pažymius generuoti atsitiktinai" << endl;
            cout << "3 - Spausdinti studentų rezultatus" << endl;
            cout << "4 - Nuskaityti studentų duomenis iš failo" << endl;
            cout << "5 - Atsitiktinai generuoti studentų duomenis į failus" << endl;
            cout << "6 - Padalinti studentus į dvi grupes (vargšiukai ir kietiakai) ir išvesti į atskirus failus" << endl;
            cout << "7 - Patikrinti Rule of three veikimą" << endl;
            cout << "8 - Išeiti" << endl;

            string ivestis;
            cin >> ivestis;

            try {
                pasirinkimas1 = stoi(ivestis);
                if (pasirinkimas1 < 1 || pasirinkimas1 > 8) {
                    cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 8." << endl;
                    continue;
                }
                break;
            } catch (const invalid_argument&) {
                cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 8." << endl;
            }
        }

        if (pasirinkimas1 == 1) {
            Studentas s;
            // naudojamas operatorius >>
            cin >> s ;
            grupe.push_back(s);
            
            cout << "Studento objektas saugomas adresu: " << &grupe.back() << endl;

        } else if (pasirinkimas1 == 2) {
            Studentas s;
            s.readStudent(cin, true);
            grupe.push_back(s);
            
            cout << "Studento objektas saugomas adresu: " << &grupe.back() << endl;

        } else if (pasirinkimas1 == 3) {
            
            int pasirinkimas = galutiniai_pazymiai(grupe);
            int kur1;
            
            if (pasirinkimas != 0) {
                
                while (true) {
                    cout << "Kur norite išvesti duomenis?" << endl;
                    cout << "1 - Į konsolę" << endl;
                    cout << "2 - Į failą" << endl;

                    string kur;
                    cin >> kur;

                    try {
                        kur1 = stoi(kur);

                        if (kur1 < 1 || kur1 > 2) {
                            cout << "Neteisingas pasirinkimas. Įveskite skaičių nuo 1 iki 2." << endl;
                            continue;
                        }
                        break;

                    } catch (const invalid_argument&) {
                        cout << "Įvesta netinkama reikšmė. Įveskite skaičių nuo 1 iki 2." << endl;
                    }
                }
                if (kur1 == 1){
                    spausdinti_studentus(grupe, pasirinkimas);
                } else {
                    string failo_pav;
                    cout << "Įveskite failo pavadinimą: ";
                    cin >> failo_pav;

                    vector<Studentas> surusiuota = grupe;

                    int rikiavimo_pasirinkimas;

                    while (true) {
                        cout << "Pagal ką norite rikiuoti studentus prieš išvedant į failą?" << endl;
                        cout << "1 - Pagal vardą" << endl;
                        cout << "2 - Pagal pavardę" << endl;
                        cout << "3 - Pagal galutinį pažymį" << endl;

                        string rinktis;
                        cin >> rinktis;

                        try {
                            rikiavimo_pasirinkimas = stoi(rinktis);
                            if (rikiavimo_pasirinkimas < 1 || rikiavimo_pasirinkimas > 3) {
                                cout << "Neteisingas pasirinkimas. Įveskite 1-3." << endl;
                                continue;
                            }
                            break;
                        } catch (...) {
                            cout << "Įvesta netinkama reikšmė. Bandykite dar kartą." << endl;
                        }
                    }

                    if (rikiavimo_pasirinkimas == 1) {
                        sort(surusiuota.begin(), surusiuota.end(), comparePagalVarda);

                    } else if (rikiavimo_pasirinkimas == 2) {
                        sort(surusiuota.begin(), surusiuota.end(), comparePagalPavarde);

                    } else if (rikiavimo_pasirinkimas == 3) {

                        if (pasirinkimas == 1) {
                            sort(surusiuota.begin(), surusiuota.end(), comparePagalVidurki);

                        } else if (pasirinkimas == 2) {
                            sort(surusiuota.begin(), surusiuota.end(), comparePagalMediana);

                        } else if (pasirinkimas == 3) {

                            int kuris;
                            while (true) {
                                cout << "Pasirinkite pagal kurį galutinį pažymį rikiuoti:" << endl;
                                cout << "1 - Pagal vidurkį" << endl;
                                cout << "2 - Pagal medianą" << endl;

                                string t;
                                cin >> t;

                                try {
                                    kuris = stoi(t);
                                    if (kuris < 1 || kuris > 2) {
                                        cout << "Neteisingas pasirinkimas. Įveskite 1 arba 2." << endl;
                                        continue;
                                    }
                                    break;
                                } catch (...) {
                                    cout << "Įvesta netinkama reikšmė. Bandykite dar kartą." << endl;
                                }
                            }

                            if (kuris == 1)
                                sort(surusiuota.begin(), surusiuota.end(), comparePagalVidurki);
                            else
                                sort(surusiuota.begin(), surusiuota.end(), comparePagalMediana);
                        }
                    }
                    isvesti_i_faila(surusiuota, failo_pav, pasirinkimas);
                }
            }

        } else if (pasirinkimas1 == 4) {
            cout << "Įveskite failo pavadinimą: ";
            string failas;
            cin >> failas;
            
            laikas t;
            t.reset();
            
            nuskaityti_duomenis_is_failo(failas, grupe);
            
            cout << "Failo nuskaitytas per " << t.elapsed() << " sekundžių" << endl;

        } else if (pasirinkimas1 == 5) {
            failo_generavimo_pasirinkimas();

        } else if (pasirinkimas1 == 6) {
            padalinti_ir_isvesti_studentus(grupe);

        } else if (pasirinkimas1 == 7) {
            rule_of_three();

        } else if (pasirinkimas1 == 8){
            cout << "Programa baigta." << endl;
            break;
        } else {
            cout << "Neteisingas pasirinkimas." << endl;
        }
    }
    return 0;
}
