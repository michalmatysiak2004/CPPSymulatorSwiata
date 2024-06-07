//
// Created by polsk on 13.04.2024.
//

#ifndef PROJEKTC_ZWIERZE_H
#define PROJEKTC_ZWIERZE_H
#include "Organizm.h"
#include "Wektor2d.h"
#include <random>
#include <string>
class Wektor2d;
class Zwierze : public Organizm {
public:
    Zwierze(Wektor2d polozenie, int sila, int inicjatywa, Swiat* swiat,  char symbol);
    void akcja() override;
    void kolizja() override;
    void nowaTura() override;

    ~Zwierze() override;
    virtual std::string Nazwa() const =0;



protected:
    void losowyRuch(int dystans = 1);
    void Ruch(Wektor2d wektor);

    Wektor2d pozycjaprzedruchem;
    void atakuj(Organizm* atakowany);
    void powrotdopozycji();
    void rozmnazaj(Zwierze* partner);
    bool czysierozmozylo = false;
    virtual bool czymawech()=0;

    __attribute__((unused)) bool czyktosnaszabije();
};

#endif //PROJEKTC_ZWIERZE_H
