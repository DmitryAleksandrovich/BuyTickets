#include "PayOrder.h"
#include "AcceptanceOrder.h"
#include "CancelOrder.h"
#include "DisplayOrder.h"
#include "ShowHistoryOrder.h"

PayOrder::PayOrder()
{
}


PayOrder::~PayOrder()
{
}

void PayOrder::MakeOrder(OrderingTickets* tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
	delete this;
}

void PayOrder::CancelBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
	delete this;
}


void PayOrder::ShowOrder(OrderingTickets* tPtr)
{
	std::cout << "\nDisplay order\n";
	std::cout << "Place number: " << tPtr->GetPlaceNumber() << '\n';
	std::cout << "Surname: " << tPtr->GetSurname() << '\n';
	std::cout << "Flight number: " << tPtr->GetFlightNumber() << '\n';
	if(tPtr->GetCheckIn() == 1)
	{
		std::cout << "Check in online\n";
	}
	else if(tPtr->GetCheckIn() == 0)
	{
		std::cout << "Check in offline\n";
	}

	if(tPtr->GetTicketPayment() == 1)
	{
		std::cout << "Ticket payment: Yes\n";
	}
	else if(tPtr->GetTicketPayment() == 0)
	{
		std::cout << "Ticket payment: No\n";
	}

	if(tPtr->GetTicketCancel() == 1)
	{
		std::cout << "Ticket cancel: Yes\n";
	}
	else if(tPtr->GetTicketCancel() == 0)
	{
		std::cout << "Ticket cancel: No\n";
	}

	tPtr->SetCurrent(new DisplayOrder()); // Chage state on "DisplayOrder"
	delete this;
}


void PayOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
	delete this;
}

