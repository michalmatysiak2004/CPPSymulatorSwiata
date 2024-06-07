//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_ROSLINA_H
#define PROJEKTC_ROSLINA_H


#pragma once

#include "Organizm.h"
#include "Swiat.h"
#include <iostream>




class Roslina : public Organizm {


public:





    Roslina(Wektor2d polozenie, int sila, Swiat *swiat, char symbol);

    void akcja() override;

    void kolizja() override;
    virtual std::string Nazwa() const =0;
    void nowaTura() override {};



protected:
    void rozprzestrzen();

};

#endif //PROJEKTC_ROSLINA_H
