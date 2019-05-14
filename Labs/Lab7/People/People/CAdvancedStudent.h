#pragma once
#include "CStudentImpl.h"
#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		const std::string& ticketNumber,
		const std::string& dissertationTopic
	);

	~CAdvancedStudent() = default;

	std::string GetDissertationTopic() const override;

private:
	std::string m_dissertationTopic;
};
