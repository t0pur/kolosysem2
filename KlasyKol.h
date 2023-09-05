#pragma once
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <cmath>
#include <iostream>

class Uprawnienie
{
protected:
	bool m_doZapisu = false;
	bool m_doOdczytu = true;
	bool m_doWykonania = true;
public:
	Uprawnienie(bool zap, bool od, bool wyk)
		: m_doZapisu(zap), m_doOdczytu(od), m_doWykonania(wyk)
	{}
	Uprawnienie()
	{}
	void setDoZapisu(bool zap) { m_doZapisu = zap; }
	void setDoOdczytu(bool od) { m_doOdczytu = od; }
	void setDoWykonania(bool wyk) { m_doWykonania = wyk; }
	bool getDoZapisu() const { return m_doZapisu; }
	bool getDoOdczytu() const { return m_doOdczytu; }
	bool getDoWykonania() const { return m_doWykonania; }
};

class Uzytkownik{
private:
	const char* m_nazwa;
	Uprawnienie m_uprawnienie;
public:
	void set_nazwa(const char* nazwa) {
		m_nazwa = nazwa;
	}
	void set_uprawnienia(const char * nazwa, bool zap, bool od, bool wyk) {
		m_nazwa = nazwa;
		m_uprawnienie.setDoZapisu(zap);
		m_uprawnienie.setDoOdczytu(od);
		m_uprawnienie.setDoWykonania(wyk);
	}
	Uzytkownik(const char * nazwa = "root", bool zap = true, bool od = true, bool wyk = true)
		: m_nazwa(nazwa), m_uprawnienie(zap, od, wyk)
	{

	}
	const char* getNazwa() const
	{
		return m_nazwa;
	}

	bool getDoZapisu() const
	{
		return m_uprawnienie.getDoZapisu();
	}

	bool getDoOdczytu() const
	{
		return m_uprawnienie.getDoOdczytu();
	}

	bool getDoWykonania() const
	{
		return m_uprawnienie.getDoWykonania();
	}

	virtual bool sprawdzUprawnienia(const char* typOperacji) const
	{
		if (strcmp(typOperacji, "zapis") == 0)
			return getDoZapisu();
		else if (strcmp(typOperacji, "odczyt") == 0)
			return getDoOdczytu();
		else if (strcmp(typOperacji, "wykonanie") == 0)
			return getDoWykonania();
		else
			return false;
	}
};
class UzytkownikChroniony : public Uzytkownik{
private:
	const char* m_haslo;
public:
	void set_haslo(const char* haslo) {
		m_haslo = haslo;
	}
	UzytkownikChroniony(const char* nazwa = "root", bool zap = true, bool od = true, bool wyk = true, const char* haslo = "")
		: Uzytkownik(nazwa, zap ,od ,wyk), m_haslo(haslo)
	{

	}

	const char* get_haslo() const
	{
		return m_haslo;
	};

	bool sprawdzUprawnienia(const char* typOperacji) const override
	{
		if (Uzytkownik::sprawdzUprawnienia(typOperacji))
		{
			char wprowadzoneHaslo[100];
			std::cout << "Podaj haslo: ";
			std::cin >> wprowadzoneHaslo;

			if (strcmp(wprowadzoneHaslo, get_haslo()) == 0)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
};