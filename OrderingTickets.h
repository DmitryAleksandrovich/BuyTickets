#ifndef OrderingTickets_H
#define OrderingTickets_H
#include "OrderingSystemState.h"
#include <iostream>
#include <memory>

class OrderingSystemState;
class AcceptanceOrder;
class PayOrder;
class CancelOrder;
class DisplayOrder;
class ShowHistoryOrder;

class OrderingTickets
{
public:
	OrderingTickets();
	~OrderingTickets();
	void SetCurrent(OrderingSystemState* tPtr); // Sets the current state
	void MakeOrder(); // Make order (booking)
	void PayBooking(); // Payment booking
	void CancelBooking();
	void ShowOrder(); // Show info about current oreder
	void HistoryOrder(); // Show history order selected
	void SetCheckIn(std::string const& str); // Online order
	void SetCheckIn(std::string const& pNumber, std::string const& str); // Offline order
	void SetTicketPayment(bool tPayment);
	void SetTicketCancel(bool tCancel);
	void SetPlaceNumber(int pNumber);
	void SetTicketNumberForHistory(int pNumberForHistory);
	int GetPlaceNumber() const;
	std::string GetSurname() const;
	int GetFlightNumber() const;
	bool GetCheckIn() const;
	bool GetTicketPayment() const;
	bool GetTicketCancel() const;
	int GetTicketNumberForHistory() const;
	void AddOrderXml(); // Add initial order in XML
	void AddPayXml(); // Add payment booking in XML
	void AddCancelXml(); // Add cancel booking in XML
private:
	class OrderingSystemState* current; // Current state
	std::tr1::shared_ptr<OrderingTickets>otPtr;
	int placeNumber;
	std::string surname;
	bool checkIn;
	bool ticketPayment;
	bool ticketCancel;
	int ticketNumberForHistory; // Ticket number to restore order history
	enum{maxNumberOrder = 10};
	enum{flightNumber = 312};
};

#endif // OrderingTickets_H