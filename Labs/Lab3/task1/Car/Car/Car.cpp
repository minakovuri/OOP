#include "pch.h"
#include <iostream>
#include "CCar.h"
#include "RemoteControl.h"

int main()
{
	CCar car;
	CRemoteControl remoteControl(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		remoteControl.HandleComand();
	}

	return 0;
}
