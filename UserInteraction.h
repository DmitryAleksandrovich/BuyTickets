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
private:
	static const int stateZero;
	static const int stateOne;
	static const int stateTwo;
	static const int stateThree;
	static const int stateFour;
	static const int maxNumberOrder;
};

