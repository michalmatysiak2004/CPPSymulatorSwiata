//
// Created by polsk on 22.04.2024.
//

#include "Komentator.h"


void Komentator::operator<<(std::string komunikat) {

    komunikaty.push_back(komunikat);

}

void Komentator::wypisz() {



    for(const auto& kom : komunikaty){

        std::cout << kom << std::endl;

    }



}

void Komentator::czysc() {

    komunikaty.clear();

}