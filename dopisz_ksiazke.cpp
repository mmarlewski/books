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

// dopisuje nowa ksiazke na koncu " ksiazki.txt "

void dopisz_ksiazke ( ksiazka* nowa_ksiazka )
{
	std::fstream plik;

	plik.open ( "ksiazki.txt", std::ios::out | std::ios::app );

	plik << "";
	plik << "#";
	plik << "\n";
	plik << nowa_ksiazka->tytul;
	plik << "\n";
	plik << nowa_ksiazka->autor;
	plik << "\n";
	plik << nowa_ksiazka->rok_wydania;
	plik << "\n";

	plik.close ();
}