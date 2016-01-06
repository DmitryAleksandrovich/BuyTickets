// BuyTickets.cpp : Defines the entry point for the console application.
//

#include "OrderingTickets.h"
#include "UserInteraction.h"

int main(int argc, char* argv[])
{
	OrderingTickets ob;
	UserInteraction uObj;
	uObj.ShowInfo(ob);
	
	return 0;
}

