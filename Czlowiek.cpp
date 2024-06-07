//
// Created by polsk on 23.04.2024.
//

#include "Czlowiek.h"
Czlowiek::Czlowiek(Wektor2d polozenie,Swiat* swiat) : Zwierze(polozenie,5,4,swiat,'C'){

}
void Czlowiek::akcja() {
    int zasieg = 1;
    switch(swiat->popRuch()){

        case Swiat::Ruch::STOJ:
            break;

        case Swiat::Ruch::GORA:
            Ruch({-1 * zasieg,0});
            break;

        case Swiat::Ruch::DOL:
            Ruch({zasieg,0});
            break;

        case Swiat::Ruch::PRAWO:
            Ruch({0,zasieg});
            break;

        case Swiat::Ruch::LEWO:
            Ruch({0,-1 * zasieg});
            break;

        case Swiat::Ruch::SPECJALNY:

            if(!turySpecjalne){

                turySpecjalne = 5;
                std::string komunikat = "Aktywowano umiejetnosc specjalna";
                swiat->getKomentator() << komunikat;
            }

            break;



    }
}
std:: string Czlowiek::Nazwa() const {
    return "CZLOWIEK";
}
void Czlowiek::setTurySpecjalne(int turySpecjalne) {
    turySpecjalne = turySpecjalne;
}
Czlowiek *Czlowiek::Dziecko() const{
    return new Czlowiek{pozycja,swiat};
}
void Czlowiek::rysowanie() {
    std::cout << "C";

}
bool Czlowiek::czymawech() {
   return false;

}

int Czlowiek::getTurySpecjalne() {

    return turySpecjalne;
}

bool Czlowiek::Niesmiertelny() {
    if(turySpecjalne){
        turySpecjalne--;
        return true;
    }
    return false;
}

