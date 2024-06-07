//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_BARSZCZSOSNOWSKIEGO_H
#define PROJEKTC_BARSZCZSOSNOWSKIEGO_H
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina {
public:
    explicit BarszczSosnowskiego(Wektor2d polozenie, Swiat* swiat);
    void rysowanie()  override;
    void akcja() override;
    std::string Nazwa() const override;

private:

    BarszczSosnowskiego* Dziecko() const override;
};


#endif //PROJEKTC_BARSZCZSOSNOWSKIEGO_H
