#include "pch.h"
#include "Dictionary.h"
#include "DictionaryUploader.h"
#include "UserDialog.h"

#include <iostream>

int main()
{
	Dictionary dictionary;

	try
	{
		UploadDictionaryFromFile(DICTIONARY_FILE_NAME, dictionary);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	HavingDialogWithUser(dictionary);

	return 0;
}
