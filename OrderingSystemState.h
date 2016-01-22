#ifndef OrderingSystemState_H
#define OrderingSystemState_H
#include "OrderingTickets.h"
#include <iostream>
#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

class OrderingTickets;
/* Base class of states */
class OrderingSystemState
{
public:
	OrderingSystemState();
	virtual ~OrderingSystemState();
	virtual void MakeOrder(OrderingTickets* tPtr);
	virtual void PayBooking(OrderingTickets* tPtr);
	virtual void CancelBooking(OrderingTickets* tPtr);
	virtual void ShowOrder(OrderingTickets* tPtr);
	virtual void HistoryOrder(OrderingTickets* tPtr);
	void DisplayHistory(OrderingTickets* tPtr);
};

#endif // OrderingSystemState_H