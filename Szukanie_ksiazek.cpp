#include "Szukanie_ksiazek.h"

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

void szukaj_ksiazki ( bool czy_szukac_tytul, bool czy_szukac_dokladny_tytul, std:: string szukany_tytul,
				 bool czy_szukac_autor, bool czy_szukac_dokladny_autor, std:: string szukany_autor,
				 bool czy_szukac_rok_wydania, int min_rok_wydania, int max_rok_wydania,
				 bool czy_szukac_cena, int min_cena, int max_cena,
				 bool czy_szukac_wypozyczenia, int min_wypozyczenia, int max_wypozyczenia );

Szukanie_ksiazek::Szukanie_ksiazek ()
{
	//
}

Szukanie_ksiazek::~Szukanie_ksiazek ()
{
	//
}

void Szukanie_ksiazek::zacznij ()
{
	czy_szukac_tytul = false;
	czy_szukac_dokladny_tytul = false;
	szukany_tytul = "";

	czy_szukac_autor = false;
	czy_szukac_dokladny_autor = false;
	szukany_autor = "";

	czy_szukac_rok_wydania = false;
	min_rok_wydania = MIN_ROK;
	max_rok_wydania = MAX_ROK;

	czy_szukac_cena = false;
	min_cena = MIN_CENA;
	max_cena = MAX_CENA;

	czy_szukac_wypozyczenia = false;
	min_wypozyczenia = MIN_WYPOZ;
	max_wypozyczenia = MAX_WYPOZ;
}

void Szukanie_ksiazek::zakoncz ()
{
	//
}

void Szukanie_ksiazek::petla ()
{
	wyczysc_ekran ();

	// parametry wyszukiwania

	wypisz ( " --------------------------------------------- \n" );
	wypisz ( " Szukaj ksiazke wedlog :\n" );
	wypisz ( " --------------------------------------------- \n" );

	if ( czy_szukac_tytul )
	{
		if ( czy_szukac_dokladny_tytul )
			wypisz ( " Tytul ksiazki : " + szukany_tytul + "\n" );
		else
			wypisz ( " Tytul zawiera : " + szukany_tytul + "\n" );
	}
	else
	{
		wypisz ( " - nie szukaj na podstawie tytulu - \n" );
	}

	if ( czy_szukac_autor )
	{
		if ( czy_szukac_dokladny_autor )
			wypisz ( " Autor ksiazki : " + szukany_autor + "\n" );
		else
			wypisz ( " Autor zawiera : " + szukany_autor + "\n" );
	}
	else
	{
		wypisz ( " - nie szukaj na podstawie autora - \n" );
	}

	if ( czy_szukac_rok_wydania )
	{
		wypisz ( " Rok wydania  od : " + std::to_string ( min_rok_wydania ) + " do : " + std::to_string ( max_rok_wydania ) + "\n" );
	}
	else
	{
		wypisz ( " - nie szukaj na podstawie roku wydania - \n" );
	}

	if ( czy_szukac_cena )
	{
		wypisz ( " Cena         od : " + std::to_string ( min_cena ) + " do : " + std::to_string ( max_cena ) + "\n" );
	}
	else
	{
		wypisz ( " - nie szukaj na podstawie ceny - \n" );
	}

	if ( czy_szukac_wypozyczenia )
	{
		wypisz ( " Wypozyczenia od : " + std::to_string ( min_wypozyczenia ) + " do : " + std::to_string ( max_wypozyczenia ) + "\n" );
	}
	else
	{
		wypisz ( " - nie szukaj na podstawie wypozyczen - \n" );
	}

	// zmiana parametrow wyszukiwania

	wypisz ( " --------------------------------------------- \n" );

	if ( czy_szukac_tytul )
	{
		wypisz ( " [t] nie szukaj na podstawie tytulu \n" );

		if ( czy_szukac_dokladny_tytul )
			wypisz ( "  [1] szukaj na podstawie czesci tytulu \n" );
		else
			wypisz ( "  [1] szukaj na podstawie dokladnego tytulu \n" );

		wypisz ( "  [2] zmien szukany tytul \n" );
	}
	else
	{
		wypisz ( " [t] szukaj na podstawie tytulu \n" );
	}

	if ( czy_szukac_autor )
	{
		wypisz ( " [a] nie szukaj na podstawie autora \n" );

		if ( czy_szukac_dokladny_autor )
			wypisz ( "  [3] szukaj na podstawie czesci autora \n" );
		else
			wypisz ( "  [3] szukaj na podstawie dokladnego autora \n" );

		wypisz ( "  [4] zmien szukanego autora \n" );
	}
	else
	{
		wypisz ( " [a] szukaj na podstawie autora \n" );
	}

	if ( czy_szukac_rok_wydania )
	{
		wypisz ( " [r] nie szukaj na podstawie roku wydania \n" );

		wypisz ( "  [5] zmien min roku wydania \n" );

		wypisz ( "  [6] zmien max roku wydania \n" );
	}
	else
	{
		wypisz ( " [r] szukaj na podstawie roku wydania \n" );
	}

	if ( czy_szukac_cena )
	{
		wypisz ( " [c] nie szukaj na podstawie ceny \n" );

		wypisz ( "  [7] zmien min ceny \n" );

		wypisz ( "  [8] zmien max ceny \n" );
	}
	else
	{
		wypisz ( " [c] szukaj na podstawie ceny \n" );
	}


	if ( czy_szukac_wypozyczenia )
	{
		wypisz ( " [w] nie szukaj na podstawie wypozyczen \n" );

		wypisz ( "  [9] zmien min wypozyczen \n" );

		wypisz ( "  [0] zmien max wypozyczen \n" );
	}
	else
	{
		wypisz ( " [w] szukaj na podstawie wypozyczen \n" );
	}

	if ( czy_szukac_tytul || czy_szukac_autor || czy_szukac_rok_wydania || czy_szukac_cena || czy_szukac_wypozyczenia )
	{
		wypisz ( " [e] gotowe \n" );
	}

	wypisz ( " [ESC] wroc \n" );
	wypisz ( " --------------------------------------------- \n" );
	wypisz ( "  :" );

	znak = pobierz_znak ();

	// reagowanie na wpisany znak

	// zbyt dlugie tytuly i autorzy sa ucinani
	// liczby o zbyt duzej liczbie cyfr sa ignorowane
	// liczby wykraczajace poza zakresy sa wyrownywane do zakresow
	// tabulatory sa zamieniane na spacje

	switch ( znak )
	{
		// tytul

		case 't':

		czy_szukac_tytul = !czy_szukac_tytul;

		szukany_tytul = "";

		break;
		case '1':

		if ( czy_szukac_tytul )
		{
			czy_szukac_dokladny_tytul = !czy_szukac_dokladny_tytul;
		}

		break;
		case '2':

		if ( czy_szukac_tytul )
		{
			wypisz ( " szukany tytul : " );

			szukany_tytul = pobierz_napis ();

			if ( szukany_tytul.length () > ROZM_TYTUL )
				szukany_tytul.erase ( ROZM_TYTUL );

			for ( int i = 0; i < szukany_tytul.length (); i++ )
			{
				if ( szukany_tytul[i] == '\t' )
				{
					szukany_tytul[i] = ' ';
				}
			}
		}
		break;

		// autor

		case 'a':

		czy_szukac_autor = !czy_szukac_autor;

		szukany_autor = "";

		break;
		case '3':

		if ( czy_szukac_autor )
		{
			czy_szukac_dokladny_autor = !czy_szukac_dokladny_autor;
		}

		break;
		case '4':

		if ( czy_szukac_autor )
		{
			wypisz ( " szukany autor : " );

			szukany_autor = pobierz_napis ();

			if ( szukany_autor.length () > ROZM_AUTOR )
				szukany_autor.erase ( ROZM_AUTOR );

			for ( int i = 0; i < szukany_autor.length (); i++ )
			{
				if ( szukany_autor[i] == '\t' )
				{
					szukany_autor[i] = ' ';
				}
			}
		}

		break;

		// rok_wydania

		case 'r':

		czy_szukac_rok_wydania = !czy_szukac_rok_wydania;

		break;
		case '5':

		if ( czy_szukac_rok_wydania )
		{
			wypisz ( " min rok wydania : " );

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
					min_rok_wydania = std::stoi ( napis );

					if ( min_rok_wydania < MIN_ROK )
						min_rok_wydania = MIN_ROK;

					if ( min_rok_wydania > MAX_ROK )
						min_rok_wydania =MAX_ROK;
				}
			}
		}

		break;
		case '6':

		if ( czy_szukac_rok_wydania )
		{
			wypisz ( " max rok wydania : " );

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
					max_rok_wydania = std::stoi ( napis );

					if ( max_rok_wydania < MIN_ROK )
						max_rok_wydania = MIN_ROK;

					if ( max_rok_wydania > MAX_ROK )
						max_rok_wydania = MAX_ROK;
				}
			}
		}

		break;

		// cena

		case 'c':

		czy_szukac_cena = !czy_szukac_cena;

		break;
		case '7':

		if ( czy_szukac_cena )
		{
			wypisz ( " min ceny : " );

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
					min_cena = std::stoi ( napis );

					if ( min_cena < MIN_CENA )
						min_cena = MIN_CENA;

					if ( min_cena > MAX_CENA )
						min_cena = MAX_CENA;
				}
			}
		}

		break;
		case '8':

		if ( czy_szukac_cena )
		{
			wypisz ( " max ceny : " );

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
					max_cena = std::stoi ( napis );

					if ( max_cena < MIN_CENA )
						max_cena = MIN_CENA;

					if ( max_cena > MAX_CENA )
						max_cena = MAX_CENA;
				}
			}
		}

		break;

		// wypozyczenia

		case 'w':

		czy_szukac_wypozyczenia = !czy_szukac_wypozyczenia;

		break;
		case '9':

		if ( czy_szukac_wypozyczenia )
		{
			wypisz ( " min wypozyczen : " );

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
					min_wypozyczenia = std::stoi ( napis );

					if ( min_wypozyczenia < MIN_WYPOZ )
						min_wypozyczenia = MIN_WYPOZ;

					if ( min_wypozyczenia > ROZM_WYPOZ )
						min_wypozyczenia = ROZM_WYPOZ;
				}
			}
		}

		break;
		case '0':

		if ( czy_szukac_wypozyczenia )
		{
			wypisz ( " max wypozyczen : " );

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
					max_wypozyczenia = std::stoi ( napis );

					if ( max_wypozyczenia < MIN_WYPOZ )
						max_wypozyczenia = MIN_WYPOZ;

					if ( max_wypozyczenia > ROZM_WYPOZ )
						max_wypozyczenia = ROZM_WYPOZ;
				}
			}
		}

		break;
		case 'e':

		if ( czy_szukac_tytul || czy_szukac_autor || czy_szukac_rok_wydania || czy_szukac_cena || czy_szukac_wypozyczenia )
		{
			wybrane_ksiazki.clear ();

			szukaj_ksiazki ( czy_szukac_tytul, czy_szukac_dokladny_tytul, szukany_tytul,
							 czy_szukac_autor, czy_szukac_dokladny_autor, szukany_autor,
							 czy_szukac_rok_wydania, min_rok_wydania, max_rok_wydania,
							 czy_szukac_cena, min_cena, max_cena,
							 czy_szukac_wypozyczenia, min_wypozyczenia, max_wypozyczenia );

			zmien_tryb ( tryb::lista_ksiazek );
		}

		break;
		case 27:

		zmien_tryb(tryb::lista_ksiazek);

		break;
		default:break;
	}
}