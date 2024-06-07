//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_ZOLW_H
#define PROJEKTC_ZOLW_H
#include "Zwierze.h"

class Zolw :public Zwierze{
public:
    explicit Zolw(Wektor2d pozycja, Swiat* swiat);
    void akcja() override;
    void rysowanie() override;
    bool OdbicieAtaku(const Organizm *org) const override;
    std::string Nazwa() const override;
    bool czymawech() override;
    Zolw* Dziecko() const override;
};


#endif //PROJEKTC_ZOLW_H
