# Projektas studentų pažymiai

## Trumpas projekto aprašymas:

ši programa skaičiuoja studentų galutinius įvertinimus:
#### Galutinis = 0.4 * vidurkis(ND pažymių)/mediana(ND pažymių) + 0.6 * egzamino pažymys.

Vartotojui leidžia pasirinkti:
1. Įvesti studentus su savo turimais duomenimis.
2. Įvesti studentų vardus, pavardes su savo turimais duomenimis ir namų darbų, egzamino pažymius generuoti atsitiktinai.
3. Spausdinti studentų rezultatus (pasirinkus ar su vidurkiu ar su mediana ar su abiem yra norima skaičiuoti galutinį pažymį).
4. Nuskaityti studentų duomenis iš failo (pavadinimas.txt).
5. Atsitiktinai generuoti studentų duomenis į failus
6. Padalinti studentus į dvi grupes (vargšiukai ir kietiakai) ir išvesti į atskirus failus
7. Išeiti iš programos.

Failas (pavadinimas.txt), iš kurio norima nuskaityti duomenis turi atrodyti taip:

|  Vardas  |  Pavardė  | ND1 | ND2 | ND3 | ... | NDn | Egzaminas |
|:--------:|:---------:|:---:|:---:|:---:|:---:|:---:|:---------:|
| Vardas1  | Pavardė1  |  8  |  7  |  6  | ... |  9  |     9     |
| Vardas2  | Pavardė2  |  9  |  8  |  8  | ... |  8  |     9     |
| Vardas3  | Pavardė3  |  6  |  5  |  7  | ... |  8  |     9     |
|   ...    |   ...     | ... | ... | ... | ... | ... |    ...    |


## Studentų duomenų apdorojimo našumo analizė

Buvo atlikti matavimai su skirtingais sugeneruotų studentų skaičiais:
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Analizė buvo daroma su failais, kuriuose studentų ND kiekis yra 10. Rezultatuose paimamas 5 laiko matavimų vidurkis.

Matuota:
- Failo kūrimo laikas
- Failo nuskaitymo laikas
- Padalinimo į dvi grupes laikas
- Rikiavimo laikas (pagal galutinį pažymį)
- Išvedimo į failus laikas

## Rezultatai

| Studentų skaičius | Failo kūrimas (ms) | Nuskaitymas (ms) | Padalinimas (ms) | Rikiavimas (ms) | Išvedimas į failus (ms) |
|:-----------------:|:------------------:|:----------------:|:----------------:|:---------------:|:-----------------------:|
| 1 000             | 9.9                | 5.1              | 0.266            | 0.32            | 1.29                    |
| 10 000            | 25.3               | 20.7             | 1.637            | 1.05            | 2.54                    |
| 100 000           | 126.9              | 167.7            | 9.864            | 7.35            | 10.62                   |
| 1 000 000         | 1242.7             | 1636.7           | 61.116           | 45.46           | 104.21                  |
| 10 000 000        | 12501.7            | 1636.7           | 526.31           | 463.31          | 1074.91                 |






