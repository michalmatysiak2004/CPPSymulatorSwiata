//
// Created by polsk on 23.04.2024.
//

#include "Mlecz.h"


void Mlecz::rysowanie() {
    std::cout << "M";
}
void Mlecz::akcja() {
    for (int i = 0; i < 3; i++) {
        rozprzestrzen();
    }
}
Mlecz::Mlecz(Wektor2d polozenie,Swiat* swiat): Roslina(polozenie, 0, swiat, 'M') {

}
Mlecz *Mlecz::Dziecko() const {
    return new Mlecz{*this};
}

std::string Mlecz::Nazwa() const {
    return "MLECZ";
}
