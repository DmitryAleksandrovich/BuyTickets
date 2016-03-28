#include "AcceptanceOrder.h"
#include "PayOrder.h"
#include "DisplayOrder.h"
#include "ShowHistoryOrder.h"

AcceptanceOrder::AcceptanceOrder()
{
}


AcceptanceOrder::~AcceptanceOrder()
{
}

void AcceptanceOrder::PayBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
	delete this;
}

void AcceptanceOrder::ShowOrder(OrderingTickets* tPtr)
{
	std::cout << "\nDisplay order\n";
	std::cout << "Place number: " << tPtr->GetPlaceNumber() << '\n';
	std::cout << "Surname: " << tPtr->GetSurname() << '\n';
	std::cout << "Flight number: " << tPtr->GetFlightNumber() << '\n';
	if(tPtr->GetCheckIn())
	{
		std::cout << "Check in online\n";
	}
	else if(!tPtr->GetCheckIn())
	{
		std::cout << "Check in offline\n";
	}

	if(tPtr->GetTicketPayment())
	{
		std::cout << "Ticket payment: Yes\n";
	}
	else if(!tPtr->GetTicketPayment())
	{
		std::cout << "Ticket payment: No\n";
	}

	if(tPtr->GetTicketCancel())
	{
		std::cout << "Ticket cancel: Yes\n";
	}
	else if(!tPtr->GetTicketCancel())
	{
		std::cout << "Ticket cancel: No\n";
	}

	tPtr->SetCurrent(new DisplayOrder()); // Chage state on "DisplayOrder"
	delete this;
}

void AcceptanceOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
	delete this;
}


