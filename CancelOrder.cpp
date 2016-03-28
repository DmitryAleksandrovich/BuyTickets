#include "CancelOrder.h"
#include "AcceptanceOrder.h"
#include "DisplayOrder.h"
#include "ShowHistoryOrder.h"

CancelOrder::CancelOrder()
{
}


CancelOrder::~CancelOrder()
{
}

void CancelOrder::MakeOrder(OrderingTickets* tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
	delete this;
}

void CancelOrder::ShowOrder(OrderingTickets* tPtr)
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

void CancelOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
	delete this;
}