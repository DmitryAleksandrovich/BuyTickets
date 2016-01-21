#include "OrderingTickets.h"
#include "AcceptanceOrder.h"
#include <string>

OrderingTickets::OrderingTickets()
{
	placeNumber = std::rand() % 10 + 1;
	flightNumber = 312;
	checkIn = false;
	ticketPayment = false;
	ticketCancel = false;
	current = new AcceptanceOrder();
}

OrderingTickets::~OrderingTickets()
{
	delete current;
}

void OrderingTickets::AddOrderXml()
{
    using boost::property_tree::ptree;
	ptree pt, ptAccessory;
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		ptAccessory.put("<xmlattr>.number", v.second.size()+1);
		v.second.add_child("order", ptAccessory);
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				p.second.add("Place_number", placeNumber);
				p.second.add("Surname", surname);
				p.second.add("Flight_number", flightNumber);
				if(checkIn == false)
				{
					p.second.add("Check_in_online", "No");
				}
				else if(checkIn == true)
				{
					p.second.add("Check_in_online", "Yes");
				}
			}
		}
	}
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<ptree::key_type>(' ', 4u));
}

void OrderingTickets::AddPayXml()
{
    using boost::property_tree::ptree;
	ptree pt;
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				if(ticketPayment == false)
				{
					p.second.put("Ticket_payment", "No");
				}
				else if(ticketPayment == true)
				{
					p.second.put("Ticket_payment", "Yes");
				}
			}
		}
	}
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<ptree::key_type>(' ', 4u));
}

void OrderingTickets::AddCancelXml()
{
    using boost::property_tree::ptree;
	ptree pt;
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				if(ticketCancel == false)
				{
					p.second.put("Ticket_cancel", "No");
				}
				else if(ticketCancel == true)
				{
					p.second.put("Ticket_cancel", "Yes");
				}
			}
		}
	}
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<ptree::key_type>(' ', 4u));
}

void OrderingTickets::SetCheckIn(std::string const& str)
{
	surname = str;
	checkIn = false;
}

void OrderingTickets::SetCheckIn(std::string const& pNumber, std::string const& str)
{
	std::string::size_type sz;
	placeNumber = std::stoi(pNumber,&sz);
	surname = str;
	checkIn = true;
}

void OrderingTickets::SetTicketPayment(bool tPayment)
{
	ticketPayment = tPayment;
}

void OrderingTickets::SetTicketCancel(bool tCancel)
{
	ticketCancel = tCancel;
}

void OrderingTickets::SetPlaceNumber(int pNumber)
{
	placeNumber = pNumber;
}

void OrderingTickets::SetPlaceNumberForHistory(int pNumberForHistory)
{
	placeNumberForHistory = pNumberForHistory;
}

void OrderingTickets::SetCurrent(OrderingSystemState* tPtr)
{
	current = tPtr;
}

void OrderingTickets::MakeOrder()
{
	current->MakeOrder(this);
}

void OrderingTickets::PayBooking()
{
	current->PayBooking(this);
}

void OrderingTickets::CancelBooking()
{
	current->CancelBooking(this);
}

void OrderingTickets::ShowOrder()
{
	current->ShowOrder(this);
}

void OrderingTickets::HistoryOrder()
{
	current->HistoryOrder(this);
}

int OrderingTickets::GetPlaceNumber() const
{
	return placeNumber;
}

std::string OrderingTickets::GetSurname() const
{
	return surname;
}

int OrderingTickets::GetFlightNumber() const
{
	return flightNumber;
}

int OrderingTickets::GetPlaceNumberForHistory() const
{
	return placeNumberForHistory;
}

bool OrderingTickets::GetCheckIn() const
{
	return checkIn;
}

bool OrderingTickets::GetTicketPayment() const
{
	return ticketPayment;
}

bool OrderingTickets::GetTicketCancel() const
{
	return ticketCancel;
}