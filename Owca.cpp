//
// Created by polsk on 23.04.2024.
//

#include "Owca.h"
#include "Zwierze.h"
Owca::Owca(Wektor2d pozycja,Swiat* swiat) : Zwierze(pozycja,4,4,swiat,'O') {

}


std::string Owca:: Nazwa() const {
    return "OWCA";
}
bool Owca::czymawech() {
    return false;
}
Owca *Owca::Dziecko() const{
    return new Owca{pozycja,swiat};
}

void Owca::rysowanie() {
    std::cout << "O";

}