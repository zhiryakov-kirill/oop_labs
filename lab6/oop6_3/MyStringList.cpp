#include "stdafx.h"
#include "MyStringList.h"

using namespace std;

CMyStringList::CMyStringList()
:m_first()
, m_last()
{
}

CMyStringList::~CMyStringList()
{
	auto it = m_first;
	while (it != nullptr)
	{
		auto next = it->GetNext();
		it->SetNext(nullptr);
		it = next;
	}
}

shared_ptr<CItem> CMyStringList::GetFirst() const
{
	return m_first;
}

shared_ptr<CItem> CMyStringList::GetLast() const
{
	return m_last;
}

shared_ptr<CItem> CMyStringList::GetNext(const shared_ptr<CItem> &ptr) const
{
	return ptr->GetNext();
}

shared_ptr<CItem> CMyStringList::GetPrev(const shared_ptr<CItem> &ptr) const
{
	return ptr->GetPrev();
}

string CMyStringList::GetVal(const shared_ptr<CItem> &ptr) const
{
	return ptr->GetValue();
}

void CMyStringList::Insert(string const&str, shared_ptr<CItem> &ptr)
{
	auto newElement = make_shared<CItem>(str);
	if (!m_first)
	{
		m_first = newElement;
		m_last = newElement;
		return;
	}

	if (ptr)
	{
		newElement->SetPrev(ptr);
		auto next = ptr->GetNext();
		newElement->SetNext(next);
		if (next)
		{
			next->SetPrev(newElement);
		}
		ptr->SetNext(newElement);
		if (m_last == ptr)
		{
			m_last = newElement;
		}
	}
	else
	{
		newElement->SetPrev(m_last);
		newElement->SetNext(shared_ptr<CItem>());
		m_last->SetNext(newElement);
		m_last = newElement;
	}
}

void CMyStringList::Delete(const shared_ptr<CItem> elem)
{
	auto next = elem->GetNext();
	auto prev = elem->GetPrev();

	if (next)
	{
		next->SetPrev(elem->GetPrev());
	}
	else
	{
		m_last = elem->GetPrev();
	}
	
	if (prev)
	{
		prev->SetNext(elem->GetNext());
	}
	else
	{
		m_first = elem->GetNext();
	}
	elem->SetNext(nullptr);
	elem->SetPrev(nullptr);
}