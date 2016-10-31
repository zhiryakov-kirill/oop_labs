#include "stdafx.h"
#include "Student.h"
using namespace std;


CStudent::CStudent(int age, string const &name, string const &surname, string const &patronymic)
{
	SetAge(age);
	Rename(name, surname, patronymic);
}

const bool CStudent::CheckStringOnSpases(string const& name) 
{
	return (name.find_first_of(" ") != std::string::npos);
}

string CStudent::GetName() const
{
	return m_name;
}

string CStudent::GetSurname() const
{
	return m_surname;
}

string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	if (name.empty() || CheckStringOnSpases(name))
	{
		throw invalid_argument("Invalid name");
	}
	if (surname.empty() || CheckStringOnSpases(surname))
	{
		throw invalid_argument("Invalid surname");
	}
	if (CheckStringOnSpases(patronymic))
	{
		throw invalid_argument("Invalid patronymic");
	}

	m_name = move(name);
	m_surname = move(surname);
	m_patronymic = move(patronymic);
}

void CStudent::SetAge(int age)
{
	if (age < 14 || age > 60)
	{
		throw out_of_range("Invalid age");
	}
	if (age < m_age)
	{
		throw domain_error("Invalid age");
	}
	m_age = age;
}

CStudent::~CStudent()
{
}
