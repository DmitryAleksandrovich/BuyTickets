#pragma once
#include "OrderingSystemState.h"

class DisplayOrder: public OrderingSystemState
{
public:
	DisplayOrder();
	~DisplayOrder();
	void MakeOrder(OrderingTickets* tPtr);
	void PayBooking(OrderingTickets* tPtr);
	void CancelBooking(OrderingTickets* tPtr);
	void HistoryOrder(OrderingTickets* tPtr);
};

