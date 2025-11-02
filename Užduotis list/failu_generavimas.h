#include<string>
#include<list>
#include "studentas.h"

using std::list;
using std::string;

void sugeneruoti_faila(const string& failo_pavadinimas, int studentu_kiekis, int nd_pazymiu_kiekis);
void failo_generavimo_pasirinkimas();
void padalinti_ir_isvesti_studentus(list<studentas>& grupe);
void isvesti_padalintus_i_faila(const list<studentas>& grupe, const string& failo_pavadinimas, int pagal_kuri_galutini);
void padalinimo_1_strategija(list<studentas> &grupe, list<studentas> &vargsiukai, list<studentas> &kietiakai, int pagal_kuri_galutini);
void padalinimo_2_strategija(list<studentas> &grupe, list<studentas> &vargsiukai, int pagal_kuri_galutini);
void padalinimo_3_strategija(list<studentas>& grupe, list<studentas>& vargsiukai, list<studentas>& kietiakai, int pagal_kuri_galutini);


