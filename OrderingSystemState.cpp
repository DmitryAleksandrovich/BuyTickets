#include "OrderingSystemState.h"

OrderingSystemState::OrderingSystemState()
{

}


OrderingSystemState::~OrderingSystemState()
{
}

void OrderingSystemState::MakeOrder(shared_ptr<OrderingTickets> tPtr)
{
	assert(false);
}

void OrderingSystemState::PayBooking(shared_ptr<OrderingTickets> tPtr)
{
	assert(false);
}

void OrderingSystemState::CancelBooking(shared_ptr<OrderingTickets> tPtr)
{
	assert(false);
}

void OrderingSystemState::ShowOrder(shared_ptr<OrderingTickets> tPtr)
{
	assert(false);
}


void OrderingSystemState::HistoryOrder(shared_ptr<OrderingTickets> tPtr)
{
	assert(false);
}

/* Disaplay history order by number */
void OrderingSystemState::DisplayHistory(shared_ptr<OrderingTickets> tPtr)
{
	using boost::property_tree::ptree;
	ptree pt; // Create variable to store the tree structure
	/* Read XML and it write in variable "pt" */
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	std::cout << "\nShow history order\n";
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("orderList"))
    {
		if (v.first == "order" &&  v.second.get<std::size_t>("<xmlattr>.number") == tPtr->GetTicketNumberForHistory())
		{
			std::cout << "Place number: " << v.second.get<std::string>("Place_number") << '\n'
				<< "Surname: " << v.second.get<std::string>("Surname") << '\n'
				<< "Flight number: " << v.second.get<std::string>("Flight_number") << '\n'
				<< "Check in online: " << v.second.get<std::string>("Check_in_online") << '\n';
			if (const boost::optional<std::string>optionalTicketPayment = v.second.get_optional<std::string>("Ticket_payment"))
			{
				std::cout << "Tichet payment: " << optionalTicketPayment.get() << '\n';
			}
			if (const boost::optional<std::string>optionalTicketCancel = v.second.get_optional<std::string>("Ticket_cancel"))
			{
				std::cout << "Tichet payment: " << optionalTicketCancel.get() << '\n';
			}
		}
    }
}


