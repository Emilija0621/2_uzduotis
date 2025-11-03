#include <string>
#include "studentas.h"
#include <vector>

using std::vector;
using std::string;

void sugeneruoti_faila(const string& failo_pavadinimas, int studentu_kiekis, int nd_pazymiu_kiekis);
void failo_generavimo_pasirinkimas();
void padalinti_ir_isvesti_studentus(vector<studentas>& grupe);
void isvesti_padalintus_i_faila(const vector<studentas>& grupe, const string& failo_pavadinimas, int pagal_kuri_galutini);
void padalinimo_1_strategija(vector<studentas> &grupe, vector<studentas> &vargsiukai, vector<studentas> &kietiakai, int pagal_kuri_galutini);
void padalinimo_2_strategija(vector<studentas> &grupe, vector<studentas> &vargsiukai, int pagal_kuri_galutini);
void padalinimo_3_strategija(vector<studentas> &grupe, vector<studentas> &vargsiukai, vector<studentas> &kietiakai, int pagal_kuri_galutini);


