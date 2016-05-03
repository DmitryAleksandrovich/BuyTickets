#ifndef OrderingSystemState_H
#define OrderingSystemState_H
#include "OrderingTickets.h"
#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

using std::tr1::shared_ptr;

class OrderingTickets;
/* Base class of states */
class OrderingSystemState
{
public:
	OrderingSystemState();
	virtual ~OrderingSystemState();
	virtual void MakeOrder(shared_ptr<OrderingTickets> tPtr);
	virtual void PayBooking(shared_ptr<OrderingTickets> tPtr);
	virtual void CancelBooking(shared_ptr<OrderingTickets> tPtr);
	virtual void ShowOrder(shared_ptr<OrderingTickets> tPtr);
	virtual void HistoryOrder(shared_ptr<OrderingTickets> tPtr);
	void DisplayHistory(shared_ptr<OrderingTickets> tPtr);
};

#endif // OrderingSystemState_H