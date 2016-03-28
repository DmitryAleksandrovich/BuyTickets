#ifndef DisplayOrder_H
#define DisplayOrder_H
#include "OrderingSystemState.h"

class DisplayOrder: public OrderingSystemState
{
public:
	DisplayOrder();
	~DisplayOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
};

#endif // DisplayOrder_H