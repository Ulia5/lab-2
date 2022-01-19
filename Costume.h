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
        cout << "����: " << color << endl;
        cout << "������: " << size << endl;
        cout << "����: " << price << endl;
    }

    int getPrice() {
        return price;
    }

};

