#pragma once

#include "Tryb_programu.h"
#include"ksiazka.h"

class Nowa_ksiazka :public Tryb_programu
{
	public:

	Nowa_ksiazka ();
	~Nowa_ksiazka ();

	void zacznij ();
	void petla ();
	void zakoncz ();

	ksiazka* nowa_ksiazka;

	char znak;
};

