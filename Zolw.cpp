//
// Created by polsk on 23.04.2024.
//

#include "Zolw.h"

Zolw::Zolw(Wektor2d pozycja, Swiat *swiat) : Zwierze(pozycja, 2, 1, swiat, 'Z'){

}



void Zolw::akcja() {

    if((float) rand() / (float) RAND_MAX < 0.25) losowyRuch();

}
bool Zolw::OdbicieAtaku(const Organizm *org) const {

    return org->getSila() < 5;
}

void Zolw::rysowanie() {
    std::cout << "Z";

}

std::string Zolw::Nazwa() const {
    return "ZOLW";
}

bool Zolw::czymawech() {
    return false;
}

Zolw *Zolw::Dziecko() const {
    return new Zolw(pozycja,swiat);
}

