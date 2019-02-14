#include "pch.h"
#include "StringReplacer.h"

void ReplaceString(std::string& searchString, std::string& replaceString, std::string& currentLine)
{
	for (size_t position = 0;; position += replaceString.length())
	{
		position = currentLine.find(searchString, position);

		if (position == std::string::npos)
		{
			break;
		}

		currentLine.erase(position, searchString.length());
		currentLine.insert(position, replaceString);
	}
}
