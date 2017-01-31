#pragma once
#include <stdio.h>
#include <iostream>
#include <random>     
#include <ctime>
using namespace std;

class Sesja {
private:
	double lambda;
	double mi;
	double T;
	int L;
	int iloscKanalow;


public:
	double getiloscKanalow() { return iloscKanalow; }
	double getLambda() { return lambda; }
	double getMi() { return mi; }
	double getT() { return T; }
	int getL() { return L; }

	void setT(double time) { T -= time; }
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