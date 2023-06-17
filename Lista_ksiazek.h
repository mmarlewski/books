#pragma once

#include "Tryb_programu.h"

class Lista_ksiazek :public Tryb_programu
{
	public:

	Lista_ksiazek ();
	~Lista_ksiazek ();

	void zacznij ();
	void petla ();
	void zakoncz ();

	int nr_ksiazki;
	int nr_czesci;
	int max_czesci;

	float srednia_cena;
	float srednia_wypozyczenia;

	char znak;
};