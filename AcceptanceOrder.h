#ifndef AcceptanceOrder_H
#define AcceptanceOrder_H
#include "OrderingSystemState.h"

class AcceptanceOrder: public OrderingSystemState
{
public:
	AcceptanceOrder();
	~AcceptanceOrder();
	void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
};

#endif // AcceptanceOrder_H