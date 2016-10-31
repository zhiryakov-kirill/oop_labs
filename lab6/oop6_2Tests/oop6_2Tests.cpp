// oop6_2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop6_2/Student.h"
using namespace std;

BOOST_AUTO_TEST_CASE(CheckNameInConstructor)
{
	BOOST_CHECK_THROW(CStudent(20, "P e t r", "Petrov"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", "P e t r o v"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "", "Petrov"), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", ""), invalid_argument);
	BOOST_CHECK_THROW(CStudent(20, "Petr", "Petrov", "Pet rovich"), invalid_argument);
	BOOST_CHECK_NO_THROW(CStudent(20, "Petr", "Petrov", "Petrovich"));
}

BOOST_AUTO_TEST_CASE(CheckAgeInConstructor)
{
	BOOST_CHECK_THROW(CStudent(13, "Petr", "Petrov"), out_of_range);
	BOOST_CHECK_NO_THROW(CStudent(30, "Petr", "Petrov", "Petrovich"));
	BOOST_CHECK_THROW(CStudent(61, "Petr", "Petrov"), out_of_range);
}

BOOST_AUTO_TEST_CASE(CheckOfPropertiesTheStudentAfterCreation)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_EQUAL(student.GetAge(), 21);
}

BOOST_AUTO_TEST_CASE(RenameStudent)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	student.Rename("Ivan", "Ivanov", "Ivanovich");
	BOOST_CHECK_EQUAL(student.GetName(), "Ivan");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Ivanov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
}

BOOST_AUTO_TEST_CASE(RenameStudentWithInvalidParameters)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	BOOST_CHECK_THROW(student.Rename("I v a n", "Ivanov", "Ivanovich"), invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_THROW(student.Rename("Ivan", "I v a n o v", "Ivanovich"), invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_THROW(student.Rename("Ivan", "Ivanov", "I v a n ovich"), invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
}
BOOST_AUTO_TEST_CASE(ChangeOfAgeWithInvalidParameters)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	BOOST_CHECK_THROW(student.SetAge(20), domain_error);
	BOOST_CHECK_EQUAL(student.GetAge(), 21);
	BOOST_CHECK_THROW(CStudent(61, "Petr", "Petrov", "Petrovich"), out_of_range);
	BOOST_CHECK_EQUAL(student.GetAge(), 21);
}
BOOST_AUTO_TEST_CASE(ChangeOfAgeWithValidParameters)
{
	CStudent student = CStudent(21, "Petr", "Petrov", "Petrovich");
	BOOST_CHECK_NO_THROW(student.SetAge(22));
	BOOST_CHECK_EQUAL(student.GetAge(), 22);
}
