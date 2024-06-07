//
// Created by polsk on 23.04.2024.
//

#include "WilczeJagody.h"
void WilczeJagody::rysowanie() {
    std::cout << "J";
}

WilczeJagody::WilczeJagody(Wektor2d polozenie,Swiat* swiat): Roslina(polozenie, 0, swiat, 'J') {

}
WilczeJagody *WilczeJagody::Dziecko() const {
    return new WilczeJagody{*this};
}

std::string WilczeJagody::Nazwa() const {
    return "WILCZEJAGODY";
}
void WilczeJagody::dodajModyfikator(Organizm *organizm) const {
    organizm->zabij();
    std::string komunikat =  organizm->Nazwa() + "zjada Wilcze Jagody i ginie";
    swiat->getKomentator() << komunikat;
}
