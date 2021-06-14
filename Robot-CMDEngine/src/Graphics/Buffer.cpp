#include "Buffer.h"

#include <cstring>

namespace Robot {

	Buffer::Buffer(int sizeX, int sizeY)
		: m_Buffer(nullptr), m_SizeX(sizeX), m_SizeY(sizeY)
	{
		Create();
	}

	Buffer::Buffer(const Buffer& buffer)
		: m_Buffer(nullptr), m_SizeX(buffer.m_SizeX), m_SizeY(buffer.m_SizeY)
	{
		Create();

		for (int i = 0; i < m_SizeY; i++)
		{
			std::memcpy(m_Buffer[i], buffer.m_Buffer[i], m_SizeX);
		}
	}

	Buffer& Buffer::operator=(const Buffer& right)
	{
		if (&right == this) return *this;

		if (m_Buffer) Delete();

		m_SizeX = right.m_SizeX;
		m_SizeY = right.m_SizeY;

		Create();

		for (int i = 0; i < m_SizeY; i++)
		{
			std::memcpy(m_Buffer[i], right.m_Buffer[i], sizeof(char) * m_SizeX);
		}

		return *this;
	}

	char* Buffer::operator[](int index)
	{
		return m_Buffer[index];
	}

	Buffer::~Buffer()
	{
		Delete();
	}

	void Buffer::SetMemory(char c)
	{
		for (int i = 0; i < m_SizeY; i++)
		{
			std::memset(m_Buffer[i], c, sizeof(char) * m_SizeX);
		}
	}

	int Buffer::GetX()
	{
		return m_SizeX;
	}

	int Buffer::GetY()
	{
		return m_SizeY;
	}

	void Buffer::Create()
	{
		m_Buffer = new char* [m_SizeY];

		for (int i = 0; i < m_SizeY; i++)
		{
			m_Buffer[i] = new char[m_SizeX];
		}
	}

	void Buffer::Delete()
	{
		for (int i = 0; i < m_SizeY; i++)
		{
			delete[] m_Buffer[i];
		}

		delete[] m_Buffer;
	}

}