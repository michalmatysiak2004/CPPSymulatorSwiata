//
// Created by polsk on 23.04.2024.
//

#include "Antylopa.h"

Antylopa::Antylopa(Wektor2d pozycja, Swiat *swiat) : Zwierze(pozycja, 4, 4, swiat, 'A') {

}

bool Antylopa::SzanseNaUcieczke() const {

    return (float)rand()/(float)RAND_MAX < 0.5;

}

Antylopa *Antylopa::Dziecko() const {
    return new Antylopa{pozycja,swiat};
}
void Antylopa::akcja() {

    losowyRuch(2);

}
std::string Antylopa::Nazwa() const {
    return "ANTYLOPA";
}

bool Antylopa::czymawech() {
    return false;
}

void Antylopa::rysowanie() {
std:: cout <<  "A";
}
