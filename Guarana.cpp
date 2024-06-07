//
// Created by polsk on 23.04.2024.
//

#include "Guarana.h"
void Guarana::rysowanie() {
    std::cout << "G";
}

Guarana::Guarana(Wektor2d polozenie,Swiat* swiat): Roslina(polozenie, 0, swiat, 'G') {

}
Guarana *Guarana::Dziecko() const {
    return new Guarana{*this};
}

std::string Guarana::Nazwa() const {
    return "GUARANA";
}
void Guarana::dodajModyfikator(Organizm *organizm) const {
    std::cout << "jestem w dodaj modyfikator";
    organizm->setSila(organizm->getSila() + 3);
    std::string komunikat =  organizm->Nazwa() + "zjada Guarane i zwieksza swoja sile o 3";
    swiat->getKomentator() << komunikat;

}