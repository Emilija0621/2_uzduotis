# Projektas studentų pažymiai

## Programos diegimo ir paleidimo instrukcija

1. Atsisiųsti programos failus ir CMakeLists.txt
2. Viską sudėti į aplanką "Studentai", Studentai aplanke turi būti:
- Aplankas "Include" su visais header failais (pavadinimas.h)
- Aplankas "src" su visais source failais (pavadinimas.cpp)
- CMakeLists.txt
3. Atsidaryti komandinę eilutę ir ten (ios operacinė sistema):
- Nueiti į "Studentai" aplanko direktoriją (pvz. cd ~/Desktop/Studentai)
- Eilutėje parašyti komandas:<br>
  mkdir build <br>
  cd build<br>
  cmake ..<br>
  make<br>
- Tada paleisti programą su komanda: ./Studentai


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

<img width="688" height="141" alt="image" src="https://github.com/user-attachments/assets/7e947558-2eab-48d1-a0ba-b63f311145eb" /><br>

- #### Vartotojui įvedus duomenis rankiniu būdu ekrane išvedamas objekto saugojimo atmintyje adresas:
  
<img width="374" height="18" alt="image" src="https://github.com/user-attachments/assets/04260ffa-a8c4-4b3a-a64d-234cdeee042a" /><br>

- #### Spausdinant studentus leidžiama pasirinkti, pagal ką vartotojas nori skaičiuoti galutinį pažymį bei pagal ką išrikiuoti:

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

## Rūšiavimo strategijų palyginimas (v1.0 spartos analizė)

- 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
- 3 strategija: Optimizuota 1 strategija.


### Vector versija

| Studentų skaičius | 1 strategija (s) |  2 strategija (s) |  3 strategija (s) | 
|:-----------------:|:----------------:|:-----------------:|:-----------------:|
| 1 000             | 0.00045          | 0.00052           |                   |
| 10 000            | 0.00127          | 0.00356           |                   |
| 100 000           | 0.01596          | 0.08670           |                   |
| 1 000 000         | 0.08906          | 0.11815           |                   |
| 10 000 000        | 0.55538          | 1.81777           |                   |


### List versija

| Studentų skaičius | 1 strategija (s) |  2 strategija (s) |  3 strategija (s) | 
|:-----------------:|:----------------:|:-----------------:|:-----------------:|
| 1 000             | 0.00082          | 0.00122           |                   |
| 10 000            | 0.00605          | 0.01890           |                   |
| 100 000           | 0.03761          | 0.05593           |                   |
| 1 000 000         | 0.19540          | 0.83532           |                   |
| 10 000 000        | 1.83842          | 14.4482           |                   |


































