#include "pch.h"
#include "CControlMenu.h"

int main()
{
	CÑontrolMenu menu(std::cin, std::cout, std::cerr);

	menu.HandleCommands();
}
