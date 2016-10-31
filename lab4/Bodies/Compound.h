#pragma once
#include "Body.h"
#include <memory>
#include <vector>

class CCompound :
	public CBody
{
public:
	CCompound();
	~CCompound();
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	std::string GetInformation() const override;
	bool Add(const std::shared_ptr<CBody> &body);
	size_t GetContentsCount() const;
private:
	std::vector<std::shared_ptr<CBody>> m_partsBody;
	const bool HasBodyInside(const CBody *body);
};