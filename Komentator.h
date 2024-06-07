//
// Created by polsk on 22.04.2024.
//

#ifndef PROJEKTC_KOMENTATOR_H
#define PROJEKTC_KOMENTATOR_H




#include <vector>
#include <string>
#include <iostream>

class Komentator {
public:

    void operator<<(std::string komunikat);
    void wypisz();


    void czysc();

private:

    std::vector<std::string> komunikaty;


};


#endif //PROJEKTC_KOMENTATOR_H
