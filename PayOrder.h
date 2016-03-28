#ifndef PayOrder_H
#define PayOrder_H
#include "OrderingSystemState.h"

class PayOrder: public OrderingSystemState
{
public:
	PayOrder();
	~PayOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
};

#endif // PayOrder_H