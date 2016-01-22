#include "DisplayOrder.h"
#include "AcceptanceOrder.h"
#include "PayOrder.h"
#include "CancelOrder.h"
#include "ShowHistoryOrder.h"

DisplayOrder::DisplayOrder()
{
}


DisplayOrder::~DisplayOrder()
{
}

void DisplayOrder::MakeOrder(OrderingTickets* tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
	delete this;
}

void DisplayOrder::PayBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
	delete this;
}

void DisplayOrder::CancelBooking(OrderingTickets* tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
	delete this;
}

void DisplayOrder::HistoryOrder(OrderingTickets* tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
	delete this;
}