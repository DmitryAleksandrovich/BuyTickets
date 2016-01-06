#include "OrderingTickets.h"
#include "AcceptanceOrder.h"
#include <string>

OrderingTickets::OrderingTickets()
{
	placeNumber = std::rand() % 10 + 1;
	orderNumber = 1;
	flightNumber = 3122;
	checkIn = false;
	tichetPayment = false;
	ticketCancel = false;
	ticketPrice = 0;
	current = new AcceptanceOrder();
}

OrderingTickets::~OrderingTickets()
{
}

void OrderingTickets::AddOrderXml()
{
    boost::property_tree::ptree pt;

    boost::property_tree::ptree orderListNode;
    boost::property_tree::ptree orderNode;
    boost::property_tree::ptree labelNode1;
    boost::property_tree::ptree labelNode2;
    boost::property_tree::ptree labelNode3;
    boost::property_tree::ptree labelNode4;

    labelNode1.put("<xmlattr>.name", "Place number: ");
	labelNode1.put("", placeNumber);
    labelNode2.put("<xmlattr>.name", "Surname: ");
	labelNode2.put("", surname);
    labelNode3.put("<xmlattr>.name", "Flight number: ");
	labelNode3.put("", flightNumber);
    labelNode4.put("<xmlattr>.name", "Check in online: ");
	labelNode4.put("", checkIn);

    orderNode.add_child("label", labelNode1);
    orderNode.add_child("label", labelNode2);
    orderNode.add_child("label", labelNode3);
    orderNode.add_child("label", labelNode4);

    orderNode.put("<xmlattr>.name", orderNumber);

    orderListNode.add_child("order", orderNode);
    pt.add_child("orderList", orderListNode);
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<boost::property_tree::ptree::key_type>(' ', 4u));
	orderNumber++;
}

void OrderingTickets::AddPayXml()
{
    boost::property_tree::ptree pt;

    boost::property_tree::ptree orderListNode;
    boost::property_tree::ptree orderNode;
    boost::property_tree::ptree labelNode1;
    boost::property_tree::ptree labelNode2;
    boost::property_tree::ptree labelNode3;
    boost::property_tree::ptree labelNode4;
	boost::property_tree::ptree labelNode5;

    labelNode1.put("<xmlattr>.name", "Place number: ");
	labelNode1.put("", placeNumber);
    labelNode2.put("<xmlattr>.name", "Surname: ");
	labelNode2.put("", surname);
    labelNode3.put("<xmlattr>.name", "Flight number: ");
	labelNode3.put("", flightNumber);
    labelNode4.put("<xmlattr>.name", "Check in online: ");
	labelNode4.put("", checkIn);
	labelNode5.put("<xmlattr>.name", "Payment: ");
	labelNode5.put("", tichetPayment);

    orderNode.add_child("label", labelNode1);
    orderNode.add_child("label", labelNode2);
    orderNode.add_child("label", labelNode3);
    orderNode.add_child("label", labelNode4);
	orderNode.add_child("label", labelNode5);

    orderNode.put("<xmlattr>.name", orderNumber);

    orderListNode.add_child("order", orderNode);
    pt.add_child("orderList", orderListNode);
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<boost::property_tree::ptree::key_type>(' ', 5u));
}

void OrderingTickets::AddCancelXml()
{
    boost::property_tree::ptree pt;

    boost::property_tree::ptree orderListNode;
    boost::property_tree::ptree orderNode;
    boost::property_tree::ptree labelNode1;
    boost::property_tree::ptree labelNode2;
    boost::property_tree::ptree labelNode3;
    boost::property_tree::ptree labelNode4;
	boost::property_tree::ptree labelNode5;
	boost::property_tree::ptree labelNode6;

    labelNode1.put("<xmlattr>.name", "Place number: ");
	labelNode1.put("", placeNumber);
    labelNode2.put("<xmlattr>.name", "Surname: ");
	labelNode2.put("", surname);
    labelNode3.put("<xmlattr>.name", "Flight number: ");
	labelNode3.put("", flightNumber);
    labelNode4.put("<xmlattr>.name", "Check in online: ");
	labelNode4.put("", checkIn);
	labelNode5.put("<xmlattr>.name", "Payment: ");
	labelNode5.put("", tichetPayment);
	labelNode5.put("<xmlattr>.name", "Cancel booking: ");
	labelNode5.put("", ticketCancel);

    orderNode.add_child("label", labelNode1);
    orderNode.add_child("label", labelNode2);
    orderNode.add_child("label", labelNode3);
    orderNode.add_child("label", labelNode4);
	orderNode.add_child("label", labelNode5);
	orderNode.add_child("label", labelNode6);

    orderNode.put("<xmlattr>.name", orderNumber);

    orderListNode.add_child("order", orderNode);
    pt.add_child("orderList", orderListNode);
    write_xml("HistoryOrder.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<boost::property_tree::ptree::key_type>(' ', 6u));
}

void OrderingTickets::SetCheckIn(std::string const& str)
{
	placeNumber = std::rand() % 10 + 1;
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
	tichetPayment = tPayment;
}

void OrderingTickets::SetTicketCancel(bool tCancel)
{
	ticketCancel = tCancel;
}

void OrderingTickets::SetPlaceNumber(int pNumber)
{
	placeNumber = pNumber;
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

bool OrderingTickets::GetCheckIn() const
{
	return checkIn;
}

bool OrderingTickets::GetTicketPayment() const
{
	return tichetPayment;
}

bool OrderingTickets::GetTicketCancel() const
{
	return ticketCancel;
}