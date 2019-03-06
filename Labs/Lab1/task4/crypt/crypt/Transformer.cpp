#include "pch.h"
#include "Transformer.h"
#include "Constants.h"

void TransformInputFile(InputParameters& inputParameters)
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

	byte = ((byte & 0b00000111) << 2)
		| ((byte & 0b00011000) << 3)
		| ((byte & 0b01100000) >> 5)
		| ((byte & 0b10000000) >> 2);
}

void Decrypt(char& byte, const Key key)
{
	byte = ((byte & 0b00000011) << 5)
		| ((byte & 0b00011100) >> 2)
		| ((byte & 0b00100000) << 2)
		| ((byte & 0b11000000) >> 3);

	byte ^= key;
}