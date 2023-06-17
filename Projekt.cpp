#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include "tryb.h"
#include "Strona_startowa.h"
#include "Lista_ksiazek.h"
#include "Nowa_ksiazka.h"
#include "Szukanie_ksiazek.h"
#include "Sortowanie_ksiazek.h"

// wszystkie ksiazki sa zapisane w pliku " ksiazki.txt " w formacie
// #
// tytul
// autor
// rok wydania
// cena
// wypozyczenia
// #
// ...

// globalne zmienne

bool czy_zakonczyc_program;
Tryb_programu* aktualny_tryb;

std::vector<ksiazka*> wszystkie_ksiazki;
std::vector<ksiazka*> wybrane_ksiazki;

// tryby programu

Strona_startowa* strona_startowa;
Lista_ksiazek* lista_ksiazek;
Nowa_ksiazka* nowa_ksiazka;
Szukanie_ksiazek* szukanie_ksiazek;
Sortowanie_ksiazek* sortowanie_ksiazek;

// dlugosci i zakresy informacji o ksiazkach

int ROZM_ID = 3;
int MIN_ID = 1;
int MAX_ID = 999;
int ROZM_TYTUL = 20;
int ROZM_AUTOR = 20;
int ROZM_ROK = 4;
int MIN_ROK = 0;
int MAX_ROK = 9999;
int ROZM_CENA = 5;
int MIN_CENA = 0;
int MAX_CENA = 99999;
int ROZM_WYPOZ = 3;
int MIN_WYPOZ = 0;
int MAX_WYPOZ = 999;

void pobierz_ksiazki ();

// globalne funkcje uzywane przez tryby programu

void zakoncz_program ()
{
	czy_zakonczyc_program = true;
}

void wypisz ( std::string output )
{
	std::cout << output;
}

void wyczysc_ekran ()
{
	system ( "cls" );
}

char pobierz_znak ()
{
	return _getch ();
}

std::string pobierz_napis ()
{
	std::string napis;

	std::getline ( std::cin, napis );

	return napis;
}

void zmien_tryb ( tryb nowy_tryb )
{
	aktualny_tryb->zakoncz ();

	switch ( nowy_tryb )
	{
		case tryb::strona_startowa:

		aktualny_tryb = strona_startowa;

		break;
		case tryb::lista_ksiazek:

		aktualny_tryb = lista_ksiazek;

		break;
		case tryb::nowa_ksiazka:

		aktualny_tryb = nowa_ksiazka;

		break;
		case tryb::Szukanie_ksiazek:

		aktualny_tryb = szukanie_ksiazek;

		break;
		case tryb::sortowanie_ksiazek:

		aktualny_tryb = sortowanie_ksiazek;

		break;
		default:break;
	}

	aktualny_tryb->zacznij ();
}

// main

int main ()
{
	czy_zakonczyc_program = false;

	strona_startowa = new Strona_startowa;
	lista_ksiazek = new Lista_ksiazek;
	nowa_ksiazka = new Nowa_ksiazka;
	szukanie_ksiazek = new Szukanie_ksiazek;
	sortowanie_ksiazek = new Sortowanie_ksiazek;

	pobierz_ksiazki ();

	aktualny_tryb = strona_startowa;
	aktualny_tryb->zacznij ();

	while ( !czy_zakonczyc_program )
	{
		aktualny_tryb->petla ();
	}

	aktualny_tryb->zakoncz ();

	delete strona_startowa;
	delete lista_ksiazek;
	delete nowa_ksiazka;
	delete szukanie_ksiazek;
	delete sortowanie_ksiazek;

	for ( int i = 0; i < wszystkie_ksiazki.size (); i++ )
	{
		delete wszystkie_ksiazki[i];
	}

	wszystkie_ksiazki.clear ();
	wybrane_ksiazki.clear ();

	return 0;
}