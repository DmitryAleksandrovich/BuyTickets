#pragma once
#include "OrderingSystemState.h"

class ShowHistoryOrder: public OrderingSystemState
{
public:
	ShowHistoryOrder();
	~ShowHistoryOrder();
	void MakeOrder(OrderingTickets* tPtr);
	void PayBooking(OrderingTickets* tPtr);
	void CancelBooking(OrderingTickets* tPtr);
	void ShowOrder(OrderingTickets* tPtr);
};

