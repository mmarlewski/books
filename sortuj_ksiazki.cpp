#include <vector>
#include <cmath>
#include "tryb.h"
#include "ksiazka.h"

extern void zakoncz_program ();
extern void wypisz ( std::string output );
extern void wyczysc_ekran ();
extern char pobierz_znak ();
extern std::string pobierz_napis ();
extern void zmien_tryb ( tryb nowy_tryb );

extern std::vector<ksiazka*> wybrane_ksiazki;

// sortuje tablice wybranych ksiazek

// sortowanie babelkowe bo najlatwiejsze

void sortuj_ksiazki ( bool czy_rosnaco, bool czy_id, bool czy_tytul, bool czy_autor, bool czy_rok_wydania, bool czy_cena, bool czy_wypozyczenia )
{
	for ( int i = 0; i < wybrane_ksiazki.size (); i++ )
	{
		for ( int j = 0; j < wybrane_ksiazki.size () - i - 1; j++ )
		{
			// id

			if ( czy_id )
			{
				if ( czy_rosnaco )
				{
					if ( wybrane_ksiazki[j + 1]->id > wybrane_ksiazki[j]->id )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( wybrane_ksiazki[j + 1]->id < wybrane_ksiazki[j]->id )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

			// tytul

			else if ( czy_tytul )
			{
				// male i duze litery tytulow sa rownowazne
				// porownuje wersje tytulow z samymi malymi literami

				// tworzenie nowych wersji tytulow
				std::string tytul_1 = wybrane_ksiazki[j]->tytul;
				std::string tytul_2 = wybrane_ksiazki[j + 1]->tytul;

				for ( int k = 0; k < tytul_1.length (); k++ )
				{
					if ( tytul_1[k] >= 65 && tytul_1[k] <= 90 ) tytul_1[k] += 32;
				}

				for ( int k = 0; k < tytul_2.length (); k++ )
				{
					if ( tytul_2[k] >= 65 && tytul_2[k] <= 90 ) tytul_2[k] += 32;
				}

				bool czy_wieksza = false;

				int max = std::max ( wybrane_ksiazki[j]->tytul.length (), wybrane_ksiazki[j + 1]->tytul.length () );

				// porownywanie nowych wersji tytulow
				for ( int k = 0; k < max; k++ )
				{
					if ( k > tytul_1.length () )
					{
						czy_wieksza = true;
						break;
					}
					else if ( k > tytul_2.length () )
					{
						czy_wieksza = false;
						break;
					}
					else if ( tytul_2[k] > tytul_1[k] )
					{
						czy_wieksza = true;
						break;
					}
					else if ( tytul_1[k] > tytul_2[k] )
					{
						czy_wieksza = false;
						break;
					}
				}

				// zamienianie ksiazek
				if ( czy_wieksza )
				{
					if ( czy_rosnaco )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( !czy_rosnaco )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

			// autor

			if ( czy_autor )
			{
				std::string autor_1 = wybrane_ksiazki[j]->autor;
				std::string autor_2 = wybrane_ksiazki[j + 1]->autor;

				for ( int k = 0; k < autor_1.length (); k++ )
				{
					if ( autor_1[k] >= 65 && autor_1[k] <= 90 ) autor_1[k] += 32;
				}

				for ( int k = 0; k < autor_2.length (); k++ )
				{
					if ( autor_2[k] >= 65 && autor_2[k] <= 90 ) autor_2[k] += 32;
				}

				bool czy_wieksza = false;

				int max = std::max ( wybrane_ksiazki[j]->autor.length (), wybrane_ksiazki[j + 1]->autor.length () );

				for ( int k = 0; k < max; k++ )
				{
					if ( k > autor_1.length () )
					{
						czy_wieksza = true;
						break;
					}
					else if ( k > autor_2.length () )
					{
						czy_wieksza = false;
						break;
					}
					else if ( autor_2[k] > autor_1[k] )
					{
						czy_wieksza = true;
						break;
					}
					else if ( autor_1[k] > autor_2[k] )
					{
						czy_wieksza = false;
						break;
					}
				}

				if ( czy_wieksza )
				{
					if ( czy_rosnaco )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( !czy_rosnaco )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

			// rok_wydania

			else if ( czy_rok_wydania )
			{
				if ( czy_rosnaco )
				{
					if ( wybrane_ksiazki[j + 1]->rok_wydania > wybrane_ksiazki[j]->rok_wydania )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( wybrane_ksiazki[j + 1]->rok_wydania < wybrane_ksiazki[j]->rok_wydania )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

			// cena

			else if ( czy_cena )
			{
				if ( czy_rosnaco )
				{
					if ( wybrane_ksiazki[j + 1]->cena > wybrane_ksiazki[j]->cena )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( wybrane_ksiazki[j + 1]->cena < wybrane_ksiazki[j]->cena )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

			// wypozyczenia

			else if ( czy_wypozyczenia )
			{
				if ( czy_rosnaco )
				{
					if ( wybrane_ksiazki[j + 1]->wypozyczenia > wybrane_ksiazki[j]->wypozyczenia )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
				else
				{
					if ( wybrane_ksiazki[j + 1]->wypozyczenia < wybrane_ksiazki[j]->wypozyczenia )
					{
						ksiazka* tym = wybrane_ksiazki[j];
						wybrane_ksiazki[j] = wybrane_ksiazki[j + 1];
						wybrane_ksiazki[j + 1] = tym;
					}
				}
			}

		}
	}
}