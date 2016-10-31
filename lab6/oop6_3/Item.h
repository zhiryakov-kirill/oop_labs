#pragma once
class CItem
{
public:
	CItem(const std::string &s);
	~CItem();
	std::shared_ptr<CItem> GetPrev() const;
	std::shared_ptr<CItem> GetNext() const;
	std::string GetValue() const;
	void SetPrev(const std::shared_ptr<CItem> &prev);
	void SetNext(const std::shared_ptr<CItem> &prev);
private:
	std::string m_value;
	std::shared_ptr<CItem> m_next, m_prev;
};

