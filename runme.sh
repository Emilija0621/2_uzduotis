#!/bin/bash
mkdir -p build
cd build
cmake ..
make

echo "Pasirinkite ką paleisti:"
echo "1 - Programa"
echo "2 - Unit testai"
read -p "Įveskite 1 arba 2: " choice

case $choice in
    1)
        echo "Paleidžiama programa"
        ./studentas_programa
        ;;
    2)
        echo "Paleidžiami unit testai"
        ./unit_tests
        ;;
    *)
        echo "Neteisingas pasirinkimas."
        ;;
esac
