//
// Created by polsk on 23.04.2024.
//

#ifndef PROJEKTC_PLIKI_H
#define PROJEKTC_PLIKI_H
#include "Swiat.h"
#include <fstream>
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include <vector>
class Pliki {
public:

    void zapisz(Swiat* swiat, std::string plik);
    int wczytaj(Swiat*& swiat, std::string plik);

private:

    void wczytajOrganizm(std::ifstream& in, std::vector<Organizm*>& orgs);

    Organizm *alokujPoNazwie(std::string nazwa, std::ifstream& in);
};


#endif //PROJEKTC_PLIKI_H
