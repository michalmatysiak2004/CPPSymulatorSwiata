//
// Created by polsk on 23.04.2024.
//

#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
void BarszczSosnowskiego::akcja() {

    for(int y = -1; y <= 1; y++){

        for(int x = -1; x <= 1; x++){

            Organizm* org = swiat->wezOrganizmztegopola(pozycja + Wektor2d{y,x});

            if(dynamic_cast<Zwierze*>(org) != nullptr){
                if(!org->Niesmiertelny()) org->zabij();
            }

        }

    }

    Roslina::akcja();

}


BarszczSosnowskiego::BarszczSosnowskiego(Wektor2d polozenie, Swiat* swiat): Roslina(polozenie, 10, swiat, 'B') {

}
BarszczSosnowskiego *BarszczSosnowskiego::Dziecko() const {
    return new BarszczSosnowskiego{*this};
}

void BarszczSosnowskiego::rysowanie() {
    std:: cout<< "B";
}

std::string BarszczSosnowskiego::Nazwa() const {
    return "BARSZCZSOSNOWSKIEGO";
}
