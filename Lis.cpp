//
// Created by polsk on 23.04.2024.
//

#include "Lis.h"

Lis::Lis(Wektor2d pozycja, Swiat *swiat):Zwierze(pozycja,3,7,swiat,'L') {

}

std::string Lis::Nazwa() const {
    return "LIS";
}
Lis *Lis::Dziecko() const {
    return new Lis{pozycja,swiat};
}
bool Lis::czymawech() {
    return true;
}
void Lis::rysowanie() {
    std::cout << "L";
}



