#include "ShowHistoryOrder.h"
#include "AcceptanceOrder.h"
#include "PayOrder.h"
#include "CancelOrder.h"
#include "DisplayOrder.h"

ShowHistoryOrder::ShowHistoryOrder()
{
}


ShowHistoryOrder::~ShowHistoryOrder()
{
}

void ShowHistoryOrder::MakeOrder(OrderingTickets* tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
	delete this;
}

void ShowHistoryOrder::PayBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
	delete this;
}

void ShowHistoryOrder::CancelBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
	delete this;
}

void ShowHistoryOrder::ShowOrder(OrderingTickets* tPtr)
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