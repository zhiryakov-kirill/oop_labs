// oop3_2Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../oop3_2/Rectangle.h"

bool CheckIntersection(CRectangle a, CRectangle const& b, bool willPass, CRectangle const& result)
{
	if (a.Intersect(b) != willPass)
	{
		return false;
	}

	return( (a.GetLeft() == b.GetLeft()) &&
		(a.GetTop == b.GetTop) &&
		(a.GetWidth == b.GetWidth) &&
		(a.GetHeight == b.GetHeight));
}

struct RectangleFixture
{
	CRectangle rectangle;
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture)

BOOST_AUTO_TEST_CASE(CreateRectangleWithZeroValues)
{	
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 0);
}

BOOST_AUTO_TEST_CASE(RectangleHaveWidthAndHeight)
{
	rectangle.SetWidth(10);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 10);
	rectangle.SetHeight(10);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 10);
}

BOOST_AUTO_TEST_CASE(UnpositiveRectangleSidesChangedToZeroSides)
{
	CRectangle rectangle1(10, 10, -10, -10);
	BOOST_CHECK_EQUAL(rectangle1.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rectangle1.GetHeight(), 0);
}

BOOST_AUTO_TEST_CASE(RectangleHaveLeftAndTopCoordinates)
{
	rectangle.SetLeft(10);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 10);
	rectangle.SetTop(10);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 10);
}

BOOST_AUTO_TEST_CASE(RectangleHaveRightAndBottomCoordinates)
{
	rectangle.SetRight(10);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 10);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 10);

	rectangle.SetBottom(10);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 10);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 10);
}

BOOST_AUTO_TEST_CASE(RectangleWithZeroValuesHaveZeroAreaAndPerimeter)
{
	BOOST_CHECK_EQUAL(rectangle.GetArea(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), 0);
}

BOOST_AUTO_TEST_CASE(RectangleHaveAreaAndPerimeter)
{
	CRectangle rectangle1(5, 5, 6, 8);
	BOOST_CHECK_EQUAL(rectangle1.GetArea(), 48);
	BOOST_CHECK_EQUAL(rectangle1.GetPerimeter(), 28);
}

BOOST_AUTO_TEST_CASE(RectangleCanChangeItsPositionOnArea)
{
	CRectangle rectangle1(5, 5, 6, 8);
	rectangle1.Move(5, 5);
	BOOST_CHECK_EQUAL(rectangle1.GetLeft(), 10);
	BOOST_CHECK_EQUAL(rectangle1.GetRight(), 16);
	BOOST_CHECK_EQUAL(rectangle1.GetTop(), 10);
	BOOST_CHECK_EQUAL(rectangle1.GetBottom(), 18);

	CRectangle rectangle2(-5, -5, 6, 8);
	rectangle2.Move(-5, -12);
	BOOST_CHECK_EQUAL(rectangle2.GetLeft(), -10);
	BOOST_CHECK_EQUAL(rectangle2.GetRight(), -4);
	BOOST_CHECK_EQUAL(rectangle2.GetTop(), -17);
	BOOST_CHECK_EQUAL(rectangle2.GetBottom(), -9);
}

BOOST_AUTO_TEST_CASE(RectangleCanChangeItsSize)
{
	CRectangle rectangle1(5, 5, 6, 8);
	rectangle1.Scale(2, 3);
	BOOST_CHECK_EQUAL(rectangle1.GetLeft(), 5);
	BOOST_CHECK_EQUAL(rectangle1.GetRight(), 17);
	BOOST_CHECK_EQUAL(rectangle1.GetTop(), 5);
	BOOST_CHECK_EQUAL(rectangle1.GetBottom(), 29);
	BOOST_CHECK_EQUAL(rectangle1.GetWidth(), 12);
	BOOST_CHECK_EQUAL(rectangle1.GetHeight(), 24);

	CRectangle rectangle2(-5, -5, 6, 8);
	rectangle2.Scale(-2, -3);
	BOOST_CHECK_EQUAL(rectangle2.GetLeft(), -5);
	BOOST_CHECK_EQUAL(rectangle2.GetRight(), 1);
	BOOST_CHECK_EQUAL(rectangle2.GetTop(), -5);
	BOOST_CHECK_EQUAL(rectangle2.GetBottom(), 3);
	BOOST_CHECK_EQUAL(rectangle2.GetWidth(), 6);
	BOOST_CHECK_EQUAL(rectangle2.GetHeight(), 8);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(TestIntersection)
{
	BOOST_CHECK(CheckIntersection(
		CRectangle(1, 1, 5, 5),
		CRectangle(3, 3, 5, 5),
		true,
		CRectangle(3, 3, 3, 3)
		));

	BOOST_CHECK(CheckIntersection(
		CRectangle(1, 1, 2, 2),
		CRectangle(3, 2, 2, 2),
		true,
		CRectangle(3, 2, 0, 1)
		));

	BOOST_CHECK(CheckIntersection(
		CRectangle(1, 1, 2, 2),
		CRectangle(3, 3, 2, 2),
		true,
		CRectangle(3, 3, 0, 0)
		));

	BOOST_CHECK(CheckIntersection(
		CRectangle(1, 1, 2, 2),
		CRectangle(5, 5, 2, 2),
		false,
		CRectangle(1, 1, 0, 0)
		));
}
