#ifndef AcceptanceOrder_H
#define AcceptanceOrder_H
#include "OrderingSystemState.h"

class AcceptanceOrder: public OrderingSystemState
{
public:
	AcceptanceOrder();
	~AcceptanceOrder();
	void PayBooking(OrderingTickets* tPtr);
	void ShowOrder(OrderingTickets* tPtr);
	void HistoryOrder(OrderingTickets* tPtr);
};

#endif // AcceptanceOrder_H