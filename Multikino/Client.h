#ifndef CLIENT_H
#define CLIENT_H

#include "Cashbox.h"
#include <iostream>
#include <unistd.h> 
#include <ncurses.h>

enum ClientState
{
	/* Czeka na zakup biletu */
	WaitingForTicket = 0, 
	/* Kupuje bilet */
	BuyingTicket = 1,
	/* Czeka na film (wejście do sali) */
	WaitingForMovie = 2,
	/* Ogląda premierę */
	WatchingMovie = 3,
	/* Opuszcza Multikino */
	AfterMovie = 4
};

class Client {
	public:
		Client(std::string name, std::string surname);
		Client(std::string name, std::string surname, Ticket* ticket);

		void SetClientState(ClientState);
		ClientState GetClientState();

		std::string GetNameAndSurname();

		Ticket* GetTicket();
		void BuyTicket(Ticket* ticket);
		void DisplayInfo();
		void WatchMovie(std::string filmName);

	private:
		ClientState _clientState;
		Ticket* _ticket;
		std::string _name;
		std::string _surname;
};

#endif