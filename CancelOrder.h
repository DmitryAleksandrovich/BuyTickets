#pragma once
#include "OrderingSystemState.h"

class CancelOrder: public OrderingSystemState
{
public:
	CancelOrder();
	~CancelOrder();
	void MakeOrder(OrderingTickets* tPtr);
	void ShowOrder(OrderingTickets* tPtr);
	void HistoryOrder(OrderingTickets* tPtr);
};

