//
// Created by polsk on 13.04.2024.
//

#include "Zwierze.h"
#include <iostream>

using namespace std;

void Zwierze::akcja() {
    losowyRuch(1);
}
void Zwierze::kolizja() {
    Organizm* org2 = swiat->wezOrganizmotejsamejpozycji(this);
    if(org2 == nullptr){
        return;
    }
    if(this->getSymbol() == org2->getSymbol()){
        rozmnazaj((Zwierze*)org2);
    } else {
        atakuj(org2);
    }
}
Zwierze::Zwierze(Wektor2d polozenie, int sila, int inicjatywa, Swiat* swiat,  char symbol) : Organizm(polozenie, sila, inicjatywa, swiat, symbol), pozycjaprzedruchem(polozenie) {

}



void Zwierze::losowyRuch(int zasieg) {
    int koordynaty[] = {-1 * (int)zasieg,0,zasieg};

    Wektor2d przemieszczenie{0,0};
    Wektor2d wczesniejsze = pozycja;

    do {
        pozycja = wczesniejsze;

        int randX = koordynaty[rand() % 3];
        int randY = koordynaty[rand() % 3];

        przemieszczenie = {randY, randX};

        Ruch(przemieszczenie);

    } while(wczesniejsze == pozycja ||(czymawech() && swiat->wezOrganizmotejsamejpozycji(this) != nullptr && swiat->wezOrganizmotejsamejpozycji(this)->getSila() > getSila()));


}
void Zwierze::Ruch(Wektor2d przemieszczenie) {



    if(!(pozycja + przemieszczenie).czyniewyszedlzamape(swiat->getWysokosc(),swiat->getSzerokosc())){

        pozycjaprzedruchem = pozycja;
        pozycja += przemieszczenie;

    }


}
void Zwierze::powrotdopozycji() {
    pozycja = pozycjaprzedruchem;
}


void Zwierze::atakuj(Organizm *atakowany) {
    if(Niesmiertelny()==true){
        std::string komunikat = "Czlowiek jest niesmiertelny";
        pozycja = swiat->WolnePole(this->getPozycja());
        return;
    }
    if(atakowany->Niesmiertelny()==true){
        std::string komunikat = atakowany->Nazwa() + "jest niesmiertelny";
        atakowany->setPozycja(swiat->WolnePole(this->getPozycja()));
        return;
    }
    if(uczieczka() || atakowany->uczieczka()) {
        std::string komunikat = "uczieczka";
        swiat->getKomentator() << komunikat;
        return;
    }
    if(this->getSila() < atakowany->getSila()){
        if(this->OdbicieAtaku(atakowany)){
            std::string komunikat = this->Nazwa() + "blokuje" + atakowany->Nazwa();
            swiat->getKomentator() << komunikat;
            powrotdopozycji();
            return;
        }
        std::string komunikat = atakowany->Nazwa() + "zabija" + this->Nazwa();

        this->zabij();
        dodajModyfikator(atakowany);
        swiat->getKomentator() << komunikat;

    }
    else{
        if(atakowany->OdbicieAtaku(this)){
            powrotdopozycji();
            return;

        }

        std::string komunikat = this->Nazwa() + "zabija" + atakowany->Nazwa();
        cout << komunikat;
        swiat->getKomentator() << komunikat;
        atakowany->zabij();
        atakowany->dodajModyfikator(this);

    }






}
Zwierze::~Zwierze() {

}
void Zwierze::rozmnazaj(Zwierze *partner) {

    if(partner->getWiek() == 0 ){

        return;

    }

    auto* org = this->Dziecko();

    this->powrotdopozycji();
    Wektor2d miejsceNarodzin = swiat->WolnePole(partner->getPozycja());

    if(miejsceNarodzin == partner->getPozycja() || czysierozmozylo || partner->czysierozmozylo){

        delete org;
        return;

    }
    org->setPozycja(miejsceNarodzin);
    org->setWiek(0);

    swiat->dodajOrganizm(org);
    czysierozmozylo = true;
    partner->czysierozmozylo = true;

    std::string komunikat = this->Nazwa() + " rozmnaza sie z " + partner->Nazwa();
    cout << komunikat;
    swiat->getKomentator() << komunikat;


}

bool Zwierze::czyktosnaszabije() {

    for(int y = -1; y <= 1; y++){

        for(int x = -1; x <= 1; x++){

            Wektor2d pol = {y,x};

            Organizm* org = swiat->wezOrganizmztegopola(this->pozycja + pol);



            if(org != this && (org == nullptr || org->getSila() <= sila)){

                return false;

            }

        }

    }

    return true;

}

void Zwierze::nowaTura() {
    czysierozmozylo=false;
}


