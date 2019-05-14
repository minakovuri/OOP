#pragma once
#include "CPersonImpl.h"
#include "ITeacher.h"

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& subjectName);

	~CTeacher() = default;

	std::string GetSubjectName() const override;
private:
	std::string m_subjectName;
};
