#ifndef PayOrder_H
#define PayOrder_H
#include "OrderingSystemState.h"

class PayOrder: public OrderingSystemState
{
public:
	PayOrder();
	~PayOrder();
	void MakeOrder(OrderingTickets* tPtr);
	void CancelBooking(OrderingTickets* tPtr);
	void ShowOrder(OrderingTickets* tPtr);
	void HistoryOrder(OrderingTickets* tPtr);
};

#endif // PayOrder_H