#pragma once
#include <string>
using namespace std;
class CStudent
{
public:
	CStudent(int age, string const &name, string const &surname, string const &patronymic = std::string());
	~CStudent();
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	int GetAge() const;
	void Rename(std::string name, std::string surname, std::string patronymic = std::string());
	void SetAge(int age);
	
private:
	static const bool CheckStringOnSpases(string const& name);
	string m_name;
	string m_surname;
	string m_patronymic;
	int m_age = 0;
};

