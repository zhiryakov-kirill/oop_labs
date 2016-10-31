#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>


CRectangle::CRectangle()
:m_height(0)
, m_width(0)
, m_left(0)
, m_top(0)
{
}

CRectangle::CRectangle(int left, int top, int width, int height)
:m_left(left)
, m_top(top)
{
	if (width > 0)
	{
		m_width = width;
	}
	else
	{
		m_width = 0;
	}

	if (height > 0)
	{
		m_height = height;
	}
	else
	{
		m_height = 0;
	}
}

CRectangle::~CRectangle()
{
}

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetWidth(int width)
{
	if (width >= 0)
	{
		m_width = width;
	}
	else
	{
		m_width = 0;
	}
}

void CRectangle::SetHeight(int height)
{
	if (height >= 0)
	{
		m_height = height;
	}
	else
	{
		m_height = 0;
	}
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetTop() const
{
	return m_top;
}

void CRectangle::SetLeft(int left)
{
	m_left = left;
}

void CRectangle::SetTop(int top)
{
	m_top = top;
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

void CRectangle::SetRight(int right)
{
	if (right > m_left)
	{
		m_width = right - m_left;
	}
}

int CRectangle::GetBottom() const
{
	return m_top + m_height;
}

void CRectangle::SetBottom(int bottom)
{
	if (bottom > m_top)
	{
		m_height = bottom - m_top;
	}
}

int CRectangle::GetArea() const
{
	return m_height * m_width;
}

int CRectangle::GetPerimeter() const
{
	return (m_height + m_width) * 2;
}

void CRectangle::Move(int dx, int dy)
{
	m_left += dx;
	m_top += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if ((sx > 0) && (sy > 0))
	{
		m_width *= sx;
		m_height *= sy;
	}
}

bool CRectangle::Intersect(CRectangle const& other)
{
	if ((std::min(GetRight(), other.GetRight()) > std::max(m_left, other.m_left))
		&& (std::min(GetBottom(), other.GetBottom()) > std::max(m_top, other.m_top)))
	{
		m_left = std::max(m_left, other.m_left);
		m_top = std::max(m_top, other.m_top);
		m_width = std::min(GetRight(), other.GetRight()) - std::max(m_left, other.m_left);
		m_height = std::min(GetBottom(), other.GetBottom()) - std::max(m_top, other.m_top);
		return true;
	}

	m_width = 0;
	m_height = 0;
	return false;
}