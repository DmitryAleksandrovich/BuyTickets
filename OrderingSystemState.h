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

class OrderingTickets;
/* Base class of states */
class OrderingSystemState
{
public:
	OrderingSystemState();
	virtual ~OrderingSystemState();
	virtual void MakeOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	virtual void PayBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	virtual void CancelBooking(std::tr1::shared_ptr<OrderingTickets> tPtr);
	virtual void ShowOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	virtual void HistoryOrder(std::tr1::shared_ptr<OrderingTickets> tPtr);
	void DisplayHistory(std::tr1::shared_ptr<OrderingTickets> tPtr);
};

#endif // OrderingSystemState_H