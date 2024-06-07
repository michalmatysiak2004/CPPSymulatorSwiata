//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_GUARANA_H
#define PROJEKTC_GUARANA_H
#include "Roslina.h"

class Guarana:public Roslina {


    public:

        explicit Guarana(Wektor2d polozenie, Swiat* swiat);
        void rysowanie() override;

        std::string Nazwa() const override;
    void dodajModyfikator(Organizm* organizm) const override;
    private:

        Guarana* Dziecko() const override;

};


#endif //PROJEKTC_GUARANA_H
