//
// Created by polsk on 28.03.2024.
//

#include "Swiat.h"
#include "Komentator.h"
#include <iostream>
using namespace std;
Swiat::Swiat(int wysokosc, int szerokosc) {
    this->wysokosc=wysokosc;
    this->szerokosc=szerokosc;
}
void Swiat::wykonajTure() {
    system("cls");
    rysujSwiat();
    nrTury++;
    ruchOrganizmow();
    usunzabitych();
}

void Swiat::setRuch(Swiat::Ruch ruch) {

    this->ruch = ruch;

}
Swiat::Ruch Swiat::getRuch() {
    return ruch;
}
Swiat::Ruch Swiat::popRuch() {
    auto obecny = ruch;
    ruch = Swiat::Ruch::STOJ;

    return obecny;
}


void Swiat::rysujSwiat() {



        for(int y = 0; y < wysokosc; y++){


            for(int x = 0; x < szerokosc; x++){

                auto* lokator = wezOrganizmztegopola({(int) y,(int) x});

                if(lokator == nullptr || !lokator->zyje()){

                    std::cout << "-";

                } else {

                    std::cout << lokator->getSymbol();

                }

            }



            std::cout << std::endl;

        }



}




void Swiat::ruchOrganizmow() {

    std::sort(organizmy.begin(),organizmy.end(),[](Organizm* org1, Organizm* org2){

        if(org1->getInicjatywa() == org2->getInicjatywa()){

            return org1->getWiek() > org2->getWiek();

        }

        return org1->getInicjatywa() > org2->getInicjatywa();

    });

    int ix = 0;
    for(int i = 0; i < organizmy.size(); i++){

        auto* organizm = organizmy[i];

        if(organizm->zyje() && organizm->getWiek() != 0){

            organizm->akcja();
            organizm->kolizja();

        }

        organizm->zwiekszWiek();
        ix++;
    }



}
Wektor2d Swiat::WolnePole(Wektor2d wektor){
    for(int dy = -1; dy <= 1; dy++){

        for(int dx = -1; dx <= 1; dx++){

            Wektor2d nowapozycja = {wektor.y + dy, wektor.x + dx};

            if(!(nowapozycja == wektor) && wezOrganizmztegopola(nowapozycja) == nullptr&& !nowapozycja.czyniewyszedlzamape(wysokosc,szerokosc)){

                return nowapozycja;

            }

        }

    }

    return wektor;
}
Organizm *Swiat::wezOrganizmotejsamejpozycji(Organizm* org) {

    for(auto* organizm : organizmy){

        if(org->getPozycja() == organizm->getPozycja()
           && org != organizm
           && org->zyje()){

            return organizm;

        }

    }

    return nullptr;
}
void Swiat::wypiszOrganizmy(std::vector<Organizm *> organizmy) {
    std::cout << "[";
    for (size_t i = 0; i < organizmy.size(); ++i) {
        std::cout << organizmy[i]->Nazwa() << organizmy[i]->getX() <<organizmy[i]->getY() ;
        if (i != organizmy.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
Organizm *Swiat::wezOrganizmztegopola(Wektor2d p) {

    Organizm* szukany = nullptr;


    for(auto* organizm : organizmy){
        //cout <<organizm->getPozycja();
        if(p == organizm->getPozycja() && organizm->zyje()){

            if(szukany == nullptr || szukany->getSila() < organizm->getSila()){

                szukany = organizm;

            }

        }

    }

    return szukany;

}
void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
    organizm->setSwiat(this);
}
int Swiat::getWysokosc() {
    return wysokosc;
}
int Swiat::getSzerokosc() {
    return szerokosc;
}
// funckje swiata dla komentatora
void Swiat::Resetujture(){
    komentator.czysc();
    for(auto* organizm : organizmy){
        organizm->nowaTura();
    }
}
Komentator& Swiat::getKomentator() {
    return komentator;
}

Swiat::~Swiat() {

    for(auto* org : organizmy){

        delete org;

    }

}

Swiat::Swiat(int wysokosc, int szerokosc, std::vector<Organizm*>&& organizmy):
        szerokosc(szerokosc),
        wysokosc(wysokosc),
        organizmy(std::move(organizmy)){

    for(auto* org : this->organizmy){

        org->setSwiat(this);

    }

    srand(time(nullptr));

}

void Swiat::setnrTury(int nrTury) {
    this->nrTury=nrTury;
}

const std::vector<Organizm *> &Swiat::getOrganizmy() {
    return organizmy;
}

int Swiat::getnrTury() {
    return nrTury;
}
void Swiat::usunzabitych() {

    int ix = 0;

    for(auto* organizm: organizmy){

        if(!organizm->zyje()){

            organizmy.erase(organizmy.begin()+ix);
            usunzabitych();
            break;

        }
        ix++;

    }

}
