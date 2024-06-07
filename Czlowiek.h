//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_CZLOWIEK_H
#define PROJEKTC_CZLOWIEK_H


#include "Zwierze.h"

class Czlowiek : public Zwierze {

public:

    explicit Czlowiek(Wektor2d polozenie,Swiat* swiat);


    void akcja() override;

    std::string Nazwa() const override;

    void setTurySpecjalne(int turySpecjalne);

    int getTurySpecjalne();
    bool Niesmiertelny() override;
    void rysowanie() override;
    bool czymawech() override;

private:

    int turySpecjalne = 0;


     Czlowiek* Dziecko() const override;




};


#endif //PROJEKTC_CZLOWIEK_H
