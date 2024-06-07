//
// Created by polsk on 22.04.2024.
//

#ifndef PROJEKTC_WEKTOR2D_H
#define PROJEKTC_WEKTOR2D_H

#include <iostream>


struct Wektor2d {

    int y, x;
    Wektor2d(){};
    Wektor2d(int y, int x): y(y), x(x) {};

    bool operator==(Wektor2d o) const {

        return x == o.x && y == o.y;

    }

    Wektor2d operator+(Wektor2d o) const {

        return {y + o.y, x + o.x};

    }
    friend std::ostream& operator<<(std::ostream& os, const Wektor2d& w) {
        os << "(" << w.y << ", " << w.x << ")";
        return os;
    }
    void operator+=(Wektor2d o)  {

        y += o.y;
        x += o.x;

    }
    void operator=(Wektor2d a){
        y=a.y;
        x=a.x;
    }
     bool czyniewyszedlzamape(int wysokosc, int szerokosc) const {

        return y < 0 || x < 0 || y >= wysokosc || x >= szerokosc;

    }

};
#endif //PROJEKTC_WEKTOR2D_H
