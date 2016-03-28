#ifndef UserInteraction_H
#define UserInteraction_H
#include "OrderingTickets.h"
#include <string>
#include <vector>

class UserInteraction
{
public:
	UserInteraction();
	~UserInteraction();
	void ShowInfo(OrderingTickets& ob); // Function is responsible for interaction with the user
	void ReadDB(); // Read data base and write to vector busy place
	void InputMenu(OrderingTickets& ob); // First input menu
	void PaymentOrder(OrderingTickets& ob); // Lohica payment order
	void PreparationOrder(OrderingTickets& ob); // Block preparation order
	void CheckOnlineFreeSeat(OrderingTickets& ob);
	void OnlineOrder(OrderingTickets& ob, std::string const& str);
	void OfflineOrder(OrderingTickets& ob);
	void LohicaCancelOrder(OrderingTickets& ob);
private:
	/* Constans states, maximum number order and nulled factor */
	enum stateMachine
	{
		stateZero = 0,
		stateOne,
		stateTwo,
		stateThree,
		stateFour
	};
	static const int maxNumberOrder;
	static const int nulledFactor;
	std::string pNumber; // Place number
	std::string::size_type sz; // Variable for conversion string to int
	int appNumber; // Count the number of orders
	int state;
	bool correctData;
	std::vector<int> busyPlace; // Storage container busy seats
};

#endif // UserInteraction_H