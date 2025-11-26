# Projektas studentų pažymiai

## Programos diegimo ir paleidimo instrukcija

### Reikalavimai:

- C++ kompiliatorius (pvz., g++ 10+ arba Apple Clang 17+ su C++20 palaikymu)
- CMake – projekto generavimo įrankis
- make – kompiliavimo ir vykdomojo failo generavimo įrankis

### Paleidimo žingsniai:

1. Atsisiųsti programos failus ir CMakeLists.txt
2. Viską sudėti į aplanką "Studentai", Studentai aplanke turi būti:
- Aplankas "Include" su visais header failais (pavadinimas.h)
- Aplankas "src" su visais source failais (pavadinimas.cpp)
- CMakeLists.txt

3. Atidaryti komandinę eilutę (terminalą) ir pereiti į projekto aplanką, pvz.:
- cd ~/Desktop/Studentai   (Unix / macOS / Linux)
- cd C:\Users\Vartotojas\Desktop\Studentai  (Windows)

4. Sukurti buid aplanką ir sukompiliuoti projektą: 
- mkdir build  
- cd build 
- cmake .. 
- make   (Unix / Linux / macOS, Windows su make palaikymu) 

5. Paleisti programą:
- ./Studentai   (Unix / macOS / Linux)
- Studentai.exe  (Windows)

### Analogiškai galima naudoti runme.sh (Unix / macOS / Linux)

1. Atsisiųsti programos failus, CMakeLists.txt ir runme.sh
  
2. Viską sudėti į aplanką "Studentai", Studentai aplanke turi būti:
- Aplankas "Include" su visais header failais (pavadinimas.h)
- Aplankas "src" su visais source failais (pavadinimas.cpp)
- CMakeLists.txt
- runme.sh

3. Atidaryti komandinę eilutę (terminalą) ir pereiti į projekto aplanką, pvz.:
- cd ~/Desktop/Studentai 

4. Įsitikinti, kad failas yra vykdomas:
- chmod +x runme.sh

5. Paleisti programą:
- ./runme.sh


## Trumpas projekto aprašymas:

ši programa leidžia apskaičiuoti studentų galutinius įvertinimus:
##### Galutinis = 0.4 * vidurkis(ND pažymių)/mediana(ND pažymių) + 0.6 * egzamino pažymys.

### Programos leidimai:

- #### v0.1 versija:

Programoje galima įvesti visus stuentų duomenis rankiniu būdu, atsitiktinai generuoti studentų pažymius, nuskaityti studentų duomenis iš failų bei atspausdinti studentus ir jų galutinius pažymius.

- #### v0.2 versija:

Patobulinta v0.1 versija: pridėta galimybė generuoti atsitiktinių studentų failus bei padalinti studentus į dvi kategorijas ("vargšiukai", "kietiakai"). Atlikta spartos analizė (žr. Studentų duomenų apdorojimo našumo analizė/Vector versija).

- #### v0.3 versija:

Patobulinta v.02 versija: dvi atskiros programos - viena su vector, kita su list. Atlikta spartos analizė (žr. Studentų duomenų apdorojimo našumo analizė/Vector versija, List versija).

- #### v1.0 versija:

Patobulinta v.03 versija: pridėtos 3 studentų padalinimo į dvi kategorijas ("vargšiukai", "kietiakai") strategijos. Atlikta spartos analizė (žr. Rūšiavimo strategijų palyginimas).

## Programos veikimo principas:

- #### Vartotojui leidžia pasirinkti:

<img width="690" height="156" alt="image" src="https://github.com/user-attachments/assets/9a94bb24-0300-4082-9ed8-6be13249c225" /><br>

- #### Vartotojui įvedus duomenis rankiniu būdu ekrane išvedamas objekto saugojimo atmintyje adresas:
  
<img width="374" height="18" alt="image" src="https://github.com/user-attachments/assets/04260ffa-a8c4-4b3a-a64d-234cdeee042a" /><br>

- #### Spausdinant studentus leidžiama pasirinkti, kur vartotojas nori išvesti duomenis, pagal ką skaičiuoti galutinį pažymį bei pagal ką išrikiuoti:

<img width="214" height="55" alt="image" src="https://github.com/user-attachments/assets/1d432a82-5f64-4f1a-8fe4-fb464b37ab59" /><br>

<img width="437" height="69" alt="image" src="https://github.com/user-attachments/assets/4ad7ab62-5bdf-4397-90a1-1869a72ff2f7" /><br>

<img width="371" height="69" alt="image" src="https://github.com/user-attachments/assets/35226478-120c-416a-b7db-37a4a34fe695" /><br>

Atveju, kai vartotojas nori gauti skaičiavimus abejais būdais bei rikiavimą pagal galutinį pažymį, jis gali pasirinkti pagal kurį galutinį pažymį nori išrikiuoti:<br>

<img width="364" height="55" alt="image" src="https://github.com/user-attachments/assets/f025de14-c6b5-478c-a3cc-370b1329032a" /><br>

- #### Failas (pavadinimas.txt), iš kurio norima nuskaityti duomenis turi atrodyti taip:

|  Vardas  |  Pavardė  | ND1 | ND2 | ND3 | ... | NDn | Egzaminas |
|:--------:|:---------:|:---:|:---:|:---:|:---:|:---:|:---------:|
| Vardas1  | Pavardė1  |  8  |  7  |  6  | ... |  9  |     9     |
| Vardas2  | Pavardė2  |  9  |  8  |  8  | ... |  8  |     9     |
| Vardas3  | Pavardė3  |  6  |  5  |  7  | ... |  8  |     9     |
|   ...    |   ...     | ... | ... | ... | ... | ... |    ...    |
<br>


- #### Programa gali sugeneruoti 1 000, 10 000, 100 000, 1 000 000, 10 000 000 studentų įrašus, vartotojas pasirenka ar nori pats įvesti ND kiekį, ar jį sugeneruoti atsitiktinai (1-20 ND):<br>

<img width="179" height="105" alt="image" src="https://github.com/user-attachments/assets/f8a81cc3-d7c8-4ac1-9756-0d72bf3d837c" /><br>

<img width="291" height="56" alt="image" src="https://github.com/user-attachments/assets/aad2320a-2e11-4619-9f06-d399bdf14c7d" /><br>

-  #### Studentai į grupes padalinami pagal jų galutinį pažymį (galutinis balas < 5.0 yra “vargšiukai”, >= 5.0 yra “kietiakiai”). Išvedant studentus į failus leidžiama pasirinkti, pagal kurią strategiją, galutinį pažymį norima padalinti studentus bei pagal ką išrikiuoti:<br>

<img width="366" height="73" alt="image" src="https://github.com/user-attachments/assets/bb38dfae-a983-4262-a847-d1e2927d4241" /><br>

<img width="424" height="53" alt="image" src="https://github.com/user-attachments/assets/2b16f3db-1c36-4c25-8168-49115ac8a555" /><br>

Pasirinkus studentus padalinti pagal galutinį pažymį (skaičiuojamas su vidurkiu):<br>

<img width="431" height="69" alt="image" src="https://github.com/user-attachments/assets/c2b9d3b0-c727-492e-b3d2-b62153423ba6" /><br>

Pasirinkus studentus padalinti pagal galutinį pažymį (skaičiuojamas su mediana):<br>

<img width="431" height="69" alt="image" src="https://github.com/user-attachments/assets/1969c469-ff51-4f4b-9bb3-bc87086179a9" /><br>

- #### Vartotojas gali patikrinti "Rule of three" veikimą: <br>

Rezultato pavyzdys:<br>

<img width="576" height="263" alt="image" src="https://github.com/user-attachments/assets/ef108ccf-548a-4fea-8175-99ea8fdf2d85" /><br>

## Studentų duomenų apdorojimo našumo analizė

### Testavimo sistemos parametrai:
- Apple M1
- 16 GB RAM
- 512 GB SSD

Abiejų versijų matavimai buvo atlikti su skirtingais sugeneruotų studentų skaičiais:
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Analizė buvo daroma su failais, kuriuose studentų ND kiekis yra 10. Rezultatuose imamas 5 laiko matavimų vidurkis.

Matuota:
- Failo kūrimo laikas
- Failo nuskaitymo laikas
- Padalinimo į dvi grupes laikas
- Rikiavimo laikas (pagal galutinį pažymį)
- Išvedimo į failus laikas

### Rezultatai su vector (v0.2, v0.3 versijos spartos analizė):

| Studentų skaičius | Failo kūrimas (s) | Nuskaitymas (s) | Padalinimas (s) | Rikiavimas (s) | Išvedimas į failus (s) |
|:-----------------:|:-----------------:|:---------------:|:---------------:|:--------------:|:----------------------:|
| 1 000             | 0.0061            | 0.0056          | 0.000282        | 0.000245       | 0.00115                |
| 10 000            | 0.0324            | 0.0207          | 0.001649        | 0.001445       | 0.00389                |
| 100 000           | 0.1394            | 0.1726          | 0.008310        | 0.012847       | 0.02138                |
| 1 000 000         | 1.2417            | 1.6133          | 0.088181        | 0.077788       | 0.08457                |
| 10 000 000        | 12.449            | 16.435          | 0.599126        | 0.459601       | 1.07342                |

### Rezultatai su list (v0.3 versijos spartos analizė):

| Studentų skaičius | Failo kūrimas (s) | Nuskaitymas (s) | Padalinimas (s) | Rikiavimas (s) | Išvedimas į failus (s) |
|:-----------------:|:-----------------:|:---------------:|:---------------:|:--------------:|:----------------------:|
| 1 000             | 0.0064            | 0.0064          | 0.000677        | 0.000407       | 0.003224               |
| 10 000            | 0.0339            | 0.0218          | 0.004377        | 0.003211       | 0.012676               |
| 100 000           | 0.1609            | 0.2120          | 0.035563        | 0.032279       | 0.031793               |
| 1 000 000         | 1.2646            | 1.7487          | 0.188587        | 0.473354       | 0.135002               |
| 10 000 000        | 12.784            | 17.624          | 1.973972        | 8.517431       | 1.537113               |

### Grafikas palyginimui:<br>

<img width="785" height="415" alt="image" src="https://github.com/user-attachments/assets/426dc1a1-af04-4047-acba-42c028a46186" /><br>

### Išvados:

- Mažais duomenų kiekiais (1 000 - 10 000 studentų) vektoriai ir sąrašai veikia labai panašiai.
- Vidutiniais duomenų kiekiais (100 000 - 1 000 000 studentų) vektoriai pastebimai spartesni, ypač atliekant operacijas, kaip padalijimas ir rikiavimas.
- Su dideliais duomenų kiekiais (10 000 000 studentų) vektoriai yra žymiai pranašesni - operacijos vyksta daug greičiau nei su sąrašais.

## Padalinimo į dvi grupes strategijų palyginimas (v1.0 spartos analizė)

- 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai".
- 3 strategija: Optimizuota 1 strategija.


### Vector versija

| Studentų skaičius | 1 strategija (s) |  2 strategija (s) |  3 strategija (s) | 
|:-----------------:|:----------------:|:-----------------:|:-----------------:|
| 1 000             | 0.00045          | 0.00052           | 0.00006           |
| 10 000            | 0.00127          | 0.00356           | 0.00075           |
| 100 000           | 0.01596          | 0.08670           | 0.00206           |
| 1 000 000         | 0.08906          | 0.11815           | 0.03201           |
| 10 000 000        | 0.55538          | 1.81777           | 0.23257           |

### Grafikas palyginimui:<br>

<img width="785" height="415" alt="image" src="https://github.com/user-attachments/assets/fbe3afdb-1b73-42ac-b54b-559fba97d8ba" /> <br>

### List versija

| Studentų skaičius | 1 strategija (s) |  2 strategija (s) |  3 strategija (s) | 
|:-----------------:|:----------------:|:-----------------:|:-----------------:|
| 1 000             | 0.00082          | 0.00122           | 0.00011           |
| 10 000            | 0.00605          | 0.01890           | 0.00214           |
| 100 000           | 0.03761          | 0.05593           | 0.01117           |
| 1 000 000         | 0.19540          | 0.83532           | 0.08208           |
| 10 000 000        | 1.92752          | 14.4482           | 1.81345           |

### Grafikas palyginimui:<br>

<img width="785" height="415" alt="image" src="https://github.com/user-attachments/assets/eacaecd7-1c61-48a5-8790-d90c8c8abcf7" />


## v1.1

Buvo testuojama (analizė buvo atlikta su vector):
- 100 000, 1 000 000 studentų failų kūrimas
- 100 000, 1 000 000 studentų failų nuskaitymas
- Studentų padalinimas į grupes (3 strategija)
- Rikiavimas
- Išvedimas į failus
  

## Struct ir class spartos analizė

### Struct
 
| Studentų skaičius | Failo kūrimas (s) | Nuskaitymas (s) | Padalinimas (s) | Rikiavimas (s) | Išvedimas į failus (s) |
|:-----------------:|:-----------------:|:---------------:|:---------------:|:--------------:|:----------------------:|
| 100 000           | 0.1394            | 0.1726          | 0.0083          | 0.0128         | 0.0213                 |
| 1 000 000         | 1.2417            | 1.6133          | 0.0881          | 0.0777         | 0.0845                 |

### Class

| Studentų skaičius | Failo kūrimas (s) | Nuskaitymas (s) | Padalinimas (s) | Rikiavimas (s) | Išvedimas į failus (s) |
|:-----------------:|:-----------------:|:---------------:|:---------------:|:--------------:|:----------------------:|
| 100 000           | 0.1322            | 0.2173          | 0.0453          | 0.1157         | 0.1129                 |
| 1 000 000         | 1.2234            | 1.6704          | 0.0986          | 0.2188         | 0.1895                 |




### Išvados:
- Struct ir Class versijų našumas yra labai panašus, tačiau pagrindinis skirtumas išryškėja po padalinimo etapo.
- Failo kūrimo ir nuskaitymo laikai abiejose versijose beveik sutampa — skirtumai minimalūs.
- Rikiavimo, išvedimo į grupes metu klasės versija veikia žymiai lėčiau.


## Struct ir class spartos analizė pagal optimizavimo lygi

### Struct

#### Studentų skaičius - 100 000

| Optimizavimo lygis |  Failo sukūrimas (s) | Nuskaitymas (s) | Padalijimas (s) | Rikiavimas (s)  | Išvedimas į failus (s) |
|:------------------:|:--------------------:|:---------------:|:---------------:|:---------------:|:----------------------:|
| O0                 | 0.1394               | 0.1726          | 0.0083          | 0.0128          | 0.0213                 |          
| O1                 | 0.1363               | 0.1687          | 0.0076          | 0.0119          | 0.0198                 |
| O2                 | 0.1335               | 0.1647          | 0.0072          | 0.0113          | 0.0189                 |
| O3                 | 0.1319               | 0.1626          | 0.0070          | 0.0111          | 0.0182                 |


#### Studentų skaičius - 1 000 000

| Optimizavimo lygis |  Failo sukūrimas (s) | Nuskaitymas (s) | Padalijimas (s) |  Rikiavimas (s) | Išvedimas į failus (s) |
|:------------------:|:--------------------:|:---------------:|:---------------:|:---------------:|:----------------------:|
| O0                 | 1.2417               | 1.6133          |  0.0320         | 0.0777          | 0.0845                 |            
| O1                 | 1.2135               | 1.5972          |  0.0277         | 0.0707          | 0.0807                 |
| O2                 | 1.1913               | 1.5637          |  0.0246         | 0.0652          | 0.0865                 |
| O3                 | 1.1837               | 1.5810          |  0.0237         | 0.0565          | 0.0843                 |


| Optimizavimo lygis | Vykdomojo failo dydis (KB) |
|:------------------:|:--------------------------:|
| O0                 | 430                        |
| O1                 | 224                        |
| O2                 | 143                        |
| O3                 | 142                        |


### Class

#### Studentų skaičius - 100 000

| Optimizavimo lygis |  Failo sukūrimas (s) | Nuskaitymas (s) | Padalijimas (s) | Rikiavimas (s)  | Išvedimas į failus (s) |
|:------------------:|:--------------------:|:---------------:|:---------------:|:---------------:|:----------------------:|
| O0                 | 0.1322               | 0.2173          | 0.0453          | 0.1157          | 0.1129                 |
| O1                 | 0.1237               | 0.2160          | 0.0442          | 0.1148          | 0.1123                 |   
| O2                 | 0.1241               | 0.2153          | 0.0448          | 0.1139          | 0.1117                 |   
| O3                 | 0.1238               | 0.2115          | 0.0443          | 0.1134          | 0.1112                 |   

#### Studentų skaičius - 1 000 000

| Optimizavimo lygis |  Failo sukūrimas (s) | Nuskaitymas (s) | Padalijimas (s) | Rikiavimas (s)  | Išvedimas į failus (s) |
|:------------------:|:--------------------:|:---------------:|:---------------:|:---------------:|:----------------------:|
| O0                 | 1.2234               | 1.6704          | 0.0986          | 0.2188          | 0.1895                 |
| O1                 | 1.1873               | 1.6611          | 0.0963          | 0.2135          | 0.1857                 |
| O2                 | 1.1905               | 1.6179          | 0.0942          | 0.2108          | 0.1853                 |
| O3                 | 1.1903               | 1.5896          | 0.0925          | 0.2097          | 0.1844                 |                        


| Optimizavimo lygis | Vykdomojo failo dydis (KB) |
|:------------------:|:--------------------------:|
| O0                 | 254                        |
| O1                 | 121                        |
| O2                 | 121                        |
| O3                 | 120                        |


### Išvados:
- Aukštesnis optimizacijos lygis efektyviai mažina laiką ir failo dydį, bet didžiausią poveikį turi pereinant nuo O0 prie O1/O2.

## v1.2

Realizuoti visi "Rule of three" ir įvesties/išvesties operatoriai bei atliktas įvesties ir išvesties metodų perdengimas.

### Rule of three

#### 1. Kopijavimo konstruktorius

``` bash
Studentas(const Studentas& stud)
    : vardas_(stud.vardas_),
      pavarde_(stud.pavarde_),
      pazymiai_(stud.pazymiai_),
      egzamino_pazymys_(stud.egzamino_pazymys_),
      galutinis_vidurkis_(stud.galutinis_vidurkis_),
      galutinis_mediana_(stud.galutinis_mediana_) 
{}
```

#### 2. Priskyrimo operatorius (copy assignment)

``` bash
Studentas& operator=(const Studentas& stud) {
        Studentas laikinas(stud);
        if (this == &stud)
            return *this;
        
        swap(vardas_, laikinas.vardas_);
        swap(pavarde_, laikinas.pavarde_);
        swap(pazymiai_, laikinas.pazymiai_);
        swap(egzamino_pazymys_, laikinas.egzamino_pazymys_);
        swap(galutinis_vidurkis_, laikinas.galutinis_vidurkis_);
        swap(galutinis_mediana_, laikinas.galutinis_mediana_);
        return *this;
    }
```

#### 3. Destruktorius

``` bash
~Studentas(){
        vardas_.clear();
        pavarde_.clear();
        pazymiai_.clear();
        
        egzamino_pazymys_ = 0;
        galutinis_mediana_ = 0.0;
        galutinis_vidurkis_ = 0.0;
    }
```

### Įvesties/išvesties operatorių perdengimas

- #### Įvesties operatorius `operator>>`

``` bash
friend istream& operator>>(istream& is, Studentas& s);
```
Operatorius `>>` leidžia patogiai įvesti studento duomenis. Vartotojas įveda vardą, pavardę, namų darbų pažymius ir egzamino balą. Visos reikšmės tikrinamos, o suvedus duomenis automatiškai apskaičiuojami galutiniai balai.

#### Panaudojimas programoje

``` bash
// Alternatyvus įvedimo būdas (vietoje readStudent)
cin >> s;
```

- #### Išvesties operatorius `operator<<`

``` bash
friend ostream& operator<<(ostream& os, const Studentas& s);
```

Operatorius `<<` išveda studento informaciją tvarkingu, stulpeliniu formatu. Atvaizduojamas vardas, pavardė, galutinis balas pagal vidurkį ir pagal medianą. Naudojami formatavimo įrankiai (setw, left, setprecision) aiškiam rezultatų pateikimui.

#### Panaudojimas programoje

``` bash
// Išvedant duomenis į failą
buferis << s << endl;
```

``` bash
// Išvedant duomenis į ekraną
cout << s << endl;
```

## v1.5

- Sukurta bazinė (abstrakti) klasė `Žmogus`.
- Iš jos sukuriama išvestinė (derived) klasė `Studentas`.

#### Klasė Zmogus
``` bash
class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const string& v, const string& p) : vardas_(v), pavarde_(p) {}

    virtual string vardas() const = 0;
    virtual string pavarde() const = 0;

    virtual ~Zmogus() {
        vardas_.clear();
        pavarde_.clear();
    }
};
```

#### Klasė Studentas
``` bash
class Studentas: public Zmogus {...}
```

### Patikrinimas, ar klasė Žmogus yra abstrakti.

- #### Sukurtos bazinės (abstrakčios) klasės Žmogus objektų kūrimas (`Zmogus z;`) yra negalimas.

Metama klaida: <br>

<img width="203" height="38" alt="image" src="https://github.com/user-attachments/assets/079aa6f7-22ab-4cd3-bea6-34bdb1a9cedb" /> <br>


- #### Naudojant `std::is_abstract<Zmogus>::value` patikrinama, ar Zmogus yra abstrakti klasė. <br>

Grąžina rezultatą: <br>

<img width="203" height="38" alt="image" src="https://github.com/user-attachments/assets/9c7c08ed-5548-43d9-80e4-90be8b82c8b5" />










 
