#ifndef AcceptanceOrder_H
#define AcceptanceOrder_H
#include "OrderingSystemState.h"

class AcceptanceOrder: public OrderingSystemState
{
public:
	AcceptanceOrder();
	~AcceptanceOrder();
	void PayBooking(shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(shared_ptr<OrderingTickets> tPtr) override;
};

#endif // AcceptanceOrder_H