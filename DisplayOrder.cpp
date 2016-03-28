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

void DisplayOrder::MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	std::cout << "How do you want check in: online or offline? Enter 0/1: ";
	tPtr->SetCurrent(new AcceptanceOrder()); // Chage state on "AcceptanceOrder"
}

void DisplayOrder::PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new PayOrder()); // Chage state on "PayOrder"
}

void DisplayOrder::CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	tPtr->SetCurrent(new CancelOrder()); // Chage state on "CancelOrder"
}

void DisplayOrder::HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr)
{
	DisplayHistory(tPtr);

	tPtr->SetCurrent(new ShowHistoryOrder()); // Chage state on "ShowHistoryOrder"
}