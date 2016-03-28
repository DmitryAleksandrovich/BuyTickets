#ifndef CancelOrder_H
#define CancelOrder_H
#include "OrderingSystemState.h"

class CancelOrder: public OrderingSystemState
{
public:
	CancelOrder();
	~CancelOrder();
	void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
	void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr) override;
};

#endif // CancelOrder_H