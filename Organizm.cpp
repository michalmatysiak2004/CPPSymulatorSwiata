//
// Created by polsk on 13.04.2024.
//

#include "Organizm.h"
#include <iostream>
Organizm::Organizm(Wektor2d pozycja, int sila, int inicjatywa, Swiat* swiat, char symbol){
    this->pozycja=pozycja;
    this->sila=sila;
    this->inicjatywa=inicjatywa;
    this->swiat=swiat;
    this->symbol=symbol;
}
bool Organizm::zyje() {

    if(zywy == true)
        return true;
    else
        return false;

}

void Organizm::zwiekszWiek() {
    wiek++;
}

char Organizm::getSymbol(){
    return symbol;
}
int Organizm::getWiek() {
    return wiek;
}
int Organizm::getSila() const {
    return sila;
}
int Organizm::getInicjatywa() {
    return inicjatywa;
}
int Organizm::getX() {
    return pozycja.x;
}
int Organizm::getY() {
    return pozycja.y;
}
void Organizm::setX(int x) {
    this->pozycja.x=x;
}
void Organizm::setY(int y) {
    this->pozycja.y=y;
}
void Organizm::setSila(int sila) {
    this->sila=sila;
}
void Organizm::setInicjatywa(int inicjatywa) {
    this->inicjatywa=inicjatywa;
}
void Organizm::setSwiat(Swiat *swiat) {
    this->swiat=swiat;
}
Swiat *Organizm::getSwiat() {
    return swiat;
}

bool Organizm::OdbicieAtaku(const Organizm *org) const {
    return false;
}

void Organizm::setPozycja(Wektor2d wektor){
    this->pozycja=wektor;
}
bool Organizm::uczieczka(){
    if(SzanseNaUcieczke()){
        Wektor2d poleuczieczki = swiat->WolnePole(pozycja);
        if(poleuczieczki==pozycja){
            return false;
        }
        setPozycja(poleuczieczki);
        return true;
    }
    return false;

}
void Organizm::setWiek(int wiek){
    this->wiek=wiek;
}

Wektor2d Organizm::getPozycja() {
    return pozycja;
}

void Organizm::zabij() {
    {

        std::string komunikat = this->Nazwa() + " umiera";

        swiat->getKomentator() << komunikat;

        zywy = false;

    }

}



bool Organizm::SzanseNaUcieczke() const {
    return false;
}

void Organizm::dodajModyfikator(Organizm *organizm) const {

}

bool Organizm::Niesmiertelny() {
    return false;
}


