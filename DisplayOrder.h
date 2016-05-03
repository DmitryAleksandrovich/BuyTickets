#ifndef DisplayOrder_H
#define DisplayOrder_H
#include "OrderingSystemState.h"

class DisplayOrder: public OrderingSystemState
{
public:
	DisplayOrder();
	~DisplayOrder();
	void MakeOrder(shared_ptr<OrderingTickets> tPtr) override;
	void PayBooking(shared_ptr<OrderingTickets> tPtr) override;
	void CancelBooking(shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(shared_ptr<OrderingTickets> tPtr) override;
};

#endif // DisplayOrder_H