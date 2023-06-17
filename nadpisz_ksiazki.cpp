#include <fstream>
#include <vector>
#include "tryb.h"
#include "ksiazka.h"

extern void zakoncz_program ();
extern void wypisz ( std::string output );
extern void wyczysc_ekran ();
extern char pobierz_znak ();
extern std::string pobierz_napis ();
extern void zmien_tryb ( tryb nowy_tryb );

extern std::vector<ksiazka*> wszystkie_ksiazki;

// usuwa zawartosc " ksizki.txt " i zastepuje ja informacjami z tablicy wszystkich ksiazek

void nadpisz_ksiazki ()
{
	std::fstream plik;

	plik.open ( "ksiazki.txt", std::ios::out );

	for ( int i = 0; i < wszystkie_ksiazki.size (); i++ )
	{
		plik << "#";
		plik << "\n";
		plik << wszystkie_ksiazki[i]->tytul;
		plik << "\n";
		plik << wszystkie_ksiazki[i]->autor;
		plik << "\n";
		plik << wszystkie_ksiazki[i]->rok_wydania;
		plik << "\n";
		plik << wszystkie_ksiazki[i]->cena;
		plik << "\n";
		plik << wszystkie_ksiazki[i]->wypozyczenia;
		plik << "\n";
	}

	plik.close ();
}