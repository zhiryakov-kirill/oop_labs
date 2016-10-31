﻿#include "stdafx.h"
#include "Rational.h"
#include <iostream>
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

unsigned LCM(unsigned x, unsigned y)
{
	return (x / GCD(x, y) * y);
}

double  CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

CRational const CRational::operator +() const
{
	return *this;
}

CRational const CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}

const CRational operator + (const CRational &num1, const CRational &num2)
{
	const unsigned lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
	return CRational(num1.GetNumerator() * (lcm / num1.GetDenominator()) + num2.GetNumerator() * (lcm / num2.GetDenominator()), lcm);
}

const CRational operator - (const CRational &num1, const CRational &num2)
{
	const unsigned lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
	return CRational(num1.GetNumerator() * (lcm / num1.GetDenominator()) - num2.GetNumerator() * (lcm / num2.GetDenominator()), lcm);
}

CRational& CRational::operator +=(CRational const& rational)
{
	m_numerator = m_numerator * rational.m_denominator + rational.m_numerator * m_denominator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}

CRational& CRational::operator -=(CRational const& rational)
{
	m_numerator = m_numerator * rational.m_denominator - rational.m_numerator * m_denominator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}

const CRational operator * (const CRational &num1, const CRational &num2)
{
	return CRational(num1.GetNumerator() * num2.GetNumerator(), num1.GetDenominator() * num2.GetDenominator());
}

const CRational operator / (const CRational &num1, const CRational &num2)
{
	return CRational(num1.GetNumerator() * num2.GetDenominator(), num2.GetNumerator() * num1.GetDenominator());
}

CRational& CRational::operator *=(CRational const& other)
{
	m_numerator *= other.m_numerator;
	m_denominator *= other.m_denominator;
	Normalize();
	return *this;
}

CRational& CRational::operator /=(CRational const& other)
{
	m_numerator *= other.m_denominator;
	m_denominator *= other.m_numerator;
	Normalize();
	return *this;
}

const bool operator == (const CRational &num1, const CRational &num2)
{
	return (num1.GetNumerator() == num2.GetNumerator() && num1.GetDenominator() == num2.GetDenominator());
}

const bool operator != (const CRational &num1, const CRational &num2)
{
	return !(num1 == num2);
}

const bool operator < (const CRational &num1, const CRational &num2)
{
	CRational rational = num1 - num2;
	return (rational.GetNumerator() < 0);
}

const bool operator > (const CRational &num1, const CRational &num2)
{
	CRational rational = num1 - num2;
	return (rational.GetNumerator() > 0);
}

const bool operator <= (const CRational &num1, const CRational &num2)
{
	return (!(num1 > num2));
}

const bool operator >=(const CRational &num1, const CRational &num2)
{
	return (!(num1 < num2));
}

std::ostream& operator << (std::ostream &stream, const CRational &num)
{
	return stream << num.GetNumerator() << "/" << num.GetDenominator();
}

std::istream & operator>>(std::istream & stream, CRational & rational)
{
	std::streamoff pos = stream.tellg();

	int numerator = 0;
	int denominator = 0;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
		return stream;
	}

	stream.seekg(pos);
	stream.setstate(std::ios_base::failbit | stream.rdstate());
	return stream;
}


