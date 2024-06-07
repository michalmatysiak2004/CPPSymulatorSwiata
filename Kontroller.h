//
// Created by polsk on 22.04.2024.
//

#ifndef PROJEKTC_KONTROLLER_H
#define PROJEKTC_KONTROLLER_H
#include "Swiat.h"
#include "Pliki.h"
#include <iostream>
#include <conio.h>
class Kontroller {
public:
    Pliki plik;
    void menu();
    bool czyNastepnaTura = true;

    bool graj=true;

    Swiat* swiat = nullptr;
    //MenedzerPlikow menedzerPlikow;

    void start();

    void zapiszGre();

    void wczytajGre();

    void Komenterz();

    void opcjeGracza();

    void opcjePoruszanie();

    void rysujInterfejs();

    void NowySwiat();


};


#endif //PROJEKTC_KONTROLLER_H
