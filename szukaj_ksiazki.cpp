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
extern std::vector<ksiazka*> wybrane_ksiazki;

// szuka w tablicy wszystkich ksiazek i tworzy tablice wybranych ksiazek z pasujacych ksiazek

void szukaj_ksiazki ( bool czy_szukac_tytul, bool czy_szukac_dokladny_tytul, std::string szukany_tytul,
				 bool czy_szukac_autor, bool czy_szukac_dokladny_autor, std::string szukany_autor,
				 bool czy_szukac_rok_wydania, int min_rok_wydania, int max_rok_wydania,
				 bool czy_szukac_cena, int min_cena, int max_cena,
				 bool czy_szukac_wypozyczenia, int min_wypozyczenia, int max_wypozyczenia )
{
	bool czy_ksiazka_pasuje;

	for ( int i = 0; i < wszystkie_ksiazki.size (); i++ )
	{
		czy_ksiazka_pasuje = true;

		if ( czy_szukac_tytul )
		{
			// male i duze litery tytulow sa rownowazne
			// porownuje wersje tytulow z samymi malymi literami

			// tworzenie nowych wersji tytulow
			std::string tytul_1 = wszystkie_ksiazki[i]->tytul;
			std::string tytul_2 = szukany_tytul;

			for ( int j = 0; j < tytul_1.length (); j++ )
			{
				if ( tytul_1[j] >= 65 && tytul_1[j] <= 90 ) tytul_1[j] += 32;
			}

			for ( int j = 0; j < tytul_2.length (); j++ )
			{
				if ( tytul_2[j] >= 65 && tytul_2[j] <= 90 ) tytul_2[j] += 32;
			}

			// sprawdzanie czy ksiazka pasuje
			if ( czy_szukac_dokladny_tytul )
			{
				if ( tytul_1 != tytul_2 )
				{
					czy_ksiazka_pasuje = false;
				}
			}
			else
			{
				if ( tytul_1.find ( tytul_2 ) == std::string::npos )
				{
					czy_ksiazka_pasuje = false;
				}
			}
		}

		if ( czy_szukac_autor )
		{
			std::string autor_1 = wszystkie_ksiazki[i]->autor;
			std::string autor_2 = szukany_autor;

			for ( int j = 0; j < autor_1.length (); j++ )
			{
				if ( autor_1[j] >= 65 && autor_1[j] <= 90 ) autor_1[j] += 32;
			}

			for ( int j = 0; j < autor_2.length (); j++ )
			{
				if ( autor_2[j] >= 65 && autor_2[j] <= 90 ) autor_2[j] += 32;
			}

			if ( czy_szukac_dokladny_autor )
			{
				if ( autor_1 != autor_2 )
				{
					czy_ksiazka_pasuje = false;
				}
			}
			else
			{
				if ( autor_1.find ( autor_2 ) == std::string::npos )
				{
					czy_ksiazka_pasuje = false;
				}
			}
		}

		if ( czy_szukac_rok_wydania )
		{
			if ( wszystkie_ksiazki[i]->rok_wydania < min_rok_wydania || wszystkie_ksiazki[i]->rok_wydania > max_rok_wydania )
			{
				czy_ksiazka_pasuje = false;
			}
		}

		if ( czy_szukac_cena )
		{
			if ( wszystkie_ksiazki[i]->cena < min_cena || wszystkie_ksiazki[i]->cena > max_cena )
			{
				czy_ksiazka_pasuje = false;
			}
		}

		if ( czy_szukac_wypozyczenia )
		{
			if ( wszystkie_ksiazki[i]->wypozyczenia < min_wypozyczenia || wszystkie_ksiazki[i]->wypozyczenia > max_wypozyczenia )
			{
				czy_ksiazka_pasuje = false;
			}
		}

		// dodawanie do tablicy wybranych ksiazek
		if ( czy_ksiazka_pasuje )
		{
			wybrane_ksiazki.push_back ( wszystkie_ksiazki[i] );
		}
	}
}