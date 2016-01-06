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
	tPtr->SetCurrent(new AcceptanceOrder());
	delete this;
}

void PayOrder::CancelBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new CancelOrder());
	delete this;
}


void PayOrder::ShowOrder(OrderingTickets* tPtr)
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


void PayOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory();

	tPtr->SetCurrent(new ShowHistoryOrder());
	delete this;
}

