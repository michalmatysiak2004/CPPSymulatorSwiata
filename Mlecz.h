//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_MLECZ_H
#define PROJEKTC_MLECZ_H
#include "Roslina.h"

class Mlecz :public Roslina{
public:

    explicit Mlecz(Wektor2d polozenie, Swiat* swiat);
    void rysowanie()  override;
    void akcja();
    std::string Nazwa() const override;

private:

    Mlecz* Dziecko() const override;


};


#endif //PROJEKTC_MLECZ_H
