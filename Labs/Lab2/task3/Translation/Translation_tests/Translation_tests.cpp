#define CATCH_CONFIG_MAIN
#include "Dictionary.h"
#include "Translator.h"
#include "catch.hpp"

TEST_CASE("Test TranslateWord() function")
{
	Dictionary dictionary = {
		{ "dog", "собака" },
		{ "cat", "кошка" },
		{ "home", "дом" },
		{ "cat", "кот" },
		{
			"the red square",
			"красная площадь",
		}
	};

	CHECK(Translate("dog", dictionary) == VectorOfWords{ "собака" });
	CHECK(Translate("cat", dictionary) == VectorOfWords{ "кошка", "кот" });
	CHECK(Translate("home", dictionary) == VectorOfWords{ "дом" });
	CHECK(Translate("the red square", dictionary) == VectorOfWords{ "красная площадь" });

	CHECK(Translate("CAt", dictionary) == VectorOfWords{ "кошка", "кот" });

	CHECK(Translate("cat", dictionary) != VectorOfWords{ "собака" });
	CHECK(Translate("coding", dictionary) == std::nullopt);
};

TEST_CASE("Test AddTranslation() function")
{
	Dictionary dictionary = {
		{ "dog", "собака" },
		{ "cat", "кошка" },
		{ "home", "дом" },
		{ "cat", "кот" },
	};

	CHECK_NOTHROW(AddTranslation("the red square", "красная площадь", dictionary));

	Dictionary requiredDictionary = {
		{ "dog", "собака" },
		{ "cat", "кошка" },
		{ "home", "дом" },
		{ "cat", "кот" },
		{
			"the red square",
			"красная площадь",
		}
	};

	CHECK(dictionary == requiredDictionary);
};
