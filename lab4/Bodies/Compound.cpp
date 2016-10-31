#include "stdafx.h"
#include <numeric>
#include "Compound.h"

using namespace std;

CCompound::CCompound()
{
}

CCompound::~CCompound()
{
}

double CCompound::GetDensity() const
{
	return GetMass() / GetVolume();
}

double CCompound::GetVolume() const
{
	return accumulate(m_partsBody.cbegin(), m_partsBody.cend(), 0.0,
		[](double sum, const shared_ptr<CBody> &body){ return sum + body->GetVolume(); });;
}

double CCompound::GetMass() const
{
	return accumulate(m_partsBody.cbegin(), m_partsBody.cend(), 0.0,
		[](double sum, const shared_ptr<CBody> &body){ return sum + body->GetMass(); });
}

std::string CCompound::GetInformation() const
{
	std::ostringstream out;
	out << "Compound: " << std::endl << " Density: " << GetDensity() << " Mass: " << GetMass() << " Volume: " << GetVolume();
	return out.str();
}

bool CCompound::Add(const shared_ptr<CBody> &body)
{
	if (this == body.get())
		return false;

	shared_ptr<CCompound> bodyAsCompound = dynamic_pointer_cast<CCompound>(body);
	if (bodyAsCompound.get() != nullptr)
	{
		if (bodyAsCompound->HasBodyInside(this))
		{
			return false;
		}
	}

	m_partsBody.push_back(body);
	return true;
}

size_t CCompound::GetContentsCount() const
{
	return m_partsBody.size();
}
const bool CCompound::HasBodyInside(const CBody *body)
{
	for (auto & curBody : m_partsBody)
	{
		if (body == curBody.get())
		{
			return true;
		}

		shared_ptr<CCompound> curBodyAsCompound = dynamic_pointer_cast<CCompound>(curBody);
		if (curBodyAsCompound)
		{
			if (curBodyAsCompound->HasBodyInside(body))
			{
				return true;
			}
		}
	}

	return false;
}