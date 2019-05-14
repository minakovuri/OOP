#pragma once
#include "IPerson.h"

class IPupil : public IPerson
{
public:
	IPupil() = default;
	virtual ~IPupil() = default;

	virtual std::string GetSchoolName() const = 0;
	virtual std::string GetSchoolClassName() const = 0;
};
