#include <fstream>
#include <string>
#include <vector>
#include "ksiazka.h"
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

// na podstawie informacji z " ksiazki.txt " tworzy tablice wszystkich ksiazek

// zbyt dlugie tytuly i autorzy sa ucinani
// liczby o zbyt duzej liczbie cyfr sa ignorowane
// liczby wykraczajace poza zakresy sa wyrownywane do zakresow
// tabulatory sa zamieniane na spacje
// niepoprawne informacje sa uzupelniane wartosciami domyslnymi

void pobierz_ksiazki ()
{
	std::fstream plik;
	std::string linia;

	int id_nowej_ksiazki = MIN_ID;

	ksiazka* nowa_ksiazka = nullptr;

	bool czy_pobrac_nowa_ksiazke;
	bool czy_pobrano_tytul;
	bool czy_pobrano_autor;
	bool czy_pobrano_rok_wydania;
	bool czy_pobrano_cena;
	bool czy_pobrano_wypozyczenia;

	plik.open ( "ksiazki.txt", std::ios::in );

	while ( getline ( plik, linia ) )
	{
		if ( linia == "#" )
		{
			// kazda linia z samym symbolem ' # ' oznacza nowa ksiazke

			if ( id_nowej_ksiazki <= MAX_ID )
			{
				nowa_ksiazka = new ksiazka ();
				nowa_ksiazka->id = id_nowej_ksiazki;
				id_nowej_ksiazki++;
				nowa_ksiazka->tytul = "----------";
				nowa_ksiazka->autor = "----------";
				nowa_ksiazka->rok_wydania = MIN_ROK;
				nowa_ksiazka->cena = MIN_CENA;
				nowa_ksiazka->wypozyczenia = MIN_WYPOZ;

				wszystkie_ksiazki.push_back ( nowa_ksiazka );

				czy_pobrac_nowa_ksiazke = true;
				czy_pobrano_tytul = false;
				czy_pobrano_autor = false;
				czy_pobrano_rok_wydania = false;
				czy_pobrano_cena = false;
				czy_pobrano_wypozyczenia = false;
			}
			
		}
		else
		{
			if ( czy_pobrac_nowa_ksiazke )
			{
				// tytul

				if ( !czy_pobrano_tytul )
				{
					nowa_ksiazka->tytul = linia;

					if ( nowa_ksiazka->tytul.length () > ROZM_TYTUL )
						nowa_ksiazka->tytul.erase ( ROZM_TYTUL );

					for ( int i = 0; i < nowa_ksiazka->tytul.length (); i++ )
					{
						if ( nowa_ksiazka->tytul[i] == '\t' )
						{
							nowa_ksiazka->tytul[i] = ' ';
						}
					}

					czy_pobrano_tytul = true;
				}

				// autor

				else if ( !czy_pobrano_autor )
				{
					nowa_ksiazka->autor = linia;

					if ( nowa_ksiazka->autor.length () > ROZM_AUTOR )
						nowa_ksiazka->autor.erase ( ROZM_AUTOR );

					for ( int i = 0; i < nowa_ksiazka->autor.length (); i++ )
					{
						if ( nowa_ksiazka->autor[i] == '\t' )
						{
							nowa_ksiazka->autor[i] = ' ';
						}
					}

					czy_pobrano_autor = true;
				}

				// rok_wydania

				else if ( !czy_pobrano_rok_wydania )
				{
					if ( linia.length () > 0 && linia.length () <= ROZM_ROK )
					{
						bool czy_liczba = true;

						for ( int i = 0; i < linia.length (); i++ )
						{
							if ( !std::isdigit ( linia[i] ) )
							{
								czy_liczba = false;
								break;
							}
						}

						if ( czy_liczba )
						{
							nowa_ksiazka->rok_wydania = std::stoi ( linia );

							if ( nowa_ksiazka->rok_wydania > MAX_ROK )
								nowa_ksiazka->rok_wydania = MAX_ROK;

							if ( nowa_ksiazka->rok_wydania < MIN_ROK )
								nowa_ksiazka->rok_wydania = MIN_ROK;
						}
					}

					czy_pobrano_rok_wydania = true;
				}

				// cena

				else if ( !czy_pobrano_cena )
				{
					if ( linia.length () > 0 && linia.length () <= ROZM_CENA )
					{
						bool czy_liczba = true;

						for ( int i = 0; i < linia.length (); i++ )
						{
							if ( !std::isdigit ( linia[i] ) )
							{
								czy_liczba = false;
								break;
							}
						}

						if ( czy_liczba )
						{
							nowa_ksiazka->cena = std::stoi ( linia );

							if ( nowa_ksiazka->cena > MAX_CENA )
								nowa_ksiazka->cena = MAX_CENA;

							if ( nowa_ksiazka->cena < MIN_CENA )
								nowa_ksiazka->cena = MIN_CENA;
						}
					}

					czy_pobrano_cena = true;
				}

				// wypozyczenia

				else if ( !czy_pobrano_wypozyczenia )
				{
					if ( linia.length () > 0 && linia.length () <= ROZM_WYPOZ )
					{
						bool czy_liczba = true;

						for ( int i = 0; i < linia.length (); i++ )
						{
							if ( !std::isdigit ( linia[i] ) )
							{
								czy_liczba = false;
								break;
							}
						}

						if ( czy_liczba )
						{
							nowa_ksiazka->wypozyczenia = std::stoi ( linia );

							if ( nowa_ksiazka->wypozyczenia > MAX_WYPOZ )
								nowa_ksiazka->wypozyczenia = MAX_WYPOZ;

							if ( nowa_ksiazka->wypozyczenia < MIN_WYPOZ )
								nowa_ksiazka->wypozyczenia = MIN_WYPOZ;
						}
					}

					czy_pobrano_wypozyczenia = true;
				}
			}
		}
	}

	plik.close ();
}