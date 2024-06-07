//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_ANTYLOPA_H
#define PROJEKTC_ANTYLOPA_H
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:

    Antylopa(Wektor2d pozycja, Swiat* swiat);
    void akcja() override;
    std::string Nazwa() const override;
    bool czymawech() override;
    Antylopa* Dziecko() const override;
    void rysowanie() override;
    bool SzanseNaUcieczke() const override;
};


#endif //PROJEKTC_ANTYLOPA_H
