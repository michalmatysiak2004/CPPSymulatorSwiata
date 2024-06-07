//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_TRAWA_H
#define PROJEKTC_TRAWA_H

#include "Roslina.h"
#include <iostream>
class Trawa : public Roslina{

public:

    explicit Trawa(Wektor2d polozenie, Swiat* swiat);
    void rysowanie()  override;

    std::string Nazwa() const override;

private:

         Trawa* Dziecko() const override;

};



#endif //PROJEKTC_TRAWA_H
