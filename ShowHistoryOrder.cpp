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

void ShowHistoryOrder::MakeOrder(shared_ptr<OrderingTickets> tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
}

void ShowHistoryOrder::PayBooking(shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
}

void ShowHistoryOrder::CancelBooking(shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
}

void ShowHistoryOrder::ShowOrder(shared_ptr<OrderingTickets> tPtr)
{
	std::cout << "\nDisplay order\n";
	std::cout << "Place number: " << tPtr->GetPlaceNumber() << '\n';
	std::cout << "Surname: " << tPtr->GetSurname() << '\n';
	std::cout << "Flight number: " << tPtr->GetFlightNumber() << '\n';
	if(tPtr->GetCheckIn())
	{
		std::cout << "Check in online\n";
	}
	else
	{
		std::cout << "Check in offline\n";
	}

	if(tPtr->GetTicketPayment())
	{
		std::cout << "Ticket payment: Yes\n";
	}
	else
	{
		std::cout << "Ticket payment: No\n";
	}

	if(tPtr->GetTicketCancel())
	{
		std::cout << "Ticket cancel: Yes\n";
	}
	else
	{
		std::cout << "Ticket cancel: No\n";
	}

	tPtr->SetCurrent(new DisplayOrder()); // Chage state on "DisplayOrder"
}
