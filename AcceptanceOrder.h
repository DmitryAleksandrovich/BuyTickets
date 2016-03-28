#ifndef AcceptanceOrder_H
#define AcceptanceOrder_H
#include "OrderingSystemState.h"

class AcceptanceOrder: public OrderingSystemState
{
public:
	AcceptanceOrder();
	~AcceptanceOrder();
	void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
};

#endif // AcceptanceOrder_H