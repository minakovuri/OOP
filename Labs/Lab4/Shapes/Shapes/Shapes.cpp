#include "pch.h"
#include "CControlMenu.h"

int main()
{
	C�ontrolMenu menu(std::cin, std::cout, std::cerr);

	menu.HandleCommands();
}
