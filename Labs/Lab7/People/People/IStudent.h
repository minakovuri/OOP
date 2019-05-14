#pragma once
#include "IPerson.h"

class IStudent : public IPerson
{
public:
	IStudent() = default;
	virtual ~IStudent() = default;

	virtual std::string GetUniversityName() const = 0;
	virtual std::string GetTicketNumber() const = 0;
};