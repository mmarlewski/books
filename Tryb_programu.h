#pragma once

class Tryb_programu
{
	public:

	Tryb_programu ();
	~Tryb_programu ();

	virtual void zacznij () = 0;
	virtual void petla () = 0;
	virtual void zakoncz () = 0;
};