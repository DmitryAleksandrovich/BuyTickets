#ifndef PayOrder_H
#define PayOrder_H
#include "OrderingSystemState.h"

class PayOrder: public OrderingSystemState
{
public:
	PayOrder();
	~PayOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
};

#endif // PayOrder_H