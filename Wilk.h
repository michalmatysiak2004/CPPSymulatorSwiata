//
// Created by polsk on 15.04.2024.
//

#ifndef PROJEKTC_WILK_H
#define PROJEKTC_WILK_H
#include "Zwierze.h"
#include <iostream>



class Wilk : public Zwierze {

public:

     Wilk(Wektor2d pozycja, Swiat* swiat);

    std::string Nazwa() const override;
    bool czymawech() override;
    Wilk* Dziecko() const override;
    void rysowanie() override;



};


#endif //PROJEKTC_WILK_H
