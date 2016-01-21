#pragma once
#include "OrderingSystemState.h"
#include <iostream>

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
	void SetCurrent(OrderingSystemState* tPtr);
	void MakeOrder();
	void PayBooking();
	void CancelBooking();
	void ShowOrder();
	void HistoryOrder();
	void SetCheckIn(std::string const& str);
	void SetCheckIn(std::string const& pNumber, std::string const& str);
	void SetTicketPayment(bool tPayment);
	void SetTicketCancel(bool tCancel);
	void SetPlaceNumber(int pNumber);
	void SetPlaceNumberForHistory(int pNumberForHistory);
	int GetPlaceNumber() const;
	std::string GetSurname() const;
	int GetFlightNumber() const;
	bool GetCheckIn() const;
	bool GetTicketPayment() const;
	bool GetTicketCancel() const;
	int GetPlaceNumberForHistory() const;
	void AddOrderXml();
	void AddPayXml();
	void AddCancelXml();
private:
	class OrderingSystemState* current;
	int placeNumber;
	std::string surname;
	int flightNumber;
	bool checkIn;
	bool ticketPayment;
	bool ticketCancel;
	int placeNumberForHistory;
};

