#include <stdio.h>
#include <iostream>
#include "Zgloszenie.h"
#include "Zgloszenie.h"
#include "Sesja.h"
#include <list>
#include <fstream>
#include <math.h>
using namespace std;

int main() {

	ofstream stanKolejki;
	ofstream stanKanalow;
	ofstream czasPrzybycia;
	ofstream czasObslugi;
	ofstream czasZakonczeniaObslugi;
	ofstream odrzucone;
	stanKolejki.open("stanKolejki.dat");
	stanKanalow.open("stanKanalow.dat");
	czasPrzybycia.open("czasPrzybycia.dat");
	czasObslugi.open("czasObslugi.dat");
	czasZakonczeniaObslugi.open("czasZakonczeniaObslugi.dat");
	odrzucone.open("odrzucone.dat");
	Sesja sesja;
	list<Zgloszenie*> kolejka;
	list<Zgloszenie*> obsluga;
	list<Zgloszenie*> wynik;

	int raz = 0;
	bool dostep = false;
	int odrzucona=0;
	double jednostkaCzasu = 1.00000;

	double timer = 0.000000;
	double czasOczekiwania = 0.0000;
	int liczbaZajetychStanowisk = 0;
	int iloscZajetychKanalow = 0;
	int nr = 0;
	bool wSystemie = false;
	Zgloszenie *z = new Zgloszenie(sesja.getLambda(), sesja.getMi());
	
	z->updateCzasObslugi(sesja.getLambda());
	obsluga.push_back(z);
	stanKanalow << sesja.getLambda() << " " << iloscZajetychKanalow << endl;
	iloscZajetychKanalow++;
	stanKanalow << sesja.getLambda() << " " << iloscZajetychKanalow << endl;
	stanKolejki << sesja.getLambda() << " " << 1  <<endl;
	stanKolejki << sesja.getLambda() << " " << 0  <<endl;
	timer = sesja.getLambda();
	while (1) {

		if (iloscZajetychKanalow > 0) {
			if (obsluga.front()->getCzasObslugi() <= timer) {
				wynik.push_back(obsluga.front());
				obsluga.pop_front();
				stanKanalow << timer << " " << iloscZajetychKanalow << endl;
				iloscZajetychKanalow--;
				stanKanalow << timer << " " << iloscZajetychKanalow << endl;
			}
		}
		
		if (czasOczekiwania >= sesja.getLambda()) {
			czasOczekiwania = 0;
			if(timer < sesja.getT()){
				if (liczbaZajetychStanowisk < sesja.getL()) {
					z = new Zgloszenie(timer, sesja.getMi());
					kolejka.push_back(z);
					stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
					liczbaZajetychStanowisk++;
					stanKolejki << timer << " " << liczbaZajetychStanowisk << endl;
				}
				else {
					odrzucona++;
					dostep = true;
					raz++;
				}
			}
		}
		

		
		if (jednostkaCzasu < timer) {
			
				
				if (raz == 1) {
					
					odrzucone << jednostkaCzasu << " " << 0 << endl;
				}
				jednostkaCzasu = floor(timer);
				odrzucone << jednostkaCzasu-1 << " " << odrzucona << endl;
				odrzucone << jednostkaCzasu  << " " << odrzucona << endl;
				jednostkaCzasu += 1.00000;
				odrzucona = 0;
			

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
				stanKanalow << timer << " " << iloscZajetychKanalow << endl;
				iloscZajetychKanalow++;
				stanKanalow << timer << " " << iloscZajetychKanalow << endl;
			}
		}
		
		
		

		czasOczekiwania += 0.0001000;
		timer += 0.0001000;

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