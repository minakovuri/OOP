#include "pch.h"
#include "UserDialog.h"
#include "DictionaryRewriter.h"

#include <iostream>

const std::string END_OF_PROGRAM_SIGN = "...";

void FinishProgram(bool isDictionaryChanged, const Dictionary& dictionary)
{
	using namespace std;

	if (isDictionaryChanged)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;

		string saveDictionarySign;
		getline(cin, saveDictionarySign);

		if ((saveDictionarySign == "Y") || (saveDictionarySign == "y"))
		{
			WriteDictionaryToFile(DICTIONARY_FILE_NAME, dictionary);
		}

		cout << "Изменения сохранены.";
	}

	cout << "До свидания." << std::endl;
}

void DisplayTranslatedWords(VectorOfWords& wordsVector)
{
	using namespace std;

	auto wordsVectorSize = wordsVector.size();

	for (size_t i = 0; i < wordsVectorSize - 1; i++)
	{
		cout << wordsVector[i] << ", ";
	}

	cout << wordsVector[wordsVectorSize - 1] << endl;
}

void HavingDialogWithUser(Dictionary& dictionary)
{
	using namespace std;

	string word;
	bool isDictionaryChanged = false;

	while (getline(cin, word))
	{
		if (word == END_OF_PROGRAM_SIGN)
		{
			FinishProgram(isDictionaryChanged, dictionary);
			return;
		}

		optional<VectorOfWords> translatedWords = Translate(word, dictionary);

		if (!translatedWords)
		{
			cout << "Неизвестное слово \"" << word << "\".Введите перевод или пустую строку для отказа." << endl;

			string newTranslatedWord;
			getline(cin, newTranslatedWord);

			if (!newTranslatedWord.length())
			{
				cout << "Слово \"" << word << "\" проигнорировано." << endl;
			}
			else
			{
				AddTranslation(word, newTranslatedWord, dictionary);
				isDictionaryChanged = true;

				cout << "Слово \"" << word << "\" сохранено в словаре как \"" << dictionary.find(word)->second << "\"." << endl;
			}
		}
		else
		{
			DisplayTranslatedWords(translatedWords.value());
		}
	}
}
