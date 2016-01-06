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
	tPtr->SetCurrent(new AcceptanceOrder());
	delete this;
}

void ShowHistoryOrder::PayBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new PayOrder());
	delete this;
}

void ShowHistoryOrder::CancelBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new CancelOrder());
	delete this;
}

void ShowHistoryOrder::ShowOrder(OrderingTickets* tPtr)
{
	std::cout << "\nDisplay order\n";
	std::cout << "Place number: " << tPtr->GetPlaceNumber() << '\n';
	std::cout << "Surname: " << tPtr->GetSurname() << '\n';
	std::cout << "Flight number: " << tPtr->GetFlightNumber() << '\n';
	std::cout << "Payment: Yes\n";
	if(tPtr->GetCheckIn() == true)
	{
		std::cout << "Check in online\n";
	}
	else if(tPtr->GetCheckIn() == false)
	{
		std::cout << "Check in offline\n";
	}

	tPtr->SetCurrent(new DisplayOrder());
	delete this;
}