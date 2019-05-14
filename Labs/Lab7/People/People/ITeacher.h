#pragma once
#include "IPerson.h"

class ITeacher : public IPerson
{
public:
	ITeacher() = default;
	virtual ~ITeacher() = default;

	virtual std::string GetSubjectName() const = 0;
};
