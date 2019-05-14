#pragma once
#include "IPerson.h"

class IWorker : public IPerson
{
public:
	IWorker() = default;
	virtual ~IWorker() = default;

	virtual std::string GetSpecialty() const = 0;
};
