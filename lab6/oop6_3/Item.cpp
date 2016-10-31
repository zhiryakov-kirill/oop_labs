#include "stdafx.h"
#include "Item.h"

using namespace std;

CItem::CItem(const string &s)
: m_value(s)
, m_prev(shared_ptr<CItem>())
, m_next(shared_ptr<CItem>())
{
}

CItem::~CItem()
{
}

shared_ptr<CItem> CItem::GetPrev() const
{
	return m_prev;
}

shared_ptr<CItem> CItem::GetNext() const
{
	return m_next;
}

string CItem::GetValue() const
{
	return m_value;
}

void CItem::SetPrev(const shared_ptr<CItem> &prev)
{
	m_prev = prev;
}

void CItem::SetNext(const shared_ptr<CItem> &next)
{
	m_next = next;
}