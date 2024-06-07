//
// Created by polsk on 15.04.2024.
//

#include "Wilk.h"
#include <iostream>
#include <string>

Wilk::Wilk(Wektor2d pozycja,Swiat* swiat) : Zwierze(pozycja,9,5,swiat,'W') {

}


std::string Wilk:: Nazwa() const {
    return "WILK";
}
bool Wilk::czymawech() {
    return false;
}
Wilk *Wilk::Dziecko() const{
    return new Wilk{pozycja,swiat};
}

void Wilk::rysowanie() {
    std::cout << "W";

}


