#ifndef CASHBOX_H
#define CASHBOX_H

#include <iostream>
#include <vector>

struct Ticket
{
	std::string filmName;
	short startTime;
	short endTime;

	Ticket(std::string filmName, short start, short end)
	{
		this->filmName = filmName;
		startTime = start;
		endTime = end;
	}

	std::string TicketInfo()
	{
		return "Nazwa filmu: " + this->filmName + 
			   " Termin: " + std::to_string(this->startTime) + " - " + 
			   std::to_string(this->endTime);
	}
};

class Cashbox
{
	public:
		Cashbox(int capacity);
		Cashbox(int capacity, std::vector<Ticket> tickets);

		void AddTicket(Ticket ticket);
		Ticket GetTicket();

	private:
		int _capacity;
		std::vector<Ticket> _tickets;
};

#endif 