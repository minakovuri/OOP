#pragma once

#include "InputFormat.h"

using Byte = char;

void HandleFiles(InputParameters& inputParameters);
void Encrypt(char& byte, const Key);
void Decrypt(char& byte, const Key);