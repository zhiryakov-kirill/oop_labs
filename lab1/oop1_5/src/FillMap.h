#pragma once

class CFillMap
{
public:
	typedef int8_t index_t;
	enum class value_t { EMPTY = ' ', WALL = '#', SOURCE = 'O', FULL = '.', USED_SOURCE = '!' };

	typedef struct coord_struct
	{
		index_t row, column;
	}
	coord_t;

	CFillMap(const char fileName[]);
	void FillMap();
	void PrintMap(const char fileName[]);

protected:
	static const index_t MAX_SIZE = 100;

	value_t m_data[MAX_SIZE][MAX_SIZE];
	index_t m_width, m_height;
	std::queue<coord_t> m_fillBuffer;

	void ClearMap(value_t value = value_t::EMPTY);
	void ParseLine(index_t row, const char line[]);
	index_t GetRowLength(index_t row);
	void PrintRow(index_t row, FILE *outFile);
};
