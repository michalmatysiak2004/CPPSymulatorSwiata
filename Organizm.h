//
// Created by polsk on 13.04.2024.
//

#ifndef PROJEKTC_ORGANIZM_H
#define PROJEKTC_ORGANIZM_H
#include "Swiat.h"
#include "Wektor2d.h"
#include <string>
class Swiat;
class Organizm {
protected:
    int sila;
    int inicjatywa;
    int wiek = 0;
    bool zywy = true;
    char symbol = '0';
    Swiat* swiat;
    Wektor2d pozycja;
    friend bool operator<(const Organizm& o1, const Organizm& o2);
    friend bool operator>(const Organizm& o1, const Organizm& o2);
    friend bool operator==(const Organizm& o1, const Organizm& o2);
public:

    // funckje do zachowan organizmu

    Organizm(Wektor2d pozycja, int sila, int inicjatywa, Swiat* swiat, char symbol);
    virtual void akcja()=0;
    virtual void kolizja()=0;
    virtual void rysowanie()=0;
    virtual void zwiekszWiek();
    virtual void nowaTura()=0;
    virtual bool SzanseNaUcieczke() const;
    bool uczieczka();
    void zabij();
    virtual bool OdbicieAtaku(const Organizm *org) const;
    virtual Organizm* Dziecko() const = 0;
    virtual std:: string Nazwa() const= 0;
    virtual void dodajModyfikator(Organizm* organizm) const;
    virtual bool Niesmiertelny();
    //Gettery
    char getSymbol();
    int getSila() const;
    int getInicjatywa();
    int getX();
    int getY();
    int getWiek();
    Swiat *getSwiat();
    Wektor2d getPozycja();
    bool zyje ();

    //Settery
    void setX(int x);
    void setY(int y);
    void setSila(int sila);
    void setInicjatywa(int inicjatywa);
    void setWiek(int wiek);
    void setSwiat(Swiat *swiat);
    void setPozycja(Wektor2d wektor);

    //Destruktor
    virtual ~Organizm() = default;


};


#endif //PROJEKTC_ORGANIZM_H
