#define CATCH_CONFIG_MAIN
#include "Dictionary.h"
#include "Translator.h"
#include "catch.hpp"

TEST_CASE("Test TranslateWord() function")
{
	Dictionary dictionary = {
		{ "dog", "������" },
		{ "cat", "�����" },
		{ "home", "���" },
		{ "cat", "���" },
		{
			"the red square",
			"������� �������",
		}
	};

	CHECK(Translate("dog", dictionary) == VectorOfWords{ "������" });
	CHECK(Translate("cat", dictionary) == VectorOfWords{ "�����", "���" });
	CHECK(Translate("home", dictionary) == VectorOfWords{ "���" });
	CHECK(Translate("the red square", dictionary) == VectorOfWords{ "������� �������" });

	CHECK(Translate("CAt", dictionary) == VectorOfWords{ "�����", "���" });

	CHECK(Translate("cat", dictionary) != VectorOfWords{ "������" });
	CHECK(Translate("coding", dictionary) == std::nullopt);
};

TEST_CASE("Test AddTranslation() function")
{
	Dictionary dictionary = {
		{ "dog", "������" },
		{ "cat", "�����" },
		{ "home", "���" },
		{ "cat", "���" },
	};

	CHECK_NOTHROW(AddTranslation("the red square", "������� �������", dictionary));

	Dictionary requiredDictionary = {
		{ "dog", "������" },
		{ "cat", "�����" },
		{ "home", "���" },
		{ "cat", "���" },
		{
			"the red square",
			"������� �������",
		}
	};

	CHECK(dictionary == requiredDictionary);
};
