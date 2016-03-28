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

void CancelOrder::MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
}

void CancelOrder::ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr)
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
}

void CancelOrder::HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
}