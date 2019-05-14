#pragma once
#include "CPersonImpl.h"
#include "IWorker.h"

class CWorker : public CPersonImpl<IWorker> 
{
public:
	CWorker(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& specialty);

	~CWorker() = default;

	std::string GetSpecialty() const override;

private:
	std::string m_specialty;
};
