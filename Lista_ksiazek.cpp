#include "Lista_ksiazek.h"

#include <fstream>
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

void sortuj_ksiazki ( bool czy_rosnaco, bool czy_id, bool czy_tytul, bool czy_autor, bool czy_rok_wydania, bool czy_cena, bool czy_wypozyczenia );

void nadpisz_ksiazki ();

Lista_ksiazek::Lista_ksiazek ()
{
	//
}

Lista_ksiazek::~Lista_ksiazek ()
{
	//
}

void Lista_ksiazek::zacznij ()
{
	// nr_ksiazki i nr_czesci
	nr_ksiazki = 0;
	nr_czesci = 0;

	// max_czesci
	if ( wybrane_ksiazki.size () % 10 == 0 )
	{
		max_czesci = wybrane_ksiazki.size () / 10;
	}
	else
	{
		max_czesci = ( wybrane_ksiazki.size () / 10 ) + 1;
	}

	// srednia_cena i srednia_wypozyczenia
	if ( wybrane_ksiazki.size () > 0 )
	{
		int suma_cena = 0;
		int suma_wypozyczenia = 0;

		for ( int i = 0; i < wybrane_ksiazki.size (); i++ )
		{
			suma_cena += wybrane_ksiazki[i]->cena;
			suma_wypozyczenia += wybrane_ksiazki[i]->wypozyczenia;
		}

		srednia_cena = float ( suma_cena ) / wybrane_ksiazki.size ();
		srednia_wypozyczenia = float ( suma_wypozyczenia ) / wybrane_ksiazki.size ();
	}
	else
	{
		srednia_cena = 0.00f;
		srednia_wypozyczenia = 0.00f;
	}
}

void Lista_ksiazek::zakoncz ()
{
	//
}

void Lista_ksiazek::petla ()
{
	wyczysc_ekran ();

	// zamienianie srednia_cena i srednia_wypozyczenia na napisy

	std::string srednia_cena_napis = std::to_string ( srednia_cena );

	for ( int i = 0; i < srednia_cena_napis.length (); i++ )
	{
		if ( srednia_cena_napis[i] == '.' )
		{
			srednia_cena_napis.erase ( i + 3 );
			break;
		}
	}

	std::string srednia_wypozyczenia_napis = std::to_string ( srednia_wypozyczenia );

	for ( int i = 0; i < srednia_wypozyczenia_napis.length (); i++ )
	{
		if ( srednia_wypozyczenia_napis[i] == '.' )
		{
			srednia_wypozyczenia_napis.erase ( i + 3 );
			break;
		}
	}

	//

	wypisz ( " ------------------------------------------------------------- \n" );
	wypisz ( " Lista ksiazek : \n" );
	wypisz ( " ------------------------------------------------------------- \n" );
	wypisz ( " Srednia cen : " + srednia_cena_napis );
	for ( int i = 0; i < 12 - srednia_cena_napis.length (); i++ ) wypisz ( " " );
	wypisz ( " Srednia wypozyczen : " + srednia_wypozyczenia_napis + "\n" );
	wypisz ( " ------------------------------------------------------------- \n" );
	wypisz ( "   ID  tytul                autor                r.w. cena l.w \n" );
	wypisz ( " ------------------------------------------------------------- \n" );

	// do wypisywania informacji w rownych odstepach

	std::string id_ksiazki;
	std::string tytul_ksiazki;
	std::string autor_ksiazki;
	std::string rok_wydania_ksiazki;
	std::string cena_ksiazki;
	std::string wypozyczenia_ksiazki;

	bool czy_pokazac_id;
	bool czy_pokazac_tytul;
	bool czy_pokazac_autor;
	bool czy_pokazac_rok_wydania;
	bool czy_pokazac_cena;
	bool czy_pokazac_wypozyczenia;
	int indeks;

	for ( int i = 0; i < 10; i++ )
	{
		if ( nr_czesci * 10 + i < wybrane_ksiazki.size () )
		{
			// zamienianie informacji na napisy

			id_ksiazki = std::to_string ( wybrane_ksiazki[nr_czesci * 10 + i]->id );
			tytul_ksiazki = wybrane_ksiazki[nr_czesci * 10 + i]->tytul;
			autor_ksiazki = wybrane_ksiazki[nr_czesci * 10 + i]->autor;
			rok_wydania_ksiazki = std::to_string ( wybrane_ksiazki[nr_czesci * 10 + i]->rok_wydania );
			cena_ksiazki = std::to_string ( wybrane_ksiazki[nr_czesci * 10 + i]->cena );
			wypozyczenia_ksiazki = std::to_string ( wybrane_ksiazki[nr_czesci * 10 + i]->wypozyczenia );

			czy_pokazac_id = false;
			czy_pokazac_tytul = false;
			czy_pokazac_autor = false;
			czy_pokazac_rok_wydania = false;
			czy_pokazac_cena = false;
			czy_pokazac_wypozyczenia = false;
			indeks = 0;

			// wypisywanie informacji

			for ( int j = 0; j < 100; j++ )
			{
				switch ( j )
				{
					case 1:

					if ( i == nr_ksiazki )
					{
						wypisz ( ">" );
					}
					else
					{
						wypisz ( " " );
					}

					break;
					case 3:

					czy_pokazac_id = true;
					indeks = 0;

					break;
					case 6:

					czy_pokazac_id = false;

					break;
					case 7:

					czy_pokazac_tytul = true;
					indeks = 0;

					break;
					case 27:

					czy_pokazac_tytul = false;

					break;
					case 28:

					czy_pokazac_autor = true;
					indeks = 0;

					break;
					case 48:

					czy_pokazac_autor = false;

					break;
					case 49:

					czy_pokazac_rok_wydania = true;
					indeks = 0;

					break;
					case 53:

					czy_pokazac_rok_wydania = false;

					break;
					case 54:

					czy_pokazac_cena = true;
					indeks = 0;

					break;
					case 58:

					czy_pokazac_cena = false;

					break;
					case 59:

					czy_pokazac_wypozyczenia = true;
					indeks = 0;

					break;
					case 63:

					czy_pokazac_wypozyczenia = false;

					break;
					default:break;
				}

				if ( czy_pokazac_id )
				{
					if ( indeks < id_ksiazki.length () )
						wypisz ( std::string ( 1, id_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else if ( czy_pokazac_tytul )
				{
					if ( indeks < tytul_ksiazki.length () )
						wypisz ( std::string ( 1, tytul_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else if ( czy_pokazac_autor )
				{
					if ( indeks < autor_ksiazki.length () )
						wypisz ( std::string ( 1, autor_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else if ( czy_pokazac_rok_wydania )
				{
					if ( indeks < rok_wydania_ksiazki.length () )
						wypisz ( std::string ( 1, rok_wydania_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else if ( czy_pokazac_cena )
				{
					if ( indeks < cena_ksiazki.length () )
						wypisz ( std::string ( 1, cena_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else if ( czy_pokazac_wypozyczenia )
				{
					if ( indeks < wypozyczenia_ksiazki.length () )
						wypisz ( std::string ( 1, wypozyczenia_ksiazki[indeks] ) );
					else wypisz ( " " );
				}
				else
				{
					if ( j != 1 ) wypisz ( " " );
				}

				indeks++;
			}
		}

		wypisz ( "\n" );
	}

	//

	wypisz ( " ------------------------( " );
	wypisz ( std::to_string ( nr_czesci + 1 ) );
	if ( nr_czesci + 1 < 10 ) wypisz ( " " );
	wypisz ( " / " );
	wypisz ( std::to_string ( max_czesci ) );
	if ( max_czesci < 10 ) wypisz ( " " );
	wypisz ( " )-------------------------- \n" );
	wypisz ( " [w][s] zmien ksiazke                  [a][d] przewin liste    \n" );
	wypisz ( " [q] dodaj ksiazke                     [r] usun ksiazke        \n" );
	wypisz ( " [t] szukaj ksiazki                    [y] wszystkie ksiazki   \n" );
	wypisz ( " [f] posortuj ksiazki                  [g] bez sortowania      \n" );
	wypisz ( " [ESC] wyjdz z programu                [e] wypozycz ksiazke    \n" );
	wypisz ( " ------------------------------------------------------------- \n" );
	wypisz ( " :" );

	znak = pobierz_znak ();

	// reagowanie na wpisany znak

	switch ( znak )
	{
		case 'w':

		// przesuniecie znacznika w gore

		if ( nr_ksiazki == 0 )
		{
			if ( nr_czesci + 1 == max_czesci )
			{
				nr_ksiazki = ( wybrane_ksiazki.size () % 10 ) - 1;
			}
			else
			{
				nr_ksiazki = 9;
			}
		}
		else
		{
			nr_ksiazki--;
		}

		break;
		case 's':

		// przesuniecie znacznika w dol

		if ( nr_czesci * 10 + nr_ksiazki + 1 < wybrane_ksiazki.size () && nr_ksiazki < 9 )
		{
			nr_ksiazki++;
		}
		else
		{
			nr_ksiazki = 0;
		}

		break;
		case 'a':

		// przewiniecie listy w gore

		if ( nr_czesci == 0 )
		{
			nr_czesci = max_czesci - 1;

			if ( nr_czesci * 10 + nr_ksiazki >= wybrane_ksiazki.size () )
			{
				nr_ksiazki = ( wybrane_ksiazki.size () % 10 ) - 1;
			}
		}
		else
		{
			nr_czesci--;
		}

		break;
		case 'd':

		// przewiniecie listy w dol

		if ( nr_czesci == max_czesci - 1 )
		{
			nr_czesci = 0;
		}
		else
		{
			nr_czesci++;

			if ( nr_czesci * 10 + nr_ksiazki >= wybrane_ksiazki.size () )
			{
				nr_ksiazki = ( wybrane_ksiazki.size () % 10 ) - 1;
			}
		}

		break;
		case 'q':

		// dodanie nowej ksiazki

		if ( wszystkie_ksiazki.size () < 1000 )
		{
			zmien_tryb ( tryb::nowa_ksiazka );
		}

		break;
		case 'r':

		// usuniecie ksiazki

		wypisz ( " Czy na pewno usunac ksiazke ? ( wpisz ponownie \'r\' ) : " );

		if ( pobierz_znak () != 'r' ) break;

		if ( nr_czesci * 10 + nr_ksiazki < wybrane_ksiazki.size () )
		{
			// usuniecie z tablicy wszystkich ksiazek
			wszystkie_ksiazki.erase ( wszystkie_ksiazki.begin () + wybrane_ksiazki[nr_czesci * 10 + nr_ksiazki]->id - 1 );

			// zmiana id ksiazek wystepujacych po usunietej ksiazce
			for ( int i = wybrane_ksiazki[nr_czesci * 10 + nr_ksiazki]->id - 1; i < wszystkie_ksiazki.size (); i++ )
			{
				wszystkie_ksiazki[i]->id--;
			}

			// zwolnienie pamieci usunietej ksiazki
			delete wybrane_ksiazki[nr_czesci * 10 + nr_ksiazki];

			// usuniecie z tablicy wybranych ksiazek
			wybrane_ksiazki.erase ( wybrane_ksiazki.begin () + nr_czesci * 10 + nr_ksiazki );

			// nadpisanie wszystkich ksiazek
			nadpisz_ksiazki ();

			// sytuacja znacznika po usunieciu
			if ( nr_czesci * 10 + nr_ksiazki + 1 > wybrane_ksiazki.size () )
			{
				if ( wybrane_ksiazki.size () == 0 )
				{
					nr_ksiazki = 0;
				}
				else if ( wybrane_ksiazki.size () % 10 == 0 )
				{
					nr_czesci--;
					nr_ksiazki = 9;
				}
				else
				{
					nr_ksiazki--;
				}
			}

			// ewentualna zmiana max_czesci
			if ( wybrane_ksiazki.size () % 10 == 0 )
			{
				max_czesci--;
			}
		}

		break;
		case 't':

		// szukanie we wszystkich ksiazkach

		if ( wszystkie_ksiazki.size () > 1 )
		{
			zmien_tryb ( tryb::Szukanie_ksiazek );
		}

		break;
		case 'y':

		// pokazanie wszystkich ksiazek ( cofniecie szukania )

		if ( wszystkie_ksiazki.size () > 1 )
		{
			wybrane_ksiazki.clear ();

			szukaj_ksiazki ( 0, 0, "", 0, 0, "", 0, 0, 0, 0, 0, 0, 0, 0, 0 );

			zacznij ();
		}

		break;
		case 'f':

		// sortowanie pokazywanych ksiazek

		if ( wszystkie_ksiazki.size () > 1 )
		{
			zmien_tryb ( tryb::sortowanie_ksiazek );
		}

		break;
		case 'g':

		// sortowanie wg id ( cofniecie sortowania )

		if ( wszystkie_ksiazki.size () > 1 )
		{
			sortuj_ksiazki ( 0, 1, 0, 0, 0, 0, 0 );

			zacznij ();
		}

		break;
		case 'e':

		// wypozyczenie ksiazki

		if ( nr_czesci * 10 + nr_ksiazki < wybrane_ksiazki.size () )
		{
			if ( wybrane_ksiazki[nr_czesci * 10 + nr_ksiazki]->wypozyczenia < MAX_WYPOZ )
			{
				wybrane_ksiazki[nr_czesci * 10 + nr_ksiazki]->wypozyczenia++;
			}
		}

		break;
		case 27:

		// wyjscie z programu

		nadpisz_ksiazki ();

		zakoncz_program ();

		break;
		default:break;
	}
}

