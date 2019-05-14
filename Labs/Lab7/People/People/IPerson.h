#pragma once
#include "pch.h"

class IPerson
{
public:
	IPerson() = default;
	virtual ~IPerson() = default;

	virtual std::string GetName() const = 0;
	virtual std::string GetSurname() const = 0;
	virtual std::string GetPatronymic() const = 0;
	virtual std::string GetAddress() const = 0;
};