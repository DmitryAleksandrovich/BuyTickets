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
	using boost::property_tree::ptree;
	ptree pt;
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	std::cout << "\nShow history order\n";
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("orderList"))
    {
		if (v.first == "order" &&  v.second.get<std::size_t>("<xmlattr>.number") == 2)
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


