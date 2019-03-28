#include "pch.h"
#include "Decryptor.h"

std::string HtmlEncode(const std::string& text)
{
	std::string encodingText;
	encodingText.reserve(text.size());

	for (const char& ch : text)
	{
		std::optional<std::string> htmlEntity = GetHtmlEntity(ch);

		if (!htmlEntity)
		{
			encodingText += ch;
		}
		else
		{
			encodingText += htmlEntity.value();
		}
	}

	return encodingText;
}

std::string HtmlDecode(std::string& text)
{
	std::string decodingText;
	decodingText.reserve(text.size());

	std::string::iterator it = text.begin();

	while (it != text.end())
	{
		if ((*it) == START_HTML_ENTITY_SYMBOL)
		{
			auto htmlEntityEnd = std::find(it, text.end(),END_HTML_ENTITY_SYMBOL);

			if (htmlEntityEnd != text.end())
			{
				int currentPosition = it - text.begin();
				int offset = (htmlEntityEnd - it) + 1;

				std::string htmlEntity = text.substr(currentPosition, offset);
				std::optional<char> specialSymbol = GetSpecialSymbol(htmlEntity);

				if (!specialSymbol)
				{
					decodingText += htmlEntity;
				}
				else
				{
					decodingText += specialSymbol.value();
				}

				it += offset;
			}
			else
			{
				decodingText += (*it);
				++it;
			}
		}
		else
		{
			decodingText += (*it);
			++it;
		}
	}

	return decodingText;
}
