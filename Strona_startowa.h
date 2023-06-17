#pragma once

#include <string>
#include "Tryb_programu.h"

class Strona_startowa :public Tryb_programu
{
	public:

	Strona_startowa ();
	~Strona_startowa ();

	void zacznij ();
	void petla ();
	void zakoncz ();

	bool czy_napisano_ok;
	int liczba_niepowodzen;

	std::string napis;
};