#include <iostream>
#include <cstring>
#include <bitset>
#include "KlasyKol.h"

using namespace std;

#define BlokBartek

#ifdef Blok4Termin1

class Zarowka
{
protected:
	const char* m_nazwa;
	int m_moc;
	bool m_stan;

public:
	Zarowka(const char* nazwa, int moc) 
		: m_nazwa(nazwa), m_moc(moc), m_stan(false) {}

	void set_nazwa(const char* nazwa) {
		m_nazwa = nazwa;
	}

	void set_moc(int moc) {
		m_moc = moc;
	}

	virtual void wylacz() {
		m_stan = false;
	}

	virtual void wlacz() {
		m_stan = true;
	}
	
	virtual int zuzycie() {
		if (m_stan) {
			return m_moc;
		}
		else {
			return 0;
		}
	}
};

class ZarowkaSciemnialna : public Zarowka
{
private:
	int m_jasnosc;

public:
	ZarowkaSciemnialna(const char* m_nazwa, int m_moc) : Zarowka(m_nazwa, m_moc), m_jasnosc(0) {}

	void wlacz() override{
		m_stan = true;
		m_jasnosc = rand() % 100 + 1;
	}

	void wylacz() override{
		m_stan = false;
	}

	int zuzycie() override{
		if (m_stan) {
			return (m_moc * m_jasnosc) / 100;
		}
		else {
			return 0;
		}
	}
};

class Pokoj {
private:
	Zarowka** m_zarowki;
	int m_liczbaZarowek;
public:
	Pokoj(Zarowka* zarowki[], int liczbaZarowek) 
		: m_zarowki(zarowki), m_liczbaZarowek(liczbaZarowek) {}

	void wlaczWszystkie() {
		for (int i = 0; i < m_liczbaZarowek; ++i) {
			m_zarowki[i]->wlacz();
		}
	}

	void wylaczWszystkie() {
		for (int i = 0; i < m_liczbaZarowek; ++i) {
			m_zarowki[i]->wylacz();
		}
	}

	double zuzycieWszystkie() const {
		double sumaZuzycia = 0.0;
		for (int i = 0; i < m_liczbaZarowek; ++i) {
			sumaZuzycia += m_zarowki[i]->zuzycie();
		}
		return sumaZuzycia;
	}
};

int main() {
	Zarowka z1("Philips", 60);
	ZarowkaSciemnialna z2("Osram", 75);

	Zarowka* zarowkiWpokoju[] = { &z1, &z2 };
	Pokoj pokoj(zarowkiWpokoju, 2);

	pokoj.wlaczWszystkie();
	std::cout << "Zuzycie energii po wlaczeniu: " << pokoj.zuzycieWszystkie() << " W\n";

	pokoj.wylaczWszystkie();
	std::cout << "Zuzycie energii po wylaczeniu: " << pokoj.zuzycieWszystkie() << " W\n";

	return 0;
}

#endif

#ifdef Blok4Termin0

int main()
{
	Uzytkownik uzytkownik("user", true, false, true);
	Uzytkownik uzytkownik2;
	UzytkownikChroniony uzytkownikChroniony("admin", true, true, true, "haslo123");

	char operacja[10];
	cout << "Podaj operacje (zapis, odczyt, wykonanie): ";
	cin >> operacja;

	bool wynik = uzytkownik.sprawdzUprawnienia(operacja);
	if (wynik)
		cout << "Uprawnienia udzielone." << endl;
	else
		cout << "Brak uprawnien." << endl;

	wynik = uzytkownikChroniony.sprawdzUprawnienia(operacja);
	if (wynik)
		cout << "Uprawnienia udzielone." << endl;
	else
		cout << "Brak uprawnien lub niepoprawne haslo." << endl;

	return 0;
}
#endif

//#ifdef Blok44
//class Zarowka {
//protected:
//	char z_Nazwa[20];
//	int z_Moc;
//	bool z_Stan;
//	static int Licznik;
//public:
//	void setNazwa(const char* Nazwa) { strcpy_s(z_Nazwa, Nazwa); }
//	void setMoc(int Moc) { z_Moc = Moc; }
//	void setStan(bool Stan) { z_Stan = Stan; }
//	const char* getNazwa() { return z_Nazwa; }
//	int getMoc() { return z_Moc; };
//	virtual bool getStan() { return z_Stan; };
//	virtual int Zuzycie()
//	{
//		if (z_Stan == 1) {
//			return z_Moc;
//		}
//		else {
//			return 0;
//		}
//	}
//	int getLicznik() {
//		return Licznik;
//	}
//	Zarowka(const char* Nazwa, int Moc) {
//		setNazwa(Nazwa);
//		setMoc(Moc);
//		Licznik++;
//	}
//	~Zarowka() {};
//};
//class ZarowkaSciemnialna :public Zarowka {
//private:
//	int zs_Stopien;
//public:
//	int getStopien() {
//		zs_Stopien = rand() % 100 + 1;
//		return zs_Stopien;
//	}
//	int Zuzycie() override {
//		if (z_Stan == 1) {
//			z_Moc = z_Moc * zs_Stopien;
//			return z_Moc;
//		}
//		else {
//			return 0;
//		}
//	}
//	ZarowkaSciemnialna(const char* Nazwa, int Moc) : Zarowka(z_Nazwa, z_Moc), zs_Stopien(0) {}
//};
//class Pokoj {
//private:
//	Zarowka** m_zarowki;
//	int m_liczbaZarowek;
//public:
//	Pokoj(Zarowka* zarowki[], int liczbaZarowek)
//		: m_zarowki(zarowki), m_liczbaZarowek(liczbaZarowek) {}
//
//	void wlaczWszystkie() {
//		for (int i = 0; i < m_liczbaZarowek; i++) {
//			m_zarowki[i]->setStan(true);
//		}
//	}
//
//	void wylaczWszystkie() {
//		for (int i = 0; i < m_liczbaZarowek; i++) {
//			m_zarowki[i]->setStan(false);
//		}
//	}
//
//	double zuzycieWszystkie() const {
//		double sumaZuzycia = 0.0;
//		for (int i = 0; i < m_liczbaZarowek; ++i) {
//			sumaZuzycia += m_zarowki[i]->Zuzycie();
//		}
//		return sumaZuzycia;
//	}
//
//};
//int Zarowka::Licznik = 0;
//int main() {
//	srand(time(NULL));
//	Zarowka z1("Philips", 60);
//	ZarowkaSciemnialna z2("Osram", 75);
//
//	Zarowka* zarowkiWpokoju[] = { &z1, &z2 };
//	Pokoj pokoj(zarowkiWpokoju, 2);
//
//	pokoj.wlaczWszystkie();
//	std::cout << "Zuzycie energii po wlaczeniu: " << pokoj.zuzycieWszystkie() << " W\n";
//
//	pokoj.wylaczWszystkie();
//	std::cout << "Zuzycie energii po wylaczeniu: " << pokoj.zuzycieWszystkie() << " W\n";
//
//	return 0;
//}
//
//#endif

#ifdef Blok2

char* alokujTablice(int rozmiar)
{
	rozmiar += 2;

	char* tab = new char[rozmiar] {'^'};

	uint16_t rozmiarTab = rozmiar;
	tab[0] = rozmiarTab;
	tab += 2;

	return tab;
}

void zwolnijTablice(char* tab)
{
	tab -= 2;

	delete[] tab;
	tab = nullptr;
}

void wczytajTekst(const char* nazwaPliku)
{
	FILE* plik = fopen(nazwaPliku, "r");

	char* tab = alokujTablice(21);

	while (true)
	{
		fgets(tab, 21, plik);

		if (feof(plik))
		{
			break;
		}

		cout << tab << endl;
	}

	zwolnijTablice(tab);
	fclose(plik);
}

int main()
{
	setlocale(LC_ALL, "");

	wczytajTekst("Tekst.txt");
}

#endif

#ifdef Blok22

using namespace std;

char* WczytywanieTekstu()
{
	FILE* plik = nullptr;
	plik = fopen("Tekst.txt", "r");
	char znak; int i = 0; int Rozmiar = 0;
	char Tablica[200] = {};

	if (plik != nullptr)
	{
		rewind(plik);
		while (!feof(plik))
		{
			znak = fgetc(plik);
			if (znak == '\n') znak = ' ';
			//cout << znak;
			Tablica[i] = znak;
			Rozmiar++;
			i++;
		}
	}
	else return nullptr;
	char* Dynamiczna = new char[Rozmiar];


	for (size_t i = 0; i < Rozmiar; i++) {
		Dynamiczna[i] = Tablica[i];
	}

	Dynamiczna[Rozmiar - 1] = '\0';
	fclose(plik);
	plik = nullptr;

	return Dynamiczna;
}

void Justowanie(char* tablica, int liczba_znakow_w_wierszu)
{
	int i = 0;
	while (tablica[i] != NULL)
	{
		char index = tablica[i];
		if (i % liczba_znakow_w_wierszu == 0) cout << endl;
		cout << tablica[i];
		i++;
	}
}

void dealokacja(char* tablica)
{
	delete[] tablica;
	tablica = nullptr;
	cout << "\nTablice zdealokowano";
}

int main()
{
	setlocale(LC_ALL, "");
	char* tablica;
	tablica = WczytywanieTekstu();
	Justowanie(tablica, 55);
	dealokacja(tablica);
}

#endif

#ifdef BlokBartek

double* alokuj(int rozmiar) {
	double* tab = new double[rozmiar];
	return tab;
}

void dealokuj(double*& tab) {
	delete[] tab;
	tab = nullptr;
}
struct tablica {
	double* tab;
	uint32_t rozmiar;
	int ile;
};

void wypelnij(tablica& t, int rozmiar) {


	if (t.tab != nullptr) {
		dealokuj(t.tab);
		t.ile++;
	}
	else {
		t.ile = 0;
	}

	cout << "\nile: " << t.ile << "\n";
	t.tab = alokuj(rozmiar);

	t.rozmiar = (rozmiar << 8) | t.ile;

	cout << bitset<32>(t.rozmiar);

}

double* zapisz(const char* nameF) {
	FILE* desp = fopen(nameF, "r");

	rewind(desp);


	char line[1024];
	fgets(line, 1024, desp);

	int rozmiar = 0;
	for (unsigned int i = 0; i < strlen(line); i++) {
		if (line[i] == ',') {
			rozmiar++;
		}
	}
	rozmiar++;


	double* tab = alokuj(rozmiar);
	cout << "\n" << "rozmiar: " << rozmiar << "\n";

	rewind(desp);
	for (int i = 0; i < rozmiar; i++) {
		fscanf(desp, "%lf,", &tab[i]);
	}

	for (size_t i = 0; i < 4; i++)
	{
		cout << tab[i] << " ";
	}
	fclose(desp);
	return tab;
}


int main() {
	tablica a;
	a.tab = nullptr;
	wypelnij(a, 10);
	wypelnij(a, 8);
	wypelnij(a, 7);
	tablica b;
	b.tab = nullptr;
	wypelnij(b, 10);

	zapisz("Tekst.txt");
}

#endif