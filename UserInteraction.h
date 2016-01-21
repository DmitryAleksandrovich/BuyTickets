#pragma once
#include "OrderingTickets.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UserInteraction
{
public:
	UserInteraction();
	~UserInteraction();
	void ShowInfo(OrderingTickets& ob);
	void ReadDB();
	void InputMenu(OrderingTickets& ob);
	void PaymentOrder(OrderingTickets& ob);
	void PreparationOrder(OrderingTickets& ob);
	void CheckOnlineFreeSeat(OrderingTickets& ob);
	void OnlineOrder(OrderingTickets& ob, std::string const& str);
	void OfflineOrder(OrderingTickets& ob);
	void LohicaCancelOrder(OrderingTickets& ob);
private:
	static const int stateZero;
	static const int stateOne;
	static const int stateTwo;
	static const int stateThree;
	static const int stateFour;
	static const int maxNumberOrder;
	string pNumber;
	string::size_type sz;
	int appNumber;
	int state;
	bool correctData;
	vector<int> busyPlace;
};

