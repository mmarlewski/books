#pragma once

#include "Tryb_programu.h"

class Sortowanie_ksiazek :public Tryb_programu
{
	public:

	Sortowanie_ksiazek ();
	~Sortowanie_ksiazek ();

	void zacznij ();
	void petla ();
	void zakoncz ();

	bool czy_rosnaco;
	bool czy_id;
	bool czy_tytul;
	bool czy_autor;
	bool czy_rok_wydania;
	bool czy_cena;
	bool czy_wypozyczenia;

	char znak;
};