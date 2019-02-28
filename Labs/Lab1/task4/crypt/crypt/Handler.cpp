#include "pch.h"
#include "Handler.h"
#include "Masks.h"
#include "Constants.h"

void HandleFiles(InputParameters& inputParameters)
{
	Byte byte;

	while (inputParameters.inputFile.read(&byte, sizeof(byte)))
	{
		(inputParameters.mode == CRYPT) ? Encrypt(byte, inputParameters.key) : Decrypt(byte, inputParameters.key);

		inputParameters.outputFile.write(&byte, sizeof(byte));
	}
}

void Encrypt(char& byte, const Key key)
{
	byte ^= key;

	byte = ((byte & ENCRYPT_MASK_00000111) << 2)
		| ((byte & ENCRYPT_MASK_00011000) << 3)
		| ((byte & ENCRYPT_MASK_01100000) >> 5)
		| ((byte & ENCRYPT_MASK_10000000) >> 2);
}

void Decrypt(char& byte, const Key key)
{
	byte = ((byte & DECRYPT_MASK_00000011) << 5)
		| ((byte & DECRYPT_MASK_00011100) >> 2)
		| ((byte & DECRYPT_MASK_00100000) << 2)
		| ((byte & DECRYPT_MASK_11000000) >> 3);

	byte ^= key;
}