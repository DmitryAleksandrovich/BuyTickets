#ifndef ShowHistoryOrder_H
#define ShowHistoryOrder_H
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

#endif // ShowHistoryOrder_H