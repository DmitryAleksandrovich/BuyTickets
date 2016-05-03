#ifndef CancelOrder_H
#define CancelOrder_H
#include "OrderingSystemState.h"

class CancelOrder: public OrderingSystemState
{
public:
	CancelOrder();
	~CancelOrder();
	void MakeOrder(shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(shared_ptr<OrderingTickets> tPtr) override;
};

#endif // CancelOrder_H