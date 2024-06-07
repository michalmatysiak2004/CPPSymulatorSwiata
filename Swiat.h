//
// Created by polsk on 28.03.2024.
//

#ifndef PROJEKTC_SWIAT_H
#define PROJEKTC_SWIAT_H
#include "Organizm.h"
#include "Komentator.h"
#include "Wektor2d.h"
#include <vector>
#include <algorithm>

class Organizm;

class Swiat {
private:
    int wysokosc,szerokosc;
    int nrTury=0;



public:
    std::vector <Organizm*> organizmy;
    Komentator komentator;
    Swiat(int wysokosc, int szerokosc);
    Swiat(int wysokosc, int szerokosc, std::vector<Organizm*>&& organizmy);
    ~Swiat();
    // ruchyczlowieka
    enum Ruch {
        GORA,
        DOL,
        LEWO,
        PRAWO,
        SPECJALNY,
        STOJ
    };
    void setRuch(Ruch ruch);
    Ruch getRuch();
    Ruch popRuch();
    Ruch ruch = Ruch::STOJ;
    //Gettery
void wykonajTure();
void rysujSwiat();
int getWysokosc();
int getSzerokosc();
int  getnrTury();
const std::vector<Organizm*>& getOrganizmy();




Komentator& getKomentator();



// Funckje do organizmów
void dodajOrganizm(Organizm *organizm);
void zabijOrganizm(Organizm *organizm);
Organizm* wezOrganizmztegopola(Wektor2d p);
void ruchOrganizmow();
Organizm* wezOrganizmotejsamejpozycji(Organizm* organizm);
Wektor2d WolnePole(Wektor2d wektor);
void wypiszOrganizmy(std::vector<Organizm*> organizmy);
void Resetujture();
void usunzabitych();
//Settery
void setnrTury(int nrTury);


};


#endif //PROJEKTC_SWIAT_H
