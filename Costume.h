#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include "ITheatricalThings.h"
using namespace std;

class Costume : public ITheatricalThings
{
public:
    string color;
    int size;
    int price;

    Costume(string newColor, int newSize, int newPrice) {
        color = newColor;
        size = newSize;
        price = newPrice;

    }

    void printCostume() {
        cout << "Цвет: " << color << endl;
        cout << "Размер: " << size << endl;
        cout << "Цена: " << price << endl;
    }

    int getPrice() {
        return price;
    }

};

