#include "Strona_startowa.h"
#include "tryb.h"

extern void zakoncz_program ();
extern void wypisz ( std::string output );
extern void wyczysc_ekran ();
extern char pobierz_znak ();
extern std::string pobierz_napis ();
extern void zmien_tryb ( tryb nowy_tryb );

void szukaj_ksiazki ( bool czy_szukac_tytul, bool czy_szukac_dokladny_tytul, std::string szukany_tytul,
				 bool czy_szukac_autor, bool czy_szukac_dokladny_autor, std::string szukany_autor,
				 bool czy_szukac_rok_wydania, int min_rok_wydania, int max_rok_wydania,
				 bool czy_szukac_cena, int min_cena, int max_cena,
				 bool czy_szukac_wypozyczenia, int min_wypozyczenia, int max_wypozyczenia );

Strona_startowa::Strona_startowa ()
{
	//
}

Strona_startowa::~Strona_startowa ()
{
	//
}

void Strona_startowa::zacznij ()
{
	liczba_niepowodzen = 0;
}

void Strona_startowa::petla ()
{
	if ( liczba_niepowodzen == 0 )
	{
		wypisz ( " -------------------------------- \n" );
		wypisz ( " < PROJEKT : PROSTA BAZA DANYCH > \n" );
		wypisz ( " -------------------------------- \n" );
	}

	if ( liczba_niepowodzen == 0 )
		wypisz ( "\n Dzien dobry, prosze napisac \" ok \" : " );

	if ( liczba_niepowodzen == 1 )
		wypisz ( "\n Najwyrazniej wystapil blad, prosze jeszcze raz napisac \" ok \" : " );

	if ( liczba_niepowodzen == 2 )
		wypisz ( "\n To chyba jakies nieporozumienie, prosze napisac \" ok \" : " );

	if ( liczba_niepowodzen == 3 )
		wypisz ( "\n Ostatnia szansa : " );


	if ( pobierz_napis () == "ok" )
	{
		szukaj_ksiazki ( 0, 0, "", 0, 0, "", 0, 0, 0, 0, 0, 0, 0, 0, 0 );

		zmien_tryb ( tryb::lista_ksiazek );
	}
	else
	{
		if ( liczba_niepowodzen == 3 )
		{
			zakoncz_program ();
		}
		else
		{
			liczba_niepowodzen++;
		}
	}
}

void Strona_startowa::zakoncz ()
{
	//
}