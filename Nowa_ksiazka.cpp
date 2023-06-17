#include "Nowa_ksiazka.h"

#include <fstream>
#include <vector>
#include "tryb.h"

extern void zakoncz_program ();
extern void wypisz ( std::string output );
extern void wyczysc_ekran ();
extern char pobierz_znak ();
extern std::string pobierz_napis ();
extern void zmien_tryb ( tryb nowy_tryb );

extern std::vector<ksiazka*> wszystkie_ksiazki;
extern std::vector<ksiazka*> wybrane_ksiazki;

extern int ROZM_ID;
extern int MIN_ID;
extern int MAX_ID;
extern int ROZM_TYTUL;
extern int ROZM_AUTOR;
extern int ROZM_ROK;
extern int MIN_ROK;
extern int MAX_ROK;
extern int ROZM_CENA;
extern int MIN_CENA;
extern int MAX_CENA;
extern int ROZM_WYPOZ;
extern int MIN_WYPOZ;
extern int MAX_WYPOZ;

void szukaj_ksiazki ( bool czy_szukac_tytul, bool czy_szukac_dokladny_tytul, std::string szukany_tytul,
					  bool czy_szukac_autor, bool czy_szukac_dokladny_autor, std::string szukany_autor,
					  bool czy_szukac_rok_wydania, int min_rok_wydania, int max_rok_wydania,
					  bool czy_szukac_cena, int min_cena, int max_cena,
					  bool czy_szukac_wypozyczenia, int min_wypozyczenia, int max_wypozyczenia );

void dopisz_ksiazke ( ksiazka* nowa_ksiazka );

Nowa_ksiazka::Nowa_ksiazka ()
{
	//
}

Nowa_ksiazka::~Nowa_ksiazka ()
{
	//
}

void Nowa_ksiazka::zacznij ()
{
	nowa_ksiazka = new ksiazka ();

	nowa_ksiazka->id = wszystkie_ksiazki.size () + 1;
	nowa_ksiazka->tytul = "----------";
	nowa_ksiazka->autor = "----------";
	nowa_ksiazka->rok_wydania = MIN_ROK;
	nowa_ksiazka->cena = MIN_CENA;
	nowa_ksiazka->wypozyczenia = MIN_WYPOZ;
}

void Nowa_ksiazka::zakoncz ()
{
	//
}

void Nowa_ksiazka::petla ()
{
	//

	wyczysc_ekran ();

	wypisz ( " ---------------------------------------- \n" );
	wypisz ( " Dodaj nowa ksiazke : \n" );
	wypisz ( " ---------------------------------------- \n" );
	wypisz ( " Tytul        : " + nowa_ksiazka->tytul + "\n" );
	wypisz ( " Autor        : " + nowa_ksiazka->autor + "\n" );
	wypisz ( " Rok wydania  : " + std::to_string ( nowa_ksiazka->rok_wydania ) + "\n" );
	wypisz ( " Cena         : " + std::to_string ( nowa_ksiazka->cena ) + "\n" );
	wypisz ( " Wypozyczenia : " + std::to_string ( nowa_ksiazka->wypozyczenia ) + "\n" );
	wypisz ( " ---------------------------------------- \n" );

	wypisz ( " [t] zmien tytul \n" );
	wypisz ( " [a] zmien autor \n" );
	wypisz ( " [r] zmien rok produkcji \n" );
	wypisz ( " [c] zmien cene \n" );
	wypisz ( " [w] zmien wypozyczenia \n" );
	wypisz ( " [e] gotowe \n" );
	wypisz ( " [ESC] wroc \n" );
	wypisz ( " ---------------------------------------- \n" );
	wypisz ( " :" );

	znak = pobierz_znak ();

	// reagowanie na wpisany znak

	// zbyt dlugie tytuly i autorzy sa ucinani
	// liczby o zbyt duzej liczbie cyfr sa ignorowane
	// liczby wykraczajace poza zakresy sa wyrownywane do zakresow
	// tabulatory sa zamieniane na spacje

	switch ( znak )
	{
		case 't':

		wypisz ( " tytul : " );

		nowa_ksiazka->tytul = pobierz_napis ();

		if ( nowa_ksiazka->tytul.length () > 0 )
		{
			if ( nowa_ksiazka->tytul.length () > ROZM_TYTUL )
				nowa_ksiazka->tytul.erase ( ROZM_TYTUL );

			for ( int i = 0; i < nowa_ksiazka->tytul.length (); i++ )
			{
				if ( nowa_ksiazka->tytul[i] == '\t' )
				{
					nowa_ksiazka->tytul[i] = ' ';
				}
			}
		}

		break;
		case 'a':

		wypisz ( " autor : " );

		nowa_ksiazka->autor = pobierz_napis ();

		if ( nowa_ksiazka->autor.length () > 0 )
		{
			if ( nowa_ksiazka->autor.length () > ROZM_AUTOR )
				nowa_ksiazka->autor.erase ( ROZM_AUTOR );

			for ( int i = 0; i < nowa_ksiazka->autor.length (); i++ )
			{
				if ( nowa_ksiazka->autor[i] == '\t' )
				{
					nowa_ksiazka->autor[i] = ' ';
				}
			}
		}

		break;
		case 'r':
		{
			wypisz ( " rok wydania : " );

			std::string napis = pobierz_napis ();

			if ( napis.length () > 0 && napis.length () <= ROZM_ROK )
			{
				bool czy_liczba = true;

				for ( int i = 0; i < napis.length (); i++ )
				{
					if ( !std::isdigit ( napis[i] ) )
					{
						czy_liczba = false;
						break;
					}
				}

				if ( czy_liczba )
				{
					nowa_ksiazka->rok_wydania = std::stoi ( napis );

					if ( nowa_ksiazka->rok_wydania > MAX_ROK )
						nowa_ksiazka->rok_wydania = MAX_ROK;

					if ( nowa_ksiazka->rok_wydania < MIN_ROK )
						nowa_ksiazka->rok_wydania = MIN_ROK;
				}
			}
		}
		break;
		case 'c':
		{
			wypisz ( " cena : " );

			std::string napis = pobierz_napis ();

			if ( napis.length () > 0 && napis.length () <= ROZM_CENA )
			{
				bool czy_liczba = true;

				for ( int i = 0; i < napis.length (); i++ )
				{
					if ( !std::isdigit ( napis[i] ) )
					{
						czy_liczba = false;
						break;
					}
				}

				if ( czy_liczba )
				{
					nowa_ksiazka->cena = std::stoi ( napis );

					if ( nowa_ksiazka->cena > MAX_CENA )
						nowa_ksiazka->cena = MAX_CENA;

					if ( nowa_ksiazka->cena < MIN_CENA )
						nowa_ksiazka->cena = MIN_CENA;
				}
			}
		}
		break;
		case 'w':
		{
			wypisz ( " wypozyczenia : " );

			std::string napis = pobierz_napis ();

			if ( napis.length () > 0 && napis.length () <= ROZM_WYPOZ )
			{
				bool czy_liczba = true;

				for ( int i = 0; i < napis.length (); i++ )
				{
					if ( !std::isdigit ( napis[i] ) )
					{
						czy_liczba = false;
						break;
					}
				}

				if ( czy_liczba )
				{
					nowa_ksiazka->wypozyczenia = std::stoi ( napis );

					if ( nowa_ksiazka->wypozyczenia > MAX_WYPOZ )
						nowa_ksiazka->wypozyczenia = MAX_WYPOZ;

					if ( nowa_ksiazka->wypozyczenia < MIN_WYPOZ )
						nowa_ksiazka->wypozyczenia = MIN_WYPOZ;
				}
			}
		}
		break;
		case 'e':

		dopisz_ksiazke ( nowa_ksiazka );

		wszystkie_ksiazki.push_back ( nowa_ksiazka );

		wybrane_ksiazki.clear ();

		szukaj_ksiazki ( 0, 0, "", 0, 0, "", 0, 0, 0, 0, 0, 0, 0, 0, 0 );

		zmien_tryb ( tryb::lista_ksiazek );

		break;
		case 27:

		delete nowa_ksiazka;

		zmien_tryb ( tryb::lista_ksiazek );

		break;
		default:break;
	}
}