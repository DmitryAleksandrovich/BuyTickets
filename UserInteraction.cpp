#include "UserInteraction.h"

const int UserInteraction::stateZero = 0;
const int UserInteraction::stateOne = 1;
const int UserInteraction::stateTwo = 2;
const int UserInteraction::stateThree = 3;
const int UserInteraction::stateFour = 4;
const int UserInteraction::maxNumberOrder = 10;

UserInteraction::UserInteraction(void)
{
}


UserInteraction::~UserInteraction(void)
{
}

void UserInteraction::ShowInfo(OrderingTickets& ob)
{
		string str;
		string pNumber;
		string::size_type sz;
		int state = 0;
		vector<int> busyPlace;

		while(1)
		{
			cout << "\nHow do you want check in: online or offline? Enter 0/1: ";
			cin >> str;
			if(str == "0")
			{
				cout << "Select a seat from 1 to maxNumberOrder: ";
				cin >> pNumber;
				cout << "Enter your surname: ";
				cin >> str;
				ob.SetCheckIn(pNumber, str);
				ob.AddOrderXml();
				busyPlace.push_back(ob.GetPlaceNumber());
				break;
			}
			else if(str == "1")
			{
				cout << "Enter your surname: ";
				cin >> str;
				ob.SetCheckIn(str);
				ob.AddOrderXml();
				busyPlace.push_back(ob.GetPlaceNumber());
				break;
			}
			else
			{
				cout << "\nEnter correct data!\n";
				continue;
			}
		}
	
		while(1)
		{
			bool correctData = true;
			switch(state)
			{
				case 0: // make
					cout << "\nTo pay for the ticket, press 1:\n";
					cout << "To display information to the screen, press 2:\n";
					cout << "To display the history of the application, press 3:\n";
					cout << "Enter 1, 2 or 3: ";
					cin >> str;
					if(str == "1")
					{
						cout << "Ticket price is 200 dollars. Do you realy want to pay the ticket (Y/N)?\n";
						cin >> str;
						if(str == "Y")
						{
							state = stateZero;
							ob.SetTicketPayment(true);
							ob.SetTicketCancel(false);
							ob.PayBooking();
							ob.AddPayXml();
							cout << "Thank you for your order!\n";
						}
						else if(str == "N")
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
						ob.HistoryOrder();
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
					break;
				case 1: // pay
					cout << "\nTo commit the order, press 1:\n";
					cout << "To cancel the order, press 2:\n";
					cout << "To display information to the screen, press 3:\n";
					cout << "To display the history of the application, press 4:\n";
					cout << "Enter 1, 2, 3 or 4: ";
					cin >> str;
					if(str == "1")
					{
						if(busyPlace.size() == maxNumberOrder)
						{
							cout << "Not free place!\n";
							break;
						}
						ob.SetTicketPayment(false);
						ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
						state = stateZero;
						ob.MakeOrder();
						cin >> str;
						if(str == "0")
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
							if(!correctData)
							{
								cout << "\nEnter correct data!\n";
								break;
							}
							cout << "Enter your surname: ";
							cin >> str;
							ob.SetCheckIn(pNumber, str);
							ob.AddOrderXml();
							busyPlace.push_back(ob.GetPlaceNumber());
						}
						else if(str == "1")
						{
							for(unsigned i = 0; i < busyPlace.size(); ++i)
							{
								if(ob.GetPlaceNumber() == busyPlace[i])
								{
									ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
									i = 0;
								}
							}
							cout << "Enter your surname: ";
							cin >> str;
							busyPlace.push_back(ob.GetPlaceNumber());
							ob.SetCheckIn(str);
							ob.AddOrderXml();
							
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
						if(str == "Y")
						{
							busyPlace.erase(busyPlace.end()-1);
							state = stateTwo;
							ob.SetTicketCancel(true);
							ob.SetTicketPayment(false);
							ob.CancelBooking();
							ob.AddCancelXml();
							cout << "Thank you! You cancel the order!\n";
						}
						else if(str == "N")
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
						ob.HistoryOrder();
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
					break;
				case 2: // cancel
					cout << "\nTo commit the order, press 1:\n";
					cout << "To display information to the screen, press 2:\n";
					cout << "To display the history of the application, press 3:\n";
					cout << "Enter 1, 2 or 3: ";
					cin >> str;
					if(str == "1")
					{
						if(busyPlace.size() == maxNumberOrder)
						{
							cout << "Not free place!\n";
							break;
						}
						ob.SetTicketPayment(false);
						state = stateZero;
						ob.MakeOrder();
						cin >> str;
						if(str == "0")
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
							if(!correctData)
							{
								cout << "\nEnter correct data!\n";
								break;
							}
							cout << "Enter your surname: ";
							cin >> str;
							ob.SetCheckIn(pNumber, str);
							busyPlace.push_back(ob.GetPlaceNumber());
						}
						else if(str == "1")
						{
							for(unsigned i = 0; i < busyPlace.size(); ++i)
							{
								if(ob.GetPlaceNumber() == busyPlace[i])
								{
									ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
									i = 0;
								}
							}
							cout << "Enter your surname: ";
							cin >> str;
							busyPlace.push_back(ob.GetPlaceNumber());
							ob.SetCheckIn(str);
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
						ob.HistoryOrder();
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
					break;
				case 3: // display
					cout << "\nTo commit the order, press 1:\n";
					cout << "To pay for the ticket, press 2:\n";
					cout << "To cancel the order, press 3:\n";
					cout << "To display the history of the application, press 4:\n";
					cout << "Enter 1, 2, 3 or 4: ";
					cin >> str;
					if(str == "1")
					{
						if(busyPlace.size() == maxNumberOrder)
						{
							cout << "Not free place!\n";
							break;
						}
						ob.SetTicketPayment(false);
						state = stateZero;
						ob.MakeOrder();
						cin >> str;
						if(str == "0")
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
							if(!correctData)
							{
								cout << "\nEnter correct data!\n";
								break;
							}
							cout << "Enter your surname: ";
							cin >> str;
							ob.SetCheckIn(pNumber, str);
							busyPlace.push_back(ob.GetPlaceNumber());
						}
						else if(str == "1")
						{
							for(unsigned i = 0; i < busyPlace.size(); ++i)
							{
								if(ob.GetPlaceNumber() == busyPlace[i])
								{
									ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
									i = 0;
								}
							}
							cout << "Enter your surname: ";
							cin >> str;
							busyPlace.push_back(ob.GetPlaceNumber());
							ob.SetCheckIn(str);
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
						if(str == "Y")
						{
							state = stateOne;
							ob.SetTicketPayment(true);
							ob.SetTicketCancel(false);
							ob.PayBooking();
							ob.AddPayXml();
							cout << "Thank you for your order!\n";
						}
						else if(str == "N")
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
						if(str == "Y")
						{
							busyPlace.erase(busyPlace.end()-1);
							state = stateTwo;
							ob.SetTicketCancel(true);
							ob.SetTicketPayment(false);
							ob.CancelBooking();
							ob.AddCancelXml();
							cout << "Thank you! You cancel the order!\n";
						}
						else if(str == "N")
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
						ob.HistoryOrder();
					}
					else
					{
						cout << "\nEnter correct data!\n";
						continue;
					}
					break;
				case 4: // history
					cout << "\nTo commit the order, press 1:\n";
					cout << "To pay for the ticket, press 2:\n";
					cout << "To cancel the order, press 3:\n";
					cout << "To display information to the screen, press 4:\n";
					cout << "Enter 1, 2, 3 or 4: ";
					cin >> str;
					if(str == "1")
					{
						if(busyPlace.size() == maxNumberOrder)
						{
							cout << "Not free place!\n";
							break;
						}
						ob.SetTicketPayment(false);
						state = stateZero;
						ob.MakeOrder();
						cin >> str;
						if(str == "0")
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
							if(!correctData)
							{
								cout << "\nEnter correct data!\n";
								break;
							}
							cout << "Enter your surname: ";
							cin >> str;
							ob.SetCheckIn(pNumber, str);
							busyPlace.push_back(ob.GetPlaceNumber());
						}
						else if(str == "1")
						{
							for(unsigned i = 0; i < busyPlace.size(); ++i)
							{
								if(ob.GetPlaceNumber() == busyPlace[i])
								{
									ob.SetPlaceNumber(rand() % maxNumberOrder + 1);
									i = 0;
								}
							}
							cout << "Enter your surname: ";
							cin >> str;
							busyPlace.push_back(ob.GetPlaceNumber());
							ob.SetCheckIn(str);
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
						if(str == "Y")
						{
							state = stateOne;
							ob.SetTicketPayment(true);
							ob.SetTicketCancel(false);
							ob.PayBooking();
							ob.AddPayXml();
							cout << "Thank you for your order!\n";
						}
						else if(str == "N")
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
						if(str == "Y")
						{
							busyPlace.erase(busyPlace.end()-1);
							state = stateTwo;
							ob.SetTicketCancel(true);
							ob.SetTicketPayment(false);
							ob.CancelBooking();
							ob.AddCancelXml();
							cout << "Thank you! You cancel the order!\n";
						}
						else if(str == "N")
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
