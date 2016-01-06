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
	tPtr->SetCurrent(new PayOrder());
	delete this;
}

void AcceptanceOrder::ShowOrder(OrderingTickets* tPtr)
{
	std::cout << "\nDisplay order\n";
	std::cout << "Place number: " << tPtr->GetPlaceNumber() << '\n';
	std::cout << "Surname: " << tPtr->GetSurname() << '\n';
	std::cout << "Flight number: " << tPtr->GetFlightNumber() << '\n';
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

void AcceptanceOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory();

	tPtr->SetCurrent(new ShowHistoryOrder());
	delete this;
}


