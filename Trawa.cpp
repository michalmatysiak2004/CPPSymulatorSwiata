//
// Created by polsk on 23.04.2024.
//

#include "Trawa.h"

void Trawa::rysowanie() {
    std::cout << "T";
}

Trawa::Trawa(Wektor2d polozenie,Swiat* swiat): Roslina(polozenie, 0, swiat, 'T') {

}
Trawa *Trawa::Dziecko() const {
    return new Trawa{*this};
}

std::string Trawa::Nazwa() const {
    return "TRAWA";
}
