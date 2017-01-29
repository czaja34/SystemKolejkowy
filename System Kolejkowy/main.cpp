#include <stdio.h>
#include <iostream>
#include "Zgloszenie.h"
#include "Zgloszenie.h"
#include "Sesja.h"
#include <list>
#include <fstream>
using namespace std;

int main() {

	ofstream stanKolejki;
	ofstream czasPrzybycia;
	ofstream czasObslugi;
	ofstream czasZakonczeniaObslugi;
	stanKolejki.open("stanKolejki.dat");
	czasPrzybycia.open("czasPrzybycia.dat");
	czasObslugi.open("czasObslugi.dat");
	czasZakonczeniaObslugi.open("czasZakonczeniaObslugi.dat");
	Sesja sesja;
	list<Zgloszenie*> kolejka;
	list<Zgloszenie*> obsluga;
	list<Zgloszenie*> wynik;
	float timer = 0.0;
	float czasOczekiwania = 0.0;
	int liczbaZajetychStanowisk = 0;
	int iloscZajetychKanalow = 0;
	int nr = 0;
	bool wSystemie = false;
	Zgloszenie *z = new Zgloszenie(sesja.getLambda(), sesja.getMi());
	
	z->updateCzasObslugi(sesja.getLambda());
	obsluga.push_back(z);
	iloscZajetychKanalow++;
	stanKolejki << sesja.getLambda() << " " << 1  <<endl;
	stanKolejki << sesja.getLambda() << " " << 0  <<endl;
	timer = sesja.getLambda();
	while (1) {
		
		if (czasOczekiwania >= sesja.getLambda() && timer < sesja.getT()) {
			if (liczbaZajetychStanowisk < sesja.getL()) {
				z = new Zgloszenie(timer, sesja.getMi());
				kolejka.push_back(z);
				stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
				liczbaZajetychStanowisk++;
				stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
				czasOczekiwania = 0;
			}
		}
		if (liczbaZajetychStanowisk > 0) {
			if (iloscZajetychKanalow < sesja.getiloscKanalow()) {
				z = kolejka.front();
				z->updateCzasObslugi(timer);
				obsluga.push_back(z);
				kolejka.pop_front();
				stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
				liczbaZajetychStanowisk--;
				stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
				iloscZajetychKanalow++;
			}
		}
		
		if (iloscZajetychKanalow > 0) {
			if (obsluga.front()->getCzasObslugi() <= timer) {
				wynik.push_back(obsluga.front());
				obsluga.pop_front();
				iloscZajetychKanalow--;
			}
		}
		

		czasOczekiwania += 0.01;
		timer += 0.01;

		if (timer >sesja.getT() && liczbaZajetychStanowisk==0 && iloscZajetychKanalow==0)
		{

			cout << "KONIEC" << endl << endl;
			for (list<Zgloszenie*>::iterator it = wynik.begin(); it != wynik.end(); it++) {

				cout << " czasPrzybycia: " << (*it)->czasPrzybycia << endl;
				czasPrzybycia  << (*it)->czasPrzybycia << " " << 0 << endl;
				cout << " czasObslugi: " << (*it)->czasObslugi << endl;
				czasZakonczeniaObslugi << (*it)->czasObslugi << " " << 0.5 << endl;
				czasObslugi<<(*it)->czasObslugi - sesja.getMi()<< " " << 0  << endl;

				cout << endl;
			}
			cout << "Koniec programu" << endl;
			stanKolejki.close();
			czasObslugi.close();
			czasPrzybycia.close();
			return  0;
		}
	}

	}