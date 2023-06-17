#pragma once

#include <string>

struct ksiazka
{
	public:

	ksiazka ();
	~ksiazka ();

	int id;
	std::string tytul;
	std::string autor;
	int rok_wydania;
	int cena;
	int wypozyczenia;
};