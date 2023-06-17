#include "Sortowanie_ksiazek.h"

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
extern std::vector<ksiazka*> wybrane_ksiazki;

void sortuj_ksiazki ( bool czy_rosnaco, bool czy_id, bool czy_tytul, bool czy_autor, bool czy_rok_wydania, bool czy_cena, bool czy_wypozyczenia );

Sortowanie_ksiazek::Sortowanie_ksiazek ()
{
	//
}

Sortowanie_ksiazek::~Sortowanie_ksiazek ()
{
	//
}

void Sortowanie_ksiazek::zacznij ()
{
	czy_rosnaco = true;
	czy_id = false;
	czy_tytul = false;
	czy_autor = false;
	czy_rok_wydania = false;
	czy_cena = false;
	czy_wypozyczenia = false;
}

void Sortowanie_ksiazek::zakoncz ()
{
	//
}

void Sortowanie_ksiazek::petla ()
{
	wyczysc_ekran ();

	wypisz ( " ----------------------------------- \n" );
	wypisz ( " Posortuj ksiazki wedlog : \n" );
	wypisz ( " ----------------------------------- \n" );
	
	if ( czy_tytul || czy_autor || czy_rok_wydania || czy_cena || czy_wypozyczenia )
	{
		if ( czy_tytul )
		{
			wypisz ( " tytulu ksiazki \n" );
		}
		else if ( czy_autor )
		{
			wypisz ( " autora ksiazki \n" );
		}
		else if ( czy_rok_wydania )
		{
			wypisz ( " roku wydania \n" );
		}
		else if ( czy_cena )
		{
			wypisz ( " ceny \n" );
		}
		else if ( czy_wypozyczenia )
		{
			wypisz ( " wypozyczen \n" );
		}
	}
	else
	{
		wypisz ( " niczego \n" );
	}

	if ( czy_rosnaco )
	{
		wypisz ( " rosnaco \n" );
	}
	else
	{
		wypisz ( " malejaco \n" );
	}

	wypisz ( " ----------------------------------- \n" );

	if ( czy_rosnaco )
	{
		wypisz ( " [q] posortuj malejaco \n" );
	}
	else
	{
		wypisz ( " [q] posortuj rosnaco \n" );
	}

	wypisz ( " [t] posortuj wg tytulu \n" );
	wypisz ( " [a] posortuj wg autora \n" );
	wypisz ( " [r] posortuj wg roku wydania \n" );
	wypisz ( " [c] posortuj wg ceny \n" );
	wypisz ( " [w] posortuj wg wypozyczen \n" );

	if ( czy_tytul || czy_autor || czy_rok_wydania || czy_cena || czy_wypozyczenia )
	{
		wypisz ( " [e] gotowe \n" );
	}

	wypisz ( " [ESC] wroc \n" );
	wypisz ( " ----------------------------------- \n" );
	wypisz ( "  :" );

	znak = pobierz_znak ();

	// reagowanie na wpisany znak

	switch ( znak )
	{
		case 'q':

		czy_rosnaco = !czy_rosnaco;

		break;
		case 't':

		czy_tytul = true;
		czy_autor = false;
		czy_rok_wydania = false;
		czy_cena = false;
		czy_wypozyczenia = false;

		break;
		case 'a':

		czy_tytul = false;
		czy_autor = true;
		czy_rok_wydania = false;
		czy_cena = false;
		czy_wypozyczenia = false;

		break;
		case 'r':

		czy_tytul = false;
		czy_autor = false;
		czy_rok_wydania = true;
		czy_cena = false;
		czy_wypozyczenia = false;

		break;
		case 'c':

		czy_tytul = false;
		czy_autor = false;
		czy_rok_wydania = false;
		czy_cena = true;
		czy_wypozyczenia = false;

		break;
		case 'w':

		czy_tytul = false;
		czy_autor = false;
		czy_rok_wydania = false;
		czy_cena = false;
		czy_wypozyczenia = true;

		break;
		case 'e':

		if ( czy_tytul || czy_autor || czy_rok_wydania || czy_cena || czy_wypozyczenia )
		{
			sortuj_ksiazki ( czy_rosnaco, czy_id, czy_tytul, czy_autor, czy_rok_wydania, czy_cena, czy_wypozyczenia );

			zmien_tryb ( tryb::lista_ksiazek );
		}

		break;
		case 27:

		zmien_tryb ( tryb::lista_ksiazek );

		break;
		default:break;
	}
}