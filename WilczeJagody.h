//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_WILCZEJAGODY_H
#define PROJEKTC_WILCZEJAGODY_H
#include "Roslina.h"

class WilczeJagody : public Roslina{

public:

    explicit WilczeJagody(Wektor2d polozenie, Swiat* swiat);
    void rysowanie()  override;
    void dodajModyfikator(Organizm* organizm) const override;
    std::string Nazwa() const override;

private:

    WilczeJagody* Dziecko() const override;

};


#endif //PROJEKTC_WILCZEJAGODY_H
