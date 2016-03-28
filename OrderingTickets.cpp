#include "OrderingTickets.h"
#include "AcceptanceOrder.h"
#include <string>

OrderingTickets::OrderingTickets() : placeNumber(std::rand() % maxNumberOrder + 1), checkIn(false),
	ticketPayment(false), ticketCancel(false), current(new AcceptanceOrder()), otPtr(this)
{
}

OrderingTickets::~OrderingTickets()
{
	delete current;
}

void OrderingTickets::AddOrderXml()
{
    using boost::property_tree::ptree;
	ptree pt, ptAccessory; // Create variable to store the tree structure
	/* Read XML and it write in variable "pt" */
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		ptAccessory.put("<xmlattr>.number", v.second.size()+1); // Add order number
		v.second.add_child("order", ptAccessory); // Add order
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				/* Add fields in order */
				p.second.add("Place_number", placeNumber);
				p.second.add("Surname", surname);
				p.second.add("Flight_number", flightNumber);
				if(!checkIn)
				{
					p.second.add("Check_in_online", "No");
				}
				else if(checkIn)
				{
					p.second.add("Check_in_online", "Yes");
				}
			}
		}
	}
	/* Update XML */
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<ptree::key_type>(' ', 4u));
}

void OrderingTickets::AddPayXml()
{
    using boost::property_tree::ptree;
	ptree pt;// Create variable to store the tree structure
	/* Read XML and it write in variable "pt" */
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				/* Add field "Ticket_payment" in order */
				if(!ticketPayment)
				{
					p.second.put("Ticket_payment", "No");
				}
				else if(ticketPayment)
				{
					p.second.put("Ticket_payment", "Yes");
				}
			}
		}
	}
	/* Update XML */
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<ptree::key_type>(' ', 4u));
}

void OrderingTickets::AddCancelXml()
{
    using boost::property_tree::ptree;
	ptree pt;// Create variable to store the tree structure
	/* Read XML and it write in variable "pt" */
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			if (p.second.get<std::size_t>("<xmlattr>.number") == v.second.size())
			{
				/* Add field "Ticket_payment" in order */
				if(!ticketCancel)
				{
					p.second.put("Ticket_cancel", "No");
				}
				else if(ticketCancel)
				{
					p.second.put("Ticket_cancel", "Yes");
				}
			}
		}
	}
	/* Update XML */
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
	placeNumber = std::stoi(pNumber,&sz); // Conversion string to int
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

void OrderingTickets::SetTicketNumberForHistory(int pNumberForHistory)
{
	ticketNumberForHistory = pNumberForHistory;
}

void OrderingTickets::SetCurrent(OrderingSystemState* tPtr)
{
	current = tPtr;
}

void OrderingTickets::MakeOrder()
{
	current->MakeOrder(otPtr);
}

void OrderingTickets::PayBooking()
{
	current->PayBooking(otPtr);
}

void OrderingTickets::CancelBooking()
{
	current->CancelBooking(otPtr);
}

void OrderingTickets::ShowOrder()
{
	current->ShowOrder(otPtr);
}

void OrderingTickets::HistoryOrder()
{
	current->HistoryOrder(otPtr);
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

int OrderingTickets::GetTicketNumberForHistory() const
{
	return ticketNumberForHistory;
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