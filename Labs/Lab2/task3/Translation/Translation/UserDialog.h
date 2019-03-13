#pragma once
#include "Dictionary.h"
#include "Translator.h"

void FinishProgram(bool isDictionaryChanged, const Dictionary& dictionary);
void DisplayTranslatedWords(VectorOfWords& wordsVector);
void HavingDialogWithUser(Dictionary& dictionary);
