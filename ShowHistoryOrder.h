#ifndef ShowHistoryOrder_H
#define ShowHistoryOrder_H
#include "OrderingSystemState.h"

class ShowHistoryOrder: public OrderingSystemState
{
public:
	ShowHistoryOrder();
	~ShowHistoryOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
};

#endif // ShowHistoryOrder_H