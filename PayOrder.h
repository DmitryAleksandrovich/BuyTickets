#ifndef PayOrder_H
#define PayOrder_H
#include "OrderingSystemState.h"

class PayOrder: public OrderingSystemState
{
public:
	PayOrder();
	~PayOrder();
	void MakeOrder(shared_ptr<OrderingTickets> tPtr) override;
	void CancelBooking(shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(shared_ptr<OrderingTickets> tPtr) override;
};

#endif // PayOrder_H