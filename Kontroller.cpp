//
// Created by polsk on 22.04.2024.
//

#include "Kontroller.h"
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Pliki.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
using namespace std;
void Kontroller::Komenterz() {
    system("cls");


    swiat->getKomentator().wypisz();
    std::cout << "dowolny przycisk by kontynuować..." << std::endl;
    getch();
    czyNastepnaTura=false;

}
void Kontroller::menu(){
    char wybor;
    bool wyswietlmenu = true;

    while(wyswietlmenu){
        system("cls");
        cout<<"1. Nowa gra"<<endl;
        cout<<"2. Wczytaj gre"<<endl;
        cout<<"3. Opcje"<<endl;
        cout<<"4. Wyjscie"<<endl;
        cout<<"Wybierz opcje: ";

        cin>>wybor;
        switch(wybor){
            case '1':
                wyswietlmenu = false;
                NowySwiat();
                break;
            case '2':
                wczytajGre();
                czyNastepnaTura = true;
                wyswietlmenu = false;
                break;
            case '3':
                graj=false;
                wyswietlmenu = false;
                break;
            default:
                cout<<"Nie ma takiej opcji"<<endl;
                break;
        }
        start();
    }
}
void Kontroller::start(){
    while(graj){
        if(czyNastepnaTura){
            swiat->wykonajTure();

        }
        rysujInterfejs();
        opcjeGracza();
    }
}
void Kontroller::opcjeGracza() {


    czyNastepnaTura = true;

    switch(getch()){

        case 'q':
            graj=false;
            break;

        case 'w':
            swiat->setRuch(Swiat::Ruch::GORA);
            break;

        case 's':
            swiat->setRuch(Swiat::Ruch::DOL);
            break;

        case 'a':
            swiat->setRuch(Swiat::Ruch::LEWO);
            break;

        case 'd':
            swiat->setRuch(Swiat::Ruch::PRAWO);
            break;

        case 'm':
            swiat->setRuch(Swiat::Ruch::SPECJALNY);

            break;

        case 'x':
            zapiszGre();

            break;

        case 'k':
            Komenterz();
            break;

    }

}


void Kontroller::rysujInterfejs() {
    system("cls");

    cout << "Michał Matysiak 198395" << endl;

    swiat->rysujSwiat();

    cout << "ENTER - Nastepna tura" << endl;
    cout << "WASD - Poruszanie" << endl;
    cout << "M - Umiejetnosc specjalna" << endl;
    cout << "X - Zapisz gre" << endl;
    cout << "Tura: " << swiat->getnrTury() << endl;


}
void Kontroller::zapiszGre() {
    cout << "Podaj nazwe pliku: ";
    std::string nazwa;
    cin>>nazwa;
    plik.zapisz(swiat,nazwa);
}
void Kontroller::wczytajGre() {
    cout << "Podaj nazwe pliku: ";
    std::string nazwa;
    cin>>nazwa;
    if(plik.wczytaj(swiat,nazwa)){
        getch();
        graj=false;
    }
    czyNastepnaTura=false;
}

void Kontroller::opcjePoruszanie() {

}
void Kontroller::NowySwiat() {
    int x, y;
    cout << "Podaj wysokosc swiata: ";
    cin >> y;
    cout << "Podaj szerokosc swiata: ";
    cin >> x;

    swiat = new Swiat(x, y,{//new Wilk({0,0},swiat),
                            //new Owca({1, 1},swiat),
                            new Czlowiek({0,1},swiat),
                            new Antylopa({0,2},swiat),
                            new Wilk({2,4},swiat),
                            new Wilk({1,5},swiat),
                            new Zolw({4,8},swiat),
                            new Lis({3,3},swiat),
                            new Trawa({9,9},swiat),
                            new Guarana({1,1},swiat),
                            //new BarszczSosnowskiego({5,5},swiat),
                            new Mlecz({7,7},swiat),
    });


}

