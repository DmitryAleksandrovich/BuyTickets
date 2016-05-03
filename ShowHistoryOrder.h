#ifndef ShowHistoryOrder_H
#define ShowHistoryOrder_H
#include "OrderingSystemState.h"

class ShowHistoryOrder: public OrderingSystemState
{
public:
	ShowHistoryOrder();
	~ShowHistoryOrder();
	void MakeOrder(shared_ptr<OrderingTickets> tPtr) override;
	void PayBooking(shared_ptr<OrderingTickets> tPtr) override;
	void CancelBooking(shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(shared_ptr<OrderingTickets> tPtr) override;
};

#endif // ShowHistoryOrder_H