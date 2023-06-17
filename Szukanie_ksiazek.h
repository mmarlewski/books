#pragma once

#include <string>
#include "Tryb_programu.h"

class Szukanie_ksiazek :public Tryb_programu
{
	public:

	Szukanie_ksiazek ();
	~Szukanie_ksiazek ();

	void zacznij ();
	void petla ();
	void zakoncz ();

	bool czy_szukac_tytul;
	bool czy_szukac_dokladny_tytul;
	std::string szukany_tytul;

	bool czy_szukac_autor;
	bool czy_szukac_dokladny_autor;
	std::string szukany_autor;

	bool czy_szukac_rok_wydania;
	int min_rok_wydania;
	int max_rok_wydania;

	bool czy_szukac_cena;
	int min_cena;
	int max_cena;

	bool czy_szukac_wypozyczenia;
	int min_wypozyczenia;
	int max_wypozyczenia;

	char znak;
};