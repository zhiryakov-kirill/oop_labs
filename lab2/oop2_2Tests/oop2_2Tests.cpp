// oop2_2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop2_2/RemoveSpaces.h"

BOOST_AUTO_TEST_CASE(StringProcessing)
{
	BOOST_CHECK_EQUAL(RemoveExtraSpaces(""), "");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("   "), "");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("Test"), "Test");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("   Test"), "Test");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("Test   "), "Test");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("   Test   "), "Test");
	BOOST_CHECK_EQUAL(RemoveExtraSpaces("   This   test string   "), "This test string");

}


