//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_OWCA_H
#define PROJEKTC_OWCA_H
#include "Zwierze.h"

class Owca : public Zwierze {

public:

    Owca(Wektor2d pozycja, Swiat* swiat);

    std::string Nazwa() const override;
    bool czymawech() override;
    Owca* Dziecko() const override;
    void rysowanie() override;



};


#endif //PROJEKTC_OWCA_H
