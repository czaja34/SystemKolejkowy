#pragma once
static int index = 0;
class Zgloszenie {

public:

	double czasObslugi;
	double czasPrzybycia;
	bool obslugiwany;
	Zgloszenie() {
		index = 0;
		czasObslugi = 0.000000;
		czasPrzybycia = 0.000000;
		obslugiwany = false;
	}
	Zgloszenie(double lambda, double mi) {
		index += 1;
		czasObslugi = mi;
		czasPrzybycia = lambda;
		obslugiwany = false;
	}
	void updateCzasObslugi(double czas) {
		czasObslugi += czas;
	}
	void updateCzasPrzybycia(double czas) {
		czasPrzybycia += czas;
	}
	double getCzasObslugi() {
		return czasObslugi;
	}
	bool getobslugiwany() {
		return obslugiwany;
	}
	void setObslugiwany() {
		obslugiwany = true;
	}
};