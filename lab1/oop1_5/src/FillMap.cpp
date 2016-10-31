#include "stdafx.h"
#include "FillMap.h"

CFillMap::CFillMap(const char fileName[])
{
	FILE *f;

	if (fopen_s(&f, fileName, "r") == 0)
	{
		ClearMap();
		m_height = 0;
		m_width = 0;

		char tmpBuffer[MAX_SIZE + 2];
		char *readResult;

		do
		{
			readResult = fgets(tmpBuffer, sizeof(tmpBuffer), f);
			if (readResult != NULL)
			{
				size_t tmpBufferLen = strlen(tmpBuffer);

				while (tmpBufferLen > 0 && tmpBuffer[tmpBufferLen - 1] == '\n')
				{
					--tmpBufferLen;
					tmpBuffer[tmpBufferLen] = '\0';
				}
				assert(tmpBufferLen <= MAX_SIZE);

				if (static_cast<size_t>(m_width) < tmpBufferLen)
				{
					m_width = tmpBufferLen;
				}

				ParseLine(m_height, tmpBuffer);
				++m_height;
			}
		}
		while (readResult != NULL && !feof(f) && m_height < MAX_SIZE);

		fclose(f);
	}
	else
	{
		throw std::runtime_error("File open error");
	}
}

void CFillMap::ClearMap(value_t value)
{
	for (index_t row = 0; row < MAX_SIZE; ++row)
	{
		for (index_t column = 0; column < MAX_SIZE; ++column)
		{
			m_data[row][column] = value;
		}
	}
}

void CFillMap::ParseLine(index_t row, const char line[])
{
	size_t lineLen = strlen(line);
	assert(lineLen <= MAX_SIZE);
	assert(row < MAX_SIZE);

	for (size_t curCharInd = 0; curCharInd < lineLen; ++curCharInd)
	{
		m_data[row][curCharInd] = static_cast<value_t>(line[curCharInd]);

		if (m_data[row][curCharInd] == value_t::SOURCE)
		{
			m_fillBuffer.push({ row, curCharInd });
		}
	}
}

void CFillMap::FillMap()
{
	while (!m_fillBuffer.empty())
	{
		coord_t tmpCoord = m_fillBuffer.front();
		m_fillBuffer.pop();

		if
			(
				tmpCoord.row >= 0 && tmpCoord.row < m_height &&
				tmpCoord.column >= 0 && tmpCoord.column < m_width &&
				(
					m_data[tmpCoord.row][tmpCoord.column] == value_t::EMPTY ||
					m_data[tmpCoord.row][tmpCoord.column] == value_t::SOURCE
				)
			)
		{
			if (m_data[tmpCoord.row][tmpCoord.column] == value_t::EMPTY)
			{
				m_data[tmpCoord.row][tmpCoord.column] = value_t::FULL;
			}

			if (m_data[tmpCoord.row][tmpCoord.column] == value_t::SOURCE)
			{
				m_data[tmpCoord.row][tmpCoord.column] = value_t::USED_SOURCE;
			}

			m_fillBuffer.push({ tmpCoord.row - 1, tmpCoord.column });
			m_fillBuffer.push({ tmpCoord.row + 1, tmpCoord.column });
			m_fillBuffer.push({ tmpCoord.row, tmpCoord.column - 1 });
			m_fillBuffer.push({ tmpCoord.row, tmpCoord.column + 1 });
		}
	}
}

CFillMap::index_t CFillMap::GetRowLength(index_t row)
{
	for (index_t lastCharInd = MAX_SIZE - 1; lastCharInd >= 0; --lastCharInd)
	{
		if (m_data[row][lastCharInd] != value_t::EMPTY)
		{
			return lastCharInd + 1;
		}
	}
	return 0;
}

void CFillMap::PrintRow(index_t row, FILE *outFile)
{
	index_t lineLength = GetRowLength(row);

	for (index_t column = 0; column < lineLength; ++column)
	{
		if (m_data[row][column] == value_t::USED_SOURCE)
		{
			putc(static_cast<char>(value_t::SOURCE), outFile);
		}
		else
		{
			putc(static_cast<char>(m_data[row][column]), outFile);
		}
	}

	putc('\n', outFile);
}

void CFillMap::PrintMap(const char fileName[])
{
	FILE *f;
	if (fopen_s(&f, fileName, "w") != 0)
	{
		assert(false);
	}

	for (index_t row = 0; row < m_height; ++row)
	{
		PrintRow(row, f);
	}

	fclose(f);
}
