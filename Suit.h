#pragma once
#include "Costume.h"
class Suit :
    public Costume
{
public:
    string type;

    Suit(string newColor, int newSize, int newPrice, string newType) : Costume(newColor, newSize, newPrice) {
        type = newType;
    }


    void printCostume()
    {
        Costume::printCostume();
        cout << "Òèï: " << type << endl;
    }

};

