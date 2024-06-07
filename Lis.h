//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_LIS_H
#define PROJEKTC_LIS_H
#include "Zwierze.h"

class Lis : public Zwierze{

public:
    Lis(Wektor2d pozycja, Swiat* swiat);

    std::string Nazwa() const override;
    bool czymawech() override;
    Lis* Dziecko() const override;
    void rysowanie() override;

};


#endif //PROJEKTC_LIS_H
