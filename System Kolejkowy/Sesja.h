#pragma once
#include <stdio.h>
#include <iostream>
#include <random>     
#include <ctime>
using namespace std;

class Sesja {
private:
	float lambda;
	float mi;
	float T;
	int L;
	int iloscKanalow;


public:
	float getiloscKanalow() { return iloscKanalow; }
	float getLambda() { return lambda; }
	float getMi() { return mi; }
	float getT() { return T; }
	int getL() { return L; }

	void setT(float time) { T -= time; }
	void setL(int l) { L = l; }

public: Sesja() {
	cout << "Podaj parametr strumienia zgloszen lambda" << endl;
	cin >> lambda;
	lambda = 1.0 / lambda;
	cout << "Podaj parametr kanalu obslugi mi" << endl;
	cin >> mi;
	mi = 1.0 / mi;
	cout << "Podaj czas dzialania systemu T" << endl;
	cin >> T;
	cout << "Podaj maksymalna dlugosc kolejki" << endl;
	cin >> L;
	cout << "Podaj ilosc kanalow" << endl;
	cin >> iloscKanalow;
}
};