// oop6_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Item.h"
#include "MyStringList.h"

using namespace std;

struct ItemFixture
{
	CItem item;

	ItemFixture()
		:item("Hello")
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Item, ItemFixture)

BOOST_AUTO_TEST_CASE(GetValue)
{
	BOOST_CHECK_EQUAL(item.GetValue(), "Hello");
}

BOOST_AUTO_TEST_CASE(GetPointerToNextPrevElement)
{
	BOOST_CHECK_EQUAL(item.GetNext(), shared_ptr<CItem>());
	BOOST_CHECK_EQUAL(item.GetPrev(), shared_ptr<CItem>());
}

BOOST_AUTO_TEST_CASE(CanSetPointerToNextPrevElement)
{
	auto it = make_shared<CItem>("world");
	item.SetNext(it);
	item.SetPrev(it);
	BOOST_CHECK_EQUAL(item.GetNext(), it);
	BOOST_CHECK_EQUAL(item.GetPrev(), it);
}

BOOST_AUTO_TEST_SUITE_END()



struct MyStringListFixture
{
	CMyStringList list;
};

BOOST_FIXTURE_TEST_SUITE(MyStringList, MyStringListFixture)

BOOST_AUTO_TEST_CASE(InsertNewElement)
{
	list.Insert("hello", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "hello");
	list.Insert("world");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "world");
	list.Insert(":)");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), ":)");
	auto it = list.GetLast()->GetPrev();
	list.Insert("^_^", it);
	BOOST_CHECK_EQUAL(list.GetLast()->GetPrev()->GetValue(), "^_^");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), ":)");
}

BOOST_AUTO_TEST_CASE(CanDeleteElem)
{
	list.Insert("1", list.GetLast());
	list.Insert("2", list.GetLast());
	list.Insert("4", list.GetLast());
	auto it = list.GetLast()->GetPrev();
	list.Insert("3", it);
	list.Delete(list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "3");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "1");
	list.Delete(list.GetFirst());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "3");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "2");
	list.Delete(list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "2");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "2");
	list.Delete(list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast(), shared_ptr<CItem>());
	BOOST_CHECK_EQUAL(list.GetFirst(), shared_ptr<CItem>());
}
BOOST_AUTO_TEST_SUITE_END()