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

void DisplayOrder::MakeOrder(shared_ptr<OrderingTickets> tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
}

void DisplayOrder::PayBooking(shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
}

void DisplayOrder::CancelBooking(shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
}

void DisplayOrder::HistoryOrder(shared_ptr<OrderingTickets> tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
}