//
// Created by polsk on 23.04.2024.
//

#include "Roslina.h"

void Roslina::akcja() {
    rozprzestrzen();
}
Roslina::Roslina(Wektor2d polozenie, int sila, Swiat* swiat,  char symbol) : Organizm(polozenie, sila, 0, swiat, symbol) {

}
void Roslina ::kolizja() {

}
void Roslina::rozprzestrzen() {

    if((float)rand()/(float) RAND_MAX <= 0.02) {

        auto pNowy = swiat->WolnePole(pozycja);

        if (pNowy == pozycja) return;

        auto *org = this->Dziecko();
        org->setWiek(0);

        org->setPozycja(pNowy);

        swiat->dodajOrganizm(org);
    }

}
