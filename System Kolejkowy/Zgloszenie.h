#pragma once
static int index = 0;
class Zgloszenie {

public:

	float czasObslugi;
	float czasPrzybycia;
	bool obslugiwany;
	Zgloszenie() {
		index = 0;
		czasObslugi = 0;
		czasPrzybycia = 0;
		obslugiwany = false;
	}
	Zgloszenie(float lambda, float mi) {
		index += 1;
		czasObslugi = mi;
		czasPrzybycia = lambda;
		obslugiwany = false;
	}
	void updateCzasObslugi(float czas) {
		czasObslugi += czas;
	}
	void updateCzasPrzybycia(float czas) {
		czasPrzybycia += czas;
	}
	float getCzasObslugi() {
		return czasObslugi;
	}
	bool getobslugiwany() {
		return obslugiwany;
	}
	void setObslugiwany() {
		obslugiwany = true;
	}
};