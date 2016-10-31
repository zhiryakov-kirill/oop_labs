#pragma once
#include "Item.h"

using namespace std;

class CMyStringList
{
public:
	CMyStringList();
	~CMyStringList();
	shared_ptr<CItem> GetFirst() const;
	shared_ptr<CItem> GetLast() const;
	shared_ptr<CItem> GetNext(const shared_ptr<CItem> &ptr) const;
	shared_ptr<CItem> GetPrev(const shared_ptr<CItem> &ptr) const;
	string GetVal(const shared_ptr<CItem> &ptr) const;
	void Insert(const string &s, shared_ptr<CItem> &ptr = shared_ptr<CItem>());
	void Delete(const shared_ptr<CItem> elem);

private:
	shared_ptr<CItem> m_first;
	shared_ptr<CItem> m_last;
};

