#include "OrderingSystemState.h"

OrderingSystemState::OrderingSystemState()
{

}


OrderingSystemState::~OrderingSystemState()
{
}

void OrderingSystemState::MakeOrder(OrderingTickets* tPtr)
{
	std::cout << "Already MakeOrder\n";
}

void OrderingSystemState::PayBooking(OrderingTickets* tPtr)
{
	std::cout << "Already PayBooking\n";
}

void OrderingSystemState::CancelBooking(OrderingTickets* tPtr)
{
	std::cout << "Already CancelBooking\n";
}

void OrderingSystemState::ShowOrder(OrderingTickets* tPtr)
{
	std::cout << "Already ShowOrder\n";
}


void OrderingSystemState::HistoryOrder(OrderingTickets* tPtr)
{
	std::cout << "Already HistoryOrder\n";
}

void OrderingSystemState::DisplayHistory()
{
	std::string XML_PATH1 = "HistoryOrder.xml";
	boost::property_tree::ptree propertyTree;
    boost::property_tree::read_xml(XML_PATH1, propertyTree);
	boost::property_tree::ptree inventoryTree = propertyTree.get_child("orderList.order");
	std::cout << "\nShow history order\n";
	BOOST_FOREACH(auto &v, inventoryTree)
	{
		std::cout << v.second.get<std::string>("") << '\n';
	}
}


