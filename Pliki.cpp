//
// Created by polsk on 23.04.2024.
//

#include "Pliki.h"
#include "Czlowiek.h"


void Pliki::zapisz(Swiat *swiat, std::string plik) {

    auto organizmy = swiat->getOrganizmy();

    std::ofstream out(plik);

    out << swiat->getnrTury() << " " << swiat->getWysokosc() << " " << swiat->getSzerokosc() << std::endl;


    for(auto* organizm : organizmy){

        out <<  organizm->Nazwa() << " " <<
            organizm->getWiek() << " " <<
            organizm->getPozycja().y << " " <<
            organizm->getPozycja().x;

        if(dynamic_cast<Czlowiek*>(organizm) != nullptr){

            out << " "<<((Czlowiek*)organizm)->getTurySpecjalne();

        }

        out << std::endl;

    }

    out.close();

}

int Pliki::wczytaj(Swiat*& swiat, std::string plik) {

    try {

        std::ifstream in(plik);
        if(in.fail()){

            in.close();
            throw std::runtime_error("plik nie istnieje lub wystąpił błąd z jego otwarciem");

        }

        int tura,wys,szer;

        in >> tura >> wys >> szer;

        std::vector<Organizm*> orgs;

        int licznik = 0;

        while(!in.eof()){

            wczytajOrganizm(in,orgs);
            licznik++;

            if(licznik >= 100000){

                throw std::runtime_error("błąd składniowy lub plik za długi");

            }

        }

        swiat = new Swiat(wys,szer,std::move(orgs));
        for (Organizm* org : orgs) {
            org->setSwiat(swiat);
        }
        swiat->setnrTury(tura);

        in.close();

        return 0;

    } catch (std::exception & ex){

        std::cout << ex.what() << std::endl;

        return 1;
    }


}

void Pliki::wczytajOrganizm(std::ifstream &in, std::vector<Organizm *>& orgs) {

    std::string nazwa;
    int y,x;
    int wiek;

    in >> nazwa >> wiek >> y >> x;

    Organizm* nowy = alokujPoNazwie(nazwa, in);

    if(nowy != nullptr){

        nowy->setPozycja({y,x});
        nowy->setWiek(wiek);

        orgs.push_back(nowy);

    }


}

Organizm *Pliki::alokujPoNazwie(std::string nazwa, std::ifstream& in) {

    Wektor2d p0 = {0,0};

    std::vector<Organizm*> wszystkie = {
            new Czlowiek(p0,nullptr),
            new Wilk(p0,nullptr),
            new Owca(p0,nullptr),
            new Lis(p0,nullptr),
            new Zolw(p0,nullptr),
            new Antylopa(p0,nullptr),
            new Trawa(p0,nullptr),
            new Mlecz(p0,nullptr),
            new Guarana(p0,nullptr),
            new WilczeJagody(p0,nullptr),
            new BarszczSosnowskiego(p0,nullptr)



    };

    Organizm* wybrany = nullptr;


    for(auto* org : wszystkie){

        if(org->Nazwa() == nazwa){

            wybrany = org->Dziecko();

            auto* czl = dynamic_cast<Czlowiek*>(wybrany);

            if(czl != nullptr){

                int tury;
                in >> tury;

                czl->setTurySpecjalne(tury);

            }

        }

    }

    for(auto* org : wszystkie){

        delete org;

    }

    if(wybrany != nullptr){

        return wybrany;

    }
    return nullptr;

}