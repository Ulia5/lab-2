#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Price
{
private:
	T value;
public:
	Price(T value) {
		this->value = value;
	}

	void printPrice() {
		cout << value<< endl;
	}

};

