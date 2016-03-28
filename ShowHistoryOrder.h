#ifndef ShowHistoryOrder_H
#define ShowHistoryOrder_H
#include "OrderingSystemState.h"

class ShowHistoryOrder: public OrderingSystemState
{
public:
	ShowHistoryOrder();
	~ShowHistoryOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
};

#endif // ShowHistoryOrder_H