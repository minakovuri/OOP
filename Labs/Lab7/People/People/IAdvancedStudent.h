#pragma once
#include "IStudent.h"

class IAdvancedStudent : public IStudent
{
public:
	IAdvancedStudent() = default;
	virtual ~IAdvancedStudent() = default;

	virtual std::string GetDissertationTopic() const = 0;
};