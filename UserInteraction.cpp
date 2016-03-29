#include "UserInteraction.h"

using namespace std;

const int UserInteraction::maxNumberOrder = 10;
const int UserInteraction::nulledFactor = -1;

UserInteraction::UserInteraction() : appNumber(stateZero), state(stateZero), correctData(true)
{
}


UserInteraction::~UserInteraction()
{
}

void UserInteraction::ReadDB()
{
	using boost::property_tree::ptree;
	ptree pt; // Create variable to store the tree structure
	/* Read XML and it write in variable "pt" */
	boost::property_tree::read_xml("HistoryOrder.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
	BOOST_FOREACH(auto &v, pt)
	{
		BOOST_FOREACH(ptree::value_type &p, v.second)
		{
			++appNumber; // Increase the count of the number of orders
			/* Checks for tag in XML */
			const boost::optional<std::string>optionalTicketCancel = p.second.get_optional<std::string>("Ticket_cancel");
			if (!optionalTicketCancel.is_initialized())
			{
				busyPlace.push_back(p.second.get<int>("Place_number"));
			}
		}
	}
}

void UserInteraction::InputMenu(OrderingTickets& ob)
{
	string str;
	while(1)
	{
		if(busyPlace.size() == maxNumberOrder)
		{
			cout << "Not free place!\n";
			state = 1;
			break;
		}
		cout << "\nHow do you want check in: online or offline? Enter 0/1: ";
		cin >> str;
		if(str == "0")
		{
			cout << "\nBusy place: ";
			for(unsigned i = 0; i < busyPlace.size(); ++i)
			{
				cout << busyPlace[i] << ", ";
			}
			cout << "\nSelect a seat from 1 to 10: ";
			cin >> pNumber;
			for(unsigned i = 0; i < busyPlace.size(); ++i)
			{
				if(stoi(pNumber,&sz) == busyPlace[i])
				{
					correctData = false;
				}
			}
			if(!correctData)
			{
				cout << "\nEnter correct data!\n";
				continue;
			}
			cout << "Enter your surname: ";
			cin >> str;
			ob.SetCheckIn(pNumber, str);
			ob.AddOrderXml(); // Add order information in XML
			busyPlace.push_back(ob.GetPlaceNumber()); // Add busy place number in vector
			++appNumber; // Increase the count the number of orders
			break;
		}
		else if(str == "1")
		{
			for(unsigned i = 0; i < busyPlace.size(); ++i)
			{
				if(ob.GetPlaceNumber() == busyPlace[i])
				{
					ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
					i = nulledFactor; // In the next iteration i == 0
				}
			}
			cout << "Enter your surname: ";
			cin >> str;
			ob.SetCheckIn(str);
			ob.AddOrderXml(); // Add order information in XML
			busyPlace.push_back(ob.GetPlaceNumber()); // Add busy place number in vector
			++appNumber; // Increase the count the number of orders
			break;
		}
		else
		{
			cout << "\nEnter correct data!\n";
			continue;
		}
	}
}

void UserInteraction::PaymentOrder(OrderingTickets& ob)
{
	state = stateOne; // Change state
	ob.SetTicketPayment(true);
	ob.SetTicketCancel(false);
	ob.PayBooking(); // Payment booking
	ob.AddPayXml(); // Add payment in XML
	cout << "Thank you for your order!\n";
}

void UserInteraction::PreparationOrder(OrderingTickets& ob)
{
	ob.SetTicketPayment(false);
	ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
	state = stateZero; // Change state
	ob.MakeOrder();
}

void UserInteraction::CheckOnlineFreeSeat(OrderingTickets& ob)
{
	cout << "\nBusy place: ";
	for(unsigned i = 0; i < busyPlace.size(); ++i)
	{
		cout << busyPlace[i] << ", ";
	}
	cout << endl;
	cout << "Select a free seat: ";
	cin >> pNumber;
	for(unsigned i = 0; i < busyPlace.size(); ++i)
	{
		if(stoi(pNumber,&sz) == busyPlace[i])
		{
			correctData = false;
		}
	}
}

void UserInteraction::OnlineOrder(OrderingTickets& ob, string const& str)
{
	ob.SetCheckIn(pNumber, str);
	ob.AddOrderXml();
	busyPlace.push_back(ob.GetPlaceNumber()); // Add busy place number in vector
	appNumber++; // Increase the count the number of orders
}

void UserInteraction::OfflineOrder(OrderingTickets& ob)
{
	std::string str;
	for(unsigned i = 0; i < busyPlace.size(); ++i)
	{
		if(ob.GetPlaceNumber() == busyPlace[i])
		{
			ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
			i = nulledFactor; // In the next iteration i == 0
		}
	}
	cout << "Enter your surname: ";
	cin >> str;
	busyPlace.push_back(ob.GetPlaceNumber()); // Add busy place number in vector
	ob.SetCheckIn(str);
	ob.AddOrderXml(); // Add offline order in XML
	appNumber++; // Increase the count the number of orders
}

void UserInteraction::LohicaCancelOrder(OrderingTickets& ob)
{
	busyPlace.erase(busyPlace.end()-1);
	state = stateTwo; // Change state
	ob.SetTicketCancel(true);
	ob.SetTicketPayment(false);
	ob.CancelBooking();
	ob.AddCancelXml(); // Add cancel booking in XML
	cout << "Thank you! You cancel the order!\n";
}

void UserInteraction::ShowInfo(OrderingTickets& ob)
{
	ReadDB();
	InputMenu(ob);
	string str;
	while(1)
	{
		switch(state)
		{
			case stateZero: // State zero: make order
				cout << "\nTo pay for the ticket, press 1:\n";
				cout << "To display information to the screen, press 2:\n";
				cout << "To display the history of the application, press 3:\n";
				cout << "Enter 1, 2 or 3: ";
				cin >> str;
				if(str == "1")
				{
					cout << "Ticket price is 200 dollars. Do you realy want to pay the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						PaymentOrder(ob);
					}
					else if(str == "N" || str == "n")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "2")
				{
					state = stateThree;
					ob.ShowOrder();
				}
				else if(str == "3")
				{
					state = stateFour;
					cout << "Enter palce number from 1 to " << appNumber << ": ";
					cin >> str;
					int pNumberForHistory = std::stoi(str,&sz);
					if(pNumberForHistory >= 1 && pNumberForHistory <= appNumber)
					{
						ob.SetTicketNumberForHistory(pNumberForHistory);
						ob.HistoryOrder();	
					}
					else
					{
						cout << "\nEnter correct data!\n";
						break;
					}
				}
				else
				{
					cout << "\nEnter correct data!\n";
					continue;
				}
				break;
			case stateOne: // State one: pay order
				cout << "\nTo commit the order, press 1:\n";
				cout << "To cancel the order, press 2:\n";
				cout << "To display information to the screen, press 3:\n";
				cout << "To display the history of the application, press 4:\n";
				cout << "Enter 1, 2, 3 or 4: ";
				cin >> str;
				if(str == "1")
				{
					ob.SetTicketPayment(false);
					ob.SetTicketCancel(false);
					if(busyPlace.size() == maxNumberOrder)
					{
						cout << "Not free place!\n";
						break;
					}
					PreparationOrder(ob);
					cin >> str;
					if(str == "0")
					{
						CheckOnlineFreeSeat(ob);
						if(!correctData)
						{
							state = stateOne;
							cout << "\nEnter correct data!\n";
							break;
						}
						cout << "Enter your surname: ";
						cin >> str;
						OnlineOrder(ob, str);
					}
					else if(str == "1")
					{
						OfflineOrder(ob);
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "2")
				{
					if(ob.GetTicketPayment() == false)
					{
						cout << "You don't pay the order! You can't cancel the order!\n";
						break;
					}
					cout << "If you cancel the order then you will get 150 dollars back. " 
						 << "Do you realy want to cancel the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						LohicaCancelOrder(ob);
					}
					else if(str == "N" || str == "n")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "3")
				{
					state = stateThree;
					ob.ShowOrder();
				}
				else if(str == "4")
				{
					state = stateFour;
					cout << "Enter palce number from 1 to " << appNumber << ": ";
					cin >> str;
					int pNumberForHistory = std::stoi(str,&sz);
					if(pNumberForHistory >= 1 && pNumberForHistory <= appNumber)
					{
						ob.SetTicketNumberForHistory(pNumberForHistory);
						ob.HistoryOrder();	
					}
					else
					{
						cout << "\nEnter correct data!\n";
						break;
					}
				}
				else
				{
					cout << "\nEnter correct data!\n";
					continue;
				}
				break;
			case stateTwo: // State two: cancel booking
				cout << "\nTo commit the order, press 1:\n";
				cout << "To display information to the screen, press 2:\n";
				cout << "To display the history of the application, press 3:\n";
				cout << "Enter 1, 2 or 3: ";
				cin >> str;
				if(str == "1")
				{
					ob.SetTicketPayment(false);
					ob.SetTicketCancel(false);
					if(busyPlace.size() == maxNumberOrder)
					{
						cout << "Not free place!\n";
						break;
					}
					PreparationOrder(ob);
					cin >> str;
					if(str == "0")
					{
						CheckOnlineFreeSeat(ob);
						if(!correctData)
						{
							cout << "\nEnter correct data!\n";
							break;
						}
						cout << "Enter your surname: ";
						cin >> str;
						OnlineOrder(ob, str);
					}
					else if(str == "1")
					{
						OfflineOrder(ob);
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "2")
				{
					state = stateThree;
					ob.ShowOrder();
				}
				else if(str == "3")
				{
					state = stateFour;
					cout << "Enter palce number from 1 to " << appNumber << ": ";
					cin >> str;
					int pNumberForHistory = std::stoi(str,&sz);
					if(pNumberForHistory >= 1 && pNumberForHistory <= appNumber)
					{
						ob.SetTicketNumberForHistory(pNumberForHistory);
						ob.HistoryOrder();	
					}
					else
					{
						cout << "\nEnter correct data!\n";
						break;
					}
				}
				else
				{
					cout << "\nEnter correct data!\n";
					continue;
				}
				break;
			case stateThree: // State three: display information about order
				cout << "\nTo commit the order, press 1:\n";
				cout << "To pay for the ticket, press 2:\n";
				cout << "To cancel the order, press 3:\n";
				cout << "To display the history of the application, press 4:\n";
				cout << "Enter 1, 2, 3 or 4: ";
				cin >> str;
				if(str == "1")
				{
					ob.SetTicketPayment(false);
					ob.SetTicketCancel(false);
					if(busyPlace.size() == maxNumberOrder)
					{
						cout << "Not free place!\n";
						break;
					}
					PreparationOrder(ob);
					cin >> str;
					if(str == "0")
					{
						CheckOnlineFreeSeat(ob);
						if(!correctData)
						{
							cout << "\nEnter correct data!\n";
							break;
						}
						cout << "Enter your surname: ";
						cin >> str;
						OnlineOrder(ob, str);
					}
					else if(str == "1")
					{
						OfflineOrder(ob);
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "2")
				{
					cout << "Ticket price is 200 dollars. Do you realy want to pay the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						PaymentOrder(ob);
					}
					else if(str == "N" || str == "n")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "3")
				{
					if(ob.GetTicketPayment() == false)
					{
						cout << "You don't pay the order! You can't cancel the order!\n";
						break;
					}
					cout << "If you cancel the order then you will get 150 dollars back. " 
						 << "Do you realy want to cancel the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						LohicaCancelOrder(ob);
					}
					else if(str == "N" || str == "n")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "4")
				{
					state = stateFour;
					cout << "Enter palce number from 1 to " << appNumber << ": ";
					cin >> str;
					int pNumberForHistory = std::stoi(str,&sz);
					if(pNumberForHistory >= 1 && pNumberForHistory <= appNumber)
					{
						ob.SetTicketNumberForHistory(pNumberForHistory);
						ob.HistoryOrder();	
					}
					else
					{
						cout << "\nEnter correct data!\n";
						break;
					}
				}
				else
				{
					cout << "\nEnter correct data!\n";
					continue;
				}
				break;
			case stateFour: // State four: display history 
				cout << "\nTo commit the order, press 1:\n";
				cout << "To pay for the ticket, press 2:\n";
				cout << "To cancel the order, press 3:\n";
				cout << "To display information to the screen, press 4:\n";
				cout << "Enter 1, 2, 3 or 4: ";
				cin >> str;
				if(str == "1")
				{
					ob.SetTicketPayment(false);
					ob.SetTicketCancel(false);
					if(busyPlace.size() == maxNumberOrder)
					{
						cout << "Not free place!\n";
						break;
					}
					PreparationOrder(ob);
					cin >> str;
					if(str == "0")
					{
						CheckOnlineFreeSeat(ob);
						if(!correctData)
						{
							cout << "\nEnter correct data!\n";
							break;
						}
						cout << "Enter your surname: ";
						cin >> str;
						OnlineOrder(ob, str);
					}
					else if(str == "1")
					{
						OfflineOrder(ob);
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "2")
				{
					cout << "Ticket price is 200 dollars. Do you realy want to pay the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						PaymentOrder(ob);
					}
					else if(str == "N" || str == "y")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "3")
				{
					if(ob.GetTicketPayment() == false)
					{
						cout << "You don't pay the order! You can't cancel the order!\n";
						break;
					}
					cout << "If you cancel the order then you will get 150 dollars back. " 
						 << "Do you realy want to cancel the ticket (Y/N)?\n";
					cin >> str;
					if(str == "Y" || str == "y")
					{
						LohicaCancelOrder(ob);
					}
					else if(str == "N" || str == "n")
					{
						break;
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
				}
				else if(str == "4")
				{
					state = stateThree;
					ob.ShowOrder();
				}
				else
				{
					cout << "\nEnter correct data!\n";
					continue;
				}
				break;
		}
	}
}
