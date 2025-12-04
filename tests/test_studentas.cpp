#include <gtest/gtest.h>
#include "skaiciavimai.h"
#include "studentas.h"
#include <vector>
#include <sstream>

using std::vector;
using std::istringstream;


// Testai skaiciavimai.cpp

TEST(SkaiciavimaiTest, Vidurkis) {
    vector<int> pazymiai = {6, 8, 10};
    // (6 + 8 + 10) / 3 = 24 / 3 = 8
    EXPECT_DOUBLE_EQ(skaiciuoti_vidurki(pazymiai), 8.0);
}

TEST(SkaiciavimaiTest, MedianaLyginis) {
    vector<int> pazymiai = {9, 3, 7, 5};
    // Rikiuota: 3, 5, 7, 9
    // (5 + 7) / 2 = 12 / 2 = 6
    EXPECT_DOUBLE_EQ(skaiciuoti_mediana(pazymiai), 6.0);
}

TEST(SkaiciavimaiTest, MedianaNelyginis) {
    vector<int> pazymiai = {9, 3, 7};
    // Rikiuota: 3, 7, 9
    // mediana = 7
    EXPECT_DOUBLE_EQ(skaiciuoti_mediana(pazymiai), 7.0);
}

TEST(SkaiciavimaiTest, GalutinisVidurkis) {
    vector<int> pazymiai = {4, 6, 8};
    int egzaminas = 5;
    // vidurkis = 6
    // galutinis = 6*0.4 + 5*0.6 = 2.4 + 3 = 5.4
    EXPECT_DOUBLE_EQ(skaiciuoti_galutinis_pazymys(pazymiai, egzaminas, false), 5.4);
}

TEST(SkaiciavimaiTest, GalutinisMediana) {
    vector<int> pazymiai = {9, 3, 7};
    int egzaminas = 10;
    // mediana = 7
    // galutinis = 7*0.4 + 10*0.6 = 2.8 + 6 = 8.8
    EXPECT_DOUBLE_EQ(skaiciuoti_galutinis_pazymys(pazymiai, egzaminas, true), 8.8);
}


// Testai Studentas klasės

TEST(StudentasTest, SetGet) {
    Studentas s;
    s.setVardas("Jonas");
    s.setPavarde("Jonaitis");
    s.setPazymiai({5, 7, 9}); // vidurkis = 7, mediana = 7
    s.setEgzaminoPazymys(6);

    s.apskaiciuotiGalutinius();

    EXPECT_EQ(s.vardas(), "Jonas");
    EXPECT_EQ(s.pavarde(), "Jonaitis");
    // galutinis pagal vidurkį = 7*0.4 + 6*0.6 = 2.8 + 3.6 = 6.4
    EXPECT_DOUBLE_EQ(s.galutinis_vidurkis(), 6.4);
    
    // galutinis pagal medianą = 7*0.4 + 6*0.6 = 6.4
    EXPECT_DOUBLE_EQ(s.galutinis_mediana(), 6.4);
}

TEST(StudentasTest, Kopijavimas) {
    Studentas s1;
    s1.setVardas("A");
    s1.setPavarde("B");
    s1.setPazymiai({5, 7, 9});
    s1.setEgzaminoPazymys(10);
    s1.apskaiciuotiGalutinius();

    Studentas s2(s1); // kopijavimo konstruktorius

    EXPECT_EQ(s1, s2);

    Studentas s3;
    s3 = s1; // priskyrimo operatorius
    EXPECT_EQ(s1, s3);
}

